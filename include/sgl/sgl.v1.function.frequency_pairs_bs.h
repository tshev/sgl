#pragma once

namespace sgl {
namespace v1 {

template <typename RandomAccessIterator, typename OutputIterator>
// requires(RandomAccessIterator(RandomAccessIterator) && OutputIterator(OutputIterator)
inline
OutputIterator frequency_pairs_bs(RandomAccessIterator f, RandomAccessIterator l, OutputIterator out) {
    // precondition: $is\_sorted(f, l)$
    while (f != l) {
        RandomAccessIterator step_back = f;
        ++f;
        f = sgl::v1::upper_bound(f, l, *step_back);
        *out = {*step_back, f - step_back};
        ++out;
    }
    return out;
}

} // namespace v1
} // namespace sgl
