#pragma once

namespace sgl {
namespace v1 {

template <typename InputIterator, typename ForwardIterator, bool exceptions, bool is_trivial>
struct _uninitialized_move {
    ForwardIterator operator()(InputIterator first, InputIterator last, ForwardIterator output) const {
        typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;
        ForwardIterator current = output;
        try {
            while (first != last) {
                sgl::v1::construct(std::addressof(*current), std::move(*first));
                ++first;
                ++current;
            }
            return current;
        } catch (...) {
            while (output != current) {
                output->~value_type();
                ++output;
            }
            throw;
        }
    }


    ForwardIterator operator()(InputIterator first, InputIterator last, ForwardIterator output, const typename std::iterator_traits<InputIterator>::value_type& value) const {
        //typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;
        ForwardIterator current = output;
        try {
            while (first != last) {
                sgl::v1::construct(std::addressof(*current), std::move(*first));
                ++first;
                ++current;
            }
            sgl::v1::construct(std::addressof(*current), value);
            ++current;
            return current;
        } catch (...) {
            while (output != current) {
                output->~value_type();
                ++output;
            }
            throw;
        }
    }


    ForwardIterator operator()(InputIterator first, InputIterator last, ForwardIterator output, typename std::iterator_traits<InputIterator>::value_type&& value) const {
        typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;
        ForwardIterator current = output;
        try {
            while (first != last) {
                sgl::v1::construct(std::addressof(*current), std::move(*first));
                ++first;
                ++current;
            }
            sgl::v1::construct(std::addressof(*current), std::move(value));
            ++current;
            return current;
        } catch (...) {
            while (output != current) {
                output->~value_type();
                ++output;
            }
            throw;
        }
    }

};
template <typename InputIterator, typename ForwardIterator, bool exceptions>
struct _uninitialized_move<InputIterator, ForwardIterator, exceptions, /*is_trivial=*/true> {
    static_assert(!exceptions, "Trivial type is noexcept copyable");

    ForwardIterator operator()(InputIterator first, InputIterator last, ForwardIterator output) const noexcept {
        return sgl::v1::copy(first, last, output);
    }


    ForwardIterator operator()(InputIterator first, InputIterator last, ForwardIterator output, const typename std::iterator_traits<InputIterator>::value_type& value) const noexcept {
        return sgl::v1::uninitialized_copy(first, last, output, value); 
    }

    ForwardIterator operator()(InputIterator first, InputIterator last, ForwardIterator output, typename std::iterator_traits<InputIterator>::value_type&& value) const noexcept {
        return sgl::v1::uninitialized_copy(first, last, output, std::move(value)); 
    }
};


template <typename InputIterator, typename ForwardIterator>
struct _uninitialized_move<InputIterator, ForwardIterator, /*exceptions=*/false, /*is_trivial=*/false> {
    ForwardIterator operator()(InputIterator first, InputIterator last, ForwardIterator output) const {
        //typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;
        while (first != last) {
            sgl::v1::construct(std::addressof(*output), std::move(*first));
            ++first;
            ++output;
        }
        return output;
    }

    ForwardIterator operator()(InputIterator first, InputIterator last, ForwardIterator output, const typename std::iterator_traits<InputIterator>::value_type& value) const {
        //typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;
        while (first != last) {
            sgl::v1::construct(std::addressof(*output), std::move(*first));
            ++first;
            ++output;
        }
        sgl::v1::construct(std::addressof(*output), value);
        ++output;
        return output;
    }

    ForwardIterator operator()(InputIterator first, InputIterator last, ForwardIterator output, typename std::iterator_traits<InputIterator>::value_type&& value) const {
        //typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;
        while (first != last) {
            sgl::v1::construct(std::addressof(*output), std::move(*first));
            ++first;
            ++output;
        }
        sgl::v1::construct(std::addressof(*output), std::move(value));
        ++output;
        return output;
    }
};

template <typename InputIterator, typename ForwardIterator>
inline
ForwardIterator uninitialized_move(InputIterator first, InputIterator last, ForwardIterator output) {
    typedef typename std::decay<typename std::iterator_traits<InputIterator>::value_type>::type T;
    return sgl::v1::_uninitialized_move<InputIterator, ForwardIterator, !sgl::v1::is_nothrow_movable<T>::value, sgl::v1::is_trivial<T>::value>()(first, last, output);
}


template <typename InputIterator, typename ForwardIterator>
ForwardIterator uninitialized_move(InputIterator first, InputIterator last, ForwardIterator output, const typename std::iterator_traits<InputIterator>::value_type& value) {
    typedef typename std::iterator_traits<InputIterator>::value_type T;
    return sgl::v1::_uninitialized_move<InputIterator, ForwardIterator, !sgl::v1::is_nothrow_movable<T>::value, sgl::v1::is_trivial<T>::value>()(first, last, output, value);
}


template <typename InputIterator, typename ForwardIterator>
ForwardIterator uninitialized_move(InputIterator first, InputIterator last, ForwardIterator output, typename std::iterator_traits<InputIterator>::value_type&& value) {
    typedef typename std::iterator_traits<InputIterator>::value_type T;
    return sgl::v1::_uninitialized_move<InputIterator, ForwardIterator, !sgl::v1::is_nothrow_movable<T>::value, sgl::v1::is_trivial<T>::value>()(first, last, output, std::move(value));
}

} // namespace v1
} // namespace sgl
