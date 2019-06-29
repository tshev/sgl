#pragma once

namespace sgl {
namespace v1 {


template<typename ForwardIterator0, typename ForwardIterator1>
inline
std::pair<ForwardIterator0, ForwardIterator1> find_missmatch(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1) {
  while (first0 != last0) {
    if (*first0 != *first1) { return {first0, first1}; }
    ++first0;
    ++first1;
  }
  return {first0, first1};
}


template<typename ForwardIterator0, typename ForwardIterator1, typename BinaryPredicate>
inline
std::pair<ForwardIterator0, ForwardIterator1> find_missmatch(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1, BinaryPredicate pred) {
  while (first0 != last0) {
    if (!pred(*first0, *first1)) { return {first0, first1}; }
    ++first0;
    ++first1;
  }
  return {first0, first1};
}


template<typename ForwardIterator0, typename ForwardIterator1, typename ForwardIterator2, typename TernaryPredicate>
inline
sgl::v1::triple<ForwardIterator0, ForwardIterator1, ForwardIterator2> find_missmatch(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1, ForwardIterator2 first2, TernaryPredicate pred) {
  while (first0 != last0) {
    if (!pred(*first0, *first1, *first2)) { return {first0, first1, first2}; }
    ++first0;
    ++first1;
    ++first2;
  }
  return {first0, first1, first2};
}

} // namespace v1
} // namespace sgl
