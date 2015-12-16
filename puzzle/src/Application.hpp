
#pragma once
#include "../include/Lacty/AppBase.h"
#include "../include/Lacty/Vector.h"
#include "../include/Lacty/Graphic.h"
#include "Cell.hpp"
#include <iostream>


using namespace lacty;

class Application : public AppBase {
private:
  enum {
    Row    = 4,
    Column = 4
  };
  Cell cells[Row][Column];
  int CellSize;
  int LastNumber;
  
  bool isAdjCellLastNumber(int x, int y);
  
  void swap(int x1, int y1, int x2, int y2);

public:
  void setup();
  void update();
  void draw();
};


bool Application::isAdjCellLastNumber(int x, int y) {
  // 範囲から外れているか判定
  if (x <= -1) return false;
  if (x >= Row) return false;
  if (y <= -1) return false;
  if (y > Column) return false;
  
  // 移動可能か判定
  if (cells[x][y].getNumber() == LastNumber) return true;
  
  // それ以外
  return false;
}

void Application::swap(int x1, int y1, int x2, int y2) {
  Cell temp = cells[x1][y1];
  cells[x1][y1] = cells[x2][y2];
  cells[x2][y2] = temp;
}

void Application::setup() {
  // セルのサイズを求める
  CellSize = std::min(getWindowWidth(), getWindowHeight()) / Row;
  std::cout << CellSize;

  // 最後の番号を求める
  LastNumber = Row * Column - 1;

  int i = 0;
  for (int r = 0; r < Row; r++) {
    for (int c = 0; c < Column; c++) {
    
      // 最後だけ黒
      if (i == LastNumber) {
        cells[r][c] = Cell(i, lacty::Color(0, 0, 0));
      }
      else {
        cells[r][c] = Cell(i, lacty::Color(0.7, 0.3, 0.4));
      }
      i++;
    }
  }
}

void Application::update() {
  if (!isPush(MouseButton::LEFT)) return;
  
  // マウス座標を左下0,0に変換
  lacty::Vec2d mp(getMousePos());
  mp.x += getWindowWidth() * 0.5f;
  mp.y += getWindowHeight() * 0.5f;
  
  // マウスの位置をr,cに変換
  lacty::Vec2i pos(mp.x / CellSize, mp.y / CellSize);
  std::cout << pos.x << "," << pos.y << std::endl;
  
  // ラストのセルをクリックした場合は処理を終了
  if (cells[pos.x][pos.y].getNumber() == LastNumber) return;
  
  // 周辺のセルの状態を確認
  // 右
  if (isAdjCellLastNumber(pos.x + 1, pos.y)) {
    swap(pos.x, pos.y, pos.x + 1, pos.y);
  }
  // 左
  if (isAdjCellLastNumber(pos.x - 1, pos.y)) {
    swap(pos.x, pos.y, pos.x - 1, pos.y);
  }
  // 上
  if (isAdjCellLastNumber(pos.x, pos.y + 1)) {
    swap(pos.x, pos.y, pos.x, pos.y + 1);
  }
  // 下
  if (isAdjCellLastNumber(pos.x, pos.y - 1)) {
    swap(pos.x, pos.y, pos.x, pos.y - 1);
  }
}

void Application::draw() {
  lacty::Vec2f pos;
  for (int r = 0; r < Row; r++) {
    for (int c = 0; c < Column; c++) {
      pos.x = r * CellSize + CellSize * 0.5f;
      pos.y = c * CellSize + CellSize * 0.5f;
      lacty::drawPoint(pos, CellSize, cells[r][c].getColor());
    }
  }
}
