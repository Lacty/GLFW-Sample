
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
  
  Vec2<T> zero() const { return Vec2<T>(0, 0); }
  Vec2<T> xAxis() const { return Vec2<T>(1, 0); }
  Vec2<T> yAxis() const { return Vec2<T>(0, 1); }
  
  Vec2<T>& operator+=(const Vec2<T>& rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }
  Vec2<T>& operator-=(const Vec2<T>& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
  }
  Vec2<T>& operator*=(const Vec2<T>& rhs) {
    x *= rhs.x;
    y *= rhs.y;
    return *this;
  }
};


template<typename T>
class Vec3 {
public:
  T x, y, z;
  
  Vec3() : x(0), y(0), z(0) {}
  Vec3(T x, T y, T z) : x(x), y(y), z(z) {}
  Vec3(const Vec3<T>& src) : x(src.x), y(src.y), z(src.z) {}
  Vec3(const Vec2<T>& src) : x(src.x), y(src.y), z(0) {}
  
  Vec2<T> xy() const { return Vec2<T>(x, y); }
  Vec3<T> zero() const { return Vec3<T>(0, 0, 0); }
  Vec3<T> xAxis() const { return Vec3<T>(1, 0, 0); }
  Vec3<T> yAxis() const { return Vec3<T>(0, 1, 0); }
  Vec3<T> zAxis() const { return Vec3<T>(0, 0, 1); }
  
  Vec3<T>& operator+=(const Vec3<T>& rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
  }
  Vec3<T>& operator-=(const Vec3<T>& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
  }
  Vec3<T>& operator*=(const Vec3<T>& rhs) {
    x *= rhs.x;
    y *= rhs.y;
    z *= rhs.z;
    return *this;
  }
};

typedef Vec2<int>    Vec2i;
typedef Vec2<float>  Vec2f;
typedef Vec2<double> Vec2d;
typedef Vec3<int>    Vec3i;
typedef Vec3<float>  Vec3f;
typedef Vec3<double> Vec3d;

LACTY_END()
