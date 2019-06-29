#pragma once

namespace sgl {
namespace v1 {
template<typename ForwardIterator0, typename Function>
void for_each(ForwardIterator0 first_0, ForwardIterator0 last_0, Function function) {
  while (first_0 != last_0) {
    function(*first_0);
    ++first_0;
  }
}

template<typename ForwardIterator0, typename ForwardIterator1, typename BinaryFunction>
void for_each(ForwardIterator0 first_0, ForwardIterator0 last_1, ForwardIterator1 first_1, BinaryFunction f) {
  while (first_0 != last_1) {
    f(*first_0, *first_1);
    ++first_0;
    ++first_1;
  }
}

template<typename ForwardIterator0, typename ForwardIterator1, typename ForwardIterator2, typename TernaryFunction>
void for_each(ForwardIterator0 first_0, ForwardIterator0 last_1, ForwardIterator1 first_1, ForwardIterator2 first_2, TernaryFunction f) {
  while (first_0 != last_1) {
    f(*first_0, *first_1, *first_2);
    ++first_0;
    ++first_1;
    ++first_2;
  }
}

template<typename ForwardIterator0, typename ForwardIterator1, typename ForwardIterator2, typename ForwardIterator3, typename QuaternionFunction>
void for_each(ForwardIterator0 first_0, ForwardIterator0 last_1, ForwardIterator1 first_1, ForwardIterator2 first_2, ForwardIterator3 first_3, QuaternionFunction f) {
  while (first_0 != last_1) {
    f(*first_0, *first_1, *first_2, *first_3);
    ++first_0;
    ++first_1;
    ++first_2;
    ++first_3;
  }
}
} // namespace v1
} // namespace sgl
