#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename T>
inline
ForwardIterator lower_bound(ForwardIterator first, size_t n, const T& value) {
    while (n != 0ul) {
        size_t half = (n >> 1ul);
        auto middle = first;
        std::advance(middle, half);
        if (*middle < value) {
            first = middle;
            ++first;
            n = n - half - 1;
        } else {
            n = half;
        }
    }
    return first;
}


template<typename RandomAccessIterator, typename T>
inline
RandomAccessIterator lower_bound(RandomAccessIterator f, RandomAccessIterator l, const T& x) {
    return sgl::v1::lower_bound(f, l - f, x); 
}

template<typename ForwardIterator, typename T, typename BinaryPredicate>
inline
ForwardIterator lower_bound(ForwardIterator first, size_t n, const T& value, BinaryPredicate pred) {
    while (n != 0ul) {
        size_t half = (n >> 1ul);
        auto middle = first;
        std::advance(middle, half);
        if (pred(*middle, value)) {
            first = middle;
            ++first;
            n = n - half - 1;
        } else {
            n = half;
        }
    }
    return first;
}

template<typename ForwardIterator, typename T, typename BinaryPredicate, typename Projection>
inline
ForwardIterator lower_bound(ForwardIterator first, size_t n, const T& value, BinaryPredicate pred, Projection proj) {
    while (n != 0ul) {
        size_t half = (n >> 1ul);
        auto middle = first;
        std::advance(middle, half);
        if (pred(proj(*middle), value)) {
            first = middle;
            ++first;
            n = n - half - 1;
        } else {
            n = half;
        }
    }
    return first;
}

template<typename ForwardIterator, typename T, typename BinaryPredicate, typename Projection>
inline
ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, const T& value, BinaryPredicate pred, Projection proj) {
    return sgl::v1::lower_bound(first, std::distance(first, last), value, pred, proj);
}


} // namespace v1
} // namespace sgl
