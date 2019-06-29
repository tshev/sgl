#pragma once
namespace sgl {
namespace v1 {

template<typename RandomAccessIterator>
void sort_partial(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last) {
    std::nth_element(first, middle, last);
    std::sort(first, middle);
}

template<typename RandomAccessIterator, typename Relation>
void sort_partial(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last, Relation r) {
    std::nth_element(first, middle, last, r);
    std::sort(first, middle, r);
}


} // namespace v1
} // namespace sgl
