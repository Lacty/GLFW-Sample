
#include <iostream>
#include <GLFW/glfw3.h>


int main() {
  GLFWwindow* window;
  
  // Initialize the library
  if (!glfwInit()) {
    return -1;
  }
  
  // Create a windowed mode window and its OpenGL
  window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }
  
  // Make the window`s context current
  glfwMakeContextCurrent(window);
  
  // Loop until the user closes the window
  while (!glfwWindowShouldClose(window)) {
    // Render here
    
    // 描画バッファを塗りつぶす色の成分を指定
    glClearColor(0.4f, 0.4f, 0.4f, 0.0f);
    
    // 描画バッファを塗りつぶす
    glClear(GL_COLOR_BUFFER_BIT);
    
    // 点を描画する位置を指定
    static const GLfloat vtx[] = { 0.0f, 0.0f };
    
    // 描画に使う頂点の配列をOpenGLに指定
    glVertexPointer(2, GL_FLOAT, 0, vtx);
    
    // 描画する点のサイズ指定
    glPointSize(4.0f);
    
    // 描画する点の色を指定
    glColor4f(1.0f, 0.6f, 0.0f, 1.0f);
    
    // 頂点配列で描画するモードに切り替えて
    // 点を描画
    glEnableClientState(GL_VERTEX_ARRAY);
    glDrawArrays(GL_POINTS, 0, 1);
    
    // 描画が終わったら描画モードを元に戻す
    glDisableClientState(GL_VERTEX_ARRAY);
    
    // Swap front and back buffers
    glfwSwapBuffers(window);
    
    // Poll for and process events
    glfwPollEvents();
  }
  
  glfwTerminate();
  return 0;
}
