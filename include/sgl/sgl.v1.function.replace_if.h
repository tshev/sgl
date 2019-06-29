#pragma once
namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename Predicate, typename T>
void replace_if(ForwardIterator first, ForwardIterator last, Predicate pred, const T& x) {
    while (first != last) {
        if (pred(*first)) {
            *first = x;
        }
        ++first;
    }
}

} // namespace v1
} // namespace sgl
