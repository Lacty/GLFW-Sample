
#pragma once
#include <set>
#include <GLFW/glfw3.h>


class Key {
private:
  GLFWwindow* window;

  std::set<int> push;
  std::set<int> press;
  std::set<int> pull;

  Key();

  static Key& get();

public:
  static void enable(GLFWwindow* window);

  static void flashInput();
  
  static void setKeyPush(int key_num);
  
  static bool isPush(int key_num);
  static bool isPress(int key_num);
};