#pragma once
namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename Func>
inline
void for_each_split(ForwardIterator first, ForwardIterator last, const SGLValueType(ForwardIterator)& value, Func func) {
    while (first != last) {
        ForwardIterator next = sgl::v1::find(first, last, value);
        func(first, next);
        first = next;
        if (first != last) {
            ++first;
        }
    }
}




template <typename ForwardIterator, typename Func, typename Hash = std::hash<SGLValueType(ForwardIterator)>, typename BinaryPredicate = std::equal_to<SGLValueType(ForwardIterator)> >
inline
void for_each_split(ForwardIterator first, ForwardIterator last, const std::boyer_moore_searcher<ForwardIterator, Hash, BinaryPredicate>& searcher, Func func, size_t step) {
    while (first != last) {
        ForwardIterator next = std::search(first, last, searcher);
        func(first, next);
        first = next;
        if (first != last) {
            sgl::v1::advance(first, step);
        }
    }
}

} // namespace v1
} // namespace sgl
