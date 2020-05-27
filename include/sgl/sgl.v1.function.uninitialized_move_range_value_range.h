#pragma once

namespace sgl {
namespace v1 {

template <typename It10, typename It11>
requires(sgl::v1::input_iterator(It0) && sgl::v1::forward_iterator(It1))
inline It11
__uninitialized_move_range_value_range(It10 first, It10 middle, It10 last,
                                       typename std::iterator_traits<It10>::value_type&& x,
                                       It11 output) {
    typedef typename std::iterator_traits<It10>::value_type value_type;
    if constexpr (std::is_trivial<value_type>::value) {
        return sgl::v1::copy_range_value_range(first, middle, last, x, output);
    } else {
        It11 current = output;
        try {
            while (first != middle) {
                ::new (static_cast<void*>(std::addressof(*current))) value_type(std::move(*first));
                ++first;
                ++current;
            }
        } catch (...) {
            sgl::v1::destruct(output, current);
            throw;
        }
        auto position_x = current;
        ++current;
        auto output1 = current;
        try {
            while (first != last) {
                ::new (static_cast<void*>(std::addressof(*current))) value_type(std::move(*first));
                ++first;
                ++current;
            }
            ::new (static_cast<void*>(std::addressof(*position_x))) value_type(std::move(x));
        } catch (...) {
            sgl::v1::destruct(output, position_x);
            sgl::v1::destruct(output1, current);
            throw;
        }
        return current;

    }
}

template <typename It10, typename It11>
requires(sgl::v1::input_iterator(It0) && sgl::v1::forward_iterator(It1))
inline It11
__uninitialized_move_range_value_range(It10 first, It10 middle, It10 last,
                                       typename std::iterator_traits<It10>::value_type&& x, size_t n,
                                       It11 output) {
    typedef typename std::iterator_traits<It10>::value_type value_type;
    if constexpr (std::is_trivial<value_type>::value) {
        return sgl::v1::copy_range_value_range(first, middle, last, x, n, output);
    } else {
        It10 current = output;
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
}

template <typename It10, typename It11>
// requires(pointer(It1) && SGLValueType(It1) == T)
inline
It11 __uninitialized_move_range_value_range__nothrow_move_assignable__(It10 first, It10 middle, It10 last, SGLValueType(It10)&& value, It11 output) {

    typedef typename std::iterator_traits<It10>::value_type value_type;
    while (first != middle) {
        ::new (static_cast<void*>(std::addressof(*output))) value_type(std::move(*first));
        ++first;
        ++output;
    }

    new (std::addressof(*output)) value_type(std::move(value));
    ++output;

    while (first != last) {
        ::new (static_cast<void*>(std::addressof(*output))) value_type(std::move(*first));
        ++first;
        ++output;
    }
    return output;
}

template <typename It1>
// requires(pointer(It1) && SGLValueType(It1) == T)
inline
It1 __uninitialized_move_range_value_range__nothrow_move_assignable__( It1 first, It1 middle, It1 last, SGLValueType(It1)&& x, size_t n, It1 output) {
    typedef typename std::iterator_traits<It1>::value_type value_type;
    while (first != middle) {
        ::new (static_cast<void*>(std::addressof(*output))) value_type(std::move(*first));
        ++first;
        ++output;
    }

    if (n != 0) {
        output = sgl::v1::uninitialized_fill_n(output, n - 1, x);
        new (std::addressof(*output)) value_type(std::move(x));
    }

    while (first != last) {
        ::new (static_cast<void*>(std::addressof(*output))) value_type(std::move(*first));
        ++first;
        ++output;
    }
    return output;
}

template <typename It1>
It1
__uninitialized_move_range_value_range__trivial__(It1 first, It1 middle, It1 last,
                                                  typename std::iterator_traits<It1>::value_type&& x,
                                                  It1 output) {
    typedef typename std::iterator_traits<It1>::value_type value_type;
    static_assert(std::is_trivial<value_type>::value, "Should be trivial");
    static_assert(std::is_nothrow_move_assignable<value_type>::value, "Trivial types a can't throw");
    output = std::move(first, middle, output);
    new (std::addressof(*output)) value_type(std::move(x));
    ++output;
    return std::move(middle, last, output);
}

template <typename It1>
It1 uninitialized_move_range_value_range(It1 first, It1 middle, It1 last,
                                                     typename std::iterator_traits<It1>::value_type&& x,
                                                     It1 output) {
    typedef typename std::iterator_traits<It1>::value_type value_type;
    if constexpr (std::is_trivial<value_type>::value) {
        return __uninitialized_move_range_value_range__trivial__(first, middle, last, std::move(x), output);
    } else if constexpr (std::is_nothrow_move_assignable<value_type>::value) {
        return __uninitialized_move_range_value_range__nothrow_move_assignable__(first, middle, last, std::move(x),
                                                                                 output);
    }
    return __uninitialized_move_range_value_range(first, middle, last, std::move(x), output);
}

template <typename It1>
requires(sgl::v1::forward_iterator(It1))
inline
It1 uninitialized_move_range_value_range(It1 first, It1 middle, It1 last, const SGLValueType(It1)& value, It1 output) {
    typedef typename std::iterator_traits<It1>::value_type value_type;
    if constexpr (std::is_trivial<value_type>::value) {
        return sgl::v1::move_range_value_range(first, middle, last, value, output);
    } else {
        It1 current = output;
        try {
            while (first != middle) {
                ::new (static_cast<void*>(std::addressof(*current))) value_type(std::move(*first));
                ++first;
                ++current;
            }

            new (std::addressof(*current)) value_type(value);
            ++current;

            while (first != last) {
                ::new (static_cast<void*>(std::addressof(*current))) value_type(std::move(*first));
                ++first;
                ++current;
            }
            return current;
        } catch (...) {
            sgl::v1::destruct(output, current);
            throw;
        }
    }
}

template <typename It0, typename It1>
requires(sgl::v1::input_iterator(It0) && sgl::v1::forward_iterator(It1))
inline
It1 uninitialized_move_range_value_range(It0 first, It0 middle, It0 last, const SGLValueType(It1)& x, size_t n, It1 output) {
    typedef typename std::iterator_traits<It1>::value_type value_type;
    if (std::is_trivial<value_type>::value) {
        return sgl::v1::move_range_value_range(first, middle, last, x, n, output);
    } else {
        It1 current = output;
        try {
            while (first != middle) {
                ::new (static_cast<void*>(std::addressof(*current))) value_type(std::move(*first));
                ++first;
                ++current;
            }

            if constexpr (std::is_base_of<std::random_access_iterator_tag, It1>::value) {
                for (It1 current_last = current + n; current != current_last; ++current) {
                    new (std::addressof(*current)) value_type(x);
                }
            } else {
                while (n-- > 0) {
                    new (std::addressof(*current)) value_type(x);
                    ++current;
                }
            }

            while (first != last) {
                ::new (static_cast<void*>(std::addressof(*current))) value_type(std::move(*first));
                ++first;
                ++current;
            }
            return current;
        } catch (...) {
            sgl::v1::destruct(output, current);
            throw;
        }
    }
} // uninitialized_move_range_value_range

} // namespace v1
} // namespace sgl
