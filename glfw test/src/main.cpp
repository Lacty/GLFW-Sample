
#include <GLFW/glfw3.h>
#include <Eigen/Core>        // Eigenを使う
#include <Eigen/Geometry>    // Eigenを使う
#include "graph.hpp"



int Width  = 640;
int Height = 480;

float toRadians(float degree) {
  return degree * M_PI * 2 / 360;
}

Eigen::Matrix4f perspectiveView(float fovy,
                                float aspect,
                                float near_z,
                                float far_z)
{
  float f = 1 / std::tan(toRadians(fovy) / 2);
  
  Eigen::Matrix4f m;
  m(0, 0) = f / aspect;
  m(0, 1) = 0.0f;
  m(0, 2) = 0.0f;
  m(0, 3) = 0.0f;
  
  m(1, 0) = 0.0f;
  m(1, 1) = f;
  m(1, 2) = 0.0f;
  m(1, 3) = 0.0f;
  
  m(2, 0) = 0.0f;
  m(2, 1) = 0.0f;
  m(2, 2) = -((far_z + near_z) / (far_z - near_z));
  m(2, 3) = -((2 * far_z * near_z) / (far_z - near_z));
  
  m(3, 0) = 0.0f;
  m(3, 1) = 0.0f;
  m(3, 2) = -1;
  m(3, 3) = 0.0f;
  return m;
}

void changeWindowSize(GLFWwindow* window,
                      const int width, const int height)
{
  glViewport(0, 0, width, height);
  glLoadIdentity();
  glOrtho(-width * 0.5f, width * 0.5f, -height * 0.5f, height * 0.5f, -0.0f, 1.0f);
}

void resize(GLFWwindow* window,
            const int width, const int height) {
  Width  = width;
  Height = height;
}


void view() {
  // 透視変換を操作するお！と宣言
  glMatrixMode(GL_PROJECTION);
  // 正規行列を読み込む
  glLoadIdentity();
  
  glViewport(0, 0, Width, Height);
  
  // 透視変換行列を作成して適用
  // glFrustum(GLdouble left, GLdouble right,
  //           GLdouble bottom, GLdouble top,
  //           GLdouble near, GLdouble far);
  // 左端の座標、右端の座標
  // 下端の座標、上端の座標
  // 最前面までの距離、最前面までの距離(距離はどちらも/Users/yanai/Desktop/OpenGL2D0より大きい値)
  /*glFrustum( -1,    1,
   1,   -1,
   0.5, 20.0);*/
  
  // Eigenの行列をOpenGLに渡す
  float aspect = Width / float(Height);
  Eigen::Matrix4f m = perspectiveView(36, aspect, 0.5, 50);
  glMultMatrixf(m.data());
  
  // モデリング行列を操作するお！と宣言
  glMatrixMode(GL_MODELVIEW);
  // 正規行列を読み込む
  glLoadIdentity();
}

int main() {
  if (!glfwInit()) return -1;
  
  GLFWwindow* window = glfwCreateWindow(Width, Height,
                                        "08 Matrix",
                                        nullptr, nullptr);
  
  if (!window) {
    glfwTerminate();
    return -1;
  }
  
  glfwMakeContextCurrent(window);
  
  // Windowのサイズが変更された際に呼ばれる関数を設定
  glfwSetWindowSizeCallback(window, resize);
  
  glfwSwapInterval(1);
  
  float angle = 0.0f;
  
  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    view();
    
    glTranslatef(0.0f, 0.0f, -1.5f);
    // 回転行列を適用
    // angle: 回転量(単位:degrees)  一周360c
    // x, y, z: 回転軸を表すベクトル(単位ベクトルでなくてよい)
    glRotatef(angle, 0.0f, 1.0f, 0.0f);
    angle += 1.0f;
    
    drawCircle(Vec2f(0, 0), 5, 0.4, Color(1, 1, 1));
    
    view();
    
    glTranslatef(0.0f, 0.0f, -1.5f);
    drawCircle(Vec2f(0, 0), 5, 0.2, Color(0, 0, 1));
    
    glfwSwapBuffers(window);
    
    glfwPollEvents();
  }
  
  glfwTerminate();
  
  return 0;
}