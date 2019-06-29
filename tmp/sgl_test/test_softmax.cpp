#include <sgl/test.h>
#include <sgl/sgl.h>
void test0() {
    std::cout << __FUNCTION__ << std::endl;
    double numbers[] = {1.0, 2.0, 3.0, 4.0};
    sgl::softmax_inplace_max(std::begin(numbers), std::end(numbers));
    double softmax_expected_values[] = {0.0320586, 0.0871443, 0.236883, 0.643914};
    sgl::for_each(std::begin(numbers), std::end(numbers), std::begin(softmax_expected_values), [](auto x, auto y) {
      sgl::assert_eps(x, y, __FUNCTION__, __LINE__);
    });
}

int main() {
  sgl::testing(__FILE__)([] {
      test0();
  });
}
