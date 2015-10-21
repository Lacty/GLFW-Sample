
/*
  |wall|ω<)/ Copyright © 2015年 Lacty.
*/

#include <iostream>
#include <memory>

#include <GLFW/glfw3.h>

#include <lacty/Vector.h>
#include <lacty/Color.h>

using namespace lacty;

class AppBase {
public:
  AppBase() {}
  virtual ~AppBase() {}
  
  virtual void update() = 0;
  virtual void draw()   = 0;
};

class App : public AppBase {
public:
  App() {}
  ~App();
  
  void update();
  void draw();
};

App::~App() {
  std::cout << "delete" << std::endl;
}

void App::update() {
  std::cout << "update" << std::endl;
}

void App::draw() {
  std::cout << "draw" << std::endl;
}

int main() {
  std::unique_ptr<AppBase> app(new App());
  
  app->update();
  app->draw();
}
