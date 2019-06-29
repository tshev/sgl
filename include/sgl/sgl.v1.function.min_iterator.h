#pragma once

namespace sgl {
namespace v1 {

template <typename T>
// requires(StrictWeakOrdering(T::operator<))
inline
T& min_iterator(T& x, T& y) {
    if (*y < *x) {
        return y;
    } else {
        return x;
    }
}

template <typename T>
// requires(StrictWeakOrdering(T::operator<))
inline
const T& min_iterator(const T& x, const T& y) {
    if (*y < *x) {
        return y;
    } else {
        return x;
    }
}

template <typename T, typename P>
// requires(StrictWeakOrdering(P, T))
inline
T& min_iterator(T& x, T& y, P p) {
    if (p(*y, *x)) {
        return y;
    } else {
        return x;
    }
}

template <typename T, typename P>
// requires(StrictWeakOrdering(P, T))
inline
const T& min_iterator(const T& x, const T& y, P p) {
    if (p(*y, *x)) {
        return y;
    } else {
        return x;
    }
}
}
}
