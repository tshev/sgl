#pragma once

namespace sgl {
namespace v1 {

template<typename It0, typename It1, typename P>
requires(
    sgl::v1::input_iterator(It0) && sgl::v1::readable(It0) &&
    sgl::v1::forward_iterator(It1) && sgl::v1::writable(It1) &&
    sgl::v1::binary_predicate<SGLValueType(It0)>(P)
)
inline
std::pair<It0, It1> copy_while(It0 first, It1 output, P pred) {
  while (pred(*first)) {
    *output = *first;
    ++output;
    ++first;
  }
  return {first, output};
}


template<typename It0, typename It1, typename P>
requires(
    sgl::v1::input_iterator(It0) && sgl::v1::readable(It0) &&
    sgl::v1::forward_iterator(It1) && sgl::v1::writable(It1) &&
    sgl::v1::binary_predicate<SGLValueType(It0)>(P)
)
inline
std::pair<It0, It1> copy_while(It0 first, It0 last, It1 output, P pred) {
  while (first != last && pred(*first)) {
    *output = *first;
    ++output;
    ++first;
  }
  return {first, output};
}

} // namespace v1
} // namespace sgl
