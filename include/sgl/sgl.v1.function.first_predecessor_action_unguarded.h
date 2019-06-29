#pragma once

namespace sgl {
namespace v1 {

template<typename T, typename UnaryPredicate, typename UnaryAction>
// requires(Regular(T) && UnaryPredicate(UnaryPredicate) && UnaryAction(UnaryPredicate))
std::pair<T, T> first_predecessor_action_unguarded(T fast_value, UnaryPredicate unary_predicate, UnaryAction action) {
    T slow = fast_value;
    action(fast_value);

    while (unary_predicate(fast_value)) {
        action(slow);
        action(fast_value);
    }
    return {slow, fast_value};
}

} // namespace v1
} // namespace sgl
