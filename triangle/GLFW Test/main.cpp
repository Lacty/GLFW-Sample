
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
    
    
    static const GLfloat vtx[] = {
      0.0f, 0.433f,
      -0.5f, -0.433f,
      0.5f, -0.433f,
    };
    
    glVertexPointer(2, GL_FLOAT, 0, vtx);
    glColor4f(1.0f, 0.6f, 0.0f, 1.0f);
    
    glEnableClientState(GL_VERTEX_ARRAY);
    
    // OpenGLに三角形の描画を指定
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    glDisableClientState(GL_VERTEX_ARRAY);
    
    
    // Swap front and back buffers
    glfwSwapBuffers(window);
    
    // Poll for and process events
    glfwPollEvents();
  }
  
  glfwTerminate();
  return 0;
}
