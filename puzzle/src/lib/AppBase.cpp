
#include <Lacty/AppBase.h>
#include <iostream>


AppBase::AppBase() :
gl_window(nullptr),
background(lacty::ColorA::gray())
{
  std::cout << "create AppBase\n";
}


bool AppBase::isPush(lacty::MouseButton button) {
  return mouse.isPush(button);
}

bool AppBase::isPull(lacty::MouseButton button) {
  return mouse.isPull(button);
}

bool AppBase::isPress(lacty::MouseButton button) {
  return mouse.isPress(button);
}

void AppBase::setBackGround(lacty::ColorA color) {
  background = color;
}

void AppBase::setup() {
  if (!glfwInit()) exit(-1);
  
  window = lacty::Window(lacty::Vec2i(640, 480));
  
  gl_window = glfwCreateWindow(window.getWidth(),
                               window.getHeight(),
                               "", nullptr, nullptr);
  
  if (!gl_window) {
    glfwTerminate();
    exit(-1);
  }
  
  glfwMakeContextCurrent(gl_window);
  
  mouse = lacty::Mouse(gl_window, &window);
}

void AppBase::update() {
  mouse.update();
}

void AppBase::draw() {}


bool AppBase::isOpen() {
  return !glfwWindowShouldClose(gl_window);
}

void AppBase::clear() {
  glClearColor(background.r, background.g, background.b, background.a);
  glClear(GL_COLOR_BUFFER_BIT);
}

void AppBase::swapBuffer() {
  glfwSwapBuffers(gl_window);
}

void AppBase::pollEvents() {
  glfwPollEvents();
}

void AppBase::end() {
  glfwTerminate();
}