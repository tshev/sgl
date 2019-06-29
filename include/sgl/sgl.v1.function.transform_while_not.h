#pragma once

namespace sgl {
namespace v1 {
template<typename ForwardIterator, typename OutputIterator, typename Predicate, typename Function>
OutputIterator transform_while_not(ForwardIterator first, OutputIterator output, Predicate predicate, Function function) {
  while (!predicate(*first)) {
    *output = function(*first);
    ++output;
    ++first;
  }
  return output;
}

template<typename ForwardIterator0, typename ForwardIterator1, typename OutputIterator, typename Predicate, typename Function>
OutputIterator transform_while_not(ForwardIterator0 first_0, ForwardIterator1 first_1, OutputIterator output, Predicate predicate, Function function) {
  while (!predicate(*first_0, *first_1)) {
    *output = function(*first_0, *first_1);
    ++output;
    ++first_0;
    ++first_1;
  }
  return output;
}

template<typename ForwardIterator0, typename ForwardIterator1, typename ForwardIterator2, typename OutputIterator, typename Predicate, typename Function>
OutputIterator transform_while_not(ForwardIterator0 first_0, ForwardIterator1 first_1, ForwardIterator2 first_2, OutputIterator output, Predicate predicate, Function function) {
  while (!predicate(*first_0, *first_1, *first_2)) {
    *output = function(*first_0, *first_1, *first_2);
    ++output;
    ++first_0;
    ++first_1;
    ++first_2;
  }
  return output;
}
} // namespace v1
} // namespace sgl
