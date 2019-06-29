#pragma once

namespace sgl {
namespace v1 {


template<typename ForwardIterator0, typename ForwardIterator1>
inline
std::pair<ForwardIterator0, ForwardIterator1> copy_bounded(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1, ForwardIterator1 last1) {
    while (first0 != last0 && first1 != last1) {
        *first1 = *first0;
        ++first1;
        ++first0;
    }
    return {first0, first1};
}


template<typename ForwardIterator0, typename OutputIterator, typename N>
inline
sgl::v1::triple<ForwardIterator0, OutputIterator, N> copy_bounded(ForwardIterator0 first0, ForwardIterator0 last0, OutputIterator out, N n) {
    constexpr N z(0);
    while (first0 != last0 && z < n) {
        --n;
        *out = *first0;
        ++out;
        ++first0;
    }
    return {first0, out, n};
}


} // namespace v1
} // namespace sgl
