#pragma once

namespace sgl {
namespace v1 {

/*
template<typename T, typename UnaryPredicate, typename UnaryAction>
void first_predecessor_action(T& x, UnaryPredicate unary_predicate, UnaryAction action) {
    if (!unary_predicate(x)) { return; }
    auto fast_value = x;
    action(fast_value);

    while (unary_predicate(fast_value)) {
        auto x = fast_value;
        action(fast_value);
    }
    return slow;
}
*/

template<typename T, typename UnaryPredicate, typename UnaryAction>
T first_predecessor_action(T fast_value, UnaryPredicate unary_predicate, UnaryAction action) {
    if (!unary_predicate(fast_value)) { return fast_value; }
    auto slow = fast_value;
    action(fast_value);

    while (unary_predicate(fast_value)) {
        auto slow = fast_value;
        action(fast_value);
    }
    return slow;
}

} // namespace v1
} // namespace sgl
