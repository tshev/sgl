#pragma once

namespace sgl {
namespace v1 {

template<typename RandomAccessIterator>
RandomAccessIterator median_element(RandomAccessIterator first, RandomAccessIterator last) {
    auto middle = first + (last - first) / 2ul;
    std::nth_element(first, middle, last);
    return middle; 
}


template<typename RandomAccessIterator, typename Predicate>
RandomAccessIterator median_element(RandomAccessIterator first, RandomAccessIterator last, Predicate pred) {
    auto middle = first + (last - first) / 2ul;
    std::nth_element(first, middle, last, pred);
    return middle; 
}

} // namespace v1
} // namespace sgl
