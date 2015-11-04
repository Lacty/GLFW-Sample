
#include "GameManager.hpp"
#include "Collision.hpp"
#include "Graph.hpp"

#include <iostream>

using namespace lacty;

GameManager::GameManager()
: bar_pos(0, -200)
{
  Vec2f size(50, 50);
  for (int h = -2; h < 4; h++) {
    for (int w = -5; w < 5; w++) {
      blocks.push_back({ Vec2f(w * size.x, h * size.y), size, ColorA(0.3f, 0.3f, 0.3f, 1.0f) });
    }
  }
}

void GameManager::update(GLFWwindow* window) {
  if (glfwGetKey(window, GLFW_KEY_A)) {
    bar_pos.x -= 3.0f;
  }
  if (glfwGetKey(window, GLFW_KEY_D)) {
    bar_pos.x += 3.0f;
  }
  
  if (glfwGetKey(window, GLFW_KEY_SPACE)) {
    bullets.push_back({ bar_pos, Vec2f(10, 10), ColorA(1, 1, 1, 1) });
  }
  
  for (auto& bullet : bullets) {
    bullet.update();
    std::cout << bullet.getPos().y << std::endl;
    for (auto& block : blocks) {
      if (isCollision(bullet.getPos(), bullet.getSize(),
                      block.getPos(), block.getSize()))
      {
        bullet.kill();
        block.kill();
      }
    }
  }
  
  
  auto bullet_itr = bullets.begin();
  while(bullet_itr != bullets.end()) {
    if (!bullet_itr->isActive()) {
      bullet_itr = bullets.erase(bullet_itr);
    } else if (bullet_itr->getPos().y > 250) {
      bullet_itr = bullets.erase(bullet_itr);
    } else {
      ++bullet_itr;
    }
  }
  
  auto block_itr = blocks.begin();
  while (block_itr != blocks.end()) {
    if (block_itr->isBloken()) {
      block_itr = blocks.erase(block_itr);
    } else {
      ++block_itr;
    }
  }
}

void GameManager::draw() {
  Vec2f size = Vec2f(50, 10);
  drawRect(Vec2f(bar_pos.x - size.x * 0.5f,
                 bar_pos.y),
           size,
           ColorA(1, 1, 1, 1));
  
  for (auto& block : blocks) {
    block.draw();
  }
  
  for (auto& bullet : bullets) {
    bullet.draw();
    drawRect(bullet.getPos(), bullet.getSize(), ColorA(0, 0, 0, 1));
  }
}