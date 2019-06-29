#pragma once
namespace sgl {
namespace v1 {

template<typename ForwardIterator>
void replace_if(ForwardIterator first, ForwardIterator last, const typename std::iterator_traits<ForwardIterator>::value_type& previous_value, const typename std::iterator_traits<ForwardIterator>::value_type& new_value) {
    while (first != last) {
        if (*first == previous_value) {
            *first = new_value;
        }
        ++first;
    }
}

template<typename ForwardIterator, typename Predicate>
void replace_if(ForwardIterator first, ForwardIterator last, const typename std::iterator_traits<ForwardIterator>::value_type& previous_value, const typename std::iterator_traits<ForwardIterator>::value_type& new_value, Predicate eq) {
    while (first != last) {
        if (eq(*first, previous_value)) {
            *first = new_value;
        }
        ++first;
    }
}



} // namespace v1
} // namespace sgl
