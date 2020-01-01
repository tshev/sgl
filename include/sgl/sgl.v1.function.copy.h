#pragma once

namespace sgl {
namespace v1 {

#ifdef __AVX2__
inline
__attribute__((__always_inline__))
__m256i stream_load(__m256i const* source) {
    return _mm256_stream_load_si256(source);
}

inline
__attribute__((__always_inline__))
void stream(__m256i source, __m256i* dist) {
    return _mm256_stream_si256(dist, source);
}

template<size_t N>
struct copy_op {};

template<>
struct copy_op<32> {
__attribute__((__always_inline__))
void operator()(void const* source, void* distanation) const {
    _mm256_storeu_si256((__m256i*)distanation, _mm256_stream_load_si256((const __m256i*)source));
}
};

template<size_t N>
struct ublock {};


template<>
struct ublock<32> {
    __m256i* val;

    ublock(void* val) : val((__m256i*)val) {}
    ublock(const void* val) : val((__m256i*)val) {}

    template<typename T>
    operator T() {
        return (T)val;
    }

    struct value_type {
        __m256i* val;

        value_type(void* val) : val((__m256i*)val) {}
        value_type(const void* val) : val((__m256i*)val) {}

        value_type& operator=(const value_type& value) {
            _mm256_storeu_si256((__m256i*)val, _mm256_stream_load_si256((const __m256i*)value.val));
            return *this;
        }
    };

    ublock& operator=(const ublock& value) {
        val = value.val;
        return *this;
    }

    friend
    inline
    bool operator==(const ublock& x, const ublock& y) {
        return x.val == y.val;
    }

    friend
    inline
    bool operator!=(const ublock& x, const ublock& y) {
        return !(x == y);
    }

    value_type operator*() {
        return value_type(val);
    }

    ublock& operator++() {
        ++val;
        return *this;
    }

    char* bytes() {
        return (char*)val;
    }
};


char* copy(sgl::v1::simd_tag<true>, char const* first1, char const* last1, char* out)  {
    size_t n = last1 - first1;
    constexpr const size_t step = 32ul;
    const char* last2 = first1 + (n / step) * step;
    auto out2 = copy_elements(ublock<step>(first1), ublock<step>(last2), ublock<step>(out)); 
    return sgl::v1::copy_elements(last2, last1, static_cast<char*>(out2));
}


char* copy(sgl::v1::simd_tag<false>, char const* first1, char const* last1, char* out1)  {
    size_t n0 = last1 - first1;
    constexpr const size_t step = 32ul;
    size_t n_head = (size_t)first1 % step;
    if (n0 < n_head) {
        return sgl::v1::copy_elements(first1, last1, out1);
    }
    char const* middle = first1 + n_head; 
    out1 = sgl::v1::copy_elements(first1, middle, out1);
    return sgl::v1::copy(sgl::v1::simd_tag<true>(), middle, last1, out1);
}

#endif

template<typename It, typename O>
inline
requires(ForwardIterator(It) && OutputIterator(O))
O copy(It first, It last, O out) {
    #ifdef __AVX2__
    typedef typename std::iterator_traits<It>::value_type T;
    if constexpr (std::is_pointer<It>() && std::is_pointer<O>() && std::is_pod<T>()) {
        if (last < out || out < first) {
            return (O)sgl::v1::copy(sgl::v1::simd_tag<false>(), (char const*)first, (char const *)last, (char*)out);
        }
    }
    #endif
    return sgl::v1::copy_elements(first, last, out);
}

} // namespace v1
} // namespace sgl
