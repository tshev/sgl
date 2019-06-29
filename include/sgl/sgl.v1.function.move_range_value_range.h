#pragma once

namespace sgl {
namespace v1 {

template <typename ForwardIterator>
inline
ForwardIterator move_range_value_range(ForwardIterator first, ForwardIterator middle, ForwardIterator last,
                                       const typename std::iterator_traits<ForwardIterator>::value_type& value, size_t n,
                                       ForwardIterator output) {
    typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;
    output = std::move(first, middle, output);
    output = sgl::v1::fill_n(output, n, value);
    return std::move(middle, last, output);
}

template<typename ForwardIterator>
inline
ForwardIterator move_range_value_range(ForwardIterator first,
                                       ForwardIterator middle,
                                       ForwardIterator last,
                                       typename std::iterator_traits<ForwardIterator>::value_type&& value,
                                       ForwardIterator output) {
    output = std::move(first, middle, output);
    *output = std::move(value);
    ++output;
    return std::move(middle, last, output);
}

template<typename ForwardIterator>
inline
ForwardIterator move_range_value_range(ForwardIterator first,
                                       ForwardIterator middle,
                                       ForwardIterator last,
                                       const typename std::iterator_traits<ForwardIterator>::value_type& value,
                                       ForwardIterator output) {
    output = std::move(first, middle, output);
    *output = value;
    ++output;
    return std::move(middle, last, output);
}
