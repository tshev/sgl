#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename S>
void generate_bm(ForwardIterator first, ForwardIterator last, const S& s) {
    std::mt19937 gen(s);
    while (first != last) {
        *first = gen();
        ++first;
    }
}


template<typename ForwardIterator, typename S>
void generate_bm(ForwardIterator first, ForwardIterator last, S& s) {
    std::mt19937 gen(s);
    while (first != last) {
        *first = gen();
        ++first;
    }
}


template<typename ForwardIterator>
void generate_bm(ForwardIterator first, ForwardIterator last) {
    generate_bm(first, last, std::distance(first, last));
}


} // namespace v1
} // namespace sgl
