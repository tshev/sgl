#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator0, typename N, typename F>
void for_each_chunk_n(ForwardIterator0 first0, N length, N n_chunks, F func) {
    N rem = length % n_chunks;
    N step1 = length / n_chunks;
    N step0 = step1 + 1;

    N n0 = rem * step0;
    N n1 = length - n0;
    while (n0 > 0) {
        func(first0, step0);
        std::advance(first0, step0);
        n0 -= step0;
    }

    while (n1 > 0) {
        func(first0, step1);
        std::advance(first0, step1);
        n1 -= step1;
    }
}

template<typename ForwardIterator0, typename ForwardIterator1, typename N, typename F>
void for_each_chunk_n(ForwardIterator0 first0, N length, ForwardIterator1 first1, N n_chunks, F func) {
    N rem = length % n_chunks;
    N step1 = length / n_chunks;
    N step0 = step1 + 1;

    N n0 = rem * step0;
    N n1 = length - n0;
    while (n0 > 0) {
        func(first0, step0, first1);
        std::advance(first0, step0);
        std::advance(first1, step0);
        n0 -= step0;
    }

    while (n1 > 0) {
        func(first0, step1, first1);
        std::advance(first0, step1);
        std::advance(first1, step1);
        n1 -= step1;
    }
}

template<typename ForwardIterator0, typename ForwardIterator1, typename ForwardIterator2, typename N, typename F>
void for_each_chunk_n(ForwardIterator0 first0, N length, ForwardIterator1 first1, ForwardIterator2 first2, N n_chunks, F func) {
    N rem = length % n_chunks;
    N step1 = length / n_chunks;
    N step0 = step1 + 1;

    N n0 = rem * step0;
    N n1 = length - n0;
    while (n0 > 0) {
        func(first0, step0, first1, first2);
        std::advance(first0, step0);
        std::advance(first1, step0);
        std::advance(first2, step0);
        n0 -= step0;
    }

    while (n1 > 0) {
        func(first0, step1, first1, first2);
        std::advance(first0, step1);
        std::advance(first1, step1);
        std::advance(first2, step1);
        n1 -= step1;
    }
}

} // namespace v1
} // namespace sgl
