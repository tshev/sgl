#include "sgl.h"
#include <map>
#include <algorithm>
#include <memory>
#include "matrix0.h"
#include "matrix1.h"

template<typename M>
M mm0(M a, M b) {
    typedef typename M::value_type T;

    size_t m = a.rows();
    size_t n = a.cols();
    size_t l = b.cols();
    M c(m, l);
    for (size_t i = 0; i != m; ++i) {
        for (size_t j = 0; j != n; ++j) {
            for (size_t k = 0; k != l; ++k) {
                c(i, k) += a(i, j) * b(j, k);
            }
        }
    }
    return c;
}
template<typename M>
size_t matrix_bench(size_t m, size_t n, size_t k) {
    M a(m, n, 1);
    M b(n, k, 1);
    std::cout << "BN:\n";
    sgl::stopwatch_nanoseconds sw;
    M c = mm0(a, b);
    size_t r = sw.stop();
    volatile auto sum = sgl::accumulate(std::begin(c), std::end(c), 0);
    std::cout << "S = " << sum << std::endl;
    return r;
}

int main() {
    size_t m = 1000;
    size_t n = 2000;
    size_t k = 3000;
    std::cout << matrix_bench<sgl::matrix0<int>>(m, n, k) << std::endl;
    std::cout << matrix_bench<sgl::matrix1<int>>(m, n, k) << std::endl;

}
