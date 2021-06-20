#pragma once
namespace sgl {
namespace v1 {

template<typename InputIterator, typename ForwardIterator>
inline
ForwardIterator uninitialized_copy_(InputIterator first, InputIterator last, ForwardIterator out) {
    ForwardIterator current = out;
    try {
        while (first != last) {
            sgl::v1::construct(std::addressof(*current), *first);
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
ForwardIterator uninitialized_copy_(InputIterator first, InputIterator last, ForwardIterator out, const typename std::iterator_traits<InputIterator>::value_type& value) {
    ForwardIterator current = out;
    try {
        while (first != last) {
            sgl::v1::construct(std::addressof(*current), *first);
            ++current; ++first;
        }
        sgl::v1::construct(std::addressof(*current), value);
        ++current;
        return current;
    } catch (...) {
        sgl::v1::destruct(out, current);
        throw;
    }
}

template<typename InputIterator, typename ForwardIterator>
inline
ForwardIterator uninitialized_copy_(InputIterator first, InputIterator last, ForwardIterator out, typename std::iterator_traits<InputIterator>::value_type&& value) {
    ForwardIterator current = out;
    try {
        while (first != last) {
            sgl::v1::construct(std::addressof(*current), *first);
            ++current; ++first;
        }
        sgl::v1::construct(std::addressof(*current), std::move(value));
        ++current;
        return current;
    } catch (...) {
        sgl::v1::destruct(out, current);
        throw;
    }
}

template<typename InputIterator, typename ForwardIterator, bool>
struct _uninitialized_copy {
    ForwardIterator operator()(InputIterator first, InputIterator last, ForwardIterator out) {
        return sgl::v1::uninitialized_copy_(first, last, out);
    }

    ForwardIterator operator()(InputIterator first, InputIterator last, ForwardIterator out, const typename std::iterator_traits<InputIterator>::value_type& value) {
        return sgl::v1::uninitialized_copy_(first, last, out, value);
    }

    ForwardIterator operator()(InputIterator first, InputIterator last, ForwardIterator out, typename std::iterator_traits<InputIterator>::value_type&& value) {
        return sgl::v1::uninitialized_copy_(first, last, out, std::move(value));
    }
};

template<typename InputIterator, typename ForwardIterator>
inline
ForwardIterator uninitialized_copy(InputIterator first, InputIterator last, ForwardIterator out) {
    // ranges don't intersect
    typedef typename std::iterator_traits<InputIterator>::value_type T;
    return sgl::v1::_uninitialized_copy<InputIterator, ForwardIterator, !std::is_trivial<T>::value>()(first, last, out);
}

} // namespace v1
} // namespace sgl
