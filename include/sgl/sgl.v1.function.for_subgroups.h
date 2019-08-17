#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename Predicate, typename Function>
inline
void for_subgroups(ForwardIterator first, ForwardIterator last, Predicate pred, Function function) {
    if (first == last) {
        return;
    }
    ForwardIterator slow = first;
    ForwardIterator fast = slow;
    ++fast;

    while (fast != last) {
        if (!pred(*slow, *fast)) {
            function(first, fast);
            first = fast;
        }
        ++slow;
        ++fast;
    }
    function(first, fast);
}

} // namespace v1
} // namespace sgl
