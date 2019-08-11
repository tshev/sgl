#include <cassert>
#include <algorithm>
#include <random> 
#include <sgl/macros.h>
#include <sgl/sgl.v1.function.all.h>
#include <sgl/sgl.v1.function.find_adjacent.h>
#include <sgl/sgl.v1.function.advance.h>
#include <sgl/sgl.v1.function.generate.h>
#include <sgl/sgl.v1.function.begin.h>
#include <sgl/sgl.v1.function.end.h>
#include <sgl/sgl.v1.function.advance_to_middle.h>
#include <sgl/sgl.v1.function.lower_bound.h>
#include <sgl/sgl.v1.function.upper_bound.h>
#include <sgl/sgl.v1.function.equal_range.h>

namespace sgl {
namespace v1 {
namespace test {
namespace function_equal_range {

void test0() {
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
                auto [left, right] = sgl::v1::equal_range(first, last, x0);
                return sgl::v1::all(first, left, [x0](auto x1) { return x1 < x0; }) && sgl::v1::all(left, last, [x0](auto x1) { return x1 >= x0; }) &&
                       sgl::v1::all(first, right, [x0](auto x1) { return x1 <= x0; }) && sgl::v1::all(right, last, [x0](auto x1) { return x1 > x0; }) && 
                       sgl::v1::find_adjacent(left, right, [](auto x, auto y) { return x < y || y < x; }) == right;
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
                auto [left, right] = sgl::v1::equal_range(first, last, x0);
                return sgl::v1::all(first, left, [x0](auto x1) { return x1 < x0; }) && sgl::v1::all(left, last, [x0](auto x1) { return x1 >= x0; }) &&
                       sgl::v1::all(first, right, [x0](auto x1) { return x1 <= x0; }) && sgl::v1::all(right, last, [x0](auto x1) { return x1 > x0; }) && 
                       sgl::v1::find_adjacent(left, right, [](auto x, auto y) { return x < y || y < x; }) == right;
            });
            assert(correct_invariant);
        }
    }
}


} // namespace function_equal_range
} // namespace test
} // namespace v1
} // namespace sgl

int main() {
    sgl::v1::test::function_equal_range::test0();
    sgl::v1::test::function_equal_range::test1();
    sgl::v1::test::function_equal_range::test2();
}
