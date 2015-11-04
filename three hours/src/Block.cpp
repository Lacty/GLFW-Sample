
#include "Block.hpp"
#include "Graph.hpp"


Block::Block(const lacty::Vec2f& pos,
             const lacty::Vec2f& size,
             const lacty::ColorA& color)
: pos(pos), size(size), color(color)
{ mIsBloken = false; }


void Block::update() {}

void Block::draw() {
  drawRect(pos, size, color);
}

bool Block::isBloken() {
  return mIsBloken;
}

lacty::Vec2f Block::getPos() {
  return pos;
}

lacty::Vec2f Block::getSize() {
  return size;
}

void Block::kill() {
  mIsBloken = true;
}