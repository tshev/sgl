#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename F>
inline
ForwardIterator for_each_adjacent(ForwardIterator first, ForwardIterator last, F f) {
    if (first == last) {
        return last;
    }

    auto fast = first;
    ++fast;
    while (fast != first) {
        f(*first, *fast);
        ++first;
        ++fast;
    }    
    return first;
}

} // namespace v1
} // namespace sgl
