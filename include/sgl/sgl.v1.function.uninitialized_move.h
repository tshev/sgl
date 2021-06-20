#pragma once

namespace sgl {
namespace v1 {

template <class InputIterator, class ForwardIterator, bool>
struct _uninitialized_move_exceptions {
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

template <class InputIterator, class ForwardIterator>
struct _uninitialized_move_exceptions<InputIterator, ForwardIterator, false> {
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

template <class InputIterator, class ForwardIterator>
inline
ForwardIterator uninitialized_move(InputIterator first, InputIterator last, ForwardIterator output) {
    typedef typename std::decay<typename std::iterator_traits<InputIterator>::value_type>::type T;
    return sgl::v1::_uninitialized_move_exceptions<InputIterator, ForwardIterator, !sgl::v1::is_nothrow_movable<T>::value>()(first, last, output);
}



template <class InputIterator, class ForwardIterator>
ForwardIterator uninitialized_move(InputIterator first, InputIterator last, ForwardIterator output, const typename std::iterator_traits<InputIterator>::value_type& value) {
    typedef typename std::iterator_traits<InputIterator>::value_type T;
    return sgl::v1::_uninitialized_move_exceptions<InputIterator, ForwardIterator, !sgl::v1::is_nothrow_movable<T>::value>()(first, last, output, value);
}


template <class InputIterator, class ForwardIterator>
ForwardIterator uninitialized_move(InputIterator first, InputIterator last, ForwardIterator output, typename std::iterator_traits<InputIterator>::value_type&& value) {
    typedef typename std::iterator_traits<InputIterator>::value_type T;
    return sgl::v1::_uninitialized_move_exceptions<InputIterator, ForwardIterator, !sgl::v1::is_nothrow_movable<T>::value>()(first, last, output, std::move(value));
}

} // namespace v1
} // namespace sgl
