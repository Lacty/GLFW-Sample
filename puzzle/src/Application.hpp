
#pragma once
#include "../include/Lacty/AppBase.h"
#include "../include/Lacty/Vector.h"
#include <iostream>

#include "Cell.hpp"


using namespace lacty;

class Application : public AppBase {
private:
  Cell cell;

public:
  void setup();
  void update();
  void draw();
};

void Application::setup() {
  cell = Cell(1, lacty::Vec2i(1, 0), 100.0f);
}

void Application::update() {}

void Application::draw() {
  cell.draw();
}
