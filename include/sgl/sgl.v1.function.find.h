#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename T>
inline
ForwardIterator find(ForwardIterator first, ForwardIterator last, const T& x) {
    while (first != last && !(*first == x)) {
        ++first;
    }
    return first;
}


template<typename ForwardIterator, typename T, typename Equality>
inline
ForwardIterator find(ForwardIterator first, ForwardIterator last, const T& x, Equality pred) {
    while (first != last && !pred(*first, x)) {
        ++first;
    }
    return first;
}

template<typename ForwardIterator, typename T, typename N>
inline
typename std::enable_if<std::is_arithmetic<N>::value, ForwardIterator>::type
find(ForwardIterator first, ForwardIterator last, const T& x, N& n) {
    while (first != last && !(*first == x)) {
        ++first;
        ++n;
    }
    return first;
}

template<typename ForwardIterator, typename T, typename Equality, typename N>
inline
typename std::enable_if<std::is_arithmetic<N>::value, ForwardIterator>::type
find(ForwardIterator first, ForwardIterator last, const T& x, Equality eq, N& n) {
    while (first != last && !eq(*first, x)) {
        ++first;
        ++n;
    }
    return first;
}

} // namespace v1
} // namespace sgl
