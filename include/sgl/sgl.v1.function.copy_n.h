#pragma once

namespace sgl {
namespace v1 {
template <typename ForwardIterator, typename N, typename OutputIterator>
inline
std::pair<ForwardIterator, OutputIterator> copy_n(ForwardIterator first, N n, OutputIterator output) {
  while (n != 0) {
    --n;
    *output = *first;
    ++output;
    ++first;
  }
  return {first, output};
}
} // namespace v1
} // namespace sgl
