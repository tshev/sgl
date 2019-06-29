#pragma once
// metasgl::certification = true
namespace sgl {
namespace v1 {
template<typename ForwardIterator, typename OutputIterator, typename Function>
OutputIterator transform_n(ForwardIterator first, ForwardIterator last, size_t n, OutputIterator out, Function function) {
  size_t i = 0;
  while(i != n && first != last) {
    *out = function(*first);
    ++out;
    ++first;
    ++i;
  }
  return out;
}


template<typename ForwardIterator0, typename ForwardIterator1, typename OutputIterator, typename Function>
OutputIterator
transform_n(ForwardIterator0 first_0, ForwardIterator0 last_0, ForwardIterator1 first_1, size_t n, OutputIterator out, Function function) {
  size_t i = 0;
  while(i != n && first_0 != last_0) {
    *out = function(*first_0, *first_1);
    ++out;
    ++first_0;
    ++first_1;
    ++i;
  }
  return out;
}
} // namespace v1
} // namespace sgl
