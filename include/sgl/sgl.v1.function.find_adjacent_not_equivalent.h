#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator>
inline
ForwardIterator find_not_equivalent(ForwardIterator f, ForwardIterator l) {
    if (f  == l) { return f; }
    auto fast = f;
    ++fast;
    while (fast != l) {
        if (*f < *fast) {
            return f;
        }
        ++fast;
        ++f;
    }
    return l;
}


template<typename ForwardIterator, typename R>
inline
ForwardIterator find_not_equivalent(ForwardIterator f, ForwardIterator l, R r) {
    if (f  == l) { return f; }
    auto fast = f;
    ++fast;
    while (fast != l) {
        if (r(*f, *fast)) {
            return f;
        }
        ++fast;
        ++f;
    }
    return l;
}

} // namespace v1
} // namespace sgl
