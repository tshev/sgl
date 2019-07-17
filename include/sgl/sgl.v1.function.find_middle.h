#pragma once

namespace sgl {
namespace v1 {

template<typename RandomAccessIterator>
inline
RandomAccessIterator find_middle(RandomAccessIterator first, RandomAccessIterator last, std::random_access_iterator_tag) {
    first += (last - first) / 2ul;
    return first;
}

template<typename ForwardIterator>
inline
ForwardIterator find_middle(ForwardIterator first, ForwardIterator last, std::forward_iterator_tag) {
    if (first == last) {
        return first;
    }
    ForwardIterator fast = first;
    ++fast;
    while (fast != last) {
        ++first;
        ++fast;
        if (fast == last) {
            return first;
        }
        ++fast;
    }
    return first;
}


template<typename ForwardIterator>
inline
ForwardIterator find_middle(ForwardIterator& first, ForwardIterator last) {
    typedef typename std::iterator_traits<ForwardIterator>::iterator_category iterator_category;
    return sgl::v1::find_middle(first, last, iterator_category{}); 
}

} // namespace v1
} // namespace sgl
