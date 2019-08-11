#include <cassert>
#include <algorithm>
#include <random> 
#include <sgl/macros.h>
#include <sgl/sgl.v1.function.all.h>
#include <sgl/sgl.v1.function.generate.h>
#include <sgl/sgl.v1.function.begin.h>
#include <sgl/sgl.v1.function.end.h>
#include <sgl/sgl.v1.function.advance_to_middle.h>
#include <sgl/sgl.v1.function.lower_bound.h>

namespace sgl {
namespace v1 {
namespace test {
namespace function_lower_bound {

void test0() {
    int out_of_range_val = 100;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    assert(sgl::v1::lower_bound(a, a, out_of_range_val) == a);
    assert(sgl::v1::lower_bound(a, a, 2) == a);
    assert(sgl::v1::lower_bound(a, a + 1, 1) == a);
    assert(sgl::v1::lower_bound(a, a + 1, out_of_range_val) == a + 1);
    assert(sgl::v1::lower_bound(a, a + 2, 0) == a);
    assert(sgl::v1::lower_bound(a, a + 2, 1) == a);
    assert(sgl::v1::lower_bound(a, a + 2, 2) == a + 1);
    assert(sgl::v1::lower_bound(a, a + 2, out_of_range_val) == a + 2);
}


void test1() {
    constexpr size_t n = 100;
    int a[n];
    constexpr size_t repeat_n = 10;
    for (size_t i = 0; i < repeat_n; ++i) {
        for (size_t k = 0; k < n; ++k) {
            auto first = sgl::v1::begin(a);
            auto last = a + k;
            std::random_device rd;
            sgl::v1::generate(first, last, [&]() { return rd(); });
            std::sort(first, last);
            auto correct_invariant = sgl::v1::all(first, last, [=](auto x0) {
                auto position = sgl::v1::lower_bound(first, last, x0);
                return sgl::v1::all(first, position, [x0](auto x1) { return x1 < x0; }) && sgl::v1::all(position, last, [x0](auto x1) { return x1 >= x0; });
            });
            assert(correct_invariant);
        }
    }
}

void test2() {
    constexpr size_t n = 100;
    int a[n];
    constexpr size_t repeat_n = 10;
    for (size_t i = 0; i < repeat_n; ++i) {
        for (size_t k = 0; k < n; ++k) {
            auto first = sgl::v1::begin(a);
            auto last = a + k;
            std::random_device rd;
            sgl::v1::generate(first, last, [&]() { return rd() % 10; });
            std::sort(first, last);
            auto correct_invariant = sgl::v1::all(first, last, [=](auto x0) {
                auto position = sgl::v1::lower_bound(first, last, x0);
                return sgl::v1::all(first, position, [x0](auto x1) { return x1 < x0; }) && sgl::v1::all(position, last, [x0](auto x1) { return x1 >= x0; });
            });
            assert(correct_invariant);
        }
    }
}


} // namespace function_lower_bound
} // namespace test
} // namespace v1
} // namespace sgl

int main() {
    sgl::v1::test::function_lower_bound::test0();
    sgl::v1::test::function_lower_bound::test1();
    sgl::v1::test::function_lower_bound::test2();
}
