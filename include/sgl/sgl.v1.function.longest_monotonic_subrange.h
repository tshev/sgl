#pragma once

namespace sgl {
namespace v1 {

template<typename It>
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
            ++fast;
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
            ++fast;
        }
        ++first;
    }

    if (r_n < c_n) {
        return {c_first, c_last};
    }

    return {r_first, r_last};
}


template<typename It, typename Relation>
std::pair<It, It> longest_monotonic_subrange(It first, It last, Relation r) {
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
            ++fast;
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
            ++fast;
        }
        ++first;
    }

    if (r_n < c_n) {
        return {c_first, c_last};
    }

    return {r_first, r_last};
}

}
}
