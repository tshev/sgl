#pragma once

namespace sgl {
namespace v1 {
template<typename ForwardIterator, typename OutputIterator, typename Predicate, typename Function>
inline
std::pair<ForwardIterator, OutputIterator> transform_while_with_sentinel(ForwardIterator first, OutputIterator output, Predicate predicate, Function function) {
  while (predicate(*first)) {
    *output = function(*first);
    ++output;
    ++first;
  }
  return {first, output};
}

template<typename ForwardIterator0, typename ForwardIterator1, typename OutputIterator, typename Predicate, typename Function>
inline
sgl::v1::triple<ForwardIterator0, ForwardIterator1, OutputIterator> transform_while_with_sentinel(ForwardIterator0 first0, ForwardIterator1 first1, OutputIterator output, Predicate predicate, Function function) {
  while (predicate(*first0, *first1)) {
    *output = function(*first0, *first1);
    ++output;
    ++first0;
    ++first1;
  }
  return {first0, first1, output};
}

/*
template<typename ForwardIterator0, typename ForwardIterator1, typename ForwardIterator2, typename OutputIterator, typename Predicate, typename Function>
inline
OutputIterator transform_while_with_sentinel(ForwardIterator0 first0, ForwardIterator1 first1, ForwardIterator2 first2, OutputIterator output, Predicate predicate, Function function) {
  while (predicate(*first0, *first1, *first2)) {
    *output = function(*first0, *first1, *first2);
    ++output;
    ++first0;
    ++first1;
    ++first2;
  }
  return output;
}
*/

} // namespace v1
} // namespace sgl
