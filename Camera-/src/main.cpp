
#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <GLFW/glfw3.h>


int Width  = 640;
int Height = 480;
const int cHeight = Height;
const int cWidth = Width;

float toRadians(float degree) {
  return degree * M_PI / 180;
}

float toDegree(float radian) {
  return radian / M_PI * 180;
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

void resize(GLFWwindow* window,
            const int width, const int height) {
  Width = width;
  Height = height;
}

using Vec3f = Eigen::Vector3f;
Eigen::Matrix4f lookAt(const Vec3f& eye,
                       const Vec3f& target,
                       const Vec3f& up)
{
  Vec3f a = eye - target;
  Vec3f z_ = a / a.norm();

  Vec3f b = up.cross(z_);
  Vec3f x_ = b / b.norm();

  Vec3f y_ = z_.cross(x_);

  Eigen::Matrix4f R;
  R(0, 0) = x_.x();
  R(0, 1) = x_.y();
  R(0, 2) = x_.z();
  R(0, 3) = 0;

  R(1, 0) = y_.x();
  R(1, 1) = y_.y();
  R(1, 2) = y_.z();
  R(1, 3) = 0;

  R(2, 0) = z_.x();
  R(2, 1) = z_.y();
  R(2, 2) = z_.z();
  R(2, 3) = 0;

  R(3, 0) = 0;
  R(3, 1) = 0;
  R(3, 2) = 0;
  R(3, 3) = 1;

  Eigen::Matrix4f T;
  for (int y = 0; y < 4; y++) {
    for (int x = 0; x < 4; x++) {
      T(x, y) = 0;
    }
  }

  T(0, 0) = 1;
  T(0, 3) = -eye.x();
  T(1, 1) = 1;
  T(1, 3) = -eye.y();
  T(2, 2) = 1;
  T(2, 3) = -eye.z();
  T(3, 3) = 1;

  return R * T;
};

void drawCircle() {
  static const GLfloat vtx[] = {
    0.0f, 0.433f,
    -0.5f, -0.433f,
    0.5f, -0.433f
  };

  glVertexPointer(2, GL_FLOAT, 0, vtx);
  glColor4f(1.0f, 0.6f, 0.0f, 1.0f);

  glEnableClientState(GL_VERTEX_ARRAY);

  glDrawArrays(GL_TRIANGLES, 0, 3);

  glDisableClientState(GL_VERTEX_ARRAY);
}

float fovy = 0;
void view() {
  glMatrixMode(GL_PROJECTION);
  // 正規行列を読み込む
  glLoadIdentity();

  glViewport(0, 0, Width, Height);

  float aspect = Width / float(Height);

  float near_z = 0.5f;
  float far_z = 30;
  float f = 35.f;

  if (Width < Height) {
    float half_w = std::tan(toRadians(f / 2)) * near_z;
    float half_h = half_w / aspect;
    fovy = toDegree(std::atan(half_h / near_z) * 2);
  }
  else {
    fovy = f;
  }
  
  Eigen::Matrix4f m = perspectiveView(fovy, aspect, near_z, far_z);
  glMultMatrixf(m.data());

  // モデリング行列を操作するお！と宣言
  glMatrixMode(GL_MODELVIEW);
  // 正規行列を読み込む
  glLoadIdentity();
}

void camera() {
  static Eigen::Vector3f camera_pos(0, 0, 2.0);
  static Eigen::Vector3f target_pos(0, 0, 0);
  static Eigen::Vector3f camera_up(0, 1, 0);

  Eigen::Matrix4f cm = lookAt(camera_pos, target_pos, camera_up);
  glMultMatrixf(cm.data());

  static Eigen::Vector3f camera_rotate(0, 0, 0);

  //camera_rotate.x() += 0.1f;
  //camera_rotate.y() += 0.1f;

  glRotatef(-camera_rotate.x(), 1.0f, 0.0f, 0.0f);
  glRotatef(-camera_rotate.y(), 0.0f, 1.0f, 0.0f);
  glRotatef(-camera_rotate.z(), 0.0f, 0.0f, 1.0f);

  glTranslatef(-camera_pos.x(), -camera_pos.y(), -camera_pos.z());
}

int main() {
  if (!glfwInit()) return -1;

  GLFWwindow* window = glfwCreateWindow(Width, Height,
                                        "Camera", nullptr, nullptr);

  if (!window) {
    glfwTerminate();
    return -1;
  }

  glfwSwapInterval(1);
  glfwSetWindowSizeCallback(window, resize);
  glfwMakeContextCurrent(window);

  float angle = 0;

  while(!glfwWindowShouldClose(window)) {
    glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    view();

    camera();
    angle += 0.1f;
    glRotatef(angle, 0, 1, 0);
    drawCircle();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();

  return 0;
}
