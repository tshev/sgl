#pragma once
// metasgl::certification = true;

namespace sgl {
namespace v1 {
template<typename ForwardIterator, typename OutputIterator, typename Transformation>
inline
std::pair<ForwardIterator, OutputIterator>
transform_n(ForwardIterator first, size_t n, OutputIterator out, Transformation transformation) {
  for (size_t i = 0; i != n; ++i) {
    *out = transformation(*first);
    ++out;
    ++first;
  }
  return {first, out};
}

template<typename ForwardIterator0, typename ForwardIterator1, typename OutputIterator, typename Transformation>
inline
std::pair<ForwardIterator0, OutputIterator>
transform_n(ForwardIterator0 first0, size_t n, ForwardIterator1 first1, OutputIterator out, Transformation transformation) {
  for (size_t i = 0; i != n; ++i) {
    *out = transformation(*first0, *first1);
    ++out;
    ++first0;
  }
  return {first0, out};
}
} // namespace v1
} // namespace sgl
