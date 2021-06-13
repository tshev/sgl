#pragma once
namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename OutputIterator, typename Func>
inline
OutputIterator transform_splits(ForwardIterator first, ForwardIterator last, OutputIterator out, const typename std::iterator_traits<ForwardIterator>::value_type& value, Func func) {
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
