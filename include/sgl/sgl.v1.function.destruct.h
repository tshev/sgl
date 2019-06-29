#pragma once
namespace sgl {
namespace v1 {
template<typename Pointer>
void destruct(Pointer first, Pointer last) {
    typedef typename std::iterator_traits<Pointer>::value_type value_type;
    while (first != last) {
        first->~value_type();
        ++first;
    }
}

template<typename T>
void destruct(T& x) {
    x.~T();
}

} // namespace v1
} // namespace sgl
