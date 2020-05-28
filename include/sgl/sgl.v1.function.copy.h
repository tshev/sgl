#pragma once
#include <immintrin.h>

namespace sgl {
namespace v1 {

/*
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
    _mm256_storeu_si256((__m256i*)distanation, _mm256_loadu_si256((const __m256i*)source));
}
};

template<typename T>
struct iloadu;

template<typename T>
struct istoreu;

template<>
struct istoreu<__m256i> {
    void operator()(__m256i* mem_addr, __m256i a) const {
        _mm256_storeu_si256((__m256i*)mem_addr, a);
    }
};

template<>
struct iloadu<__m256i> {
    auto operator()(__m256i* mem_addr) const {
        return _mm256_loadu_si256((__m256i*)mem_addr);
    }
};



template<typename T>
struct memory_block {
    typedef T inner_type;

    static constexpr size_t size = sizeof(T);

    static constexpr size_t shrink(size_t n) {
        return (n / memory_block::size) * memory_block::size;
    }

    struct value_type {
        T* val;
        value_type(void* val) : val((T*)val) {}

        value_type& operator=(const value_type& value) {
            istoreu<T>()(val, iloadu<T>()(value.val));
            return *this;
        }
    };


    T* val;

    memory_block(void* val) : val((T*)val) {}
    memory_block(const void* val) : val((T*)val) {}

    template<typename U>
    operator U() {
        return (U)val;
    }

    memory_block& operator=(const memory_block& value) {
        val = value.val;
        return *this;
    }

    friend
    inline
    bool operator==(const memory_block& x, const memory_block& y) {
        return x.val == y.val;
    }

    friend
    inline
    bool operator!=(const memory_block& x, const memory_block& y) {
        return !(x == y);
    }

    value_type operator*() {
        return value_type(val);
    }

    memory_block& operator++() {
        ++val;
        return *this;
    }

    char* bytes() {
        return (char*)val;
    }
};


*/

/*
#ifdef __AVX2__
char* copy(sgl::v1::simd_tag<false>, char const* first, char const* last, char* out)  {
    return (char*)sgl::v1::memcpy_fast(out, first, last - first);
}
#endif
*/


/*
char* copy(sgl::v1::simd_tag<true>, char const* first, char const* last0, char* out0)  {
    return copy(sgl::v1::simd_tag<false>(), first, last0, out0);
}
*/

template<typename It, typename O>
inline
requires(ForwardIterator(It) && OutputIterator(O))
O copy(It first, It last, O out) {
    
    /*
    #ifdef __AVX2__
    typedef typename std::iterator_traits<It>::value_type T;
    if constexpr (std::is_pointer<It>() && std::is_pointer<O>() && std::is_pod<T>()) {
        if (last < out || out < first) {
            return (O)sgl::v1::copy(sgl::v1::simd_tag<false>(), (char const*)first, (char const *)last, (char*)out);
        }
    }
    while (first != last) {
        *out = *first;
        ++out;
        ++first;
    }
    return out;
    #endif
    */

    while (first != last) {
        *out = *first;
        ++out;
        ++first;
    }
    return out;
}

} // namespace v1
} // namespace sgl
