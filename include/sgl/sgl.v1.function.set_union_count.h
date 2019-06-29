#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator0, typename ForwardIterator1, typename T>
// requires(
//   ForwardIterator(ForwardIterator0) && ForwardIterator(ForwardIterator1) &&
//   ValueType(ForwardIterator0) == ValueType(ForwardIterator1) && Integer(T)
// )
T set_union_count(ForwardIterator0 f0, ForwardIterator0 l0, ForwardIterator1 f1, ForwardIterator1 l1, T count) {
    // Precondition: $ValueType(ForwardIterator0) == ValueType(ForwardIterator1)$
    // Precondition: $\func{weak\_ordering}(std::less<ValueType(ForwardIterator0)>())$
    while (f0 != l0 && f1 != l1) {
        if (*f0 < *f1) {
            ++f0;
            ++count;
        } else if (*f1 < *f0) {
            ++f1;
            ++count;
        } else {
            ++f0;
            ++f1;
            ++count;
        }
    }
    count += std::distance(f0, l0);
    count += std::distance(f1, l1);
    return count;
}

} // namespace v1
} // namespace sgl
