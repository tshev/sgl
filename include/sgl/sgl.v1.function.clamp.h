#pragma once

namespace sgl {
namespace v1 {
template<typename T, typename Less>
inline
constexpr
const T& clamp(const T& x, const T& left, const T& right, Less less) {
    if (less(x, left)) {
        return left;
    }

    if (less(right, x)) {
        return right;
    }

    return x;
}

template<typename T, typename Less>
inline
constexpr
T& clamp(T& x, T& left, T& right, Less less) {
    if (less(x, left)) {
        return left;
    }

    if (less(right, x)) {
        return right;
    }

    return x;
}

template<typename T>
inline
constexpr
const T& clamp(const T& x, const T& left, const T& right) {
    if (x < left) {
        return left;
    }

    if (right < x) {
        return right;
    }

    return x;
}

template<typename T>
inline
constexpr
T& clamp(T& x, T& left, T& right) {
    if (x < left) {
        return left;
    }

    if (right < x) {
        return right;
    }

    return x;
}

/*
template<typename T0, typename T1, typename Cmp, typename Projection>
const T1& clamp(const T0& x, const T1& left, const T1& right, Cmp cmp, Projection projection) {
    if (cmp(projection(x), left)) {
        return left;
    }

    if (cmp(right, projection(x))) {
        return right;
    }

    return projection(x);
}
*/
} // namespace v1
}  // namespace sgl
