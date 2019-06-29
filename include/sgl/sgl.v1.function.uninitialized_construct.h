#pragma once
namespace sgl {
namespace v1 {
template<typename ForwardIterator, typename T>
inline
void uninitialized_construct(ForwardIterator first, ForwardIterator last, const T& x) {
  typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;
  while(first != last) {
    ::new (static_cast<void*>(std::addressof(*first))) value_type(x);
    ++first;
  }
}

template<typename T>
inline
T* uninitialized_construct(T& ptr) {
    return new (reinterpret_cast<T*>(std::addressof(ptr))) T ();
}

template<typename T, typename A, typename... Args>
inline
T* uninitialized_construct(T& ptr, A&& x0, Args&& ...xi) {
    return new (reinterpret_cast<T*>(std::addressof(ptr))) T(std::forward<A>(x0), std::forward<Args>(xi)...);
}
} // namespace v1
} // namespace sgl
