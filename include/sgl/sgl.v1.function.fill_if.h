#pragma once
namespace sgl {
namespace v1 {

template<typename ForwardaIterator, typename T, typename UnaryPredicate>
inline
void fill_if(ForwardaIterator first, ForwardaIterator last, const T& value, UnaryPredicate pred) {
    while (first != last) {
        if (pred(*first)) {
            *first = value;
        }
        ++first;
    }
}

} // namespace v1
} // namespace sgl
