
#pragma once
#include "../include/Lacty/Color.h"
#include "../include/Lacty/Vector.h"
#include "../include/Lacty/Mouse.h"
#include "../include/Lacty/Graphic.h"
#include "../include/Lacty/Window.h"

#include "Cell.hpp"


class Puzzle {
private:
  Cell cell;

public:
  Puzzle() = default;
  Puzzle(int width, int height, int cellNum);

  void update();
  void draw();
};
