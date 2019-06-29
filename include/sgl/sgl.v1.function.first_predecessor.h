#pragma once
namespace sgl {
namespace v1 {

template<typename ForwardIterator>
ForwardIterator first_predecessor(ForwardIterator first, ForwardIterator last) {
    if (first == last) { return last; }
    ForwardIterator slow = first;
    ++first;
    while (first != last) {
        ++first;
        ++slow;
    }
    return slow;
}

} // namespace v1
} // namespace sgl
