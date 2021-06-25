#pragma once
namespace sgl {
namespace v1 {

template<typename InputIterator, typename ForwardIterator, bool copy_throws, bool is_trivial>
struct _uninitialized_copy {
    ForwardIterator operator()(InputIterator first, InputIterator last, ForwardIterator out) const {
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

    ForwardIterator operator()(InputIterator first, InputIterator last, ForwardIterator out, const typename std::iterator_traits<InputIterator>::value_type& value) const {
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

    ForwardIterator operator()(InputIterator first, InputIterator last, ForwardIterator out, typename std::iterator_traits<InputIterator>::value_type&& value) const {
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
};


template<typename InputIterator, typename ForwardIterator, bool is_trivial>
struct _uninitialized_copy<InputIterator, ForwardIterator, /*copy_throws=*/false, is_trivial> {
    ForwardIterator operator()(InputIterator first, InputIterator last, ForwardIterator out) const noexcept {
        while (first != last) {
            sgl::v1::construct(std::addressof(*out), *first);
            ++out; ++first;
        }
        return out;
    }

    ForwardIterator operator()(InputIterator first, InputIterator last, ForwardIterator out, const typename std::iterator_traits<InputIterator>::value_type& value) const noexcept {
        while (first != last) {
            sgl::v1::construct(std::addressof(*out), *first);
            ++out; ++first;
        }
        sgl::v1::construct(std::addressof(*out), value);
        ++out;
        return out;
    }

    ForwardIterator operator()(InputIterator first, InputIterator last, ForwardIterator out, typename std::iterator_traits<InputIterator>::value_type&& value) const noexcept {
        while (first != last) {
            sgl::v1::construct(std::addressof(*out), *first);
            ++out; ++first;
        }
        sgl::v1::construct(std::addressof(*out), std::move(value));
        ++out;
        return out;
    }
};


template<typename InputIterator, typename ForwardIterator, bool copy_throws>
struct _uninitialized_copy<InputIterator, ForwardIterator, copy_throws, /*is_trivial=*/true> {
    ForwardIterator operator()(InputIterator first, InputIterator last, ForwardIterator out) const {
        return sgl::v1::copy(first, last, out);
    }

    ForwardIterator operator()(InputIterator first, InputIterator last, ForwardIterator out, const typename std::iterator_traits<InputIterator>::value_type& value) const {
        out = sgl::v1::copy(first, last, out);
        *out = value;
        return ++out;
    }

    ForwardIterator operator()(InputIterator first, InputIterator last, ForwardIterator out, typename std::iterator_traits<InputIterator>::value_type&& value) const {
        out = sgl::v1::copy(first, last, out);
        *out = std::move(value);
        return ++out;
    }
};


template<typename InputIterator, typename ForwardIterator>
inline
ForwardIterator uninitialized_copy(InputIterator first, InputIterator last, ForwardIterator out) {
    // ranges don't intersect
    typedef typename std::iterator_traits<InputIterator>::value_type T;
    return sgl::v1::_uninitialized_copy<InputIterator, ForwardIterator, sgl::v1::is_nothrow_copyable<T>::value, !std::is_trivial<T>::value>()(first, last, out);
}


template<typename InputIterator, typename ForwardIterator>
inline
ForwardIterator uninitialized_copy(InputIterator first, InputIterator last, ForwardIterator out, const typename std::iterator_traits<InputIterator>::value_type& value) {
    // ranges don't intersect
    typedef typename std::iterator_traits<InputIterator>::value_type T;
    return sgl::v1::_uninitialized_copy<InputIterator, ForwardIterator, sgl::v1::is_nothrow_copyable<T>::value, !std::is_trivial<T>::value>()(first, last, out, value);
}


template<typename InputIterator, typename ForwardIterator>
inline
ForwardIterator uninitialized_copy(InputIterator first, InputIterator last, ForwardIterator out, typename std::iterator_traits<InputIterator>::value_type&& value) {
    // ranges don't intersect
    typedef typename std::iterator_traits<InputIterator>::value_type T;
    return sgl::v1::_uninitialized_copy<InputIterator, ForwardIterator, sgl::v1::is_nothrow_copyable<T>::value, !std::is_trivial<T>::value>()(first, last, out, std::move(value));
}

} // namespace v1
} // namespace sgl
