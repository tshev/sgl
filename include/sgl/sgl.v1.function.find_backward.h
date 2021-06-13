#pragma once

namespace sgl {
namespace v1 {

template<typename BidirectionalIterator>
inline
BidirectionalIterator find_backward(BidirectionalIterator first, BidirectionalIterator last, const SGLValueType(BidirectionalIterator)& value) {
    if (first == last) { return last; }
    BidirectionalIterator last_fixed = last;
    --last;
    while (true) {
        if (*last == value) { return last; }
        if (first == last) { return last_fixed; }
        --last;
    }
    return last_fixed;
}


template<typename BidirectionalIterator, typename R>
inline
BidirectionalIterator find_backward(BidirectionalIterator first, BidirectionalIterator last, const SGLValueType(BidirectionalIterator)& value, R cmp) {
    if (first == last) { return last; }
    BidirectionalIterator last_fixed = last;
    --last;
    while (true) {
        if (cmp(*last, value)) { return last; }
        if (first == last) { return last_fixed; }
        --last;
    }
    return last_fixed;
}


} // namespace v1
} // namespace sgl
