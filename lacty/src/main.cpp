
/*
  |wall|ω<)/ Copyright © 2015年 Lacty.
*/

#include <iostream>
#include <GLFW/glfw3.h>
#include <lacty/Vector.hpp>

using namespace lacty;

int main() {
  Vec3f pos(1, 1, 1);
  Vec2f p = pos.xy();
  std::cout << p.x << std::endl;
}
