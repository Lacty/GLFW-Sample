# GLFW を使ったサンプル

## Mac
1. プロジェクトフォルダに配布されたincludeファイルをコピペ
2. Search Paths->Header Search Pathsに`include/`を追加
3. OSXをプロジェクトにコピペ
4. Build Phases->Link Binary LibrariesからAddを押し以下を追加
  * IOKit
  * CoreVideo
  * Cocoa
  * OpenGL
  * libglfw3.a
