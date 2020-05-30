#include <iostream>
#include <immintrin.h>
#include <type_traits>
#include <sgl/sgl.h>
#include <benchmark/benchmark.h>

// constexpr const size_t medium_size_array = 1024ull * 1024ull * 8ull;
constexpr const size_t medium_size_array = 1024ull;
constexpr const size_t extected_needle_position = medium_size_array - 1;
constexpr const int needle = 0;

static void BM_sgl__v1__find(benchmark::State& state) {
    sgl::v1::array<int> values(medium_size_array, 0xffff);
    values[extected_needle_position] = needle;
    for (auto _ : state) {
        auto position = sgl::v1::find(sgl::v1::simd_tag<false, sgl::v1::simd_vector<int, 128>>(), values.begin(), values.end(), needle) - values.begin();
        assert(extected_needle_position == position);
        
    }
}

static void BM_std__find(benchmark::State& state) {
    sgl::v1::array<int> values(medium_size_array, 0xffff);
    values[extected_needle_position] = needle;
    for (auto _ : state) {
        auto position = std::find(values.begin(), values.end(), needle) - values.begin();
        assert(position == extected_needle_position);
    }
}

static void BM_std__lower_bound(benchmark::State& state) {
    sgl::v1::array<int> values(medium_size_array, 0xffff);
    values[extected_needle_position] = needle;
    sgl::v1::fill(values.begin(), values.begin() + extected_needle_position, needle - 1);
    for (auto _ : state) {
        auto position = std::lower_bound(values.begin(), values.end(), needle) - values.begin();
        assert(position == extected_needle_position);
    }
}

/*
int main() {
    int a[] = {1, 2, 1, 1};
    find(sgl::v1::simd_tag<false, sgl::v1::simd_vector<int, 128>>(), a, a + 4, 1);
}
*/

BENCHMARK(BM_sgl__v1__find);
BENCHMARK(BM_std__find);
BENCHMARK(BM_std__lower_bound);
BENCHMARK_MAIN();
