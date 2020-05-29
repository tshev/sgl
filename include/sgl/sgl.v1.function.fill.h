#pragma once
namespace sgl {
namespace v1 {

template<typename It>
requires(sgl::v1::forward_iterator(It) && sgl::v1::writable(It))
inline
void fill(It first, It last, const SGLValueType(It)& value) noexcept(sgl::v1::is_nothrow_algorithm<SGLValueType(It), It>::value) {
    while (first != last) {
        *first = value;
        ++first;
    }
}

template<typename It>
requires(sgl::v1::forward_iterator(It) && sgl::v1::writable(It))
inline
void fill(sgl::v1::default_tag, It first, It last, const SGLValueType(It)& value) noexcept(sgl::v1::is_nothrow_algorithm<SGLValueType(It), It>::value) {
    while (first != last) {
        *first = value;
        ++first;
    }
}

template<typename V, typename T>
requires(sgl::v1::builtin_type(T))
void fill(sgl::v1::simd_tag<false, V>, T* first, T* last, const T& value) noexcept {
    constexpr const size_t block_size = sizeof(V);
    constexpr const size_t tail_size = sgl::v1::max(block_size, sizeof(T));
    constexpr const size_t buffer_size = block_size + tail_size;
    constexpr const size_t blocks_count = 8ul;
    constexpr const size_t step = block_size * blocks_count;
    static_assert(sizeof(T) <= block_size, "Type should be smaller than block size");
    static_assert(block_size % sizeof(value) == 0ul);

    char buffer[buffer_size];
    
    sgl::v1::fill(sgl::v1::default_tag{}, (T*)&buffer[0], (T*)&buffer[buffer_size], value);
    sgl::v1::fill(sgl::v1::default_tag{}, first, first + sgl::v1::min<size_t>(last - first, buffer_size / sizeof(T)), value);
	const size_t padding = sgl::v1::alignment_padding<size_t>(size_t(first), block_size);

    V* first1 = (V*)((char*)first + padding);
    V* last1 = (V*)((char*)first1 + ((char*)last - (char*)first1) / step * step);
    const V value_packed = sgl::v1::load_unaligned<V>(&buffer[padding]);

    while (first1 != last1) {
        // 8 blocks with sizeof(V) bytes per block
        sgl::v1::stream_aligned(first1,     value_packed);
        sgl::v1::stream_aligned(first1 + 1, value_packed);
        sgl::v1::stream_aligned(first1 + 2, value_packed);
        sgl::v1::stream_aligned(first1 + 3, value_packed);
        sgl::v1::stream_aligned(first1 + 4, value_packed);
        sgl::v1::stream_aligned(first1 + 5, value_packed);
        sgl::v1::stream_aligned(first1 + 6, value_packed);
        sgl::v1::stream_aligned(first1 + 7, value_packed);
        first1 += blocks_count;
    }
	_mm_sfence();
    first += ((char*)last1 - (char*)first) / sizeof(T);
    sgl::v1::fill(sgl::v1::default_tag{}, first, last, value);
}

} // namespace v1
} // namespace sgl
