#pragma once
namespace sgl {
namespace v1 {

template<typename RandomAccessIterator>
void sort_subrange(RandomAccessIterator first, RandomAccessIterator f0, RandomAccessIterator l0, RandomAccessIterator last) {
    // Precondition: $\func{weak\_strict\_ordering}(<)$
    if (f0 == l0) {
        return;
    }
    if (first != f0) {
        std::nth_element(first, f0, last);
        ++f0;
    }
    std::nth_element(f0, l0, last);
    std::sort(f0, l0);
}


template<typename RandomAccessIterator, typename Relation>
void sort_subrange(RandomAccessIterator first, RandomAccessIterator f0, RandomAccessIterator l0, RandomAccessIterator last, Relation r) {
    // Precondition: $\func{weak\_strict\_ordering}(r)$
    if (f0 == l0) {
        return;
    }
    if (first != f0) {
        std::nth_element(first, f0, last, r);
        ++f0;
    }
    std::nth_element(f0, l0, last, r);
    std::sort(f0, l0, r);
}

} // namespace v1
} // namespace sgl
