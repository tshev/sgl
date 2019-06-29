#pragma once
#include <string>
#include <iostream>
#include <cmath>

namespace sgl {
template<typename T0, typename T1>
void assert_equal(T0&& x, T1&& y, const char* name, int line) {
    std::cout << "status::assert_equal_for(" << name << ", " << line << ");\n";
    //static_assert(std::is_same<T0, T1>::value, "T0 and T1 must be the same");
    if (x == y) {
        std::cout << "status::assert_equal_success(" << name << ", " << line << ");\n"; 
        return;
    }
    auto message = "status::assert_equal = failure;";
    throw std::runtime_error(message);
}

template<typename T>
void assert_eps(T&& x, T&& y, const char* name, int line) {
  std::cout << "status::assert_equal_for(" << name << ", " << line << ");\n";
  auto d = std::abs(x - y);
  if (d < 0.000001) {
    return;
  }
  auto message = "status::assert_equal = failure;";
  throw std::runtime_error(message);
}

constexpr auto red ="\033[0;31m";
constexpr auto nocolor = "\033[0m";

struct testing {
    std::string file_name;
    testing(const std::string& file_name) : file_name(file_name) {}
    template<typename F>
    void operator()(F f) {
        auto color = red;
        std::cout << color << "begin(\"" << file_name << "\")\n" << nocolor;
        f();
        std::cout << color << "end(\"" << file_name << "\")\n" << nocolor;
    }
};

} // namespace sgl
