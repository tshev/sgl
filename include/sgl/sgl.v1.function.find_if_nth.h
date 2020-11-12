#pragma once

namespace sgl {
namespace v1 {

template<typename It, typename Predicate, typename N>
inline
It find_if_nth(It first, It last, Predicate pred, N n) {
    size_t i = 0;
    while (first != last) {
        if (pred(*first)) {
            ++i;
        }
        if (i == n) {
            return first;
        }
        ++first;
    }
    return first;
}

} // namespace v1
} // namespace sgl
