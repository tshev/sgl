#include <algorithm>
#include <cstdint>
#include <iterator>
#include <sgl/sgl.v1.class.continuous_inclosed_queue_span.h>

#include <string>
#include <cassert>

namespace sgl {
namespace v1 {
namespace test {

void test0() {
    std::string data(3 * 4 + 10 * 4, '\0');
    {
        continuous_inclosed_queue_span<uint32_t> cqv(&data[0], data.size());
        for (uint32_t i = 0; i < cqv.capacity(); ++i) {
            assert(cqv.push_back(i + 1));
            assert(cqv.front() == 1);
        }
        assert(cqv.size() == 10ul);
        for (uint32_t i = 0; i < cqv.capacity(); ++i) {
            assert(cqv.front() == i + 1);
            cqv.pop_front();
        }
        assert(cqv.size() == 0ul);
        cqv.push_back(11);
        assert(cqv.size() == 1ul);
        assert(cqv.front() == 11);
    }
    {
        continuous_inclosed_queue_span<uint32_t> cqv(&data[0], data.size());
        for (uint32_t i = 0; i < cqv.capacity(); ++i) {
            assert(cqv.push_back(i + 1));
            assert(cqv.front() == 1);
        }
        cqv.pop_front();
        cqv.pop_front();
        cqv.pop_front();
        assert(cqv.offset() == 3);
        cqv.push_back(111);
    }
}

}  // namespace test
}  // namespace v1
}  // namespace sgl


int main() {
    sgl::v1::test::test0();
}
