#pragma once
namespace sgl {
namespace v1 {

template<typename ForwardIterator0, typename ForwardIterator1>
inline
std::pair<ForwardIterator0, ForwardIterator1> gcp(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1, ForwardIterator1 last1) {
    while (first0 != last0 && first1 != last1 && *first0 == *first1) {
        ++first0;
        ++first1;
    }
    return {first0, first1};
}


template<typename ForwardIterator0, typename ForwardIterator1, typename BinaryPredicate>
inline
std::pair<ForwardIterator0, ForwardIterator1> gcp(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1, ForwardIterator1 last1, BinaryPredicate pred) {
    while (first0 != last0 && first1 != last1 && pred(*first0, *first1)) {
        ++first0;
        ++first1;
    }
    return {first0, first1};
}

}
} // namespace sgl
