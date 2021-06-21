#pragma once
namespace sgl {
namespace v1 {

template<typename InputIterator, typename ForwardIterator>
inline
std::pair<InputIterator, ForwardIterator> 
uninitialized_copy_n_(std::forward_iterator_tag, InputIterator first,  size_t n, ForwardIterator out) {
    ForwardIterator current = out;
    try {
        while (n != 0) {
            sgl::v1::construct(std::addressof(*current), *first);
            ++current; ++first;
            --n;
        }
        return {first, current};
    } catch (...) {
        sgl::v1::destruct(out, current);
        throw;
    }
}


template<typename InputIterator, typename ForwardIterator>
inline
std::pair<InputIterator, ForwardIterator> 
uninitialized_copy_n_(std::random_access_iterator_tag, InputIterator first,  size_t n, ForwardIterator out) {
    auto last = first + n;
    return {first, sgl::v1::uninitialized_copy(first, last, out)};
}

template<typename InputIterator, typename ForwardIterator>
inline
std::pair<InputIterator, ForwardIterator> 
uninitialized_copy_n_(InputIterator first,  size_t n, ForwardIterator out) {
    typedef typename std::iterator_traits<InputIterator>::iterator_category iterator_tag;
    return sgl::v1::uninitialized_copy_n_(iterator_tag{}, first, n, out);
}

template<typename InputIterator, typename ForwardIterator>
inline
std::pair<InputIterator, ForwardIterator> uninitialized_copy_n_(InputIterator first, size_t n, ForwardIterator out, const typename std::iterator_traits<InputIterator>::value_type& value) {
    ForwardIterator current = out;
    try {
        while (n != 0) {
            --n;
            sgl::v1::construct(std::addressof(*current), *first);
            ++current; ++first;
        }
        sgl::v1::construct(std::addressof(*current), value);
        ++current;
        return {first, current};
    } catch (...) {
        sgl::v1::destruct(out, current);
        throw;
    }
}

template<typename InputIterator, typename ForwardIterator>
inline
std::pair<InputIterator, ForwardIterator> uninitialized_copy_n_(InputIterator first, size_t n, ForwardIterator out, typename std::iterator_traits<InputIterator>::value_type&& value) {
    ForwardIterator current = out;
    try {
        while (n != 0) {
            --n;
            sgl::v1::construct(std::addressof(*current), *first);
            ++current; ++first;
        }
        sgl::v1::construct(std::addressof(*current), std::move(value));
        ++current;
        return {first, current};
    } catch (...) {
        sgl::v1::destruct(out, current);
        throw;
    }
}

template<typename InputIterator, typename ForwardIterator, bool>
struct _uninitialized_copy_n {
    std::pair<InputIterator, ForwardIterator> operator()(InputIterator first, size_t n, ForwardIterator out) {
        return sgl::v1::uninitialized_copy_n_(first, n, out);
    }

    std::pair<InputIterator, ForwardIterator> operator()(InputIterator first, size_t n, ForwardIterator out, const typename std::iterator_traits<InputIterator>::value_type& value) {
        return sgl::v1::uninitialized_copy_n_(first, n, out, value);
    }

    std::pair<InputIterator, ForwardIterator> operator()(InputIterator first, size_t n, ForwardIterator out, typename std::iterator_traits<InputIterator>::value_type&& value) {
        return sgl::v1::uninitialized_copy_n_(first, n, out, std::move(value));
    }
};

template<typename InputIterator, typename ForwardIterator>
inline
std::pair<InputIterator, ForwardIterator> uninitialized_copy_n(InputIterator first, size_t n, ForwardIterator out) {
    // ranges don't intersect
    typedef typename std::iterator_traits<InputIterator>::value_type T;
    return sgl::v1::_uninitialized_copy_n<InputIterator, ForwardIterator, !std::is_trivial<T>::value>()(first, n, out);
}

} // namespace v1
} // namespace sgl
