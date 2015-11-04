
#pragma once
#include "Block.hpp"
#include "Bullet.hpp"
#include <vector>


class GameManager {
private:
  std::vector<Block> blocks;
  std::vector<Bullet> bullets;
  lacty::Vec2f bar_pos;
  
public:
  GameManager();
  
  void update(GLFWwindow* window);
  void draw();
};