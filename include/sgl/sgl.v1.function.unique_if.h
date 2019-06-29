#pragma once
namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename Predicate0, typename Predicate1>
inline
ForwardIterator unique_if(ForwardIterator first, ForwardIterator last, Predicate0 eq, Predicate1 predicate1) {
    if (first == last)
        return last;

    ForwardIterator slow = first;
    ++first;
    while (first != last) {
        if (eq(*slow, *first) && predicate(*first)) {
           ++first;
        } else {
            ++slow;
            *slow = *first;
            ++first;
        }
    }
    ++slow;
    return slow;
}

} // namespace v1
} // namespace sgl
