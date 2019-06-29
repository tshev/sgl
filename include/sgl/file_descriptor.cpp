#include <iostream>
#include "sgl.v1.class.file_descriptor.h"

int main() {
  int x;
  sgl::file_descriptor fd("data2.txt", sgl::io::regular_file | sgl::io::rwo);
  std::cout << x << std::endl;
  fd.read((char*)&x, 4);
}
