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

}
}
