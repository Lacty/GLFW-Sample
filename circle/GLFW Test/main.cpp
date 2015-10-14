
#include <iostream>
#include <GLFW/glfw3.h>
#include <cmath>
#include <vector>

#ifdef _MAC_VER
//#define _USE_MATH_DEFINES // VS:算術関連の定義を有効にする
#endif

struct Vec2f {
  float x;
  float y;
  Vec2f(float x, float y) :  x(x), y(y) {}
  Vec2f Zero() { return Vec2f(0.0f, 0.0f); }
};

struct ColorA {
  float red;
  float green;
  float blue;
  float alpha;
  ColorA(float red, float green, float blue, float alpha)
    : red(red), green(green), blue(blue), alpha(alpha) {}
  ColorA(float red, float green, float blue)
    : red(red), green(green), blue(blue), alpha(1.0f) {}
};

void drawCircle(const Vec2f& center, int vertex_num,
                float radius, const ColorA& color)
{
  std::vector<GLfloat> vtx;
  for (int i = 0; i < vertex_num; i++) {
    vtx.push_back(center.x + std::sin(i * 2 * M_PI / vertex_num) * radius);
    vtx.push_back(center.y + std::cos(i * 2 * M_PI / vertex_num) * radius);
  }
  
  glVertexPointer(2, GL_FLOAT, 0, &vtx[0]);
  glColor4f(color.red, color.green, color.blue, color.alpha);
  
  glEnableClientState(GL_VERTEX_ARRAY);
  
  glDrawArrays(GL_LINE_LOOP, 0, vertex_num);
  
  glDisableClientState(GL_VERTEX_ARRAY);
}

int main() {
  GLFWwindow* window;
  
  // Initialize the library
  if (!glfwInit()) {
    return -1;
  }
  
  // Create a windowed mode window and its OpenGL
  window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }
  
  // Make the window`s context current
  glfwMakeContextCurrent(window);
  
  // Loop until the user closes the window
  while (!glfwWindowShouldClose(window)) {
    // 描画バッファを塗りつぶす色の成分を指定
    glClearColor(0.4f, 0.4f, 0.4f, 0.0f);
    
    // 描画バッファを塗りつぶす
    glClear(GL_COLOR_BUFFER_BIT);

    
    drawCircle(Vec2f(-0.3, 0), 5, 0.5f, ColorA(0.1f, 0.8f, 0.1f, 1.0f));
    drawCircle(Vec2f(0, 0), 40, 0.4f, ColorA(1.0f, 0.6f, 0.0f, 1.0f));
    drawCircle(Vec2f(0.4, 0), 8, 0.3f, ColorA(1.0f, 1.0f, 1.0f, 1.0f));
    
    // Swap front and back buffers
    glfwSwapBuffers(window);
    
    // Poll for and process events
    glfwPollEvents();
  }
  
  glfwTerminate();
  return 0;
}
