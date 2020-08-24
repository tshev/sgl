#pragma once
namespace sgl {
namespace v1 {

template<typename T, sgl::v1::simd_mode mode, size_t N>
struct _load;

// # integers
// ## 128
template<typename T>
struct _load<T, sgl::v1::simd_mode::unaligned, 128> {
    __m128i operator()(typename std::enable_if<std::numeric_limits<T>::is_integer, T>::type const* mem) const noexcept {
        return _mm_loadu_si128((__m128i const*)mem);
    }
};

// # float
template<>
struct _load<float, sgl::v1::simd_mode::unaligned, 128> {
    __m128 operator()(float const* mem) const noexcept {
        return _mm_loadu_ps(mem);
    }
};


// # double
template<>
struct _load<double, sgl::v1::simd_mode::unaligned, 128> {
    __m128d operator()(double const* mem) const noexcept {
        return _mm_loadu_pd(mem);
    }
};

// ## 256
#ifdef __AVX__
template<typename T>
struct _load<T, sgl::v1::simd_mode::unaligned, 256> {
    __m256i operator()(typename std::enable_if<std::numeric_limits<T>::is_integer, T>::type const* mem) const noexcept {
        return _mm256_loadu_si256((__m256i const*)mem);
    }
};

template<>
struct _load<float, sgl::v1::simd_mode::unaligned, 256> {
    __m256 operator()(float const* mem) const noexcept {
        return _mm256_loadu_ps(mem);
    }
};

template<>
struct _load<double, sgl::v1::simd_mode::unaligned, 256> {
    __m256d operator()(double const* mem) const noexcept {
        return _mm256_loadu_pd(mem);
    }
};
#endif


// ## 512
#ifdef __AVX512F__
template<typename T>
struct _load<T, sgl::v1::simd_mode::unaligned, 512> {
    __m512i operator()(typename std::enable_if<std::numeric_limits<T>::is_integer, T>::type const* mem) const noexcept {
        return _mm512_loadu_si512((__m512i const*)mem);
    }
};

template<>
struct _load<float, sgl::v1::simd_mode::unaligned, 512> {
    __m512 operator()(float const* mem) const noexcept {
        return _mm512_loadu_ps(mem);
    }
};

template<>
struct _load<double, sgl::v1::simd_mode::unaligned, 512> {
    __m512d operator()(double const* mem) const noexcept {
        return _mm512_loadu_pd(mem);
    }
};
#endif

template<typename T>
struct _load<T, sgl::v1::simd_mode::aligned, 128> {
    __m128i operator()(typename std::enable_if<std::numeric_limits<T>::is_integer, T>::type const* mem) const noexcept {
        return _mm_load_si128((__m128i const*)mem);
    }
};

template<>
struct _load<float, sgl::v1::simd_mode::aligned, 128> {
    __m128 operator()(float const* mem) const noexcept {
        return _mm_load_ps(mem);
    }
};

// # double
template<>
struct _load<double, sgl::v1::simd_mode::aligned, 128> {
    __m128d operator()(double const* mem) const noexcept {
        return _mm_load_pd(mem);
    }
};

#ifdef __AVX__
template<typename T>
struct _load<T, sgl::v1::simd_mode::aligned, 256> {
    __m256i operator()(typename std::enable_if<std::numeric_limits<T>::is_integer, T>::type const* mem) const noexcept {
        return _mm256_load_si256((__m256i const*)mem);
    }
};

template<>
struct _load<float, sgl::v1::simd_mode::aligned, 256> {
    __m256 operator()(float const* mem) const noexcept {
        return _mm256_load_ps(mem);
    }
};

template<>
struct _load<double, sgl::v1::simd_mode::aligned, 256> {
    __m256d operator()(double const* mem) const noexcept {
        return _mm256_load_pd(mem);
    }
};
#endif

#ifdef __AVX512F__
template<typename T>
struct _load<T, sgl::v1::simd_mode::aligned, 512> {
    __m512i operator()(typename std::enable_if<std::numeric_limits<T>::is_integer, T>::type const* mem) const noexcept {
        return _mm512_load_si512((__m512i const*)mem);
    }
};

template<>
struct _load<double, sgl::v1::simd_mode::aligned, 512> {
    __m512 operator()(double const* mem) const noexcept {
        return _mm512_load_ps(mem);
    }
};

template<>
struct _load<double, sgl::v1::simd_mode::aligned, 512> {
    __m512d operator()(double const* mem) const noexcept {
        return _mm512_load_pd(mem);
    }
};
#endif

template<sgl::v1::simd_mode mode = sgl::v1::simd_mode::unaligned, size_t N = 128, typename T>
inline
auto load(T const* mem) {
    return _load<T, mode, N>()(mem);
}

} // namespace v1
} // namespace sgl
