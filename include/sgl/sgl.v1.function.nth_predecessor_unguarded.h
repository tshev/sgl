#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename T>
ForwardIterator nth_predecessor_unguarded(ForwardIterator first, ForwardIterator last, T n) {
    ForwardIterator slow = first;
    while (first != last) {
        ++first;
        --n;
        if (n == 0) {
            while (first != last) {
                ++first;
                ++slow;
            }
            return slow;
        }
    }
    return last;
}

} // namespace v1
} // namespace sgl
