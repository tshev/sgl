#pragma once

namespace sgl {
namespace v1 {


template<typename ForwardIterator0, typename ForwardIterator1>
ForwardIterator0 uninitialized_copy_range_value_range(ForwardIterator0 first, ForwardIterator0 middle, ForwardIterator0 last, const typename std::iterator_traits<ForwardIterator1>::value_type& x, ForwardIterator1 output) {
    // typedef typename std::iterator_traits<ForwardIterator0>::value_type value_type;
    ForwardIterator1 current = output;
    try {
        while (first != middle) {
            sgl::v1::uninitialized_construct(*current, *first);
            ++first;
            ++current;
        }
        sgl::v1::uninitialized_construct(*current, x);
        ++current;
        while (first != last) {
            sgl::v1::uninitialized_construct(*current, *first);
            ++first;
            ++current;
        }
        return current;
    } catch (...) {
        sgl::v1::destruct(output, current);
        throw;
    }
}


template<typename ForwardIterator0, typename ForwardIterator1>
ForwardIterator0 uninitialized_copy_range_value_range(ForwardIterator0 first, ForwardIterator0 middle, ForwardIterator0 last, const typename std::iterator_traits<ForwardIterator1>::value_type& x, size_t n, ForwardIterator1 output) {
    // typedef typename std::iterator_traits<ForwardIterator0>::value_type value_type;
    ForwardIterator1 current = output;
    try {
        while (first != middle) {
            sgl::v1::uninitialized_construct(*current, *first);
            ++first;
            ++current;
        }
        for (size_t i = 0; i != n; ++i) {
            sgl::v1::uninitialized_construct(*current, x);
            ++current;
        }
        while (first != last) {
            sgl::v1::uninitialized_construct(*current, *first);
            ++first;
            ++current;
        }
        return current;
    } catch (...) {
        sgl::v1::destruct(output, current);
        throw;
    }
}
} // namespace v1
} // namespace sgl
