#pragma once
// I have my doubts: whether I should copy iterators or values
// Copy of an iterator looks useless

namespace sgl {
namespace v1 {
template<typename ForwardIterator, typename OutputIterator0, typename OutputIterator1, typename UnaryPredicate>
inline
std::pair<OutputIterator0, OutputIterator1> partition_copy_position(ForwardIterator first, ForwardIterator last, OutputIterator0 out0, OutputIterator1 out1, UnaryPredicate pred) {
    while (first != last) {
        if (pred(first)) {
            *out1 = *first;
            ++out1;
        } else {
            *out0 = *first;
            ++out0;
        }
        ++first;
    }
    return {out0, out1};
}
} // namespace v1
} // namespace sgl
