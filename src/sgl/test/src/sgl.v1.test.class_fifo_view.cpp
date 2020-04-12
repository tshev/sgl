#include <cassert>
#include <algorithm>
#include <iostream>
#include <sgl/sgl.v1.class.fifo_view.hpp>
#include <sgl/sgl.v1.function.equal.h>


namespace sgl {
namespace v1 {
namespace test {
namespace class_fifo_view {
void test() {
    {
        std::vector<char> data(64);
        char* data_repr = &data[0];
        sgl::v1::fifo_view<uint64_t> cq(data_repr, data.size());
        assert(cq.empty());
        assert(cq.position_first() == 16);
        assert(cq.position_last() == 16);
        assert(cq.push_back(uint64_t(1)));
        assert(cq.position_last() == 32);
        assert(cq.push_back(uint64_t(2)));
        assert(cq.position_last() == 48);
        assert(cq.push_back(uint64_t(3)));
        assert(cq.position_last() == 64);
        assert(!cq.push_back(uint64_t(3)));
        assert(cq.position_last() == 64);

        uint64_t expected[] = {1, 2, 3};
        assert(sgl::v1::equal(std::begin(expected), std::end(expected), cq.begin(), cq.end(), [](auto y, auto _x) {
            uint64_t x = sgl::v1::as_ref<uint64_t>(_x.first);
            assert(_x.second == 8ul);
            return x == y;
        }));
        auto pair = cq.pop_front();
        assert(sgl::v1::as_ref<uint64_t>(pair.first) == 1);
        assert(pair.second == 8ul);

        assert(sgl::v1::equal(std::begin(expected) + 1, std::end(expected), cq.begin(), cq.end(), [](auto y, auto _x) {
            uint64_t x = sgl::v1::as_ref<uint64_t>(_x.first);
            assert(_x.second == 8ul);
            return x == y;
        }));
        assert(cq.push_back(uint64_t(4)));
        assert(!sgl::v1::equal(std::begin(expected), std::end(expected), cq.begin(), cq.end(), [](auto y, auto _x) {
            uint64_t x = sgl::v1::as_ref<uint64_t>(_x.first);
            assert(_x.second == 8ul);
            return x == y;
        }));

        expected[0] = 2;
        expected[1] = 3;
        expected[2] = 4;
        assert(sgl::v1::equal(std::begin(expected), std::end(expected), cq.begin(), cq.end(), [](auto y, auto _x) {
            uint64_t x = sgl::v1::as_ref<uint64_t>(_x.first);
            assert(_x.second == 8ul);
            return x == y;
        }));
        assert(cq.position_first() == 16);
        assert(cq.position_last() == 64);
    }
} // void test()
} // namespace class_fifo_view
} // namespace test
} // namespace v1
} // namespace sgl

int main() {
    sgl::v1::test::class_fifo_view::test();
}
