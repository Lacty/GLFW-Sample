
#include "Cell.hpp"
#include "../include/Lacty/Graphic.h"


Cell::Cell(int number,
           const lacty::Vec2i& pos,
           float size) :
num(number),
pos(pos),
size(size) {}


void Cell::setPos(const lacty::Vec2i& pos) {
  this->pos = pos;
}

void Cell::setColor(const lacty::Color& color) {
  this->color = color;
}

int Cell::getNumber() {
  return num;
}

lacty::Vec2i Cell::getPos() {
  return pos;
}

lacty::Color Cell::getColor() {
  return color;
}


void Cell::update() {}

void Cell::draw() {
  lacty::drawPoint(lacty::Vec2f(pos.x, pos.y), size, color);
}
