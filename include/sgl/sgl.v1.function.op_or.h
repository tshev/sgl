#pragma once

namespace sgl {
namespace v1 {
// TODO: static linkage

template<typename T>
struct _op_or<T, 128> {
    __m128i operator()(__m128i x, __m128i y, typename std::enable_if<std::numeric_limits<T>::is_integer, bool>::type* _ = nullptr) const noexcept {
        return _mm_or_si128(x, y);
    }
};

template<>
struct _op_or<float, 128> {
    __m128 operator()(__m128 x, __m128 y) const noexcept {
        return _mm_or_ps(x, y);
    }
};

template<>
struct _op_or<double, 128> {
    __m128d operator()(__m128d x, __m128d y) const noexcept {
        return _mm_or_ps(x, y);
    }
};

template<typename T, size_t N, typename U>
inline
U op_or(U x, U y) {
    return sgl::v1::_op_or<T, N>(x, y);
}

} // namespace v1
} // namespace sgl
