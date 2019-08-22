#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename Predicate, typename Function>
inline
void for_subgroups_back(ForwardIterator first, ForwardIterator last, Predicate pred, Function function) {
    if (first == last) {
        return;
    }
    ForwardIterator slow = first;
    ForwardIterator fast = slow;
    ++fast;

    while (fast != last) {
        if (!pred(*slow, *fast)) {
            function(*slow);
            first = fast;
        }
        ++slow;
        ++fast;
    }
    function(*slow);
}

} // namespace v1
} // namespace sgl
