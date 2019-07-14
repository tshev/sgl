#pragma once

namespace sgl {
namespace v1 {
namespace test {
namespace function_lower_bound {

void test0() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    assert(sgl::v1::lower_bound(a, a, 1) == &a[0]);
    assert(sgl::v1::lower_bound(a, a, 2) == &a[0]);
    assert(sgl::v1::lower_bound(a, a + 1, 1) == &a[0]);
    assert(sgl::v1::lower_bound(a, a + 1, 99) == &a[1]);
    assert(sgl::v1::lower_bound(a, a + 2, 1) == &a[0]);
    assert(sgl::v1::lower_bound(a, a + 2, 2) == &a[1]);
    assert(sgl::v1::lower_bound(a, a + 2, 99) == &a[2]);
}

} // namespace function_lower_bound
} // namespace test
} // namespace v1
} // namespace sgl

