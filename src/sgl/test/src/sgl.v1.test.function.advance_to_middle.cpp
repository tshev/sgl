#include <cassert>
#include <iterator>
#include <list>
#include <sgl/sgl.v1.function.advance_to_middle.h>

namespace sgl {
namespace v1 {
namespace test {
namespace function_advance_to_middle {
void test0() {
  for (size_t i = 0; i != 1024; ++i) {
    std::list<int> els(i);
    {
      auto first = els.begin();
      auto last = els.end();
      auto m0 = first;
      sgl::v1::advance_to_middle(m0, last);
      assert(std::distance(first, m0) == els.size() / 2);
    }
  }
}
} // namespace function_advance_to_middle
} // namespace test
} // namespace v1
} // namespace sgl

int main() {
    sgl::v1::test::function_advance_to_middle::test0();
}
