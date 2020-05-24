#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator0, typename Integer>
inline
Integer count(ForwardIterator0 first0, ForwardIterator0 last0, const SGLValueType(ForwardIterator0)& value, Integer count) {
    while (first0 != last0) {
        if (*first0 == value) {
            ++count;
        }
        ++first0;
    }
    return count;
}

template<typename ForwardIterator0>
inline
auto count(ForwardIterator0 first0, ForwardIterator0 last0, const SGLValueType(ForwardIterator0)& value) {
    DifferenceType(ForwardIterator0) count{0};
    while (first0 != last0) {
        if (*first0 == value) {
            ++count;
        }
        ++first0;
    }
    return count;
}


}
}
