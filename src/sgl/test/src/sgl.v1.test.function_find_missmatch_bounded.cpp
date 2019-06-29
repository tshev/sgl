#include <cassert>
#include <iostream>
#include <list>
#include <type_traits>
#include <vector>

#include <sgl/sgl.v1.struct.if_else.h>
#include <sgl/sgl.v1.struct.empty.h>
#include <sgl/sgl.v1.struct.totally_ordered.h>
#include <sgl/sgl.v1.struct.triple.h>
#include <sgl/sgl.v1.function.find_missmatch.h>
#include <sgl/sgl.v1.function.find_missmatch_bounded.h>

namespace sgl {
namespace v1 {
namespace test {
namespace function_find_missmatch_bounded {

template<typename T0, typename T1>
struct assert_testcase {
    T0 array0;
    T1 array1;
    template<typename U0, typename U1>
    assert_testcase(std::initializer_list<U0> array0, std::initializer_list<U1> array1) : array0(array0), array1(array1) {}

    template<typename U>
    assert_testcase(std::initializer_list<U> array, sgl::v1::empty) : array0(array) {}

    template<typename U>
    assert_testcase(sgl::v1::empty, std::initializer_list<U> array) : array1(array) {}

    void operator()() {
        auto first0 = std::begin(array0);
        auto last0 = std::end(array0);

        auto first1 = std::begin(array1);
        auto last1 = std::end(array1);

        {
            auto result = sgl::v1::find_missmatch(first0, last0, first1);
            assert(result.first == last0);
            auto second = first1;
            std::advance(second, array0.size());
            assert(result.second == second);
        }


        {
            auto result = sgl::v1::find_missmatch_bounded(first0, last0, first1, last1);
            assert(result.first == last0);
            auto second = first1;
            std::advance(second, array0.size());
            assert(result.second == second);
        }

        {
            auto result = sgl::v1::find_missmatch(first1, last1, first0);
            auto first = first1;
            std::advance(first, array0.size());
            assert(result.first == first);
            assert(result.second == last0);
        }

        {
            auto result = sgl::v1::find_missmatch_bounded(first1, last1, first0, last0);
            auto first = first1;
            std::advance(first, array0.size());
            assert(result.first == first);
            assert(result.second == last0);
        }


        {
            auto result = sgl::v1::find_missmatch_bounded(first1, first1, first0, last0);
            assert(result.first == first1);
            assert(result.second == first0);
        }

    }

};


void test0() {
    sgl::v1::test::function_find_missmatch_bounded::assert_testcase<std::vector<int>, std::vector<int>>({1, 2 , 3}, {1, 2 , 3, 4, 5})();
}


void test1() {
    sgl::v1::test::function_find_missmatch_bounded::assert_testcase<std::list<int>, std::vector<int>>({1, 2 , 3}, {1, 2 , 3, 4, 5})();
}


void test2() {
    sgl::v1::test::function_find_missmatch_bounded::assert_testcase<std::vector<int>, std::list<int>>({1, 2 , 3}, {1, 2 , 3, 4, 5})();
}


void test3() {
    sgl::v1::test::function_find_missmatch_bounded::assert_testcase<std::list<int>, std::list<int>>({1, 2 , 3}, {1, 2 , 3, 4, 5})();
}

} // namespace function_find_missmatch_bounded
} // namespace test
} // namespace v1
} // namespace sgl

int main() {
    sgl::v1::test::function_find_missmatch_bounded::test0();
    sgl::v1::test::function_find_missmatch_bounded::test1();
    sgl::v1::test::function_find_missmatch_bounded::test2();
    sgl::v1::test::function_find_missmatch_bounded::test3();
}
