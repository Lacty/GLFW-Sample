//
// OpenGLでのライティング
//

#include <GLFW/glfw3.h>
#include <Eigen/Core>        // Eigenを使う
#include <Eigen/Geometry>    // Eigenを使う
#include <iostream>


// degrees -> radians
float toRadians(float degrees) {
  return float(degrees * M_PI / 180.0f);
}

// radians -> degrees
float toDegrees(float radians) {
  return float(radians * 180.0f / M_PI);
}


// 縦横比に応じてfovyを計算
// fov   横長画面の時のfov
// aspect 縦横比(w/h)
// near_z
float calcFovy(const float fov, const float aspect, const float near_z) {
  if (aspect >= 1.0f) return fov;
  
  // 画面が縦長になったら、幅基準でfovを求める
  // fovとnear_zから投影面の幅の半分を求める
  float half_w = std::tan(toRadians(fov / 2)) * near_z;

  // 表示画面の縦横比から、投影面の高さの半分を求める
  float half_h = half_w / aspect;

  // 投影面の高さの半分とnear_zから、fovが求まる
  return toDegrees(std::atan(half_h / near_z) * 2);
}


// 透視変換行列を作成
//
// fovy 視野角(縦) degree
// aspect 縦横比(w/h)
// near_z, far_z
Eigen::Matrix4f perspectiveView(float fovy,
                                float aspect,
                                float near_z,
                                float far_z) {
  Eigen::Matrix4f m;  // 4x4の行列を作成

  float fovy_rad = toRadians(fovy);
  float f        = 1.0f / (tan(fovy_rad / 2.0f));
  float d        = (far_z - near_z);

  m << f / aspect, 0.0f,                  0.0f,                         0.0f,
             0.0f,    f,                  0.0f,                         0.0f,
             0.0f, 0.0f, -(far_z + near_z) / d, -(2.0f * far_z * near_z) / d,
             0.0f, 0.0f,                 -1.0f,                         0.0f;
  
  return m;
}


// Windowのサイズ
int window_width  = 640;
int window_height = 480;


// Windowがリサイズされた時に呼び出される
void resize(GLFWwindow *, int width, int height) {
  window_width  = width;
  window_height = height;
}


void camera() {
  glViewport(0, 0, window_width, window_height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  float aspect = window_width / float(window_height);
  float fov = 35.0f;
  float near_z = 0.5f;

  float fovy = calcFovy(fov, aspect, near_z);
  Eigen::Matrix4f m = perspectiveView(fovy, aspect, near_z, 50.0f);
  glMultMatrixf(m.data());

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

using Vec3 = Eigen::Vector3f;
void drawCube(const Vec3& pos, const Vec3& scale, const Vec3& rot = Vec3::Zero()) {
  glPushMatrix();

  // 位置の移動と回転
  glTranslatef(pos.x(), pos.y(), pos.z());
  glRotatef(rot.x(), 1.0f, 0.0f, 0.0f);
  glRotatef(rot.y(), 0.0f, 0.1f, 0.0f);
  glRotatef(rot.z(), 0.0f, 0.0f, 1.0f);

  // 頂点配列を用意
  //  立方体の頂点配列
  GLfloat vtx[] = {
    // 前
    //  x,     y,    z,
    -0.5f,  0.5f, 0.5f,
    0.5f, -0.5f, 0.5f,
    0.5f,  0.5f, 0.5f,

    -0.5f,  0.5f, 0.5f,
    -0.5f, -0.5f, 0.5f,
    0.5f, -0.5f, 0.5f,

    // 後
    -0.5f, -0.5f, -0.5f,
    0.5f,  0.5f, -0.5f,
    0.5f, -0.5f, -0.5f,

    -0.5f, -0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f,
    0.5f,  0.5f, -0.5f,

    // 左
    -0.5f, -0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,

    -0.5f, -0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,

    // 右
    0.5f,  0.5f,  0.5f,
    0.5f, -0.5f, -0.5f,
    0.5f,  0.5f, -0.5f,

    0.5f,  0.5f,  0.5f,
    0.5f, -0.5f,  0.5f,
    0.5f, -0.5f, -0.5f,

    // 上
    -0.5f, 0.5f, -0.5f,
    0.5f, 0.5f,  0.5f,
    0.5f, 0.5f, -0.5f,

    -0.5f, 0.5f, -0.5f,
    -0.5f, 0.5f,  0.5f,
    0.5f, 0.5f,  0.5f,

    // 底
    -0.5f, -0.5f,  0.5f,
    0.5f, -0.5f, -0.5f,
    0.5f, -0.5f,  0.5f,

    -0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f, -0.5f,
    0.5f, -0.5f, -0.5f,
  };
  glScalef(scale.x(), scale.y(), scale.z());
  glVertexPointer(3, GL_FLOAT, 0, vtx);

  // 立方体の面法線
  GLfloat normal[] = {
    // 前
    // x,    y,    z,
    0.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 1.0f,

    // 後
    0.0f, 0.0f, -1.0f,
    0.0f, 0.0f, -1.0f,
    0.0f, 0.0f, -1.0f,
    0.0f, 0.0f, -1.0f,
    0.0f, 0.0f, -1.0f,
    0.0f, 0.0f, -1.0f,

    // 左
    -1.0f, 0.0f, 0.0f,
    -1.0f, 0.0f, 0.0f,
    -1.0f, 0.0f, 0.0f,
    -1.0f, 0.0f, 0.0f,
    -1.0f, 0.0f, 0.0f,
    -1.0f, 0.0f, 0.0f,

    // 右
    1.0f, 0.0f, 0.0f,
    1.0f, 0.0f, 0.0f,
    1.0f, 0.0f, 0.0f,
    1.0f, 0.0f, 0.0f,
    1.0f, 0.0f, 0.0f,
    1.0f, 0.0f, 0.0f,

    // 上
    0.0f, 1.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 1.0f, 0.0f,

    // 下
    0.0f, -1.0f, 0.0f,
    0.0f, -1.0f, 0.0f,
    0.0f, -1.0f, 0.0f,
    0.0f, -1.0f, 0.0f,
    0.0f, -1.0f, 0.0f,
    0.0f, -1.0f, 0.0f,
  };
  glNormalPointer(GL_FLOAT, 0, normal);

  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_NORMAL_ARRAY);

  glDrawArrays(GL_TRIANGLES, 0, 6 * 6);

  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_NORMAL_ARRAY);

  glPopMatrix();
}


using Vec4 = Eigen::Vector4f;
class Light {
private:
public:
  Light() = default;

  // ライティングを有効にする
  // 0番のライトを有効にする
  void enable() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
  }

  // 光の位置
  //  カレント行列により結果が決まる
  //  wの値が1.0だとポイントライトになる
  Light& pos(const Vec4& pos) {
    glLightfv(GL_LIGHT0, GL_POSITION, &pos.x());
    return *this;
  }

  // 拡散光
  Light& diffuse(const Vec4& diffuse) {
    glLightfv(GL_LIGHT0, GL_DIFFUSE, &diffuse.x());
    return *this;
  }

  // 環境光
  Light& ambient(const Vec4& ambient) {
    glLightfv(GL_LIGHT0, GL_AMBIENT, &ambient.x());
    return *this;
  }
  
  // スペキュラ
  Light& specular(const Vec4& specular) {
    glLightfv(GL_LIGHT0, GL_SPECULAR, &specular.x());
    return *this;
  }
};


class Material {
private:
public:
  Material() = default;

  //  環境光が当たった時の色味
  Material& ambient(const Vec4& ambient) {
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, &ambient.x());
    return *this;
  }

  // 拡散光が当たった時の色味
  Material& diffuse(const Vec4& diffuse) {
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, &diffuse.x());
    return *this;
  }

  // 自己発光
  Material& emission(const Vec4& emission) {
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, &emission.x());
    return *this;
  }

  // 光沢の色味
  Material& specular(const Vec4& specular) {
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, &specular.x());
    return *this;
  }

  // 光沢の加減
  //  値が小さいほど鋭い光沢になる
  Material& shininess(const float& shininess = 10.f) {
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
    return *this;
  }
};


int main() {
  if (!glfwInit()) return -1;

  GLFWwindow* window = glfwCreateWindow(window_width, window_height,
                                        "02 Lighting",
                                        nullptr, nullptr);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  glfwSetWindowSizeCallback(window, resize);
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);

  float angle = 0.0f;

  // ライトを作成
  Light light;
  light.enable();

  // マテリアルを作成
  Material material;

  // 法線を正規化する
  glEnable(GL_NORMALIZE);
  // カリング
  glEnable(GL_CULL_FACE);
  
  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // カメラの処理
    camera();

    // ライトの設定
    light.pos(Vec4(0, 0.0, 5.0f, 0.0f))    // 位置
      .diffuse(Vec4(1.0f, 1.0f, 1.0f, 1.0f))   // 拡散光
      .ambient(Vec4(0.0f, 0.0f, 0.0f, 1.0f))   // 環境光
      .specular(Vec4(0.6f, 0.6f, 0.6f, 1.0f)); // スペキュラ
    
    

    // 描画
    for (int x = -3; x < 4; x++) {
      // マテリアルの設定
      material.ambient(Vec4(1.0f, 0.6f, 0.0f, 1.0f)) // マテリアル(材質)の設定
        .diffuse(Vec4(angle * x + 0.3, std::cos(angle) * x, 0.4f, 1.0f))       // 拡散光が当たった時の色味
        .emission(Vec4(0.0f, 0.0f, 0.0f, 1.0f))      // 自己発光
        .specular(Vec4(0.8f, 0.8f, 0.8f, 1.0f))      // 光沢の色味
        .shininess();                                // 光沢の加減

      drawCube(Vec3(x * 0.5f, std::sin(angle * x), -4), Vec3(0.25f, 0.25f, 0.25f), Vec3(angle, angle, 0));      
    }
    
    
    angle += 0.02f;

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
}
