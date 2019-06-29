#pragma once
namespace sgl {
namespace v1 {
// TODO: FIXME

template<typename ForwardItertor0, typename ForwardItertor1>
inline
bool suffix_of(ForwardItertor0 first_0, ForwardItertor0 last_0, ForwardItertor1 first_1, ForwardItertor1 last_1) {
  /**
   *
   *
   * @code
   * #include <algorithm>
   * #include <iostream>
   * #include <string>
   * #include "sgl.v1.function.suffix_of.h"

   * int main() {
   *   const std::string a = "abc";
   *   const std::string b = "bc";
   *   std::cout << sgl::v1::suffix_of(std::begin(a), std::end(a), std::begin(b), std::end(b)) << std::endl;;
   * }
  **/
  while (first_0 != last_0 && first_1 != last_1) {
    --last_0;
    --last_1;
    if (*last_0 != *last_1) {
      return false;
    }
  }
  return first_0 == last_0;
}


template<typename ForwardItertor0, typename ForwardItertor1, typename BinaryPredicate>
inline
bool suffix_of(ForwardItertor0 first_0, ForwardItertor0 last_0, ForwardItertor1 first_1, ForwardItertor1 last_1, BinaryPredicate pred) {
  while (first_0 != last_0 && first_1 != last_1) {
    --last_0;
    --last_1;
    if (!pred(*last_0, *last_1)) {
      return false;
    }
  }
  return first_0 == last_0;
}
}; // namespace v1
}; // namespace sgl
