#include <tuple>
#include <sgl/function_domains.h>

int foo(double x, char*, int&) {
  return 0;
}

int main() {
  typedef sgl::function_domains<decltype(foo)> domain;
  static_assert(std::is_same<domain::domain, std::tuple<double, char*, int&>>::value, "Expected domain: (double, char*, int&)");
  static_assert(std::is_same<domain::codomain, int>::value, "Expected codomain: int");
}
