#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename OutputIterator, typename Predicate>
inline
std::pair<ForwardIterator, OutputIterator> copy_while_not(ForwardIterator first, ForwardIterator last, OutputIterator output, Predicate predicate) {
  while (first != last && !predicate(*first)) {
    *output = *first;
    ++output;
    ++first;
  }
  return {first, output};
}


template<typename ForwardIterator, typename OutputIterator, typename Predicate>
inline
std::pair<ForwardIterator, OutputIterator> copy_while_not(ForwardIterator first, OutputIterator output, Predicate predicate) {
  while (!predicate(*first)) {
    *output = *first;
    ++output;
    ++first;
  }
  return {first, output};
}

} // namespace v1
} // namespace sgl
