
#pragma once
#include <GLFW/glfw3.h>


struct Vec2f {
  float x;
  float y;
  Vec2f(float x, float y) :  x(x), y(y) {}
  Vec2f Zero() { return Vec2f(0.0f, 0.0f); }
};

struct Color {
  float red;
  float green;
  float blue;
  float alpha;
  Color(float red, float green, float blue, float alpha)
  : red(red), green(green), blue(blue), alpha(alpha) {}
  Color(float red, float green, float blue)
  : red(red), green(green), blue(blue), alpha(1.0f) {}
};

void drawPoint(const Vec2f& pos, const float& size, const Color& color);


void drawCircle(const Vec2f& center, int vertex_num,
                float radius, const Color& color);