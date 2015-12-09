
#include <vector>
#include <math.h>
#include <GLFW/glfw3.h>
#include <Lacty/Graphic.h>


namespace lacty {

void drawPoint(const Vec2f& pos, const float& size, const Color& color) {
  GLfloat vtx[] = { pos.x, pos.y };
  
  // 描画に使う頂点の配列をOpenGLに指定
  glVertexPointer(2, GL_FLOAT, 0, vtx);
  
  // サイズ指定
  glPointSize(size);
  
  // 色指定
  glColor3f(color.r, color.g, color.b);
  
  // 頂点配列で描画するモードに切り替えて
  // 点を描画
  glEnableClientState(GL_VERTEX_ARRAY);
  glDrawArrays(GL_POINTS, 0, 1);
  
  // 描画が終わったら描画モードを元に戻す
  glDisableClientState(GL_VERTEX_ARRAY);
}

void drawPoint(const Vec2f& pos, const float& size, const ColorA& color) {
  GLfloat vtx[] = { pos.x, pos.y };
  
  // 描画に使う頂点の配列をOpenGLに指定
  glVertexPointer(2, GL_FLOAT, 0, vtx);
  
  // サイズ指定
  glPointSize(size);
  
  // 色指定
  glColor4f(color.r, color.g, color.b, color.a);
  
  // 頂点配列で描画するモードに切り替えて
  // 点を描画
  glEnableClientState(GL_VERTEX_ARRAY);
  glDrawArrays(GL_POINTS, 0, 1);
  
  // 描画が終わったら描画モードを元に戻す
  glDisableClientState(GL_VERTEX_ARRAY);
}

void drawCircle(const Vec2f& center, int vertex_num,
                float radius, const Color& color)
{
  std::vector<GLfloat> vtx;
  for (int i = 0; i < vertex_num; i++) {
    vtx.push_back(center.x + sin(i * 2 * M_PI / vertex_num) * radius);
    vtx.push_back(center.y + cos(i * 2 * M_PI / vertex_num) * radius);
  }
  
  glVertexPointer(2, GL_FLOAT, 0, &vtx[0]);
  glColor3f(color.r, color.g, color.b);
  
  glEnableClientState(GL_VERTEX_ARRAY);
  
  glDrawArrays(GL_LINE_LOOP, 0, vertex_num);
  
  glDisableClientState(GL_VERTEX_ARRAY);
}

void drawCircle(const Vec2f& center, int vertex_num,
                float radius, const ColorA& color)
{
  std::vector<GLfloat> vtx;
  for (int i = 0; i < vertex_num; i++) {
    vtx.push_back(center.x + sin(i * 2 * M_PI / vertex_num) * radius);
    vtx.push_back(center.y + cos(i * 2 * M_PI / vertex_num) * radius);
  }
  
  glVertexPointer(2, GL_FLOAT, 0, &vtx[0]);
  glColor4f(color.r, color.g, color.b, color.a);
  
  glEnableClientState(GL_VERTEX_ARRAY);
  
  glDrawArrays(GL_LINE_LOOP, 0, vertex_num);
  
  glDisableClientState(GL_VERTEX_ARRAY);
}

void drawTriangle(const Vec2f& v1, const Vec2f& v2, const Vec2f& v3, const Color& color) {
  std::vector<GLfloat> vtx;
  vtx.push_back(v1.x); vtx.push_back(v1.y);
  vtx.push_back(v2.x); vtx.push_back(v2.y);
  vtx.push_back(v3.x); vtx.push_back(v3.y);
  
  glVertexPointer(2, GL_FLOAT, 0, &vtx[0]);
  glColor3f(color.r, color.g, color.b);
  
  glEnableClientState(GL_VERTEX_ARRAY);
  
  glDrawArrays(GL_LINE_LOOP, 0, 3);
  
  glDisableClientState(GL_VERTEX_ARRAY);
}

void drawTriangle(const Vec2f& v1, const Vec2f& v2, const Vec2f& v3, const ColorA& color) {
  std::vector<GLfloat> vtx;
  vtx.push_back(v1.x); vtx.push_back(v1.y);
  vtx.push_back(v2.x); vtx.push_back(v2.y);
  vtx.push_back(v3.x); vtx.push_back(v3.y);
  
  glVertexPointer(2, GL_FLOAT, 0, &vtx[0]);
  glColor4f(color.r, color.g, color.b, color.a);
  
  glEnableClientState(GL_VERTEX_ARRAY);
  
  glDrawArrays(GL_LINE_LOOP, 0, 3);
  
  glDisableClientState(GL_VERTEX_ARRAY);
}

} // namespace lacty