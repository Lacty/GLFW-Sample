
#include "Graph.hpp"

void drawRect(const lacty::Vec2f& pos, const lacty::Vec2f& size,
              const lacty::ColorA& color)
{
  std::vector<GLfloat> vtx = {
    pos.x, pos.y,
    pos.x + size.x, pos.y,
    pos.x, pos.y + size.y,
    pos.x + size.x, pos.y + size.y
  };
  glVertexPointer(2, GL_FLOAT, 0, &vtx[0]);
  glColor4f(color.r, color.g, color.b, color.a);

  glEnableClientState(GL_VERTEX_ARRAY);

  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  glDisableClientState(GL_VERTEX_ARRAY);
}