#include <cassert>
#include <algorithm>
#include <list>
#include <vector>
#include <sgl/sgl.v1.function.swap_ranges.h>

namespace sgl {
namespace v1 {
namespace test {
namespace function_swap_ranges {

template<typename T0, typename T1>
void test() {
    T0 array0 = {1, 2, 3, 4, 5};
    T1 array1 = {6, 7};

    auto first0 = std::begin(array0);
    auto last0 = std::end(array0);
    auto first1 = std::begin(array1);
    auto last1 = std::end(array1);
    {
        auto border = sgl::v1::swap_ranges(first0, last0, first1, last1);
        assert(*first0 == 6);
        assert(*std::next(first0, 1) == 7);
        assert(*first1 == 1);
        assert(*std::next(first1, 1) == 2);
        assert(border.first == std::next(first0, 2));
        assert(border.second == last1);
    }
    {
        auto border = sgl::v1::swap_ranges(first1, last1, first0, last0);
        assert(*first0 == 1);
        assert(*std::next(first0, 1) == 2);
        assert(*first1 == 6);
        assert(*std::next(first1, 1) == 7);
        assert(border.first == last1);
        assert(border.second == std::next(first0, 2));
    }
} 

void test0() {
    test<int[], int[]>();
    test<int[], std::list<int>>();
    test<std::list<int>, int[]>();
    test<std::list<int>, std::list<int>>();
    test<std::vector<int>, int[]>();
}

} // namespace function_swap_ranges
} // namespace test
} // namespace v1
} // namespace sgl

int main() {
    sgl::v1::test::function_swap_ranges::test0();
}
