#include <cassert>
#include <vector>
#include <sgl/sgl.v1.function.find_backward.h>

namespace sgl {
namespace v1 {

namespace test {
namespace function_find_backward {

void test() {
    std::vector<int> empty;
    auto position = sgl::v1::find_backward(std::begin(empty), std::end(empty), 1);
    assert(position == std::end(empty));

    std::vector<int> values = {1, 2, 3, 4, 5};
    {
        auto position = sgl::v1::find_backward(std::begin(values), std::end(values), 5);
        assert(position == std::end(values) - 1ul);
    }

    {
        auto position = sgl::v1::find_backward(std::begin(values), std::end(values), 4);
        assert(position == std::end(values) - 2ul);
    }

    {
        auto position = sgl::v1::find_backward(std::begin(values), std::end(values), 2);
        assert(position == std::begin(values) + 1ul);
    }

    {
        auto position = sgl::v1::find_backward(std::begin(values), std::end(values), 1);
        assert(position == std::begin(values));
    }

    {
        auto position = sgl::v1::find_backward(std::begin(values), std::end(values), 10);
        assert(position == std::end(values));
    }

    {
        auto position = sgl::v1::find_backward(std::begin(values), std::end(values), 10);
        assert(position == std::end(values));
    }
}

} // namespace function_find_backward
} // namespace test
} // namespace v1
} // namespace sgl

int main() {
    sgl::v1::test::function_find_backward::test();
}
