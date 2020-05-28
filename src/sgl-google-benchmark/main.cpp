#include <benchmark/benchmark.h>
#include <sgl/sgl.h>

constexpr const size_t medium_size_array = 1000ull * 1000ull * 10ull;


static void BM_std__fill__0(benchmark::State& state) {
    sgl::v1::array<int> values(medium_size_array);
    int value = 0xFFFFFFFF;
    for (auto _ : state) {
        std::fill(std::begin(values), std::end(values), value);
    }
}

static void BM_sgl__v1__fill__0(benchmark::State& state) {
    size_t n = 1000ull * 1000ull * 10ul;
    sgl::v1::array<int> values(medium_size_array);
    int value = 0xFFFFFFFF;
    for (auto _ : state) {
        sgl::v1::fill(std::begin(values), std::end(values), value);
    }
}

static void BM_sgl__v1__fill_simd__0(benchmark::State& state) {
    size_t n = 1000ull * 1000ull * 10ul;
    sgl::v1::array<int> values(medium_size_array);
    int value = 0xFFFFFFFF;
    for (auto _ : state) {
        sgl::v1::fill(sgl::v1::simd_tag<false>(), std::begin(values), std::end(values), value);
    }
}



static void BM_std__copy__0(benchmark::State& state) {
    sgl::v1::array<int> values(medium_size_array);
    sgl::v1::array<int> out(medium_size_array);
    for (auto _ : state) {
        std::copy(std::begin(values), std::end(values), std::begin(out));
    }
}

static void BM_sgl__v1__copy__0(benchmark::State& state) {
    size_t n = 1000ull * 1000ull * 10ul;
    sgl::v1::array<int> values(medium_size_array);
    sgl::v1::array<int> out(medium_size_array);
    for (auto _ : state) {
        sgl::v1::copy(std::begin(values), std::end(values), std::begin(out));
    }
    static_assert(!sgl::v1::is_nothrow_algorithm<int, int*, std::back_insert_iterator<std::vector<int>>>::value);
    static_assert(!sgl::v1::is_nothrow_algorithm<std::string, std::string*>::value);
}




BENCHMARK(BM_std__fill__0);
BENCHMARK(BM_sgl__v1__fill__0);
BENCHMARK(BM_sgl__v1__fill_simd__0);
BENCHMARK(BM_std__copy__0);
BENCHMARK(BM_sgl__v1__copy__0);
BENCHMARK_MAIN();
