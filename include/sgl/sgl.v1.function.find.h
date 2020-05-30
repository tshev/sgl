#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename T>
inline
ForwardIterator find(sgl::v1::default_tag, ForwardIterator first, ForwardIterator last, const T& value) {
    while (first != last && !(*first == value)) {
        ++first;
    }
    return first;
}


template <typename T, typename V>
inline
typename std::enable_if<(std::numeric_limits<T>::is_integer && sizeof(T) == 4) && sizeof(typename V::block_type) == 16, T const*>::type
find(sgl::v1::simd_tag<false, V>, T const* first, T const* last, const T& value) noexcept {
    constexpr const size_t block_size = sizeof(typename V::block_type);
    constexpr const size_t step = block_size / sizeof(T);
    const size_t n = (last - first) / step * step;
    T const* first0 = first;
    T const* last0 = first0 + n;
    T buffer[step];
    sgl::v1::fill(sgl::v1::default_tag(), buffer, buffer + step, value);

    const V value_packed = sgl::v1::load_unaligned<V>(buffer);

    while (first != last0) {
        const V current_value_packed = sgl::v1::load_unaligned<V>(first);
        const auto r = current_value_packed == value_packed;
        const int b = _mm_movemask_epi8(r.value);
        if (b != 0) {
            if ((0x0000000F & b) != 0) {
                return first;
            }
            if ((0x000000F0 & b) != 0) {
                return first + 1;
            }
            if ((0x00000F00 & b) != 0) {
                return first + 2;
            }
            return first + 3;
        }
        first += step;
    }
    return sgl::v1::find(sgl::v1::default_tag(), first, last, value);
}

template<typename ForwardIterator, typename T>
inline
ForwardIterator find(ForwardIterator first, ForwardIterator last, const T& x) {
    while (first != last && !(*first == x)) {
        ++first;
    }
    return first;
}

template<typename ForwardIterator, typename T, typename Equality>
inline
ForwardIterator find(ForwardIterator first, ForwardIterator last, const T& x, Equality pred) {
    while (first != last && !pred(*first, x)) {
        ++first;
    }
    return first;
}

template<typename ForwardIterator, typename T, typename N>
inline
typename std::enable_if<std::is_arithmetic<N>::value, ForwardIterator>::type
find(ForwardIterator first, ForwardIterator last, const T& x, N& n) {
    while (first != last && !(*first == x)) {
        ++first;
        ++n;
    }
    return first;
}

template<typename ForwardIterator, typename T, typename Equality, typename N>
inline
typename std::enable_if<std::is_arithmetic<N>::value, ForwardIterator>::type
find(ForwardIterator first, ForwardIterator last, const T& x, Equality eq, N& n) {
    while (first != last && !eq(*first, x)) {
        ++first;
        ++n;
    }
    return first;
}

} // namespace v1
} // namespace sgl
