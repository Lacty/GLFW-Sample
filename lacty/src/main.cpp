
/*
  |wall|ω<)/ Copyright © 2015年 Lacty.
*/

#include <iostream>
#include <GLFW/glfw3.h>
#include <lacty/Vector.h>
#include <lacty/Color.h>

using namespace lacty;

int main() {
  Color color;
  color = Color::orange();
  std::cout << color.g << std::endl;
}
