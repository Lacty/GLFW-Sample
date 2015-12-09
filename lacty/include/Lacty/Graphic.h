
#pragma once
#include <Lacty/Vector.h>
#include <Lacty/Color.h>


namespace lacty {

void drawPoint(const Vec2f& pos, const float& size, const Color& color);
void drawPoint(const Vec2f& pos, const float& size, const ColorA& color);

void drawCircle(const Vec2f& center, int vertex_num, float radius, const Color& color);
void drawCircle(const Vec2f& center, int vertex_num, float radius, const ColorA& color);

void drawTriangle(const Vec2f& v1, const Vec2f& v2, const Vec2f& v3, const Color& color);
void drawTriangle(const Vec2f& v1, const Vec2f& v2, const Vec2f& v3, const ColorA& color);

} // namespace lacty