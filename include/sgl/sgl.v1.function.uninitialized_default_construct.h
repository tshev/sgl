#pragma once
namespace sgl {
namespace v1 {

template<typename ForwardIterator>
inline
void uninitialized_default_construct(ForwardIterator first, ForwardIterator last) {
  typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;
  if constexpr (std::is_nothrow_default_constructible<value_type>::value) {
    sgl::v1::default_construct(first, last);
  } else {
    ForwardIterator start = first;
    try {
      while (first != last) {
        ::new (static_cast<void*>(std::addressof(*first))) value_type();
        ++first;
      }
    } catch (...) {
      while (start != first) {
        start->~value_type();
        ++start;
      }
    }
  }
}
} // namespace v1
} // namespace sgl
