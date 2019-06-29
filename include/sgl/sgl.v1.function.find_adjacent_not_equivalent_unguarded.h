#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator>
inline
ForwardIterator find_adjacent_not_equivalent_unguarded(ForwardIterator f, ForwardIterator l) {
    auto fast = f;
    ++fast;
    while (fast != l && !(*f < *fast)) {
        ++fast;
        ++f;
    }
    return f;
}


template<typename ForwardIterator, typename R>
inline
ForwardIterator find_adjacent_not_equivalent_unguarded(ForwardIterator f, ForwardIterator l, R r) {
    auto fast = f;
    ++fast;
    while (fast != l && !r(*f, *fast)) {
        ++fast;
        ++f;
    }
    return f;
}

} // namespace v1
} // namespace sgl
