#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename R>
ForwardIterator find_adjacent_last_unguarded(ForwardIterator f, ForwardIterator l, R r) {
    auto fast = f;
    ++fast;

    auto result = l;
    while (fast != l) {
        if (r(*f, *fast)) {
            result = f;
        }
        ++f;
        ++fast;
    }
    return result;
}
} // namespace v1
} // namespace sgl
