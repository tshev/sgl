#include <cassert>
#include <algorithm>
#include <iostream>
#include <sgl/sgl.v1.function.set_union_count.h>

namespace sgl {
namespace v1 {
namespace test {
namespace function_set_union_count {

void test0() {
    int array0[] = {1};
    int array1[] = {};
    int count = sgl::v1::set_union_count(array0, array0 + sizeof(array0) / sizeof(int), array1, array1 + sizeof(array1) / sizeof(int), 0);
    assert(count == 1);
}


void test1() {
    int array0[] = {1};
    int array1[] = {1};
    int count = sgl::v1::set_union_count(array0, array0 + sizeof(array0) / sizeof(int), array1, array1 + sizeof(array1) / sizeof(int), 0);
    assert(count == 1);
}


void test2() {
    int array0[] = {1, 2};
    int array1[] = {1};
    int count = sgl::v1::set_union_count(array0, array0 + sizeof(array0) / sizeof(int), array1, array1 + sizeof(array1) / sizeof(int), 0);
    assert(count == 2);
}


void test3() {
    int array0[] = {1, 2, 3};
    int array1[] = {0, 1};
    int count = sgl::v1::set_union_count(array0, array0 + sizeof(array0) / sizeof(int), array1, array1 + sizeof(array1) / sizeof(int), 0);
    assert(count == 4);
}

void test4() {
    int array0[] = {1, 1, 1};
    int array1[] = {};
    int count = sgl::v1::set_union_count(array0, array0 + sizeof(array0) / sizeof(int), array1, array1 + sizeof(array1) / sizeof(int), 0);
    assert(count == 3);
}

void test5() {
    int array0[] = {1, 1, 1};
    int array1[] = {1, 1};
    int count = sgl::v1::set_union_count(array0, array0 + sizeof(array0) / sizeof(int), array1, array1 + sizeof(array1) / sizeof(int), 0);
    assert(count == 3);
}

} // namespace function_set_union_count
} // namespace test
} // namespace v1
} // namespace sgl

int main() {
    sgl::v1::test::function_set_union_count::test0();
    sgl::v1::test::function_set_union_count::test1();
    sgl::v1::test::function_set_union_count::test2();
    sgl::v1::test::function_set_union_count::test3();
    sgl::v1::test::function_set_union_count::test4();
    sgl::v1::test::function_set_union_count::test5();
}
