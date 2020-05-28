#pragma once
namespace sgl {
namespace v1 {

template<typename It>
requires(sgl::v1::forward_iterator(It) && sgl::v1::writable(It))
inline
void fill(It first, It last, const SGLValueType(It)& value) noexcept(std::is_base_of<std::forward_iterator_tag, It>::value && std::is_nothrow_copy_assignable<SGLValueType(It)>::value) {
    while (first != last) {
        *first = value;
        ++first;
    }
}

template<typename T>
struct simd_block_size {
    static constexpr const size_t value = 32;
};

template<typename T>
requires(sgl::v1::builtin_type(T))
inline
void fill(sgl::v1::simd_tag<false> _, T* first, T* last, const T& value) {
    constexpr const size_t block_size = simd_block_size<T>::value;
    constexpr const size_t tail_size = sgl::v1::max(4ul, sizeof(T));
    constexpr const size_t buffer_size = block_size + tail_size;
    constexpr const size_t blocks_count = 8ul;
    constexpr const size_t step = block_size * blocks_count;
    static_assert(sizeof(T) < block_size, "The type should");
    static_assert(buffer_size % sizeof(value) == 0ul);

    char buffer[buffer_size];

    sgl::v1::fill((T*)&buffer[0], (T*)&buffer[buffer_size], value);
    sgl::v1::fill(first, first + sgl::v1::min(size_t(last - first), buffer_size / sizeof(T)), value);
    const size_t addr = (size_t)first;
	const size_t padding = (32ul - (addr & 31ul)) & 31ul;

    char* first1 = (char*)first + padding;
    char* last1 = first1 + ((char*)last - first1) / step * step;
    const auto value_packed = _mm256_loadu_si256((const __m256i*)(buffer + padding));
    while (first1 != last1) {
        // 8 blocks with 256 bits per block
        _mm256_stream_si256((__m256i*)first1,     value_packed);
        _mm256_stream_si256((__m256i*)first1 + 1, value_packed);
        _mm256_stream_si256((__m256i*)first1 + 2, value_packed);
        _mm256_stream_si256((__m256i*)first1 + 3, value_packed);
        _mm256_stream_si256((__m256i*)first1 + 4, value_packed);
        _mm256_stream_si256((__m256i*)first1 + 5, value_packed);
        _mm256_stream_si256((__m256i*)first1 + 6, value_packed);
        _mm256_stream_si256((__m256i*)first1 + 7, value_packed);
        first1 += step;
    }
	_mm_sfence();
    first += ((char*)last1 - (char*)first) / sizeof(T);
    sgl::v1::fill(first, last, value);
}

template<typename T>
requires(sgl::v1::builtin_type(T))
inline
void fill(sgl::v1::simd_tag<true> _, T* first, T* last, const T& value) {
    return sgl::v1::fill(sgl::v1::simd_tag<false>(), first, last, value);
}

} // namespace v1
} // namespace sgl
