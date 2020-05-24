#pragma once
namespace sgl {
namespace v1 {

template<typename InputIterator, typename ForwardIterator>
inline
ForwardIterator uninitialized_copy_(InputIterator first, InputIterator last, ForwardIterator out) {
    ForwardIterator current = out;
    try {
        while (first != last) {
            sgl::v1::uninitialized_construct(std::addressof(*current), *first);
            ++current; ++first;
        }
        return current;
    } catch (...) {
        sgl::v1::destruct(out, current);
        throw;
    }
}


template<typename InputIterator, typename ForwardIterator>
inline
ForwardIterator uninitialized_copy(InputIterator first, InputIterator last, ForwardIterator out) {
    // ranges don't intersect
    typedef typename std::iterator_traits<InputIterator>::value_type T;

    if constexpr (std::is_trivial<T>::value) {
        return sgl::v1::copy(first, last, out); 
    } else {
        return sgl::v1::uninitialized_copy_(first, last, out);
    }
}

} // namespace v1
} // namespace sgl
