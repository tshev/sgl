#include <cassert>
#include <type_traits>
#include <iterator>
#include <sgl/sgl.v1.class.projection_iterator.h>

namespace sgl {
namespace v1 {
namespace test {
namespace class_projection_iterator {

void test() {
    struct identity {
        int& operator()(int& x) const {
            return x;
        }

        const int& operator()(const int& x) const {
            return x;
        }
    };
    int array[] = {1, 2, 3};
    projection_iterator<int*, identity> p(&array[0]);
    assert(*p == 1);
    ++p;
    assert(*p == 2);
    --p;
    assert(*p == 1);
    assert(*(p + 1) == 2);
    ++p;
    assert(*(p - 1) == 1);
    p -= 1;
    assert(*p == 1);
    p += 1;
    assert(*p == 2);
    auto tmp = p;
    assert(tmp == p);
    --p;
    assert(tmp == p + 1);
    assert(tmp - p == 1);
    p++;
    assert(tmp == p);
    p--;
    assert(tmp - 1 == p);

    typedef std::iterator_traits<decltype(p)>::value_type value_type;
    static_assert(std::is_same<value_type, int>::value);
}

} // namespace class_projection_iterator
} // namespace test
} // namespace v1
} // namespace sgl

int main() {
    sgl::v1::test::class_projection_iterator::test();
}
