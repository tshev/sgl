#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator0, typename UnaryPredicate>
ForwardIterator0 remove_if_position(ForwardIterator0 first, ForwardIterator0 last, UnaryPredicate predicate) {
    sgl::v1::find_if_position_inplace(first, last, predicate);

    if (first == last) {
        return last;
    }

    ForwardIterator0 fast = first;
    sgl::v1::successor_inplace(fast);

    while (fast != last) {
        if (predicate(fast)) {
            sgl::v1::successor_inplace(fast);
        } else {
            *first = std::move(*fast);
            ++first;
            ++fast;
        }
    }
    return first;
}

template<typename ForwardIterator0, typename ForwardIterator1, typename UnaryPredicate>
std::pair<ForwardIterator0, ForwardIterator1> remove_if_position(ForwardIterator0 first, ForwardIterator0 last, ForwardIterator1 first1, UnaryPredicate predicate) {
    sgl::v1::find_if_position_inplace(first, last, first1, predicate);

    if (first == last) {
        return {last, last};
    }

    ForwardIterator0 fast = first;
    sgl::v1::successor_inplace(fast);

    ForwardIterator0 fast1 = first1;
    sgl::v1::successor_inplace(fast1);

    while (fast != last) {
        if (predicate(fast, fast1)) {
            sgl::v1::successor_inplace(fast);
            sgl::v1::successor_inplace(fast1);
        } else {
            *first = std::move(*fast);
            ++first;
            ++fast;
            *first1 = std::move(*fast1);
            ++first1;
            ++fast1;
        }
    }
    return {first, first1};
}

} // namespace
} // namespace 
