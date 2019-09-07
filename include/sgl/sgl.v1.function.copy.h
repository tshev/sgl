#pragma once
namespace sgl {
namespace v1 {

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

void* copy(sgl::v1::simd_tag<true>, void const* first0, void* last0, void* out)  {
    char const* first1 = (char const*)first0;
    char const* last1 = (char const*)last0;
    size_t n = last1 - first1;
    constexpr const size_t step = 32ul;
    const __m256i* first2 = (__m256i*)first1;
    const __m256i* last2 = first2 + ((n / step) * step) / step;
    __m256i* out2 = (__m256i*)out;

    while (first2 != last2) {
        //_mm_prefetch(first2, _mm_hint(32));
        auto loaded = stream_load(first2);
        stream(loaded, out2);
        ++first2;
        ++out2;
    }
    _mm_sfence();

    first1 = (char*)first2;
    auto out1 = (char*)out2;
    while (first1 != last1) {
        *out1 = *first1;
        ++first1;
    }
    return out1;
}


void* copy(sgl::v1::simd_tag<false>, void const* first0, void* last0, void* out)  {
    char const* first1 = (char const*)first0;
    char const* last1 = (char const*)last0;
    char* out1 = (char*)out;
    size_t n0 = last1 - first1;
    constexpr const size_t step = 32ul;
    size_t n_head = (size_t)first1 % step;
    if (n0 < n_head) {
        while (first1 != last1) {
            *out1 = *first1;
            ++out1;
            ++first1;
        }
        return out1;
    }
    char const* middle = first1 + n_head; 
    while (first1 != middle) {
        *out1 = *first1;
        ++out1;
        ++first1;
    }
    return sgl::v1::copy(sgl::v1::simd_tag<true>(), middle, last0, out1);
}


template<typename It, typename O>
inline
requires(ForwardIterator(It) && OutputIterator(O))
O copy(It first, It last, O out) {
    typedef typename std::iterator_traits<It>::value_type T;
    if constexpr (sgl::v1::is_pointer<It>() && sgl::v1::is_pointer<O>() && sgl::v1::is_pod<T>()) {
        if (last < out || out < first) {
            return (O)sgl::v1::copy(sgl::v1::simd_tag<false>(), first, last, out);
        }
    }
    while (first != last) {
        *out = *first;
        ++out;
        ++first;
    }
    return out;
}

} // namespace v1
} // namespace sgl
