
#pragma once
#include <Lacty/AppBase.h>
#include <iostream>


using namespace lacty;

enum Index {
  Row    = 4,
  Column = 4
};

class Application : public AppBase {
private:
  Color index[Row][Column];
  
public:
  void setup();
  void update();
  void draw();
};

//25 50 75 100
void Application::setup() {
  index[0][0] = Color(1.0f, 1.0f, 0.75f);
  index[0][1] = Color(1.0f, 1.0f, 0.50f);
  index[0][2] = Color(1.0f, 1.0f, 0.25f);
  index[0][3] = Color(1.0f, 1.0f, 0.00f);
  
  index[1][0] = Color(1.0f, 0.75f, 1.0f);
  index[1][1] = Color(1.0f, 0.50f, 1.0f);
  index[1][2] = Color(1.0f, 0.25f, 1.0f);
  index[1][3] = Color(1.0f, 0.00f, 1.0f);
  
  index[2][0] = Color(0.75f, 1.0f, 1.0f);
  index[2][1] = Color(0.50f, 1.0f, 1.0f);
  index[2][2] = Color(0.25f, 1.0f, 1.0f);
  index[2][3] = Color(0.00f, 1.0f, 1.0f);
  
  index[3][0] = Color(1.0f, 1.0f, 1.0f);
  index[3][1] = Color(0.66f, 0.66f, 0.66f);
  index[3][2] = Color(0.33f, 0.33f, 0.33f);
  index[3][3] = Color(0.0f, 0.0f, 0.0f);
}

void Application::update() {}

void Application::draw() {
  for (int r = 0; r < Row; r++) {
    for (int c = 0; c < Column; c++) {
      drawPoint(Vec2f(r, c), 50, index[r][c]);
    }
  }
}