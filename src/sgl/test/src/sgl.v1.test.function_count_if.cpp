#include <cassert>
#include <sgl/macros.h>

// IncludeGroup(
#include <sgl/macros.h>
#include <sgl/sgl.v1.function.count_if.h>
// )

namespace sgl {
namespace v1 {
namespace test {

namespace function_count_if {

void test0() {
    int a[] = {1, 2, 3, 4, 5};
    assert(sgl::v1::count_if(a, a + 5, [](int x) { return x > 0; }) == 5l);
    assert(sgl::v1::count_if(a, a + 5, 0ul, [](int x) { return x > 0; }) == 5ul);
    assert(sgl::v1::count_if(a, a + 5, 1ul, [](int x) { return x > 0; }) == 6ul);
    assert(sgl::v1::count_if(a, a + 5, a, 1ul, [](int x, int y) { return x > 1 && x == y; }) == 5ul);
    assert(sgl::v1::count_if(a, a + 5, a, a, 1ul, [](int x, int y, int z) { return x > 1 && x == y && y == z; }) == 5ul);
}

} // namespace function_count_if

} // namespace test
} // namespace v1
} // namespace sgl

int main() {
    sgl::v1::test::function_count_if::test0();
}
