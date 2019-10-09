#pragma once
namespace sgl {
namespace v1 {

template<typename ForwardIterator>
inline
void default_construct(ForwardIterator first, ForwardIterator last) {
  typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;
  while (first != last) {
    ::new (static_cast<void*>(std::addressof(*first))) value_type();
    ++first;
  }
}

} // namespace v1
} // namespace sgl
