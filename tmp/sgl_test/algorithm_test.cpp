#include <iostream>
#include "algorithm.h"

int main() {
  int data[] = { 1, 2, 3, 4, 5 };
  constexpr size_t n = sgl::cumulate_size(sizeof(data) / sizeof(*data), size_t{2});
  int out[n];
  sgl::cumulate(data, data + 2, data + 5, out, 0);
  for (auto x : out) { std::cout << x << std::endl; }
}
