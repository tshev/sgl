#pragma once
namespace sgl {
namespace v1 {

template<typename T, size_t N, sgl::v1::simd_mode mode>
struct _load;

#ifdef __SSE2__
// # integers
// ## 128
template<typename T>
struct _load<T, 128, sgl::v1::simd_mode::unaligned> {
    __m128i operator()(typename std::enable_if<std::numeric_limits<T>::is_integer, T>::type const* mem) const noexcept {
        return _mm_loadu_si128((__m128i const*)mem);
    }
};
#endif

#ifdef __SSE__
// # float
template<>
struct _load<float, 128, sgl::v1::simd_mode::unaligned> {
    __m128 operator()(float const* mem) const noexcept {
        return _mm_loadu_ps(mem);
    }
};
#endif

#ifdef __SSE2__
// # double
template<>
struct _load<double, 128, sgl::v1::simd_mode::unaligned> {
    __m128d operator()(double const* mem) const noexcept {
        return _mm_loadu_pd(mem);
    }
};
#endif

// ## 256
#ifdef __AVX__
template<typename T>
struct _load<T, 256, sgl::v1::simd_mode::unaligned> {
    __m256i operator()(typename std::enable_if<std::numeric_limits<T>::is_integer, T>::type const* mem) const noexcept {
        return _mm256_loadu_si256((__m256i const*)mem);
    }
};

template<>
struct _load<float, 256, sgl::v1::simd_mode::unaligned> {
    __m256 operator()(float const* mem) const noexcept {
        return _mm256_loadu_ps(mem);
    }
};

template<>
struct _load<double, 256, sgl::v1::simd_mode::unaligned> {
    __m256d operator()(double const* mem) const noexcept {
        return _mm256_loadu_pd(mem);
    }
};
#endif

// ## 512
#ifdef __AVX512F__
template<typename T>
struct _load<T, 512, sgl::v1::simd_mode::unaligned> {
    __m512i operator()(typename std::enable_if<std::numeric_limits<T>::is_integer, T>::type const* mem) const noexcept {
        return _mm512_loadu_si512((__m512i const*)mem);
    }
};

template<>
struct _load<float, 512, sgl::v1::simd_mode::unaligned> {
    __m512 operator()(float const* mem) const noexcept {
        return _mm512_loadu_ps(mem);
    }
};

template<>
struct _load<double, 512, sgl::v1::simd_mode::unaligned> {
    __m512d operator()(double const* mem) const noexcept {
        return _mm512_loadu_pd(mem);
    }
};
#endif

template<typename T>
struct _load<T, 128, sgl::v1::simd_mode::aligned> {
    __m128i operator()(typename std::enable_if<std::numeric_limits<T>::is_integer, T>::type const* mem) const noexcept {
        return _mm_load_si128((__m128i const*)mem);
    }
};

template<>
struct _load<float, 128, sgl::v1::simd_mode::aligned> {
    __m128 operator()(float const* mem) const noexcept {
        return _mm_load_ps(mem);
    }
};

// # double
template<>
struct _load<double, 128, sgl::v1::simd_mode::aligned> {
    __m128d operator()(double const* mem) const noexcept {
        return _mm_load_pd(mem);
    }
};

#ifdef __AVX__
template<typename T>
struct _load<T, 256, sgl::v1::simd_mode::aligned> {
    __m256i operator()(typename std::enable_if<std::numeric_limits<T>::is_integer, T>::type const* mem) const noexcept {
        return _mm256_load_si256((__m256i const*)mem);
    }
};

template<>
struct _load<float, 256, sgl::v1::simd_mode::aligned> {
    __m256 operator()(float const* mem) const noexcept {
        return _mm256_load_ps(mem);
    }
};

template<>
struct _load<double, 256, sgl::v1::simd_mode::aligned> {
    __m256d operator()(double const* mem) const noexcept {
        return _mm256_load_pd(mem);
    }
};
#endif

#ifdef __AVX512F__
template<typename T>
struct _load<T, 512, sgl::v1::simd_mode::aligned> {
    __m512i operator()(typename std::enable_if<std::numeric_limits<T>::is_integer, T>::type const* mem) const noexcept {
        return _mm512_load_si512((__m512i const*)mem);
    }
};

template<>
struct _load<double, 512, sgl::v1::simd_mode::aligned> {
    __m512 operator()(double const* mem) const noexcept {
        return _mm512_load_ps(mem);
    }
};

template<>
struct _load<double, 512, sgl::v1::simd_mode::aligned> {
    __m512d operator()(double const* mem) const noexcept {
        return _mm512_load_pd(mem);
    }
};
#endif

template<size_t N = 128, sgl::v1::simd_mode mode = sgl::v1::simd_mode::unaligned, typename T>
inline
auto load(T const* mem) {
    return _load<T, N, mode>()(mem);
}

} // namespace v1
} // namespace sgl
