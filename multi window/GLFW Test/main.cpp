
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

void draw(float angle) {
  GLfloat vtx[2 * 2 * 3];
  
  for (int i = 0; i < 3 * 2; i++) {
    if (i < 3) {
      vtx[i * 2 + 0] = std::sin(i * 2 * M_PI / 3 + angle) * 100.0f - 100.0f;
      vtx[i * 2 + 1] = std::cos(i * 2 * M_PI / 3 + angle) * 100.0f;
    } else {
      vtx[i * 2 + 0] = std::sin(i * 2 * M_PI / 3 + angle) * 100.0f + 100.0f;
      vtx[i * 2 + 1] = std::cos(i * 2 * M_PI / 3 + angle) * 100.0f;
    }
  }
  
  glVertexPointer(2, GL_FLOAT, 0, vtx);
  glColor4f(1.0f, 0.6f, 0.0f, 1.0f);
  
  
  glEnableClientState(GL_VERTEX_ARRAY);
  
  // OpenGLに三角形の描画を指定
  glDrawArrays(GL_TRIANGLES, 0, 6);
  
  glDisableClientState(GL_VERTEX_ARRAY);
}

enum WindowSize {
  Width = 640,
  Height = 480
};

int main() {
  GLFWwindow* window;
  
  // Initialize the library
  if (!glfwInit()) {
    return -1;
  }
  
  // Create a windowed mode window and its OpenGL
  window = glfwCreateWindow(Width, Height, "Hello World", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }
  
  // Make the window`s context current
  glfwMakeContextCurrent(window);
  
  // 「ビューポート変換」を指定
  // glViewport(X座標, Y座標, 幅, 高さ)
  // 画面左下からの座標(x, y)から
  // (幅 * 高さ)ピクセルの領域を描画領域とする
  glViewport(0, 0, Width, Height);
  
  // 「投影行列」を操作対象にする
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  
  // 単位行列を作り、現在の行列に掛け合わせる
  glOrtho(-Width * 0.5f, Width * 0.5f, -Height * 0.5f, Height * 0.5f, -0.0f, 1.0f);
  
  
  // Loop until the user closes the window
  while (!glfwWindowShouldClose(window)) {
    // 描画バッファを塗りつぶす色の成分を指定
    glClearColor(0.4f, 0.4f, 0.4f, 0.0f);
    
    // 描画バッファを塗りつぶす
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    static float angle = 0.1;
    angle += 0.01f;
    
    
    glViewport(0, 0, Width * 0.5f, Height);
    draw(angle);
    
    
    glViewport(Width * 0.5f, 0, Width * 0.5f, Height);
    draw(angle);
    
    
    // Swap front and back buffers
    glfwSwapBuffers(window);
    
    // Poll for and process events
    glfwPollEvents();
  }
  
  glfwTerminate();
  return 0;
}
