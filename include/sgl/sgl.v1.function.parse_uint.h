#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename Iterator, typename Predicate>
inline
ForwardIterator parse_uint(ForwardIterator first, ForwardIterator last, Iterator out, Predicate isdigit) {
  typedef typename std::iterator_traits<Iterator>::value_type T;
  if (first == last || !isdigit(*first)) {
    return first;
  }
  
  T result(*first - '0');
  ++first;
  constexpr T ten(10);
  while (first != last && isdigit(*first)) {
    result *= ten;
    result += *first - '0';
    ++first;
  }
  *out = std::move(result);
  return first;
}

template<typename ForwardIterator, typename Iterator>
inline
ForwardIterator parse_uint(ForwardIterator first, ForwardIterator last, Iterator out) {
    return sgl::v1::parse_uint(first, last, out, [](auto x) { return std::isdigit(x); });
}

} // namespace v1
} // namespace sgl
