#pragma once

namespace sgl {
namespace v1 {


template<typename ForwardIterator0, typename Function>
ForwardIterator0 __for_each_n(ForwardIterator0 first_0, size_t n, Function function, std::random_access_iterator_tag) {
  ForwardIterator0 last_0 = first_0 + n;
  while (first_0 != last_0) {
    function(*first_0);
    ++first_0;
  }
  return first_0;
}


template<typename ForwardIterator0, typename Function>
ForwardIterator0 __for_each_n(ForwardIterator0 first_0, size_t n, Function function, std::forward_iterator_tag) {
  for (size_t i = 0; i < n; ++i) {
    function(*first_0);
    ++first_0;
  }
  return first_0;
}


template<typename ForwardIterator0, typename Function>
ForwardIterator0 for_each_n(ForwardIterator0 first_0, size_t n, Function function) {
    typedef typename std::iterator_traits<ForwardIterator0>::iterator_category iterator_category;
    return __for_each_n(first_0, n, function, iterator_category());
}

} // namespace v1
} // namespace sgl
