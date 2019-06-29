#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename T>
inline
ForwardIterator upper_bound(ForwardIterator first, size_t n, const T& value) {
    while (n != 0ul) {
        size_t half = (n >> 1ul);
        auto middle = first;
        std::advance(middle, half);
        if (value < *middle) {
            n = half;
        } else {
            first = middle;
            ++first;
            n = n - half - 1ul;
        }
    }
    return first;
}

template<typename RandomAccessIterator, typename T>
inline
RandomAccessIterator upper_bound(RandomAccessIterator first, RandomAccessIterator last, const T& value) {
    return sgl::v1::upper_bound(first, last - first, value);
}



template<typename ForwardIterator, typename T, typename BinaryPredicate>
inline
ForwardIterator upper_bound(ForwardIterator first, size_t n, const T& value, BinaryPredicate pred) {
    while (n != 0ul) {
        size_t half = (n >> 1ul);
        auto middle = first;
        std::advance(middle, half);
        if (pred(value, *middle)) {
            n = half;
        } else {
            first = middle;
            ++first;
            n = n - half - 1ul;
        }
    }
    return first;
}

template<typename RandomAccessIterator, typename T, typename BinaryPredicate>
inline
RandomAccessIterator upper_bound(RandomAccessIterator first, RandomAccessIterator last, const T& value, BinaryPredicate pred) {
    return sgl::v1::upper_bound(first, last - first, value, pred);
}



template<typename ForwardIterator, typename T, typename BinaryPredicate, typename Projection>
inline
ForwardIterator upper_bound(ForwardIterator first, size_t n, const T& value, BinaryPredicate pred, Projection projection) {
    while (n != 0ul) {
        size_t half = (n >> 1ul);
        auto middle = first;
        std::advance(middle, half);
        if (pred(value, projection(*middle))) {
            n = half;
        } else {
            first = middle;
            ++first;
            n = n - half - 1ul;
        }
    }
    return first;
}
template<typename RandomAccessIterator, typename T, typename BinaryPredicate, typename Projection>
inline
RandomAccessIterator upper_bound(RandomAccessIterator first, RandomAccessIterator last, const T& value, BinaryPredicate pred, Projection projection) {
    return sgl::v1::upper_bound(first, last - first, value, pred, projection);
}


} // namespace v1
} // namespace sgl
