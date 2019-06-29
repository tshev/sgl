#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename F>
void for_each_adjacent_unguarded(ForwardIterator first, ForwardIterator last, F f) {
    auto fast = first;
    ++fast;
    while (fast != first) {
        f(*first, *fast);
        ++first;
        ++fast;
    }    
}

} // namespace v1
} // namespace sgl
