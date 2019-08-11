#include <cassert>
#include <type_traits>
#include <sgl/macros.h>

// IncludeGroup(
#include <sgl/macros.h>
#include <sgl/sgl.v1.function.count_equal.h>
// )

namespace sgl {
namespace v1 {
namespace test {

namespace function_count_equal {

void test0() {
    int a[] = {1, 2, 3, 4, 5};
    assert(sgl::v1::count_equal(a, a + 5, a) == 5l);
    assert(sgl::v1::count_equal(a, a + 4, a + 1) == 0l);
    assert(sgl::v1::count_equal(a, a + 5, a, 1l) == 6l);
    assert(sgl::v1::count_equal(a, a + 4, a + 1, 1l) == 1l);
    static_assert(std::is_same<decltype(sgl::v1::count_equal(a, a + 4, a + 1, 0)), int>::value, "return type is not an integer");
    static_assert(std::is_same<decltype(sgl::v1::count_equal(a, a + 4, a + 1, (long long){0})), long long>::value, "return type is not a long long");
}

} // namespace function_count_equal

} // namespace test
} // namespace v1
} // namespace sgl

int main() {
    sgl::v1::test::function_count_equal::test0();
}
