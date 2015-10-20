
#pragma once
#include <lacty/Namespace.h>
#include <GLFW/glfw3.h>


LACTY_SCOPE()

template<typename T>
class Vec2 {
public:
  T x, y;

  Vec2() : x(0), y(0) {}
  Vec2(T x, T y) : x(x), y(y) {}
};

typedef Vec2<int>    Vec2i;
typedef Vec2<float>  Vec2f;
typedef Vec2<double> Vec2d;

LACTY_END()
