#pragma once
namespace sgl {
namespace v1 {

template<typename InputIterator, typename ForwardIterator>
ForwardIterator uninitialized_copy(InputIterator first, InputIterator last, ForwardIterator out) {
    typedef typename std::iterator_traits<InputIterator>::value_type T;

    if constexpr (std::is_trivial<T>::value) {
        return sgl::v1::copy(first, last, out); 
    } else {
        return sgl::v1::uninitialized_copy_trivial(first, last, out);
    }
}

} // namespace v1
} // namespace sgl
