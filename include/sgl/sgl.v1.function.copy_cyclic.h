#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator0, typename ForwardIterator1>
// requires(ForwardIterator(ForwardIterator0) && ForwardIterator1(OutputIterator) && Integer(N))
inline
ForwardIterator0 copy_cyclic(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1, ForwardIterator1 last1) {
    ForwardIterator0 first;
    while (first1 != last1) {
        first = first0;
        while (first != last0 && first1 != last1) {
            *first1 = *first;
            ++first1;
            ++first;
        }
    }
    return first;
}

template<typename ForwardIterator0, typename OutputIterator, typename N>
// requires(ForwardIterator(ForwardIterator0) && OutputIterator(OutputIterator) && Integer(N))
inline
ForwardIterator0 copy_cyclic(ForwardIterator0 first0, ForwardIterator0 last0, OutputIterator first1, N n) {
    ForwardIterator0 first;
    while (n != 0) {
        first = first0;
        while (first != last0 && n != 0) {
            *first1 = *first;
            ++first1;
            ++first;
        }
    }
    return first;
}

}
} // namespace sgl
