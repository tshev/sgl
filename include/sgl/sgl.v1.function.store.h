#pragma once
namespace sgl {
namespace v1 {

template<typename T, size_t N, sgl::v1::simd_mode mode>
struct _store;

// # 128

// ## integers
template<typename T>
struct _store<T, 128, sgl::v1::simd_mode::unaligned> {
    void operator()(typename std::enable_if<std::numeric_limits<T>::is_integer, T>::type* mem, __m128i value) const noexcept {
        return _mm_storeu_si128((__m128i*)mem, value);
    }
};

// ## float
template<>
struct _store<float, 128, sgl::v1::simd_mode::unaligned> {
    void operator()(float* mem, __m128 value) const noexcept {
        return _mm_storeu_ps(mem, value);
    }
};

// ## double
template<>
struct _store<double, 128, sgl::v1::simd_mode::unaligned> {
    void operator()(double* mem, __m128d value) const noexcept {
        return _mm_storeu_pd(mem, value);
    }
};

// ## 256
#ifdef __AVX__
template<typename T>
struct _store<T, 256, sgl::v1::simd_mode::unaligned> {
    void operator()(typename std::enable_if<std::numeric_limits<T>::is_integer, T>::type* mem, __m256i value) const noexcept {
        return _mm256_storeu_si256((__m256i*)mem, value);
    }
};

template<>
struct _store<float, 256, sgl::v1::simd_mode::unaligned> {
    void operator()(float* mem, __m256 value) const noexcept {
        return _mm256_storeu_ps(mem, value);
    }
};

template<>
struct _store<double, 256, sgl::v1::simd_mode::unaligned> {
    void operator()(double* mem, __m256d value) const noexcept {
        return _mm256_storeu_pd(mem, value);
    }
};
#endif


// # 512
#ifdef __AVX512F__
template<typename T>
struct _store<T, 512, sgl::v1::simd_mode::unaligned> {
    void operator()(typename std::enable_if<std::numeric_limits<T>::is_integer, T>::type* mem, __m512i value) const noexcept {
        return _mm512_storeu_si512((__m512i*)mem, value);
    }
};

template<>
struct _store<float, 512, sgl::v1::simd_mode::unaligned> {
    void operator()(float* mem, __m512 value) const noexcept {
        return _mm512_storeu_ps(mem, value);
    }
};

template<>
struct _store<double, 512, sgl::v1::simd_mode::unaligned> {
    void operator()(double* mem, __m512d value) const noexcept {
        return _mm512_storeu_pd(mem, value);
    }
};
#endif

template<typename T>
struct _store<T, 128, sgl::v1::simd_mode::aligned> {
    void operator()(typename std::enable_if<std::numeric_limits<T>::is_integer, T>::type* mem, __m128i value) const noexcept {
        return _mm_store_si128((__m128i*)mem, value);
    }
};

template<>
struct _store<float, 128, sgl::v1::simd_mode::aligned> {
    void operator()(float* mem, __m128 value) const noexcept {
        return _mm_store_ps(mem, value);
    }
};

template<>
struct _store<double, 128, sgl::v1::simd_mode::aligned> {
    void operator()(double* mem, __m128d value) const noexcept {
        return _mm_store_pd(mem, value);
    }
};

#ifdef __AVX__
template<typename T>
struct _store<T, 256, sgl::v1::simd_mode::aligned> {
    void operator()(typename std::enable_if<std::numeric_limits<T>::is_integer, T>::type* mem, __m256i value) const noexcept {
        return _mm256_store_si256((__m256i*)mem, value);
    }
};

template<>
struct _store<float, 256, sgl::v1::simd_mode::aligned> {
    void operator()(float* mem, __m256 value) const noexcept {
        return _mm256_store_ps(mem, value);
    }
};

template<>
struct _store<double, 256, sgl::v1::simd_mode::aligned> {
    void operator()(double* mem, __m256d value) const noexcept {
        return _mm256_store_pd(mem, value);
    }
};
#endif

#ifdef __AVX512F__
template<typename T>
struct _store<T, 512, sgl::v1::simd_mode::aligned> {
    void operator()(typename std::enable_if<std::numeric_limits<T>::is_integer, T>::type* mem, __m512i value) const noexcept {
        return _mm512_store_si512((__m512i*)mem, value);
    }
};

template<>
struct _store<float, 512, sgl::v1::simd_mode::aligned> {
    void operator()(float* mem, __m512 value) const noexcept {
        return _mm512_store_ps(mem, value);
    }
};

template<>
struct _store<float, 512, sgl::v1::simd_mode::aligned> {
    void operator()(double* mem, __m512 value) const noexcept {
        return _mm512_store_pd(mem, value);
    }
};
#endif

template<size_t N = 128, sgl::v1::simd_mode mode = sgl::v1::simd_mode::unaligned, typename T, typename U>
inline
auto store(T* mem, U value) {
    return _store<T, N, mode>()(mem, value);
}

} // namespace v1
} // namespace sgl
