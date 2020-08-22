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
    typedef typename sgl::v1::simd_vector<T, sgl::v1::max_simd_vector_size<T>::value * 8 * sizeof(T)> vector_type;
    constexpr const size_t size = sgl::v1::max_simd_vector_size<T>::value;
    if (last - first <= 2 * size) {
        sgl::v1::delta_encode(first, last);
        return;
    }
/*
    sgl::v1::simd_vector_iterator<T, N> first1{first};
    vector_type prev_value = *first1;
    ++first1;
    size_t offset = ((last - first) / size) * size - size;
    first += offset;
    sgl::v1::simd_vector_iterator<T, N> last1{first1 + offset};
    constexpr const size_t step = vector_type::size - 1;

    while (first1 != last1) {
        vector_type delta = *first1 - prev_value;
        prev_value = *(first1 + step);
        first1.sink() = delta; 
        first1 += vector_type::size;
    }
    T buffer[size];
    prev_value(buffer);
    sgl::v1::delta_encode(first, last, buffer[0]);
*/

 
    vector_type prev_value = vector_type(first);
    ++first;
    T* last1 = first + ((last - first) / size) * size - size;
    while (first != last1) {
        vector_type delta = vector_type(first) - prev_value;
        prev_value = vector_type(first + vector_type::size - 1);
        delta(first);  // sink(first) = delta;
        first += vector_type::size;
    }
    T buffer[size];
    prev_value(buffer);
    sgl::v1::delta_encode(first, last, buffer[0]);
}

/*
template<typename T>
inline
void delta_encode(sgl::v1::simd_tag<false>, simd_vector`T* const first, T* const last) {

}
*/



} // namespace sgl
} // namespace v1
