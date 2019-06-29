#pragma once

namespace sgl {
namespace v1 {
template<typename ForwardIterator, typename UnaryPredicate>
ForwardIterator partition_semistable_position(ForwardIterator first, ForwardIterator last, UnaryPredicate predicate) {
    sgl::v1::find_if_position_inplace(first, last, predicate);

    if (first == last) {
        return first;
    }

    ForwardIterator fast = first;
    sgl::v1::successor_inplace(fast);

    while (fast != last) {
        if (predicate(fast)) {
            sgl::v1::successor_inplace(fast);
        } else {
            sgl::v1::swap_step(first, fast);
        }
    }
    return first;
}


template<typename ForwardIterator0, typename ForwardIterator1, typename BinaryPredicate>
std::pair<ForwardIterator0, ForwardIterator1> partition_semistable(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1,  BinaryPredicate predicate) {
    sgl::v1::find_if_position_inplace(first0, last0, first0, predicate);

    if (first0 == last0) {
        return {first0, first1};
    }

    ForwardIterator0 fast0 = first0;
    ForwardIterator1 fast1 = first1;

    sgl::v1::successor_inplace(fast0);
    sgl::v1::successor_inplace(fast1);

    while (first0 != last0) {
        if (predicate(fast0, fast1)) {
            sgl::v1::successor_inplace(fast0);
            sgl::v1::successor_inplace(fast1);
        } else {
            sgl::v1::swap_step(first0, fast0);
            sgl::v1::swap_step(first1, fast1);
        }
    }
    return {first0, first1};
}

} // namespace 
} // namespace sgl
