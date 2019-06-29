#include <iostream>
#include <algorithm>
#include <memory>
#include "sgl.h"

struct pp {
    int first;
    int second;
};

int main() {
    size_t n = 1000000000;
    std::vector<uint32_t> values(n);
    sgl::v1::generate_bm(std::begin(values), std::end(values));

    sgl::v1::sw stopwatch;
    size_t bench_n = 10;
    sgl::v1::array<size_t> t0(bench_n);
    sgl::v1::array<size_t> t1(bench_n);

    for (size_t j = 0; j != bench_n; ++j) {
        stopwatch.start();
        {
            std::vector<int> result(n);
            /*
            for (size_t i = 0; i != n; ++i) {
                result[i] = values[i];
            }
            */
        }
        t0[j] = stopwatch.stop();

        stopwatch.start();
        {
            sgl::v1::array<int> result(n);
            for (size_t i = 0; i != n; ++i) {
                result[i] = values[i];
            }
        }
        t1[j] = stopwatch.stop();
    }

    size_t avg0 = sgl::v1::accumulate(std::begin(t0), std::end(t0), size_t(0)) / t0.size();
    size_t avg1 = sgl::v1::accumulate(std::begin(t1), std::end(t1), size_t(0)) / t1.size();

    std::nth_element(std::begin(t0), std::begin(t0) + t0.size() / 2, std::end(t0));
    std::nth_element(std::begin(t1), std::begin(t1) + t1.size() / 2, std::end(t1));

    size_t m0 = t0[t0.size() / 2];
    size_t m1 = t1[t1.size() / 2];

    size_t dev0 = std::sqrt(sgl::v1::accumulate(std::begin(t0), std::end(t0), size_t(0), sgl::v1::square_deviation<size_t>(avg0)) / t0.size());
    size_t dev1 = std::sqrt(sgl::v1::accumulate(std::begin(t1), std::end(t1), size_t(0), sgl::v1::square_deviation<size_t>(avg1)) / t1.size());

    std::cout << "median" << "\t\t" << "avg" << "\t\t" << "dev" << std::endl;
    std::cout << m0 << "\t" << avg0 << "\t" << dev0 << std::endl;
    std::cout << m1 << "\t" << avg1 << "\t" << dev1 << std::endl;
}
