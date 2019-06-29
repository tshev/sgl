#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename R>
inline
ForwardIterator find_adjacent(ForwardIterator f, ForwardIterator l, R r) {
    if (f == l) { return l; }
    ForwardIterator fast = f;
    ++fast;

    while (fast != l) {
        if (*f, *fast) {
            return f;
        }
        ++f;
        ++fast;
    }
    return l;
}

} // namespace v1
} // namespace sgl
