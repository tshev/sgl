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

template<typename It>
inline
void delta_encode(It first, It last, typename std::iterator_traits<It>::value_type value) {
    while (first != last) {
        auto delta = *first - value;
        value = *first;
        *first = delta;
        ++first;
    }
}

template<typename It, typename OutputIterator, typename _ = typename std::iterator_traits<OutputIterator>::iterator_category>
inline
OutputIterator delta_encode(It first, It last, OutputIterator output) {
    if (first == last) return output;
    *output = *first;
    ++output;
    auto fast = first;
    ++fast;
    while (fast != last) {
        *output = *fast - *first;
        ++output;
        ++first;
        ++fast;
    }
    return output;
}

template<typename It, typename OutputIterator>
inline
OutputIterator delta_encode(It first, It last, typename std::iterator_traits<It>::value_type value, OutputIterator output) {
    if (first == last) { return output; }
    *output = *first - value; 
    ++output;
    auto fast = first;
    ++fast;
    while (fast != last) {
        *output = *fast - *first;
        ++output;
        ++first;
        ++fast;
    }
    return output;
}

template<size_t N, typename T>
inline
T* delta_encode(sgl::v1::simd_tag<false, N>, T* first, T* last, T* output) {
    if (first == last) { return output; }
    *output = *first; 
    ++output;
    auto fast = first;
    ++fast;

    constexpr const size_t step = N / 8 / sizeof(T);
    //typedef sgl::v1::simd_vector<T, N> vector_type;
    typedef sgl::v1::simd_vector_iterator<T, N> iterator_type;

    iterator_type first1(first);
    iterator_type fast1(fast);
    size_t offset = (last - fast) / step * step;
    auto last1 = iterator_type(fast1 + offset);
    auto output1 = iterator_type(output);

    while (fast1 != last1) {
        sink(output1) = *fast1 - *first1;
        output1 += step;
        first1 += step;
        fast1 += step;
    }

    first += offset;
    output += offset;
    fast += offset;
    sgl::v1::delta_encode(fast, last, *first, output);
    return output;
}


template<size_t N, typename T>
inline
void delta_encode(sgl::v1::simd_tag<false, N>, T* first, T* last) {
    using sgl::v1::sink;
    using sgl::v1::source;

    typedef sgl::v1::simd_vector<T, N> vector_type;
    typedef sgl::v1::simd_vector_iterator<T, N> iterator_type;

    if (last - first < 2 * vector_type::size + 1) {
        sgl::v1::delta_encode(first, last);
        return;
    }

    iterator_type first1{first};
    vector_type prev_value = source(first1);
    ++first1;
    constexpr const size_t step = vector_type::size - 1;
    first += (last - first + 1) / vector_type::size * vector_type::size - step;
    iterator_type last1{first};

    while (first1 != last1) {
        vector_type delta = source(first1) - prev_value;
        prev_value = source(first1 + step);
        sink(first1) = delta; 
        first1 += vector_type::size;
    }
    T buffer[vector_type::size];
    sink(iterator_type{buffer}) = prev_value;
    sgl::v1::delta_encode(first, last, source(buffer));
}

} // namespace sgl
} // namespace v1
