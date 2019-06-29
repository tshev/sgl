#pragma once
namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename Predicate0>
inline
ForwardIterator unique(ForwardIterator first, ForwardIterator last, Predicate0 eq, const typename std::iterator_traits<ForwardIterator>::value_type& x) {
    if (first == last)
        return last;

    ForwardIterator result = first;
    ++first;
    while (first != last) {
        if (eq(*result, *first) && *first == x) {
           ++first;
        } else {
            ++result;
            *result = *first;
            ++first;
        }

    }
    ++result;
    return result;
}

} // namespace v1
} // namespace sgl
