
#pragma once
#include "../include/Lacty/Vector.h"
#include "../include/Lacty/Color.h"


class Cell {
private:
  int num;
  lacty::Vec2i pos;
  float size;
  lacty::Color color;

public:
  Cell() = default;
  Cell(int number,
       const lacty::Vec2i& pos,
       float size);
  
  void setPos(const lacty::Vec2i& pos);
  void setColor(const lacty::Color& color);

  int getNumber();
  lacty::Vec2i getPos();
  lacty::Color getColor();

  void update();
  void draw();
};
