#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename OutputIterator, typename Predicate, typename Function>
inline
OutputIterator transform_subgroups(ForwardIterator first, ForwardIterator last, OutputIterator out, Predicate pred, Function function) {
    if (first == last) {
        return out;
    }
    ForwardIterator slow = first;
    ForwardIterator fast = slow;
    ++fast;

    while (fast != last) {
        if (!pred(*slow, *fast)) {
            *out = function(first, fast);
            ++out;
            first = fast;
        }
        ++slow;
        ++fast;
    }
    *out = function(first, fast);
    ++out;
    return out;
}

template<typename ForwardIterator0, typename ForwardIterator1, typename OutputIterator, typename Predicate, typename Function>
inline
OutputIterator transform_subgroups(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1, OutputIterator out, Predicate pred, Function function) {
    if (first0 == last0) {
        return out;
    }
    ForwardIterator0 slow0 = first0;
    ForwardIterator0 fast0 = slow0;
    ++fast0;

    ForwardIterator1 slow1 = first1;
    ForwardIterator1 fast1 = slow1;
    ++fast1;


    while (fast0 != last0) {
        if (!pred(*slow0, *slow1, *fast0, *fast1)) {
            *out = function(first0, fast0, first1);
            ++out;
            first0 = fast0;
        }
        ++slow0;
        ++fast0;
        ++slow1;
        ++fast1;
    }
    *out = function(first0, fast0, first1);
    ++out;
    return out;
}

} // namespace v1
} // namespace sgl
