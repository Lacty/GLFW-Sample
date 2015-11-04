
#pragma once
#include <GLFW/glfw3.h>
#include "Color.h"
#include "Vector.h"


class Block {
private:
  lacty::Vec2f pos;
  lacty::Vec2f size;
  lacty::ColorA color;
  bool mIsBloken;
  
public:
  Block(const lacty::Vec2f& pos,
        const lacty::Vec2f& size,
        const lacty::ColorA& color);
  
  void update();
  void draw();
  
  bool isBloken();
  
  lacty::Vec2f getPos();
  lacty::Vec2f getSize();
  
  void kill();
};
