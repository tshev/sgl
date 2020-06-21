#pragma onace

namespace sgl {
namespace v1 {

template <typename It>
inline
std::pair<It, It> longest_monotonic_subrange(It first, It last) {
    if (first == last) {
        return {first, last};
    }
    auto fast = first;
    ++fast;
    auto r_first = first;
    auto r_last = first;
    size_t r_n = 0;

    auto c_first = first;
    auto c_last = first;
    size_t c_n = 0;

    while (fast != last) {
        if (*first < *fast) {
            c_last = fast;
            ++c_n;
        } else {
            if (r_n < c_n) {
                r_first = c_first;
                r_last = c_last;
                r_n = c_n;
            }
            c_first = fast;
            c_last = fast;
            c_n = 0;
        }
        ++first;
        ++fast;
    }
    return {r_first, r_last};
}

template <typename It, typename R>
inline
std::pair<It, It> longest_monotonic_subrange(It first, It last, R r) {
    if (first == last) {
        return {first, last};
    }
    auto fast = first;
    ++fast;
    auto r_first = first;
    auto r_last = first;
    size_t r_n = 0;

    auto c_first = first;
    auto c_last = first;
    size_t c_n = 0;

    while (fast != last) {
        if (r(*first, *fast)) {
            c_last = fast;
            ++c_n;
        } else {
            if (r_n < c_n) {
                r_first = c_first;
                r_last = c_last;
                r_n = c_n;
            }
            c_first = fast;
            c_last = fast;
            c_n = 0;
        }
        ++first;
        ++fast;
    }
    return {r_first, r_last};
}

} // namespace v1
} // namespace sgl
