#include <cassert>

#include <memory>
#include <iterator>
#include <algorithm>

#include <sgl/sgl.v1.function.default_construct.h>
#include <sgl/sgl.v1.function.repeat_n.h>
#include <sgl/sgl.v1.struct.totally_ordered.h>
#include <sgl/sgl.v1.struct.triple.h>
#include <sgl/sgl.v1.struct.is_nothrow_semiregular.h>
#include <sgl/sgl.v1.function.copy_bounded.h>
#include <sgl/sgl.v1.function.copy_construct.h>
#include <sgl/sgl.v1.function.destruct.h>
#include <sgl/sgl.v1.function.uninitialized_construct.h>
#include <sgl/sgl.v1.function.copy_range_value_range.h>
#include <sgl/sgl.v1.function.uninitialized_copy_range_value_range.h>
#include <sgl/sgl.v1.function.uninitialized_move.h>
#include <sgl/sgl.v1.function.uninitialized_copy_construct.h>
#include <sgl/sgl.v1.function.uninitialized_default_construct.h>
#include <sgl/sgl.v1.function.copy_range_value_range.h>
#include <sgl/sgl.v1.function.uninitialized_copy_range_value_range.h>
#include <sgl/sgl.v1.function.move_range_value_range.h>
#include <sgl/sgl.v1.function.uninitialized_move_range_value_range.h>
#include <sgl/sgl.v1.function.equal.h>
#include <sgl/sgl.v1.struct.totally_ordered.h>

#include <sgl/sgl.v1.class.array.h>

#include <sgl/sgl.v1.function.successor_inplace.h>
#include <sgl/sgl.v1.function.find_if_inplace.h>
#include <sgl/sgl.v1.function.swap_step.h>
#include <sgl/sgl.v1.function.partition_semistable.h>


namespace sgl {
namespace v1 {
namespace test {
namespace function_partition_semistable {

typedef sgl::v1::array<int> array_int_t;
typedef typename array_int_t::iterator iterator_type;


struct equals {
    int value;

    equals() = default;
    equals(int value) noexcept : value(value) {}

    bool operator()(int x) const noexcept {
        return x == value;
    }
};


void test0() {
    array_int_t array;
    iterator_type partition_point = sgl::v1::partition_semistable(std::begin(array), std::end(array), equals(1));
    assert(partition_point == std::end(array));
}


void test1() {
    array_int_t array = {1,};
    iterator_type partition_point = sgl::v1::partition_semistable(std::begin(array), std::end(array), equals(1));
    assert(partition_point == std::begin(array));
    array_int_t array_expected = {1,};
    assert(array == array_expected);
}


void test2() {
    array_int_t array = {0,};
    iterator_type partition_point = sgl::v1::partition_semistable(std::begin(array), std::end(array), equals(1));
    assert(partition_point == std::end(array));
    array_int_t array_expected = {0,};
    assert(array == array_expected);
}


void test3() {
    array_int_t array = {1, 0};
    iterator_type partition_point = sgl::v1::partition_semistable(std::begin(array), std::end(array), equals(1));
    assert(partition_point == std::begin(array) + 1u);
    array_int_t array_expected = {0, 1};
    assert(array == array_expected);
}


void test4() {
    array_int_t array = {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1};
    iterator_type partition_point = sgl::v1::partition_semistable(std::begin(array), std::end(array), equals(1));
    array_int_t array_expected = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};
    assert(array == array_expected);
    assert(*partition_point == 1);
}

} // namespace function_partition_semistable
} // namespace test
} // namespace v1
} // namespace sgl


int main() {
    sgl::v1::test::function_partition_semistable::test0();
    sgl::v1::test::function_partition_semistable::test1();
    sgl::v1::test::function_partition_semistable::test2();
    sgl::v1::test::function_partition_semistable::test3();
}
