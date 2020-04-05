#include <cassert>
#include <thread>
#include <mutex>
#include <atomic>
#include <shared_mutex>
#include <sgl/sgl.h>

namespace sgl {
namespace v1 {

namespace test {
namespace function_transform_while_not_with_sentinel {

void test() {
    sgl::v1::array<int> input = {1, 2, 3, 4};
    auto first0 = sgl::v1::begin(input);
    {
        sgl::v1::array<int> output(input.size());
        auto out0 = output.begin();
        auto [input_l, output_l] = sgl::v1::transform_while_not_with_sentinel(first0, out0, [](int x) { return x >= 4; }, [](int x) { return x * x; });

        assert(input_l - first0 == 3ll);
        assert(output_l - out0 == 3ll);

        assert(output[0] == 1);
        assert(output[1] == 4);
        assert(output[2] == 9);

        assert(output.size() == 4);

        assert(input[0] == 1);
        assert(input[1] == 2);
        assert(input[2] == 3);
        assert(input[3] == 4);
    }

    {
        int placeholder = 12345;
        sgl::v1::array<int> output(input.size(), placeholder);
        auto out0 = output.begin();
        auto [input_l, output_l] = sgl::v1::transform_while_not_with_sentinel(first0, out0, [](int x) { return true; }, [](int x) { return x * x; });

        assert(input_l - first0 == 0ll);
        assert(output_l - out0 == 0ll);

        assert(output[0] == placeholder);
        assert(output[1] == placeholder);
        assert(output[2] == placeholder);
        assert(output[3] == placeholder);

        assert(output.size() == 4);

        assert(input[0] == 1);
        assert(input[1] == 2);
        assert(input[2] == 3);
        assert(input[3] == 4);
    }
}

} // namespace function_find_not_backward
} // namespace test
} // namespace v1
} // namespace sgl

int main() {
    sgl::v1::test::function_transform_while_not_with_sentinel::test();
}
