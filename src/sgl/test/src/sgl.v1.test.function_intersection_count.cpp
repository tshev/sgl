#include <cassert>
#include <algorithm>
#include <iostream>

#include <sgl/sgl.v1.function.find_adjacent_missmatch_unguarded.h>
#include <sgl/sgl.v1.function.find_adjacent_not_equivalent_unguarded.h>
#include <sgl/sgl.v1.function.intersection_count.h>

namespace sgl {
namespace v1 {
namespace test {
namespace function_intersection_count {

void test0() {
    int array0[] = {1};
    int array1[] = {};
    int count = sgl::v1::intersection_count(array0, array0 + sizeof(array0) / sizeof(int), array1, array1 + sizeof(array1) / sizeof(int), 0);
    assert(count == 0);
}


void test1() {
    int array0[] = {};
    int array1[] = {1};
    int count = sgl::v1::intersection_count(array0, array0 + sizeof(array0) / sizeof(int), array1, array1 + sizeof(array1) / sizeof(int), 0);
    assert(count == 0);
}


void test2() {
    int array0[] = {1};
    int array1[] = {1};
    int count = sgl::v1::intersection_count(array0, array0 + sizeof(array0) / sizeof(int), array1, array1 + sizeof(array1) / sizeof(int), 0);
    assert(count == 1);
}


void test3() {
    int array0[] = {1};
    int array1[] = {2};
    int count = sgl::v1::intersection_count(array0, array0 + sizeof(array0) / sizeof(int), array1, array1 + sizeof(array1) / sizeof(int), 0);
    assert(count == 0);
}


void test4() {
    int array0[] = {1, 1};
    int array1[] = {1};
    int count = sgl::v1::intersection_count(array0, array0 + sizeof(array0) / sizeof(int), array1, array1 + sizeof(array1) / sizeof(int), 0);
    assert(count == 1);
}


void test5() {
    int array0[] = {1};
    int array1[] = {1, 1};
    int count = sgl::v1::intersection_count(array0, array0 + sizeof(array0) / sizeof(int), array1, array1 + sizeof(array1) / sizeof(int), 0);
    assert(count == 1);
}


void test6() {
    int array0[] = {1, 1};
    int array1[] = {1, 1};
    int count = sgl::v1::intersection_count(array0, array0 + sizeof(array0) / sizeof(int), array1, array1 + sizeof(array1) / sizeof(int), 0);
    assert(count == 1);
}


void test7() {
    int array0[] = {1, 1, 2, 2};
    int array1[] = {1, 1};
    int count = sgl::v1::intersection_count(array0, array0 + sizeof(array0) / sizeof(int), array1, array1 + sizeof(array1) / sizeof(int), 0);
    assert(count == 1);
}


void test8() {
    int array0[] = {1, 1, 2, 2};
    int array1[] = {1, 1};
    int count = sgl::v1::intersection_count(array0, array0 + sizeof(array0) / sizeof(int), array1, array1 + sizeof(array1) / sizeof(int), 0);
    assert(count == 1);
}


void test9() {
    int array0[] = {1, 1, 2, 2};
    int array1[] = {1, 1, 2, 3};
    int count = sgl::v1::intersection_count(array0, array0 + sizeof(array0) / sizeof(int), array1, array1 + sizeof(array1) / sizeof(int), 0);
    assert(count == 2);
}


void test10() {
    int array0[] = {1, 1, 2, 2, 3};
    int array1[] = {1, 1, 2, 3};
    int count = sgl::v1::intersection_count(array0, array0 + sizeof(array0) / sizeof(int), array1, array1 + sizeof(array1) / sizeof(int), 0);
    assert(count == 3);
}


void test11() {
    int array0[] = {1, 1, 2, 2, 3};
    int count = sgl::v1::intersection_count(array0, array0 + sizeof(array0) / sizeof(int), array0, array0 + sizeof(array0) / sizeof(int), 0);
    assert(count == 3);
}


void test12() {
    int array0[] = {1, 1};
    int count = sgl::v1::intersection_count(array0, array0 + sizeof(array0) / sizeof(int), array0, array0 + sizeof(array0) / sizeof(int), 0);
    assert(count == 1);
}


void test13() {
    int array0[] = {1, 2, 3, 4};
    int count = sgl::v1::intersection_count(array0, array0 + sizeof(array0) / sizeof(int), array0, array0 + sizeof(array0) / sizeof(int), 0);
    assert(count == 4);
}


void test14() {
    int array0[] = {1, 2, 3, 4, 4, 4, 5, 6};
    int count = sgl::v1::intersection_count(array0, array0 + sizeof(array0) / sizeof(int), array0, array0 + sizeof(array0) / sizeof(int), 0);
    assert(count == 6);
}


void test15() {
    int array0[] = {1, 1, 2, 2, 3, 5, 5, 5, 6};
    int array1[] = {1, 1, 2, 3, 5};
    int count = sgl::v1::intersection_count(array0, array0 + sizeof(array0) / sizeof(int), array1, array1 + sizeof(array1) / sizeof(int), 0);
    assert(count == 4);
}


void test16() {
    int array0[] = {1, 1, 2, 2, 2};
    int array1[] = {1, 1, 2, 2, 2};
    int count = sgl::v1::intersection_count(array0, array0 + sizeof(array0) / sizeof(int), array1, array1 + sizeof(array1) / sizeof(int), 0);
    assert(count == 2);
}

} // namespace function_intersection_count
} // namespace test
} // namespace v1
} // namespace sgl

int main() {
    sgl::v1::test::function_intersection_count::test0();
    sgl::v1::test::function_intersection_count::test1();
    sgl::v1::test::function_intersection_count::test2();
    sgl::v1::test::function_intersection_count::test3();
    sgl::v1::test::function_intersection_count::test4();
    sgl::v1::test::function_intersection_count::test5();
    sgl::v1::test::function_intersection_count::test6();
    sgl::v1::test::function_intersection_count::test7();
    sgl::v1::test::function_intersection_count::test8();
    sgl::v1::test::function_intersection_count::test9();
    sgl::v1::test::function_intersection_count::test10();
    sgl::v1::test::function_intersection_count::test11();
    sgl::v1::test::function_intersection_count::test12();
    sgl::v1::test::function_intersection_count::test13();
    sgl::v1::test::function_intersection_count::test14();
    sgl::v1::test::function_intersection_count::test15();
    sgl::v1::test::function_intersection_count::test16();
}
