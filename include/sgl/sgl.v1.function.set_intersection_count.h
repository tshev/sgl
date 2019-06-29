#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator0, typename ForwardIterator1, typename T>
// requires(WeakStrictOrdering(std::less<T>))
T set_intersection_count(ForwardIterator0 f0, ForwardIterator0 l0, ForwardIterator1 f1, ForwardIterator1 l1, T count) {
    while (f0 != l0 && f1 != l1) {
        if (*f0 < *f1) {
            ++f0;
        } else if (*f1 < *f0) {
            ++f1;
        } else {
            ++count;
            ++f0;
            ++f1;
        }
    }
    return count;
}


template<typename ForwardIterator0, typename ForwardIterator1, typename T, typename BinaryPredicate>
// requires(WeakStrictOrdering(BinaryPredicate))
T set_intersection_count(ForwardIterator0 f0, ForwardIterator0 l0, ForwardIterator1 f1, ForwardIterator1 l1, T count, BinaryPredicate pred) {
    while (f0 != l0 && f1 != l1) {
        if (pred(*f0, *f1)) {
            ++f0;
        } else if (pred(*f1, *f0)) {
            ++f1;
        } else {
            ++count;
            ++f0;
            ++f1;
        }
    }
    return count;
}


template<typename ForwardIterator0, typename ForwardIterator1, typename T, typename BinaryPredicate0, typename BinaryPredicate1>
// requires(TotalyOrdered(std::less<T>))
T set_intersection_count(ForwardIterator0 f0, ForwardIterator0 l0, ForwardIterator1 f1, ForwardIterator1 l1, T count, BinaryPredicate0 pred, BinaryPredicate1 eq) {
    while (f0 != l0 && f1 != l1) {
        if (pred(*f0, *f1)) {
            ++f0;
        } else { 
            if (eq(*f1, *f0)) {
                ++count;
                ++f0;
            }
            ++f1;
        }
    }
    return count;
}

} // namespace v1
} // namespace sgl
