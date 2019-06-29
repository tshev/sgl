#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename R>
ForwardIterator find_adjacent_unguarded(ForwardIterator f, ForwardIterator l, R r) {
    auto fast = f;
    ++fast;

    while (fast != l) {
        if (r(*f, *fast)) {
            return f;
        }
        ++f;
        ++fast;
    }
    return l;
}

} // namespace v1
} // namespace sgl
