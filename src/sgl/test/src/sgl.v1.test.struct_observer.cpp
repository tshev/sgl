#include <tuple>
#include <sgl/sgl.h>

namespace sgl {
namespace v1 {
namespace test {
namespace struct_observer {

	struct square {
		int operator()(int x) const { return x * x; }
	};

	struct observer0 {
		void operator()(int& x) const {
			x += 100;
		}
	};

	struct observer1 {
		void operator()(int& x) const {
			x += 3;
		}
	};

	void test0() {
		int value = 12;
		sgl::v1::observer<square, observer0, observer1> observer;
		assert(observer(value) == 144 + 100 + 3);
	}

} // namespace struct_observer
} // namespace test
} // namespace v1
} // namespace sgl


int main() {
	sgl::v1::test::struct_observer::test0();
}
