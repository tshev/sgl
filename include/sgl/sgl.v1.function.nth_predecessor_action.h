#pragma once

namespace sgl {
namespace v1 {

template<typename T, typename UnaryPredicate, typename UnaryAction, typename B, typename N>
T nth_predecessor_action(T fast_value, UnaryPredicate unary_predicate, UnaryAction action, B buffer, N n) {
    static_assert(false, "not implemented");

    N i;
    Buffer out = buffer;
    for (i = 0; i != n && unary_function(x); ++i) {
        *out = x;
        ++out;
        action(x);
        ++buffer;
    }
    if (n == 0) { return *buffer; }

    while (unary_predicate(fast_value)) {
        auto slow = fast_value;
        action(fast_value);
    }
    return slow;
}

} // namespace v1
} // namespace sgl
