#pragma once

namespace sgl {
namespace v1 {
/*
template<typename ForwardIterator, typename Function>
void for_each_block(ForwardIterator first, ForwardIterator middle, ForwardIterator last, Function function) {
  function(first, middle);
  while (offset != last) {
    auto offset = middle;
    while (first != middle) {
      ++offset;
      ++first;
    }
    middle = offset;
    function(first, middle);
  }
}

template<typename ForwardIterator, typename Function>
void for_each_block(ForwardIterator first, ForwardIterator last, size_t n, Function function) {
  auto middle = first;
  std::advance(middle, n);
  for_each_block(first, middle, last, function);
}
*/
} // namespace v1
} // namespace sgl
