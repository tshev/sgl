#pragma once

namespace sgl {
namespace v1 {

template<typename It>
inline
void delta_encode(It first, It last) {
    if (first == last) return;
    auto prev_value = *first;
    ++first;
    while (first != last) {
        auto delta = *first - prev_value;
        prev_value = *first;
        *first = delta;
        ++first;
    }
}

template<typename It, typename T>
inline
void delta_encode(It first, It last, T value) {
    while (first != last) {
        auto delta = *first - value;
        value = *first;
        *first = delta;
        ++first;
    }
}

template<typename V, typename T>
inline
void delta_encode(sgl::v1::simd_tag<false, V>, T* first, T* last) {
    using sgl::v1::sink;

    constexpr const size_t N = sgl::v1::max_simd_vector_size<T>::value * 8 * sizeof(T);
    typedef typename sgl::v1::simd_vector<T, N> vector_type;
    typedef sgl::v1::simd_vector_iterator<T, N> iterator_type;

    if (last - first <= 2 * vector_type::size) {
        sgl::v1::delta_encode(first, last);
        return;
    }

    iterator_type first1{first};
    vector_type prev_value = *first1;
    ++first1;
    constexpr const size_t step = vector_type::size - 1;
    first += (last - first + 1) / vector_type::size * vector_type::size - step;
    iterator_type last1{first};

    while (first1 != last1) {
        vector_type delta = *first1 - prev_value;
        prev_value = *(first1 + step);
        sink(first1) = delta; 
        first1 += vector_type::size;
    }
    T buffer[vector_type::size];
    sink(iterator_type{buffer}) = prev_value;
    sgl::v1::delta_encode(first, last, *buffer);
}

/*
template<typename T>
inline
void delta_encode(sgl::v1::simd_tag<false>, simd_vector`T* const first, T* const last) {

}
*/



} // namespace sgl
} // namespace v1
