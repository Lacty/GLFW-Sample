
#pragma once
#include <GLFW/glfw3.h>


namespace lacty {

template<typename T>
class ColorT {
public:
  T r, g, b;
  
  ColorT() : r(0), g(0), b(0) {}
  ColorT(T r, T g, T b) : r(r), g(g), b(b) {}
  ColorT(const ColorT<T>& src) : r(src.r), g(src.g), b(src.b) {}
  
  static ColorT<T> white()  { return ColorT<T>(1, 1, 1); }
  static ColorT<T> red()    { return ColorT<T>(1, 0, 0); }
  static ColorT<T> green()  { return ColorT<T>(0, 1, 0); }
  static ColorT<T> blue()   { return ColorT<T>(0, 0, 1); }
  static ColorT<T> orange() { return ColorT<T>(1.0f, 0.6f, 0.0f); }
  static ColorT<T> gray()   { return ColorT<T>(0.4f, 0.4f, 0.4f); }
};

template<typename T>
class ColorAT {
public:
  T r, g, b, a;
  
  ColorAT() : r(0), g(0), b(0), a(0) {}
  ColorAT(T r, T g, T b, T a) : r(r), g(g), b(b), a(a) {}
  ColorAT(const ColorAT<T>& src) : r(src.r), g(src.g), b(src.b), a(src.a) {}
  ColorAT(const ColorT<T>& src) : r(src.r), g(src.g), b(src.b), a(1) {}
  
  static ColorAT<T> white()  { return ColorAT<T>(1, 1, 1, 1); }
  static ColorAT<T> red()    { return ColorAT<T>(1, 0, 0, 1); }
  static ColorAT<T> green()  { return ColorAT<T>(0, 1, 0, 1); }
  static ColorAT<T> blue()   { return ColorAT<T>(0, 0, 1, 1); }
  static ColorAT<T> orange() { return ColorAT<T>(1.0f, 0.6f, 0.0f, 1.0f); }
  static ColorAT<T> gray()   { return ColorAT<T>(0.4f, 0.4f, 0.4f, 1.0f); }
};

typedef ColorT<float>  Color;
typedef ColorAT<float> ColorA;

}
