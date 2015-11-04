
#include "Collision.hpp"


bool isCollision(const lacty::Vec2f& pos1, const lacty::Vec2f& siz1,
                 const lacty::Vec2f& pos2, const lacty::Vec2f& siz2)
{
  if (pos1.x < pos2.x + siz2.x) {
    if (pos1.x + siz1.x > pos2.x) {
      if (pos1.y < pos2.y + siz2.y) {
        if (pos1.y + siz1.y > pos2.y) {
          return true;
        }
      }
    }
  }
  return false;
}