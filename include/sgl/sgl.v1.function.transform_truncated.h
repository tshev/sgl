#pragma once
// metasgl::certification = true;
namespace sgl {
namespace v1 {
template<typename ForwardIterator0, typename OutputIterator, typename Transformation>
inline
std::pair<OutputIterator, size_t>
transform_truncated(ForwardIterator0 first0, ForwardIterator0 last0, OutputIterator out, Transformation transformation, size_t n) {
    size_t i = 0;
    while (i != n && first0 != last0) {
        *out = transformation(*first0);
        ++out;
        ++first0;
        ++i;
    }
    return std::pair<OutputIterator, size_t>(out, n);
} // transform_truncated


template<typename ForwardIterator0, typename ForwardIterator1, typename OutputIterator, typename Transformation>
inline
std::pair<OutputIterator, size_t>
transform_truncated(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1, OutputIterator out, Transformation transformation, size_t n) {
    size_t i = 0;
    while (i != n && first0 != last0) {
        *out = transformation(*first0, *first1);
        ++out;
        ++first0;
        ++first1;
        ++i;
    }
    return {out, n};
}

template<typename ForwardIterator0, typename ForwardIterator1, typename OutputIterator, typename Transformation>
inline
std::pair<OutputIterator, size_t>
transform_truncated(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1, ForwardIterator1 last1, OutputIterator out, Transformation transformation, size_t n) {
    size_t i = 0;
    while (i != n && first0 != last0 && first1 != last1) {
        *out = transformation(*first0, *first1);
        ++out;
        ++first0;
        ++first1;
        ++i;
    }
    return {out, n};
}
} // namespace v1
} // namespace sgl
