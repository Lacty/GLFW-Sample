
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
  Vec2(const Vec2<T>& src) : x(src.x), y(src.y) {}
};


template<typename T>
class Vec3 {
public:
  T x, y, z;
  
  Vec3() : x(0), y(0), z(0) {}
  Vec3(T x, T y, T z) : x(x), y(y), z(z) {}
  Vec3(const Vec3<T>& src) : x(src.x), y(src.y), z(src.z) {}
};

typedef Vec2<int>    Vec2i;
typedef Vec2<float>  Vec2f;
typedef Vec2<double> Vec2d;
typedef Vec3<int>    Vec3i;
typedef Vec3<float>  Vec3f;
typedef Vec3<double> Vec3d;

LACTY_END()
