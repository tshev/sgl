#pragma once
namespace sgl {
namespace v1 {

template<typename ForwardIterator>
inline
size_t count_classes(ForwardIterator first, ForwardIterator last) {
    if (first == last) { return 0ul; }
    return *std::max_element(first, last) + 1ul;
}

} // namespace v1
} // namespace sgl
