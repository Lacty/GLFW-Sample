
#pragma once
#include "../include/Lacty/AppBase.h"
#include "../include/Lacty/Vector.h"
#include "Puzzle.hpp"
#include <iostream>


using namespace lacty;

class Application : public AppBase {
private:
  Puzzle game;

public:
  void setup();
  void update();
  void draw();
};

void Application::setup() {
  game = Puzzle(getWindowWidth(), getWindowHeight(), 4);
}

void Application::update() {
  game.update(isPush(MouseButton::LEFT), getMousePos());
}

void Application::draw() {
  game.draw();
}
