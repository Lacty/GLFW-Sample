
#include <Lacty/AppBase.h>
#include <iostream>


int Global_Window_Width;
int Global_Window_Height;

void changeWindowSize(GLFWwindow* window,
                      const int width, const int height)
{
  Global_Window_Width = width;
  Global_Window_Height = height;
  glViewport(0, 0, width, height);
  glLoadIdentity();
  glOrtho(0.0f, width, 0.0f, height, -0.0f, 1.0f);
}

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
  
  window = lacty::Window(lacty::Vec2i(512, 512));
  Global_Window_Width = window.getWidth();
  Global_Window_Height = window.getHeight();
  
  gl_window = glfwCreateWindow(window.getWidth(),
                               window.getHeight(),
                               "", nullptr, nullptr);
  
  if (!gl_window) {
    glfwTerminate();
    exit(-1);
  }
  
  glfwMakeContextCurrent(gl_window);
  glfwSetWindowSizeCallback(gl_window, changeWindowSize);

  glViewport(0, 0, window.getWidth(), window.getHeight());
  glLoadIdentity();
  glOrtho(0.0f, window.getWidth(), 0.0f, window.getHeight(), -0.0f, 1.0f);

  mouse = lacty::Mouse(gl_window, &window);
}

int AppBase::getWindowWidth() {
  return window.getWidth();
}

int AppBase::getWindowHeight() {
  return window.getHeight();
}

lacty::Vec2d AppBase::getMousePos() {
  return mouse.getPos();
}

void AppBase::update() {
  mouse.update();
  window.setWidth(Global_Window_Width);
  window.setHeight(Global_Window_Height);
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
