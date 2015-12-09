
#pragma once
#include <string>
#include <Lacty/Vector.h>


namespace lacty {

class Window {
private:
  Vec2i size;
  
public:
  Window();
  Window(const Vec2i& size);
  
  const Vec2i& getSize() const;
  const int    getWidth() const;
  const int    getHeight() const;
  
  void setSize(const Vec2i& size);
  void setWidth(int width);
  void setHeight(int height);
};

};
