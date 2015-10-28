
#include <iostream>
#include <GLFW/glfw3.h>
#include <cmath>

#include <cstdlib>
// C++ でファイルを扱うライブラリ
#include <fstream>
#include <vector>

#ifdef _MAC_VER
//#define _USE_MATH_DEFINES // VS:算術関連の定義を有効にする
#endif

struct Vec2f {
  float x;
  float y;
  Vec2f(float x, float y) :  x(x), y(y) {}
  Vec2f Zero() { return Vec2f(0.0f, 0.0f); }
};

struct ColorA {
  float red;
  float green;
  float blue;
  float alpha;
  ColorA(float red, float green, float blue, float alpha)
  : red(red), green(green), blue(blue), alpha(alpha) {}
  ColorA(float red, float green, float blue)
  : red(red), green(green), blue(blue), alpha(1.0f) {}
};

enum WindowSize {
  Width = 640,
  Height = 480
};

void changeWindowSize(GLFWwindow* window,
                      const int width, const int height)
{
  glViewport(0, 0, width, height);
  glLoadIdentity();
  glOrtho(-width * 0.5f, width * 0.5f, -height * 0.5f, height * 0.5f, -0.0f, 1.0f);
}

bool setupTexture(const GLuint id, const char* file) {
  std::ifstream fstr(file, std::ios::binary);
  
  // 処理を中断
  if (!fstr) return false;
  
  // ファイルサイズを取得
  //  読み込み位置をファイル末尾へ移動
  //  ->ファイル先頭から読み込み位置までのオフセット
  //  =ファイルサイズ
  const size_t file_size = static_cast<size_t>(fstr.seekg(0, fstr.end).tellg());
  
  // 読み込み位置をファイル先頭へ戻す
  fstr.seekg(0, fstr.beg);
  
  // 動的配列を使ってファイルを読み込む場所を確保
  // charをfile_size個、メモリに確保する
  std::vector<char> texture_buffer(file_size);
  
  // 確保した場所へファイルの内容をすべて読み込む
  fstr.read(&texture_buffer[0], file_size);

  // OpenGLに
  // 「これから、テクスチャ識別子idに対して指示を与えます」
  // と指示
  glBindTexture(GL_TEXTURE_2D, id);
  
  // 1ピクセルに「赤、緑、青、α」の情報を持つ
  // 幅256ピクセル、高さ256ピクセルの画像データをOpenGLへ転送
  glTexImage2D(GL_TEXTURE_2D,
               0, GL_RGBA, 256, 256,
               0, GL_RGBA, GL_UNSIGNED_BYTE,
               &texture_buffer[0]);
  
  // 画像が拡大された場合にどう振る舞うか指定
  glTexParameteri(GL_TEXTURE_2D,
                  GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  
  // 画像が縮小された場合にどう振る舞うか指定
  glTexParameteri(GL_TEXTURE_2D,
                  GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  
  return true;
}

int main() {
  GLFWwindow* window;
  
  // Initialize the library
  if (!glfwInit()) {
    return -1;
  }
  
  // Create a windowed mode window and its OpenGL
  window = glfwCreateWindow(Width, Height, "Hello World", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }
  
  // Make the window`s context current
  glfwMakeContextCurrent(window);
  
  // Windowのサイズが変更されたときに呼び出す関数
  glfwSetWindowSizeCallback(window, changeWindowSize);
  
  // 「ビューポート変換」を指定
  // glViewport(X座標, Y座標, 幅, 高さ)
  // 画面左下からの座標(x, y)から
  // (幅 * 高さ)ピクセルの領域を描画領域とする
  glViewport(0, 0, Width, Height);
  
  // 「投影行列」を操作対象にする
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  
  // 単位行列を作り、現在の行列に掛け合わせる
  glOrtho(-Width * 0.5f, Width * 0.5f, -Height * 0.5f, Height * 0.5f, -0.0f, 1.0f);
  
  
  // OpenGLにテクスチャ識別子を1つ作ってもらう
  GLuint texture_id;
  glGenTextures(1, &texture_id);
  
  // 画像ファイルを読み込んで
  // テクスチャ識別子に設定する
    if (!setupTexture(texture_id, "res/image.raw")) {
      // 画像の読み込みに失敗したら
      // テクスチャ識別子を消去、GLFWの後始末をして終了
      glDeleteTextures(1, &texture_id);
      glfwTerminate();
      return EXIT_FAILURE;
    }
  
  // Loop until the user closes the window
  while (!glfwWindowShouldClose(window)) {
    // 描画バッファを塗りつぶす色の成分を指定
    glClearColor(0.4f, 0.4f, 0.4f, 0.0f);
    
    // 描画バッファを塗りつぶす
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    static const int scale = 200;
    
    // 描画する矩形の4頂点を配列で用意
    static const GLfloat vtx[] = {
      -0.5f * scale * 1.5f, -0.5f * scale,
       0.5f * scale * 1.5f, -0.5f * scale,
       0.5f * scale * 1.5f,  0.5f * scale,
      -0.5f * scale * 1.5f,  0.5f * scale
    };
    glVertexPointer(2, GL_FLOAT, 0, vtx);
    
    // 頂点ごとのテクスチャ座標を配列で準備
    static const GLfloat texture_uv[] = {
      1.0f, 1.0f,
      0.0f, 1.0f,
      0.0f, 0.0f,
      1.0f, 0.0f
    };
    glTexCoordPointer(2, GL_FLOAT, 0, texture_uv);
    
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    
    glEnable(GL_TEXTURE_2D);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    
    // 矩形を一つ描画
    glDrawArrays(GL_QUADS, 0, 4);
    
    // 描画が済んだら使った機能を全て無効にする
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisable(GL_TEXTURE_2D);
    
    // Swap front and back buffers
    glfwSwapBuffers(window);
    
    // Poll for and process events
    glfwPollEvents();
  }
  
  // 使い終わったテクスチャ識別子を削除
  glDeleteTextures(1, &texture_id);
  
  glfwTerminate();
  return 0;
}