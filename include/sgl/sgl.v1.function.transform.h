#pragma once
namespace sgl {
namespace v1 {

template<typename ForwardIterator0, typename OutputIterator, typename Function>
inline
OutputIterator transform(ForwardIterator0 first, ForwardIterator0 last, OutputIterator out, Function func) {
    while (first != last) {
        *out = func(*first);
        ++first;
    }
    return out;
}

template<typename ForwardIterator0, typename ForwardIterator1, typename OutputIterator, typename Function>
inline
std::pair<ForwardIterator1, OutputIterator> transform(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1, OutputIterator out, Function func) {
    while (first0 != last0) {
        *out = func(*first0, *first1);
        ++first0;
        ++first1;
    }
    return {first1, out};
}

} // namespace v1
} // namespace sgl
