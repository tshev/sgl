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
    sgl::v1::array<int> values(medium_size_array);
    int value = 0xFFFFFFFF;
    for (auto _ : state) {
        sgl::v1::fill(std::begin(values), std::end(values), value);
    }
}

static void BM_sgl__v1__fill_simd128__0(benchmark::State& state) {
    sgl::v1::array<int> values(medium_size_array);
    int value = 0xFFFFFFFF;
    for (auto _ : state) {
        sgl::v1::fill(sgl::v1::simd_tag<false, sgl::v1::simd_vector<int, 128>>(), std::begin(values), std::end(values), value);
    }
    assert(std::all_of(std::begin(values), std::end(values), [&](const auto& x) { if (x != value) { std::cout << (&x - std::begin(values)) << std::endl;} return x == value; }));
}

static void BM_sgl__v1__fill_simd256__0(benchmark::State& state) {
    sgl::v1::array<int> values(medium_size_array);
    int value = 0xFFFFFFFF;
    for (auto _ : state) {
        sgl::v1::fill(sgl::v1::simd_tag<false, sgl::v1::simd_vector<int, 256>>(), std::begin(values), std::end(values), value);
    }
    assert(std::all_of(std::begin(values), std::end(values), [&](const auto& x) { if (x != value) { std::cout << (&x - std::begin(values)) << std::endl;} return x == value; }));
}



static void BM_std__copy__0(benchmark::State& state) {
    sgl::v1::array<int> values(medium_size_array);
    sgl::v1::array<int> out(medium_size_array);
    for (auto _ : state) {
        std::copy(std::begin(values), std::end(values), std::begin(out));
    }
}

static void BM_sgl__v1__copy__0(benchmark::State& state) {
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
BENCHMARK(BM_sgl__v1__fill_simd128__0);
BENCHMARK(BM_sgl__v1__fill_simd256__0);
BENCHMARK(BM_std__copy__0);
BENCHMARK(BM_sgl__v1__copy__0);
BENCHMARK_MAIN();
