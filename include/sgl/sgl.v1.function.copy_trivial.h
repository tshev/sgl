#pragma once
#include <immintrin.h>
namespace sgl {
namespace v1 {

template<typename ForwardIterator0, typename ForwardIterator1>
ForwardIterator1 copy_trivial(ForwardIterator0 first, ForwardIterator0 last, ForwardIterator1 out) {
    auto f0 = (char*)first;
    auto l0 = (char*)last;
    auto o0 = (char*)out;
    size_t n = l0 - f0;
    size_t step = 32;
    size_t m = n / step;
    auto l1 = (char*)first + m * step;
    
    while (f0 != l1) {
        auto loaded =  _mm256_loadu_pd((double*)f0);
        _mm256_storeu_pd((double*)o0, loaded);
        f0 += step; 
        o0 += step;
    }
    while (f0 != l0) {
        *o0 = *f0;
        ++f0;
        ++o0;
    }
    return out + n;
}

} // namespace v1
} // namespace sgl
