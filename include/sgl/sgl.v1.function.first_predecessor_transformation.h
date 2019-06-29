#pragma once

namespace sgl {
namespace v1 {

template<typename T, typename UnaryPredicate, typename Transformation>
// requires(Regular(T) && UnaryPredicate(UnaryPredicate) && Transformation(UnaryPredicate))
T first_predecessor_transformation(T fast_value, UnaryPredicate unary_predicate, Transformation action) {
    if (!unary_predicate(fast_value)) { return fast_value; }

    T slow = fast_value;
    fast_value = action(fast_value);

    while (unary_predicate(fast_value)) {
        slow = fast_value;
        fast_value = action(fast_value);
    }
    return slow;
}

} // namespace v1
} // namespace sgl
