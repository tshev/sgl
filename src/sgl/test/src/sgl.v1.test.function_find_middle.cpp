#include <cassert>
#include <iterator>
#include <list>
#include <sgl/sgl.v1.function.find_middle.h>

namespace sgl {
namespace v1 {
namespace test {
namespace function_find_middle {

void test0() {
  for (size_t i = 0ul; i != 16ul; ++i) {
    std::list<int> els(i);
    {
      auto first = els.begin();
      auto last = els.end();
      auto m0 = sgl::v1::find_middle(first, last);
      assert(size_t(std::distance(first, m0)) == els.size() / 2ul);
    }
  }
}

} // namespace function_find_middle
} // namespace test
} // namespace v1
} // namespace sgl

int main() {
    sgl::v1::test::function_find_middle::test0();
}
