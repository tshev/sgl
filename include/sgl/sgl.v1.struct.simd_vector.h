#pragma once
#include <immintrin.h>

namespace sgl {
namespace v1 {

template<typename T, size_t Capacity>
struct simd_vector;

template<typename T0, size_t N0>
inline
simd_vector<T0, N0> operator+(simd_vector<T0, N0> x, simd_vector<T0, N0> y) noexcept;

template<typename T0, size_t N0>
inline
simd_vector<T0, N0> operator-(simd_vector<T0, N0> x, simd_vector<T0, N0> y) noexcept;

template<typename T0, size_t N0>
inline
simd_vector<T0, N0> operator*(simd_vector<T0, N0> x, simd_vector<T0, N0> y) noexcept;

template<typename T0, size_t N0>
inline
simd_vector<T0, N0> operator/(simd_vector<T0, N0> x, simd_vector<T0, N0> y) noexcept;


template<typename T>
struct simd_vector<T, 128> {
    static constexpr const size_t size = 16 / sizeof(T);

    typedef typename std::enable_if<std::numeric_limits<T>::is_integer, T>::type value_type;
    typedef __m128i block_type;
    typedef block_type register_type;

    block_type value;

    simd_vector() = default;
    simd_vector(block_type value) noexcept : value{value} {}
    simd_vector(T value) noexcept : value{sgl::v1::broadcast<block_type>(value)} {}
    simd_vector(T* value) noexcept : value{sgl::v1::load_unaligned<block_type>(value)} {}
    simd_vector(const simd_vector&) = default;


    void operator()(int32_t* mem) const noexcept {
        _mm_storeu_si128((__m128i*)mem, value);
    }

    /*
    void operator()(int16_t* x) const noexcept {
        // dum Intel
        _mm_storeu_si16(x, value); // _mm_storeu_epi8  (wait for avx512) WHAT??
    }

    void operator()(int8_t* x) const noexcept {
        // dum Intel
        _mm_storeu_si8(x, value);
    }
    */

    friend
    inline
    simd_vector operator==(const simd_vector x,  const simd_vector y) noexcept {
        return sgl::v1::cmpeq<T>(x, y);
    }

    friend
    inline
    simd_vector operator!=(const simd_vector x,  const simd_vector y) noexcept {
        return sgl::v1::xor_op(x == y, simd_vector(0xFFFFFFFF));
    }

    template<typename T0, size_t N0>
    friend
    inline
    simd_vector<T0, N0> operator+(simd_vector<T0, N0> x, simd_vector<T0, N0> y) noexcept;

    template<typename T0, size_t N0>
    friend
    inline
    simd_vector<T0, N0> operator-(simd_vector<T0, N0> x, simd_vector<T0, N0> y) noexcept;

    template<typename T0, size_t N0>
    friend
    inline
    simd_vector<T0, N0> operator*(simd_vector<T0, N0> x, simd_vector<T0, N0> y) noexcept;

    template<typename T0, size_t N0>
    friend
    inline
    simd_vector<T0, N0> operator/(simd_vector<T0, N0> x, simd_vector<T0, N0> y) noexcept;
};

template<>
inline
simd_vector<int8_t, 128> operator+<int8_t, 128>(simd_vector<int8_t, 128> x, simd_vector<int8_t, 128> y) noexcept {
    return _mm_add_epi8(x.value, y.value);
}

template<>
inline
simd_vector<int16_t, 128> operator+(simd_vector<int16_t, 128> x, simd_vector<int16_t, 128> y) noexcept {
    return _mm_add_epi16(x.value, y.value);
}

template<>
inline
simd_vector<int32_t, 128> operator+(simd_vector<int32_t, 128> x, simd_vector<int32_t, 128> y) noexcept {
    return _mm_add_epi32(x.value, y.value);
}

template<>
inline
simd_vector<int64_t, 128> operator+(simd_vector<int64_t, 128> x, simd_vector<int64_t, 128> y) noexcept {
    return _mm_add_epi64(x.value, y.value);
}

template<>
inline
simd_vector<int8_t, 128> operator-(simd_vector<int8_t, 128> x, simd_vector<int8_t, 128> y) noexcept {
    return _mm_sub_epi8(x.value, y.value);
}

template<>
inline
simd_vector<int16_t, 128> operator-(simd_vector<int16_t, 128> x, simd_vector<int16_t, 128> y) noexcept {
    return _mm_sub_epi16(x.value, y.value);
}

template<>
inline
simd_vector<int32_t, 128> operator-(simd_vector<int32_t, 128> x, simd_vector<int32_t, 128> y) noexcept {
    return _mm_sub_epi32(x.value, y.value);
}

template<>
inline
simd_vector<int64_t, 128> operator-(simd_vector<int64_t, 128> x, simd_vector<int64_t, 128> y) noexcept {
    return _mm_sub_epi64(x.value, y.value);
}

template<>
inline
simd_vector<int8_t, 128> operator*(simd_vector<int8_t, 128> x, simd_vector<int8_t, 128> y) noexcept {
    __m128i zero = _mm_setzero_si128();
    __m128i xlo = _mm_cvtepu8_epi16(x.value);
    __m128i xhi = _mm_unpackhi_epi8(x.value, zero);
    __m128i ylo = _mm_cvtepu8_epi16(y.value);
    __m128i yhi = _mm_unpackhi_epi8(y.value, zero);
    __m128i zlo = _mm_mullo_epi16(xlo, ylo);
    __m128i zhi = _mm_mullo_epi16(xhi, yhi);
    __m128i mlo = _mm_set_epi8(0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 14, 12, 10, 8, 6, 4, 2, 0);
    __m128i mhi = _mm_set_epi8(14, 12, 10, 8, 6, 4, 2, 0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80);
    return simd_vector<int8_t, 128>(_mm_or_si128(_mm_shuffle_epi8(zlo, mlo), _mm_shuffle_epi8(zhi, mhi)));
}

template<>
inline
simd_vector<int16_t, 128> operator*(simd_vector<int16_t, 128> x, simd_vector<int16_t, 128> y) noexcept {
    return _mm_mulhi_epi16(x.value, y.value);
}

template<>
inline
simd_vector<int32_t, 128> operator*(simd_vector<int32_t, 128> x, simd_vector<int32_t, 128> y) noexcept {
    return _mm_mul_epi32(x.value, y.value);
}

/*
inline
simd_vector<int64_t, 128> operator*(simd_vector<int64_t, 128> x, simd_vector<int64_t, 128> y) noexcept {
    return _mm_mul_epi64(x.value, y.value);
}
*/

/*
inline
simd_vector<int8_t, 128> operator/(simd_vector<int8_t, 128> x, simd_vector<int8_t, 128> y) noexcept {
    return _mm_div_epi8(x.value, y.value);
}
*/

/*
inline
simd_vector<int16_t, 128> operator/(simd_vector<int16_t, 128> x, simd_vector<int16_t, 128> y) noexcept {
    return _mm_div_epi16(x.value, y.value);
}
*/

/*
inline
simd_vector<int32_t, 128> operator/(simd_vector<int32_t, 128> x, simd_vector<int32_t, 128> y) noexcept {
    return _mm_div_epi32(x.value, y.value);
}
*/

/*
inline
simd_vector<int64_t, 128> operator/(simd_vector<int64_t, 128> x, simd_vector<int64_t, 128> y) noexcept {
    return _mm_div_epi64(x.value, y.value);
}
*/

template<>
struct simd_vector<float, 128> {
    static constexpr const size_t size = 16 / sizeof(float);

    typedef float value_type;
    typedef __m128 block_type;
    typedef __m128 register_type;

    __m128 value;

    simd_vector() = default;
    simd_vector(__m128 value) noexcept : value{value} {}
    simd_vector(value_type value) noexcept : value{sgl::v1::broadcast<block_type>(value)} {}
    simd_vector(const simd_vector&) = default;

    void operator()(float* x) const noexcept {
        _mm_storeu_ps(x, value);
    }

    friend
    inline
    simd_vector operator==(simd_vector x, simd_vector y) noexcept {
        return _mm_cmpeq_ps(x.value, y.value);
    }

    friend
    inline
    simd_vector operator!=(simd_vector x, simd_vector y) noexcept {
        union { uint32_t a = 0xFFFFFFFFu; float b; };
        return _mm_xor_ps((x == y).value, simd_vector(b).value);
    }
};

template<>
struct simd_vector<double, 128> {
    static constexpr const size_t size = 16 / sizeof(double);

    typedef double value_type;
    typedef __m128d block_type;
    typedef __m128d register_type;

    __m128d value;

    simd_vector() = default;
    simd_vector(__m128d value) noexcept : value{value} {}
    simd_vector(value_type value) noexcept : value{sgl::v1::broadcast<block_type>(value)} {}
    simd_vector(const simd_vector&) = default;

    void operator()(double* x) const noexcept {
        _mm_store_pd(x, value);
    }
};

template<>
inline
simd_vector<float, 128> operator+(simd_vector<float, 128> x, simd_vector<float, 128> y) noexcept {
    return _mm_add_ps(x.value, y.value);
}

template<>
inline
simd_vector<double, 128> operator+(simd_vector<double, 128> x, simd_vector<double, 128> y) noexcept {
    return _mm_add_pd(x.value, y.value);
}

template<>
inline
simd_vector<float, 128> operator-(simd_vector<float, 128> x, simd_vector<float, 128> y) noexcept {
    return _mm_sub_ps(x.value, y.value);
}

template<>
inline
simd_vector<double, 128> operator-(simd_vector<double, 128> x, simd_vector<double, 128> y) noexcept {
    return _mm_sub_pd(x.value, y.value);
}

template<>
inline
simd_vector<float, 128> operator*(simd_vector<float, 128> x, simd_vector<float, 128> y) noexcept {
    return _mm_mul_ps(x.value, y.value);
}


template<>
inline
simd_vector<double, 128> operator*(simd_vector<double, 128> x, simd_vector<double, 128> y) noexcept {
    return _mm_mul_pd(x.value, y.value);
}

template<>
inline
simd_vector<float, 128> operator/(simd_vector<float, 128> x, simd_vector<float, 128> y) noexcept {
    return _mm_div_ps(x.value, y.value);
}

template<>
inline
simd_vector<double, 128> operator/(simd_vector<double, 128> x, simd_vector<double, 128> y) noexcept {
    return _mm_div_pd(x.value, y.value);
}



#ifdef __AVX2__
template<typename T>
struct simd_vector<T, 256> {
    static constexpr const size_t size = 32 / sizeof(T);

    typedef typename std::enable_if<std::numeric_limits<T>::is_integer, T>::type value_type;
    typedef __m256i block_type;
    typedef __m256i register_type;

    __m256i value;

    simd_vector() = default;
    simd_vector(__m256i value) noexcept : value{value} {}
    simd_vector(T value) noexcept : value{_mm256_set1_epi32(value)} {}
    simd_vector(const simd_vector&) = default;

    friend
    inline
    simd_vector operator==(const simd_vector x,  const simd_vector y) noexcept {
        return sgl::v1::cmpeq<T>(x, y);
    }

    friend
    inline
    simd_vector operator!=(const simd_vector x,  const simd_vector y) noexcept {
        return sgl::v1::xor_op(x == y, simd_vector(0xFFFFFFFF));
    }

};
#endif

template<typename T>
struct max_simd_vector_size {
#ifdef __AVX2__
    static constexpr const size_t value = 32 / sizeof(T);
#else
    static constexpr const size_t value = 16 / sizeof(T);
#endif
};


template<typename T, size_t  N>
class simd_vector_iterator {
    typedef sgl::v1::simd_vector<T, N> vector_type;

public:
    struct simd_vector_iterator_sink {
        T* data_;

        /*
        simd_vector_iterator_sink& operator=(simd_vector_iterator_source x) {
            x.value(data_);
            return *this;
        }
        */

        simd_vector_iterator_sink& operator=(sgl::v1::simd_vector<T, N> x) {
            x(data_);
            return *this;
        }
    };


    T* data_;

    simd_vector_iterator() = default;
    simd_vector_iterator(T* data) : data_(data) {}

    friend
    inline
    bool operator==(simd_vector_iterator x, simd_vector_iterator y) {
        return x.data_ == y.data_;
    }

    friend
    inline
    bool operator!=(simd_vector_iterator x, simd_vector_iterator y) {
        return !(x == y);
    }

    friend
    inline
    simd_vector_iterator operator+(simd_vector_iterator x, size_t n) {
        return simd_vector_iterator(x.data_ + n);
    }

    friend
    inline
    ptrdiff_t operator-(simd_vector_iterator x, simd_vector_iterator y) {
        return x.data_ - y.data_;
    }

    const vector_type operator*() const {
        return vector_type(data_); }

    simd_vector_iterator& operator++() {
        ++data_;
        return *this;
    }

    simd_vector_iterator& operator+=(size_t n) {
        data_ += n;
        return *this;
    }



    auto sink() {
        return simd_vector_iterator_sink{data_};
    }

    /*
        int32_t a[] = {1, 2, 3, 4};
        int32_t b[] = {4, 3, 2, 1};

        sgl::v1::simd_vector_iterator<int32_t> first0(&a[0]);
        sgl::v1::simd_vector_iterator<int32_t> first1(&b[0]);

        sink(first1) = source(first1);
    */

};


} // namespace v1
} // namespace sgl
