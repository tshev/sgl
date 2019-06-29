#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename OutputIterator, typename P, typename F>
OutputIterator transform_if(ForwardIterator first, ForwardIterator last, OutputIterator out, P p, F f) {
    while (first != last) {
        if (p(*first)) {
            *out = f(*first);
            ++out;
        }
        ++first;
    }
    return out;
}

} // namespace v1
} // namespace sgl
