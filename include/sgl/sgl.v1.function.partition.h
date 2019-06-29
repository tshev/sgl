#pragma once

namespace sgl {
namespace v1 {

template<typename BidirectionalIterator, typename Predicate>
BidirectionalIterator partition(BidirectionalIterator first, BidirectionalIterator last, Predicate predicate) {
  while (first != last) {
    while (!predicate(*first)) { ++first; if (first == last) { return first; } }
    --last;
    if (first == last) { return first; }

    while (predicate(*last)) { --last; if (first == last) { return first; } }
    // assert(first != last);
    // assert(predicate(*first) && !predicate(*last));
    std::swap(*first, *last);
    ++first;
  }
  return first;
}

template<typename BidirectionalIterator, typename Predicate>
BidirectionalIterator partition1(BidirectionalIterator first, BidirectionalIterator last, Predicate predicate) {
  while (true) {
       while (first != last && !predicate(*first)) { ++first; }
       while (first != last && predicate(*--last));
       if (first == last) return first;;
       std::swap(*first, *last);
  }
}

} // namespace v1
} // namespace sgl
