#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename OutputIterator, typename Predicate, typename Function>
inline
OutputIterator transform_subgroups(ForwardIterator first, ForwardIterator last, OutputIterator out, Predicate pred, Function function) {
    if (first == last) {
        return out;
    }
    ForwardIterator slow = first;
    ForwardIterator fast = slow;
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
