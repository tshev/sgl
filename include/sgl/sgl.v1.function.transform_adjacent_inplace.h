#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename BinaryFunction>
ForwardIterator transform_adjacent_inplace(ForwardIterator first, ForwardIterator last, BinaryFunction f) {
    // 1 2 3 ----> 3 5 3
    //                ^
    if (first == last) {
        return first;
    }
    auto fast = first;
    ++fast;
    while (fast != last) {
        *first = f(*first, *fast);
        ++first;
        ++fast;
    }
    return first;
}

} // namespace v1
} // namespace sgl
