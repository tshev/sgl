#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename Predicate, typename Function>
inline
ForwardIterator squash_subgroups(ForwardIterator first, ForwardIterator last, Predicate pred, Function function) {
    if (first == last) {
        return first;
    }
    ForwardIterator slow = first;
    ForwardIterator fast = slow;
    ForwardIterator out = first;
    ++fast;

    while (fast != last) {
        if (!pred(*slow, *fast)) {
            *out = function(first, fast);
            ++out;
            first = fast;
        }
        ++slow;
        ++fast;
    }
    *out = function(first, fast);
    ++out;
    return out;
}

} // namespace v1
} // namespace sgl
