#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator0, typename ForwardIterator1>
inline
ForwardIterator1 __uninitialized_move_range_value_range(ForwardIterator0 first,
                                                       ForwardIterator0 middle,
                                                       ForwardIterator0 last,
                                                       typename std::iterator_traits<ForwardIterator0>::value_type&& x,
                                                       ForwardIterator1 output) {
    typedef typename std::iterator_traits<ForwardIterator0>::value_type value_type;
    if constexpr (std::is_trivial<value_type>::value) {
        return std::copy_range_value_range(first, middle, last, x, output);
    } else {
        ForwardIterator1 current = output;
        try {
            while (first != middle) {
                ::new (static_cast<void*>(std::addressof(*current))) value_type(std::move(*first));
                ++first;
                ++current;
            }
            new (std::addressof(*current)) value_type(std::move(x));
            ++current;
            while (first != last) {
                ::new (static_cast<void*>(std::addressof(*current))) value_type(std::move(*first));
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
}

template<typename ForwardIterator0, typename ForwardIterator1>
inline
ForwardIterator1 __uninitialized_move_range_value_range(ForwardIterator0 first,
                                                       ForwardIterator0 middle,
                                                       ForwardIterator0 last,
                                                       typename std::iterator_traits<ForwardIterator0>::value_type&& x,
                                                       size_t n,
                                                       ForwardIterator1 output) {
    typedef typename std::iterator_traits<ForwardIterator0>::value_type value_type;
    if constexpr (std::is_trivial<value_type>::value) {
        return std::copy_range_value_range(first, middle, last, x, n, output);
    } else {
    ForwardIterator0 current = output;
    try {
        while (first != middle) {
            ::new (static_cast<void*>(std::addressof(*current))) value_type(std::move(*first));
            ++first;
            ++current;
        }
        // copy max(0, n - 1) times
        for (size_t i = 1; i < n; ++i) {
            new (std::addressof(*current)) value_type(x);
            ++current;
        }
        // move value
        if (0 < n) {
            new (std::addressof(*current)) value_type(std::move(x));
            ++current;
        }
        while (first != last) {
            ::new (static_cast<void*>(std::addressof(*current))) value_type(std::move(*first));
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

template <typename ForwardIterator0, typename ForwardIterator1>
// requires(pointer(ForwardIterator) && ValueType(ForwardIterator) == T)
inline
ForwardIterator1 __uninitialized_move_range_value_range__nothrow_move_assignable__(ForwardIterator0 first,
                                                                                  ForwardIterator0 middle,
                                                                                  ForwardIterator0 last,
                                                                                  typename std::iterator_traits<ForwardIterator0>::value_type&& x,
                                                                                  ForwardIterator1 output) {

    typedef typename std::iterator_traits<ForwardIterator0>::value_type value_type;
    while (first != middle) {
        ::new (static_cast<void*>(std::addressof(*output))) value_type(std::move(*first));
        ++first;
        ++output;
    }

    new (std::addressof(*output)) value_type(std::move(x));
    ++output;

    while (first != last) {
        ::new (static_cast<void*>(std::addressof(*output))) value_type(std::move(*first));
        ++first;
        ++output;
    }
    return output;
}

template<typename ForwardIterator>
// requires(pointer(ForwardIterator) && ValueType(ForwardIterator) == T) 
inline
ForwardIterator __uninitialized_move_range_value_range__nothrow_move_assignable__(ForwardIterator first,
                                                       ForwardIterator middle,
                                                       ForwardIterator last,
                                                       typename std::iterator_traits<ForwardIterator>::value_type&& x,
                                                       size_t n,
                                                       ForwardIterator output) {
    typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;
    while (first != middle) {
        ::new (static_cast<void*>(std::addressof(*output))) value_type(std::move(*first));
        ++first;
        ++output;
    }

    for (size_t i = 1; i < n; ++i) {
        new (std::addressof(*output)) value_type(std::move(x));
        ++output;
    }

    if (n >= 1) {
        new (std::addressof(*output)) value_type(std::move(x));
        ++output;
    }

    while (first != last) {
        ::new (static_cast<void*>(std::addressof(*output))) value_type(std::move(*first));
        ++first;
        ++output;
    }
    return output;
}


template<typename ForwardIterator>
ForwardIterator __uninitialized_move_range_value_range__trivial__(ForwardIterator first,
                                                       ForwardIterator middle,
                                                       ForwardIterator last,
                                                       typename std::iterator_traits<ForwardIterator>::value_type&& x, ForwardIterator output) {
    typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;
    static_assert(std::is_trivial<value_type>::value, "Should be trivial");
    static_assert(std::is_nothrow_move_assignable<value_type>::value, "Trivial types a can't throw");
    output = std::move(first, middle, output);
    new (std::addressof(*output)) value_type(std::move(x));
    ++output;
    return std::move(middle, last, output);
}


template<typename ForwardIterator>
ForwardIterator uninitialized_move_range_value_range(ForwardIterator first,
                                                     ForwardIterator middle,
                                                     ForwardIterator last,
                                                     typename std::iterator_traits<ForwardIterator>::value_type&& x, ForwardIterator output) {
    typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;
    if constexpr (std::is_trivial<value_type>::value) {
        return __uninitialized_move_range_value_range__trivial__(first, middle, last, std::move(x), output);
    } else if constexpr (std::is_nothrow_move_assignable<value_type>::value) {
        return __uninitialized_move_range_value_range__nothrow_move_assignable__(first, middle, last, std::move(x), output);
    }
    return __uninitialized_move_range_value_range(first, middle, last, std::move(x), output);
}

template<typename ForwardIterator>
inline
ForwardIterator uninitialized_move_range_value_range(ForwardIterator first,
                                                     ForwardIterator middle,
                                                     ForwardIterator last,
                                                     const typename std::iterator_traits<ForwardIterator>::value_type& x, ForwardIterator output) {
    typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;
    if (std::is_trivial<value_type>::value) {
        return uninitialized_move_range_value_range(first, middle, last, x, output);
    } else {
        ForwardIterator current = output;
        try {
            while (first != middle) {
                ::new (static_cast<void *>(std::addressof(*current))) value_type(std::move(*first));
                ++first;
                ++current;
            }

            new (std::addressof(*current)) value_type(x);
            ++current;

            while (first != last) {
                ::new (static_cast<void *>(std::addressof(*current))) value_type(std::move(*first));
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
}

template<typename ForwardIterator>
inline
ForwardIterator uninitialized_move_range_value_range(ForwardIterator first,
                                                     ForwardIterator middle,
                                                     ForwardIterator last,
                                                     const typename std::iterator_traits<ForwardIterator>::value_type& x,
                                                     size_t n,
                                                     ForwardIterator output) {
    typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;
    if (std::is_trivial<value_type>::value) {
        return uninitialized_move_range_value_range(first, middle, last, x, n, output);
    } else {
        ForwardIterator current = output;
        try {
            while (first != middle) {
                ::new (static_cast<void *>(std::addressof(*current))) value_type(std::move(*first));
                ++first;
                ++current;
            }

            for (size_t i = 0; i != n; ++i) {
                new (std::addressof(*current)) value_type(x);
                ++current;
            }

            while (first != last) {
                ::new (static_cast<void *>(std::addressof(*current))) value_type(std::move(*first));
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
}

} // namespace v1
} // namespace sgl
