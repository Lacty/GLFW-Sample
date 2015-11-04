
#include "Bullet.hpp"
#include "Graph.hpp"


Bullet::Bullet(const lacty::Vec2f& pos,
               const lacty::Vec2f& size,
               const lacty::ColorA& color)
: pos(pos), size(size),
color(color), mIsActive(true), mSpeed(3) {}


void Bullet::update() {
  pos.y += mSpeed;
}

void Bullet::draw() {
  drawRect(pos, size, color);
}


lacty::Vec2f Bullet::getPos() {
  return pos;
}

lacty::Vec2f Bullet::getSize() {
  return size;
}

bool Bullet::isActive() {
  return mIsActive;
}

void Bullet::kill() {
  mIsActive = false;
}
