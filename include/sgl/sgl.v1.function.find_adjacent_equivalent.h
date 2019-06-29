#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator>
inline
ForwardIterator find_adjacent_equivalent(ForwardIterator f, ForwardIterator l) {
    if (f == l) {
        return l;
    }

    auto fast = f;
    ++fast;
    while (fast != l) {
        if (!(*f < *fast)) {
            return f;
        }
        ++f;
        ++fast;
    }
    return l;
}


template<typename ForwardIterator, typename R>
inline
ForwardIterator find_adjacent_equivalent(ForwardIterator f, ForwardIterator l, R less) {
    if (f == l) {
        return l;
    }

    auto fast = f;
    ++fast;
    while (fast != l) {
        if (!less(*f, *fast)) {
            return f;
        }
        ++f;
        ++fast;
    }

    return l;
}
} // namespace v1
} // namespace sgl
