#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename OutputIterator, typename UnaryPredicate>
OutputIterator copy_if(ForwardIterator first, ForwardIterator last, OutputIterator out, UnaryPredicate pred) {
    while (first != last) {
        if (pred(*first)) {
            *out = *first;
            ++out;
        }
        ++first;
    }
    return out;
}

template<typename ForwardIterator, typename ForwardIterator1, typename OutputIterator, typename UnaryPredicate>
OutputIterator copy_if(ForwardIterator first, ForwardIterator last, ForwardIterator1 first1, OutputIterator out, UnaryPredicate pred) {
    while (first != last) {
        if (pred(*first, *first1)) {
            *out = *first;
            ++out;
        }
        ++first;
        ++first1;
    }
    return out;
}



}
}
