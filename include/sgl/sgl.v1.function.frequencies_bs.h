#pragma once

namespace sgl {
namespace v1 {

template <typename RandomAccessIterator0, typename RandomAccessIterator, typename OutputIterator, typename Predicate>
OutputIterator frequencies_bs(RandomAccessIterator0 f0, RandomAccessIterator0 l0, RandomAccessIterator f1,
                              RandomAccessIterator l1, OutputIterator out, Predicate predicate) {
    while (f1 != l1) {
        auto it = std::upper_bound(f0 + 1, l0, *f1, predicate);
        *out = it - f0;
        f0 = it;
        ++f1;
        ++out;
    }
    return out;
}


template <typename ForwardIterator0, typename ForwardIterator1, typename OutputIterator>
inline
OutputIterator frequencies_bs(ForwardIterator0 f0, ForwardIterator0 l0, ForwardIterator1 f1, ForwardIterator1 l1,
                              OutputIterator out) {
    return frequencies_bs(f0, l0, f1, l1, out, std::less<ValueType(ForwardIterator0)>{});
}

} // namespace v1
} // namespace sgl
