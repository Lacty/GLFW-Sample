
#include <Lacty/Window.h>


namespace lacty {

Window::Window() {}

Window::Window(const Vec2i& size) :
size(size) {}

const Vec2i& Window::getSize() const {
  return size;
}

const int Window::getWidth() const {
  return size.x;
}

const int Window::getHeight() const {
  return size.y;
}

void Window::setSize(const Vec2i &size) {
  this->size = size;
}

void Window::setWidth(int width) {
  size.x = width;
}

void Window::setHeight(int height) {
  size.y = height;
}

} // namespace lacty
