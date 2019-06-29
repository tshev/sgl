#pragma once

namespace sgl {
namespace v1 {

template<typename BidirectionalIterator, typename T>
inline
BidirectionalIterator find_not_backward(BidirectionalIterator first, BidirectionalIterator last, const T& x) {
    if (first == last) {
        return last;
    }
    BidirectionalIterator last_fixed = last;
    --last;
    while (true) {
        if (!(*last == x)) {
            return last;
        }
        if (first == last) {
            return last_fixed;
        }
        --last;
    }
    return last_fixed;
}


template<typename BidirectionalIterator, typename T, typename Equality>
inline
BidirectionalIterator find_not_backward(BidirectionalIterator first, BidirectionalIterator last, const T& x, Equality eq) {
    if (first == last) {
        return last;
    }
    BidirectionalIterator last_fixed = last;
    --last;
    while (true) {
        if (!eq(*last, x)) {
            return last;
        }
        if (first == last) {
            return last_fixed;
        }
        --last;
    }
    return last_fixed;
}


} // namespace v1
} // namespace sgl
