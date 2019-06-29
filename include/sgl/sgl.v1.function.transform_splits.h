#pragma once
namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename OutputIterator, typename T, typename Func>
inline
void transform_splits(ForwardIterator first, ForwardIterator last, OutputIterator out, const T& value, Func func) {
    while (first != last) {
        ForwardIterator next = sgl::v1::find(first, last, value);
        *out = func(first, next);
        ++out;
        first = next;
        if (first != last) {
            ++first;
        }
    }
    return out;
}

}
}
