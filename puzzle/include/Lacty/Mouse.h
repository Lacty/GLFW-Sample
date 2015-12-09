
#pragma once
#include <GLFW/glfw3.h>
#include <Lacty/Vector.h>
#include <Lacty/Window.h>


namespace lacty {

enum MouseButton {
  LEFT  = 1 << 0,
  RIGHT = 1 << 1
};

class Mouse {
private:
  GLFWwindow* gl_window;
  Window*     window;
  Vec2d       pos;
  
  int left;
  int right;
  
  char push;
  char pull;
  char press;

public:
  Mouse();
  Mouse(GLFWwindow* gl_window, Window* window);
  
  const Vec2d& getPos();
  
  void update();
  
  const bool isPush(MouseButton button);
  const bool isPull(MouseButton button);
  const bool isPress(MouseButton button);
};

} // namespace lacty
