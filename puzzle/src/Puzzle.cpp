
#include "Puzzle.hpp"
#include <iostream>


Puzzle::Puzzle(int width, int height, int column) {
  Column = column;
  Row    = column;
  Width  = width;
  Height = height;

  // cellのサイズを計算
  CellSize = std::min(Width, Height) / Column;

  // cellの数だけ作成
  for (int r = 0; r < Row; r++) {
    for (int c = 0; c < Column; c++) {
      // 最後だけ処理を飛ばす
      if (r * c == (Row-1) * (Column-1)) continue;
      cells.emplace_back(1, lacty::Vec2i(r, c), CellSize);
    }
  }
}


void Puzzle::update(bool isClick, const lacty::Vec2d& mp) {
  if (isClick) {
    // 左下を0,0とした座標系に変換
    lacty::Vec2d mouse(mp.x + Width * 0.5f,
                       mp.y + Height * 0.5f);

    // 0~Columnの座標に変換
    lacty::Vec2i pos(mouse.x / CellSize, mouse.y / CellSize);
  }
}

void Puzzle::draw() {
  for (auto it : cells) {
    it.draw();
  }
}
