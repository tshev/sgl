#pragma once
namespace sgl {
namespace v1 {

template<typename ForwardIterator0, typename OutputIterator, typename Function>
inline
OutputIterator transform(ForwardIterator0 first, ForwardIterator0 last, OutputIterator out, Function func) {
    while (first != last) {
        *out = func(*first);
        ++out;
        ++first;
    }
    return out;
}

template<typename ForwardIterator0, typename ForwardIterator1, typename OutputIterator, typename Function>
inline
std::pair<ForwardIterator1, OutputIterator> transform(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1, OutputIterator out, Function func) {
    while (first0 != last0) {
        *out = func(*first0, *first1);
        ++out;
        ++first0;
        ++first1;
    }
    return {first1, out};
}

template<typename ForwardIterator0, typename ForwardIterator1, typename ForwardIterator2, typename OutputIterator, typename Function>
inline
sgl::v1::triple<ForwardIterator1, ForwardIterator2, OutputIterator> transform(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1, ForwardIterator2 first2, OutputIterator out, Function func) {
    while (first0 != last0) {
        *out = func(*first0, *first1, *first2);
        ++out;
        ++first0;
        ++first1;
        ++first2;
    }
    return {first1, first2, out};
}

} // namespace v1
} // namespace sgl
