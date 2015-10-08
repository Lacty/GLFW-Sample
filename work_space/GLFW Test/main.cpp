
#include <iostream>
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

void drawPoint(const Vec2f& pos, const float& size, const Color& color) {
  GLfloat vtx[] = { pos.x, pos.y };
  
  // 描画に使う頂点の配列をOpenGLに指定
  glVertexPointer(2, GL_FLOAT, 0, vtx);
  
  // サイズ指定
  glPointSize(size);
  
  // 色指定
  glColor4f(color.red, color.green, color.blue, color.alpha);
  
  // 頂点配列で描画するモードに切り替えて
  // 点を描画
  glEnableClientState(GL_VERTEX_ARRAY);
  glDrawArrays(GL_POINTS, 0, 1);
  
  // 描画が終わったら描画モードを元に戻す
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
    // Render here
    
    // 描画バッファを塗りつぶす色の成分を指定
    glClearColor(0.4f, 0.4f, 0.4f, 0.0f);
    
    // 描画バッファを塗りつぶす
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    // 点を丸くする
    glEnable(GL_POINT_SMOOTH);
    // alpha値を使用する
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_CONSTANT_ALPHA);
    
    Vec2f pos(0.0f, 0.0f);
    float size = 10.0f;
    Color color(1.0f, 0.6f, 0.0f, 1.0f);
    drawPoint(pos, size, color);
    
    Vec2f pos2(0.4f, 0.0f);
    drawPoint(pos2, 100, Color(0.0f, 1.0f, 0.0f));
    
    Vec2f pos3(-0.4f, 0.0f);
    drawPoint(pos3, 20.0f, Color(1, 0, 0));
    
    
    // Swap front and back buffers
    glfwSwapBuffers(window);
    
    // Poll for and process events
    glfwPollEvents();
  }
  
  glfwTerminate();
  return 0;
}
