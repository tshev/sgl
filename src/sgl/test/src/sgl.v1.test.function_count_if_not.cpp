#include <cassert>
#include <sgl/macros.h>

// IncludeGroup(
#include <sgl/macros.h>
#include <sgl/sgl.v1.function.count_if_not.h>
// )

namespace sgl {
namespace v1 {
namespace test {

namespace function_count_if_not {

void test0() {
    int a[] = {1, 2, 3, 4, 5};
    assert(sgl::v1::count_if_not(a, a + 5, [](int x) { return x > 0; }) == 0l);
    assert(sgl::v1::count_if_not(a, a + 5, 0ul, [](int x) { return x > 0; }) == 0l);
    assert(sgl::v1::count_if_not(a, a + 5, 1ul, [](int x) { return x > 0; }) == 1ul);
    assert(sgl::v1::count_if_not(a, a + 5, a, 1ul, [](int x, int y) { return x > 1 && x == y; }) == 2ul);
    assert(sgl::v1::count_if_not(a, a + 5, a, a, 1ul, [](int x, int y, int z) { return x > 1 && x == y && y == z; }) == 2ul);
}

} // namespace function_count_if_not

} // namespace test
} // namespace v1
} // namespace sgl



int main() {
    sgl::v1::test::function_count_if_not::test0();
}
