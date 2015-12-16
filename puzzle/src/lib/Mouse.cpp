
#include <GLFW/glfw3.h>
#include <Lacty/Mouse.h>
#include <assert.h>
#include <iostream>


namespace lacty {

Mouse::Mouse() :
gl_window(nullptr),
window(nullptr),
pos(Vec2d::zero()),
push(0),
pull(0),
press(0) {}

Mouse::Mouse(GLFWwindow* gl_window, Window* window) :
gl_window(gl_window),
window(window),
push(0),
pull(0),
press(0) {}

const Vec2d& Mouse::getPos() {
  assert(window != nullptr);
  glfwGetCursorPos(gl_window, &pos.x, &pos.y);
  pos.x -= window->getWidth() * 0.5f;
  pos.y = -pos.y + window->getHeight() * 0.5f;
  return pos;
}

void Mouse::update() {
  left  = glfwGetMouseButton(gl_window, GLFW_MOUSE_BUTTON_LEFT);
  right = glfwGetMouseButton(gl_window, GLFW_MOUSE_BUTTON_RIGHT);
  
  char _press = 0;
  if (left  == GLFW_PRESS) _press |= MouseButton::LEFT;
  if (right == GLFW_PRESS) _press |= MouseButton::RIGHT;
  
  push = _press & ~press;
  pull = ~_press & press;
  press = _press;
}

const bool Mouse::isPush(lacty::MouseButton button) {
  return push & button;
}

const bool Mouse::isPull(lacty::MouseButton button) {
  return pull & button;
}

const bool Mouse::isPress(lacty::MouseButton button) {
  return press & button;
}

} // namespace lacty
