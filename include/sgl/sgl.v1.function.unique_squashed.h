#pragma once

namespace sgl {
namespace v1 {


template<typename ForwardIterator, typename Function>
ForwardIterator unique_squash(ForwardIterator first, ForwardIterator last, Function f) {
  if (first == last) { return first; }

  auto slow = first;
  auto fast = first;
  ++fast;

  while (fast != last) {
    if (*slow == *fast) {
      *first = f(*first, *fast);
    } else {
      ++first;
      *first = std::move(*fast);
    }
    ++fast;
    ++slow;
  }
  return ++first;
}


template<typename ForwardIterator, typename Function, typename Predicate>
ForwardIterator unique_squash(ForwardIterator first, ForwardIterator last, Function f, Predicate pred) {
  if (first == last) { return first; }

  auto slow = first;
  auto fast = first;
  ++fast;

  while (fast != last) {
    if (pred(*slow, *fast)) {
      *first = f(*first, *fast);
    } else {
      ++first;
      *first = std::move(*fast);
    }
    ++fast;
    ++slow;
  }
  return ++first;
}


} // namespace v1
} // namespace sgl
