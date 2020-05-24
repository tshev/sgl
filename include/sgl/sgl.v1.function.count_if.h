#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator0, typename T, typename UnaryPredicate>
inline
T count_if(ForwardIterator0 first0, ForwardIterator0 last0, T count, UnaryPredicate pred) {
    while (first0 != last0) {
        if (pred(*first0)) {
            ++count;
        }
        ++first0;
    }
    return count;
}


template<typename ForwardIterator0, typename UnaryPredicate>
inline
auto count_if(ForwardIterator0 first0, ForwardIterator0 last0, UnaryPredicate pred) {
    SGLDifferenceType(ForwardIterator0) count{0};
    while (first0 != last0) {
        if (pred(*first0)) {
            ++count;
        }
        ++first0;
    }
    return count;
}


template<typename ForwardIterator0, typename ForwardIterator1, typename T, typename BinaryPredicate>
inline
T count_if(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1, T count, BinaryPredicate pred) {
    while (first0 != last0) {
        if (pred(*first0, *first1)) {
            ++count;
        }
        ++first0;
        ++first1;
    }
    return count;
}


template<typename ForwardIterator0, typename ForwardIterator1, typename ForwardIterator2, typename T, typename TernaryPredicate>
inline
T count_if(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1, ForwardIterator2 first2, T count, TernaryPredicate pred) {
    while (first0 != last0) {
        if (pred(*first0, *first1, *first2)) {
            ++count;
        }
        ++first0;
        ++first1;
        ++first2;
    }
    return count;
}


} // namespace v1
} // namespace sgl
