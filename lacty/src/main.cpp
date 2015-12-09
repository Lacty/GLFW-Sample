
#include <iostream>
#include <GLFW/glfw3.h>
#include <Lacty/Graphic.h>


using namespace lacty;

int Width = 640;
int Height = 480;

void changeWindowSize(GLFWwindow* window,
                      const int width, const int height)
{
  glViewport(0, 0, width, height);
  glLoadIdentity();
  glOrtho(-width * 0.5f, width * 0.5f, -height * 0.5f, height * 0.5f, -0.0f, 1.0f);
}

int main() {
  if (!glfwInit()) return -1;
  
  GLFWwindow* window;
  window = glfwCreateWindow(Width, Height, "Hoge", nullptr, nullptr);
  
  if (!window) {
    glfwTerminate();
    return -1;
  }
  
  glfwMakeContextCurrent(window);
  
  // Windowのサイズが変更されたときに呼び出す関数
  glfwSetWindowSizeCallback(window, changeWindowSize);
  
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
  
  double mouse_x;
  double mouse_y;
  
  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glfwGetCursorPos(window, &mouse_x, &mouse_y);
    
    drawPoint(Vec2f(100, 0), 5.0f, Color(1, 1, 1));
    
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  
  glfwTerminate();
  
  return 0;
}