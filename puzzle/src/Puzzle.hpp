
#pragma once
#include "../include/Lacty/Color.h"
#include "../include/Lacty/Vector.h"
#include "../include/Lacty/Mouse.h"
#include "../include/Lacty/Graphic.h"
#include "../include/Lacty/Window.h"

#include "Cell.hpp"

#include <vector>


class Puzzle {
private:
  std::vector<Cell> cells;
  int Row;
  int Column;
  int CellNum;
  int CellSize;
  int Width;
  int Height;

public:
  Puzzle() = default;
  Puzzle(int width, int height, int column);

  void update(bool isClick, const lacty::Vec2d& mp);
  void draw();
};
