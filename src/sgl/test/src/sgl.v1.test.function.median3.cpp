#include <sgl/sgl.h>

namespace sgl {
namespace v1 {
namespace test {


void median3() {
    {
        int a[] = {1, 2, 3};
        while (true) {
            int* b[] = {&a[0], &a[1], &a[2]};
            std::stable_sort(&b[0], &b[0] + 3, [](auto x, auto y) mutable { return *x < *y; });
            assert(&sgl::v1::median3(a[0], a[1], a[2]) == b[1]);
            if (!std::next_permutation(a, a + 3)) break;
        }
    }

    {
        int a[] = {1, 2, 2};
        while (true) {
            int* b[] = {&a[0], &a[1], &a[2]};
            std::stable_sort(&b[0], &b[0] + 3, [](auto x, auto y) mutable { return *x < *y; });
            assert(&sgl::v1::median3(a[0], a[1], a[2]) == b[1]);
            if (!std::next_permutation(a, a + 3)) break;
        }
    }

    {
        int a[] = {2, 2, 2};
        while (true) {
            int* b[] = {&a[0], &a[1], &a[2]};
            std::stable_sort(&b[0], &b[0] + 3, [](auto x, auto y) mutable { return *x < *y; });
            assert(&sgl::v1::median3(a[0], a[1], a[2]) == b[1]);
            if (!std::next_permutation(a, a + 3)) break;
        }
    }
}

} // namespace test
} // namespace v1
} // namespace sgl

int main() {
    sgl::v1::test::median3();
}
