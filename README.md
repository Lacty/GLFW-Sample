# GLFW を使ったサンプル

## Mac
1. Cocoa Applicationでプロジェクトを作成
2. 以下を消去
    * [projectName]/AppDelegate.h
    * [projectName]/AppDelegate.m
    * [projectName]/ViewController.h
    * [projectName]/ViewController.m
    * [projectName]/Assets.xcassets
    * [projectName]/Main.storyboard
    * [projectName]/Supporting Files
    * [projectName]Tests/
    * [projectName]UITests/
3. プロジェクトフォルダに配布されたincludeファイルをコピペ
4. OSXをプロジェクトにコピペ
5. Search Paths->Header Search Pathsに`include/`を追加
7. Search Paths->Library Search Pathsに`OSX/lib`を追加
8. Build Phases->Link Binary LibrariesからAddを押し以下を追加
  * IOKit
  * CoreVideo
  * Cocoa
  * OpenGL
  * libglfw3.a
9. プロジェクトフォルダにsrc/を新規作成
    - main.cppを作成
10. src/をXcode上にコピペ
    - Create groupsを選択
    - [projectName]を選択
11. res/はCreate folder referenceを選択すること
