#pragma once

namespace sgl {
namespace v1 {

template<typename RandomAccessIterator>
void advance_to_middle(RandomAccessIterator& first, RandomAccessIterator last, std::random_access_iterator_tag) {
    first += (last - first) / 2ul;
}

template<typename ForwardIterator>
inline
void advance_to_middle(ForwardIterator& first, ForwardIterator last, std::forward_iterator_tag) {
    ForwardIterator fast = first;
    if (fast == last) {
        return;
    }
    ++fast;
    while (fast != last) {
        ++first;
        ++fast;
        if (fast == last) {
            return;
        }
        ++fast;
    }
}


template<typename ForwardIterator>
inline
void advance_to_middle(ForwardIterator& first, ForwardIterator last) {
    typedef typename std::iterator_traits<ForwardIterator>::iterator_category iterator_category;
    sgl::v1::advance_to_middle(first, last, iterator_category{}); 
}



} // namespace v1
} // namespace sgl
