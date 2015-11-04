
#pragma once
#include "Vector.h"
#include "Color.h"


class Bullet {
private:
  lacty::Vec2f pos;
  lacty::Vec2f size;
  lacty::ColorA color;
  bool mIsActive;
  
  float mSpeed;
  
public:
  Bullet(const lacty::Vec2f& pos,
         const lacty::Vec2f& size,
         const lacty::ColorA& color);
  
  void update();
  void draw();
  
  lacty::Vec2f getPos();
  lacty::Vec2f getSize();
  
  bool isActive();
  
  void kill();
};
