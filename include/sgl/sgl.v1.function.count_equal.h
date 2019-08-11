#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator0, typename ForwardIterator1, typename Integer>
inline
Integer count_equal(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1, Integer count) {
    while (first0 != last0) {
        if (*first0 == *first1) {
            ++count;
        }
        ++first0;
        ++first1;
    }
    return count;
}


template<typename ForwardIterator0, typename ForwardIterator1>
inline
auto count_equal(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1) {
    DifferenceType(ForwardIterator0) count{0};
    while (first0 != last0) {
        if (*first0 == *first1) {
            ++count;
        }
        ++first0;
        ++first1;
    }
    return count;
}

}
}
