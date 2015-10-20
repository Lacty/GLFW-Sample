
#include <GLFW/glfw3.h>


namespace lacty {

class Vec2f {
public:
  GLfloat x, y;
  
  Vec2f() : x(0), y(0) {}
  Vec2f(GLfloat x, GLfloat y) : x(x), y(y) {}
};

}