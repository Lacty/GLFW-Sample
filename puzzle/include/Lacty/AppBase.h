
#pragma once

#include <GLFW/glfw3.h>

#include <Lacty/Color.h>
#include <Lacty/Mouse.h>
#include <Lacty/Window.h>
#include <Lacty/Vector.h>
#include <Lacty/Graphic.h>


class AppBase {
private:
  GLFWwindow* gl_window;
  
  lacty::Window window;
  lacty::Mouse  mouse;
  
  lacty::ColorA background;
  
protected:
  bool isPush(lacty::MouseButton button);
  bool isPull(lacty::MouseButton button);
  bool isPress(lacty::MouseButton button);
  
  void setBackGround(lacty::ColorA color);

public:
  AppBase();
  
  virtual void setup();
  virtual void update();
  virtual void draw();
  
  bool isOpen();
  void clear();
  void swapBuffer();
  void pollEvents();
  void end();
};
