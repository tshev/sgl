#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename OutputIterator, typename BinaryFunction>
OutputIterator transform_adjacent(ForwardIterator first, ForwardIterator last, OutputIterator out, BinaryFunction f) {
    // 1 2 3 ----> 3 5
    //                ^
    if (first == last) {
        return out;
    }
    auto fast = first;
    ++fast;
    while (fast != last) {
        *out = f(*first, *fast);
        ++out;
        ++first;
        ++fast;
    }
    return out;
}

} // namespace v1
} // namespace sgl
