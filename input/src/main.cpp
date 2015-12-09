
#include <iostream>
#include <GLFW/glfw3.h>
#include <Lacty/Graphic.h>
#include <Lacty/Key.h>


enum {
  MOUSE_LEFT  = 1 << 0,
  MOUSE_RIGHT = 1 << 1
};

using namespace lacty;

int main() {
  if (!glfwInit()) return -1;
  
  GLFWwindow* window;
  window = glfwCreateWindow(640, 480, "Hoge", nullptr, nullptr);
  
  if (!window) {
    glfwTerminate();
    return -1;
  }
  
  glfwMakeContextCurrent(window);
  
  bool right_press = false;
  bool right_pull = false;
  bool right_push = false;
  
  bool left_press = false;
  bool left_pull = false;
  bool left_push = false;
  
  
  // ビット演算用の変数を用意
  unsigned char button_press = 0;
  unsigned char button_push = 0;
  unsigned char button_pull = 0;
  
  
  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    int left = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
    int right = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);
    
    left_push = !left_press && (left == GLFW_PRESS);
    left_pull = left_press && (left == GLFW_RELEASE);
    left_press = (left == GLFW_PRESS);
    
    right_push = !right_press && (right == GLFW_PRESS);
    right_pull = right_press && (right == GLFW_RELEASE);
    right_press = (right == GLFW_PRESS);
    
    //if (left_press) { std::cout << "left press" << std::endl; }
    //if (left_push)  { std::cout << "left push" << std::endl; }
    //if (left_pull)  { std::cout << "left pull" << std::endl; }
    
    //if (right_press) { std::cout << "right press" << std::endl; }
    //if (right_push)  { std::cout << "right push" << std::endl; }
    //if (right_pull)  { std::cout << "right pull" << std::endl; }
    
    
    unsigned char press = 0;
    if (left  == GLFW_PRESS) press |= MOUSE_LEFT;
    if (right == GLFW_PRESS) press |= MOUSE_RIGHT;
    
    button_push = press & ~button_press;
    button_pull = ~press & button_press;
    button_press = press;
    
    if (button_pull & MOUSE_LEFT) {
      std::cout << "pull left" << std::endl;
    }
    
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  
  glfwTerminate();
  
  return 0;
}