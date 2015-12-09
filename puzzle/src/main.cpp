
#include "Application.hpp"


int main() {
  Application app;
  app.AppBase::setup();
  
  app.setup();
  
  while (app.AppBase::isOpen()) {
    app.AppBase::clear();
    app.AppBase::update();
    
    app.update();
    app.draw();
    
    app.AppBase::swapBuffer();
    app.AppBase::pollEvents();
  }
  
  app.AppBase::end();
  return 0;
}