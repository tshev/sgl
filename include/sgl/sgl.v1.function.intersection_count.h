#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator0, typename ForwardIterator1, typename T>
// requires(
//   ForwardIterator(ForwardIterator0) && ForwardIterator(ForwardIterator1) &&
//   ValueType(ForwardIterator0) == ValueType(ForwardIterator1) &&
//   Integer(T) && WeakStrictOrdering(std::less<ValueType(ForwardIterator0)>)
// )
T intersection_count(ForwardIterator0 f0, ForwardIterator0 l0, ForwardIterator1 f1, ForwardIterator1 l1, T count) {

    while (f0 != l0 && f1 != l1) {
        if (*f0 < *f1) {
            ++f0;
        } else {
            if (!(*f1 < *f0)) { // equivalent
                ++count;
                f0  = sgl::v1::find_adjacent_not_equivalent_unguarded(f0, l0);
                ++f0;
                f1  = sgl::v1::find_adjacent_not_equivalent_unguarded(f1, l1);
            }
            ++f1;
        }
    }
    return count;
}


template<typename ForwardIterator0, typename ForwardIterator1, typename T, typename Relation>
// requires(
//   ForwardIterator(ForwardIterator0) && ForwardIterator(ForwardIterator1) &&
//   ValueType(ForwardIterator0) == ValueType(ForwardIterator1) &&
//   Integer(T) && WeakStrictOrdering(Relation)
// )
T intersection_count(ForwardIterator0 f0, ForwardIterator0 l0, ForwardIterator1 f1, ForwardIterator1 l1, T count, Relation r) {
    while (f0 != l0 && f1 != l1) {
        if (r(*f0, *f1)) {
            ++f0;
        } else {
            if (!r(*f1, *f0)) {
                ++count;
                f0  = sgl::v1::find_adjacent_not_equivalent_unguarded(f0, l0, r);
                ++f0;
                f1  = sgl::v1::find_adjacent_not_equivalent_unguarded(f1, l1, r);
            }
            ++f1;
        }
    }
    return count;
}


template<typename ForwardIterator0, typename ForwardIterator1, typename T, typename Relation0, typename Relation1>
// requires(
//   ForwardIterator(ForwardIterator0) && ForwardIterator(ForwardIterator1) &&
//   ValueType(ForwardIterator0) == ValueType(ForwardIterator1) &&
//   Integer(T) && WeakStrictOrdering(Relation)
// )
T intersection_count(ForwardIterator0 f0, ForwardIterator0 l0, ForwardIterator1 f1, ForwardIterator1 l1, T count, Relation0 r0, Relation1 r1) {
    // Precondition: $\property{equivalence}(eq)$
    // Precondition: $\property{total\_ordering}(r)$
    while (f0 != l0 && f1 != l1) {
        if (r0(*f0, *f1)) {
            ++f0;
        } else {
            if (eq(*f0, *f1)) {
                ++count;
                f0  = sgl::v1::find_adjacent_missmatch_unguarded(f0, l0, r1);
                ++f0;
                f1  = sgl::v1::find_adjacent_missmatch_unguarded(f1, l1, r1);
            }
            ++f1;
        }
    }
    return count;
}


} // namespace v1
} // namespace sgl
