#include <utility>
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <list>

#include <sgl/sgl.v1.function.partition_transform_position.h>

namespace sgl {
namespace v1 {
namespace test {
namespace function_partition_transform_position {
    template<typename RandomAccessIterator0, typename RandomAccessIterator1>
    struct selector_functor {
        RandomAccessIterator0 first0;
        RandomAccessIterator1 first1;

        bool operator()(RandomAccessIterator0 value_position) const {
            return first1[value_position - first0];
        }
    };

    template<typename InputIterator, typename T>
    struct square_functor {
        T operator()(InputIterator pos) const {
            return *pos * *pos;
        }
    };

    void test0() {
        typedef int value_type;

        std::vector<value_type> values = {0, 1, 2, 3, 4, 5, 6};
        std::vector<bool> selection = {true, false, true, false, true, false, true};

        assert(values.size() == selection.size());

        std::vector<value_type> negative_cases;
        negative_cases.reserve(values.size() / 2);

        std::vector<value_type> positive_cases;
        positive_cases.reserve(values.size() / 2);

        typedef typename std::vector<value_type>::iterator value_type_iterator;

        value_type_iterator first = std::begin(values);
        value_type_iterator last = std::end(values);

        typedef typename std::vector<bool>::iterator selection_iterator;
        selection_iterator first_selection = std::begin(selection);

        auto out0 = std::back_inserter(negative_cases);
        auto out1 = std::back_inserter(positive_cases);

        selector_functor<value_type_iterator, selection_iterator> predicate{first, first_selection};
        square_functor<value_type_iterator, value_type> transformation;

        //typedef std::pair<decltype(out0), decltype(out1)> return_type;
        sgl::v1::partition_transform_position(first, last, out0, out1, predicate, transformation);
        
        std::vector<int> expected_negative_cases = {1, 9, 25};
        std::vector<int> expected_positive_cases = {0, 4, 16, 36};

        assert(negative_cases == expected_negative_cases);
        assert(positive_cases == expected_positive_cases);
    } // function test0

    void test1() {
        typedef int value_type;
        typedef typename std::list<value_type>::iterator iterator0;
        typedef typename std::vector<value_type>::iterator iterator1;
        std::vector<value_type> values = {0, 1, 2, 3, 4, 5, 6};
        std::list<value_type> negative_cases(values.size());
        std::vector<value_type> positive_cases(values.size());

        auto pred = [](auto _) { return true; };
        auto transformation = [](auto position) { return *position; };
        std::pair<iterator0, iterator1> pos = sgl::v1::partition_transform_position(std::begin(values), std::end(values), std::begin(negative_cases), std::begin(positive_cases), pred, transformation);
        assert(pos.first == std::begin(negative_cases));
        assert(size_t(pos.second - std::begin(positive_cases)) == values.size());

        auto negative_pred = [](auto _) { return false; };
        pos = sgl::v1::partition_transform_position(std::begin(values), std::end(values), std::begin(negative_cases), std::begin(positive_cases), negative_pred, transformation);
        assert(size_t(std::distance(std::begin(negative_cases), pos.first)) == values.size());
        assert(pos.first == std::end(negative_cases));
        assert(pos.second == std::begin(positive_cases));
    }
} // namespace test
} // namespace function_partition_transform_position
} // namespace v1
} // namespace sgl

int main() {
    sgl::v1::test::function_partition_transform_position::test0();
    sgl::v1::test::function_partition_transform_position::test1();
}
