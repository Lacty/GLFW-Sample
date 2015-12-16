
#include <iostream>


int main() {
  int width = 512;
  int row = 4;
  int m = 330;
  int size = width / row;
  
  int num = m / size;
  std::cout << num << std::endl;
}
