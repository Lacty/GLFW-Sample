
#pragma once
#include "../include/Lacty/Color.h"


class Cell {
private:
  int number;
  lacty::Color color;
  
public:
  Cell() = default;
  Cell(int number, lacty::Color color);
  
  int getNumber();
  lacty::Color getColor();
};
