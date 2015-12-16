
#include "Puzzle.hpp"
#include <iostream>


Puzzle::Puzzle(int width, int height, int cellNum) {
  // cellのサイズを計算
  float cellSize = std::min(width, height) / cellNum;
  cell = Cell(1, lacty::Vec2i(1, 1), cellSize);
  std::cout << "cellSize = " << cellSize << std::endl;
}


void Puzzle::update() {}

void Puzzle::draw() {
  cell.draw();
}
