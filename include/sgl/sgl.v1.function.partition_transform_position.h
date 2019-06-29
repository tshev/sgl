#pragma once

namespace sgl {
namespace v1 {


template<typename ForwardIterator, typename OutputIterator0, typename OutputIterator1, typename UnaryPredicate, typename UnaryFunction0>
inline
std::pair<OutputIterator0, OutputIterator1> partition_transform_position(ForwardIterator first, ForwardIterator last, OutputIterator0 out0, OutputIterator1 out1, UnaryPredicate pred, UnaryFunction0 function0) {
    while (first != last) {
        if (pred(first)) {
            *out1 = function0(first);
            ++out1;
        } else {
            *out0 = function0(first);
            ++out0;
        }
        ++first;
    }
    return {out0, out1};
}


template<typename ForwardIterator, typename OutputIterator0, typename OutputIterator1, typename UnaryPredicate, typename UnaryFunction0, typename UnaryFunction1>
inline
std::pair<OutputIterator0, OutputIterator1> partition_transform_position(ForwardIterator first, ForwardIterator last, OutputIterator0 out0, OutputIterator1 out1, UnaryPredicate pred, UnaryFunction0 function0, UnaryFunction1 function1) {
    while (first != last) {
        if (pred(first)) {
            *out1 = function1(first);
            ++out1;
        } else {
            *out0 = function0(first);
            ++out0;
        }
        ++first;
    }
    return {out0, out1};
}

} // namespace v1
} // namespace sgl
