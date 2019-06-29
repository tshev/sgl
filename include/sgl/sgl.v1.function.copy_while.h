#pragma once

namespace sgl {
namespace v1 {
template<typename ForwardIterator, typename OutputIterator, typename Predicate>
std::pair<ForwardIterator, OutputIterator> copy_while(ForwardIterator first, OutputIterator output, Predicate predicate) {
  while (predicate(*first)) {
    *output = *first;
    ++output;
    ++first;
  }
  return {first, output};
}
} // namespace v1
} // namespace sgl
