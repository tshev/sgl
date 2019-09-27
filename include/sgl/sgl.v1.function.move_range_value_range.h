#pragma once

namespace sgl {
namespace v1 {

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

}  // namespace v1
}  // namespace sgl
