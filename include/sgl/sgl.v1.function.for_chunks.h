#pragma once

namespace sgl {
namespace v1 {

template<typename N, typename F>
void for_chunks(N length, N n_threads, F func) {
    // TODO: FIXME
    N rem = length % n_threads;
    N step1 = length / n_threads;
    N step0 = step1 + 1;

    N n0 = rem * step0;
    for (N i = 0; i < n0; i += step0) {
        func(i, i + step0);
    }

    while (n0 < length) {
        func(n0, n0 + step1);
        n0 += step1;
    }
}

}
}
