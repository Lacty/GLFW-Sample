
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
  lacty::Vec2f p(pos.x * size, pos.y * size);
  p.x += size * 0.5f;
  p.y += size * 0.5f;
  lacty::drawPoint(p, size, color);
}
