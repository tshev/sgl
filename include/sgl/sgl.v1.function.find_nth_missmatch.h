#pragma once
namespace sgl {
namespace v1 {
template<typename It, typename T>
inline
std::pair<It, size_t> find_nth_missmatch(It first, It last, const T& x, size_t n) {
    size_t expected = n;

    while (first != last) {
        if (*first != x) {
            --n;
        }
        if (n == 0) {
            return {first, expected};
        }
        ++first;
    }

    return {first, expected - n};
} 

template<typename It, typename T, typename Eq>
inline
std::pair<It, size_t> find_nth_missmatch(It first, It last, const T& x, size_t n, Eq eq) {
    size_t expected = n;

    while (first != last) {
        if (!eq(*first, x)) {
            --n;
        }
        if (n == 0) {
            return {first, expected};
        }
        ++first;
    }

    return {first, expected - n};
} 

} // namespace v1
} // namespace sgl
