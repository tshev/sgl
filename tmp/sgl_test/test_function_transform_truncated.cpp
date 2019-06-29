#include <sgl/sgl.h>
#include <sgl/test.h>
//#include <sgl/function_transform_truncated.h>
#include <vector>
void test0() {
    std::cout << __FUNCTION__ << std::endl;
    int a[] = {1, 2, 3, 4, 5};
    size_t size = sizeof(a) / sizeof(*a);
    size_t n = 4;
    int out[size];
    auto result = sgl::transform_truncated(std::begin(a), std::end(a), out, [](auto x) { return x * x; }, n);
    sgl::assert_equal(result.m0, out + size, __FUNCTION__, __LINE__);
    sgl::assert_equal(result.m1, n, __FUNCTION__, __LINE__);
}

int main() {
    sgl::testing(__FILE__)([]{
        test0(); 
    });
}
