#pragma once

namespace sgl {
namespace v1 {
template<typename ForwardIterator, typename Function>
void for_each_subrange(ForwardIterator first, ForwardIterator middle, ForwardIterator last, Function function) {
  function(first, middle);
  if (middle == last) return;
  while (true) {
    ++first;
    ++middle;
    function(first, middle);
    if (middle == last) return;
  }
}


template<typename ForwardIterator, typename Function>
void for_each_subrange(ForwardIterator first, ForwardIterator last, size_t n, Function function) {
  auto middle = first;
  std::advance(middle, n);
  for_each_subrange(first, middle, last, function);
}

template<typename ForwardIterator, typename OutputIterator, typename Function>
OutputIterator transform_subrange(ForwardIterator first, ForwardIterator middle, ForwardIterator last, OutputIterator out, Function function) {
  *out = function(first, middle);
  ++out;
  if (middle == last) return out;
  while (true) {
    ++first;
    ++middle;
    *out = function(first, middle);
    ++out;
    if (middle == last) return out;
  }
}
} // namespace v1
} // namespace sgl
