#pragma once
namespace sgl {
namespace v1 {

template<typename InputIterator, typename ForwardIterator, typename Function>
inline
ForwardIterator uninitialized_transform_(InputIterator first, InputIterator last, ForwardIterator out, Function function) {
    ForwardIterator current = out;
    try {
        while (first != last) {
            sgl::v1::uninitialized_construct(*current, function(*first));
            ++current;
            ++first;
        }
        return current;
    } catch (...) {
        sgl::v1::destruct(out, current);
        throw;
    }

}

template<typename InputIterator, typename ForwardIterator, typename Function>
inline
ForwardIterator uninitialized_transform(InputIterator first, InputIterator last, ForwardIterator out, Function function) {
    // ranges don't intersect
    typedef typename std::iterator_traits<InputIterator>::value_type T;

    if constexpr (std::is_trivial<T>::value) {
        return sgl::v1::transform(first, last, out, function); 
    } else {
        return sgl::v1::uninitialized_transform_(first, last, out, function);
    }
}

} // namespace v1
} // namespace sgl
