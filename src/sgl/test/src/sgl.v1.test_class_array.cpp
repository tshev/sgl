//#include <sgl/test_suite.h>
#include <sgl/sgl.h>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <string>

#include <sgl/sgl.v1.class.array.hpp>

namespace sgl {
namespace v1 {

template<>
struct sgl::v1::array<int>::unittest {
    static void test() {
        {
            sgl::v1::array<int> array;
        }

        {
            sgl::v1::array<int> array;
            assert(array.first_ == nullptr);
            assert(array.last_ == nullptr);
            assert(array.finish_ == nullptr);
            assert(sizeof(decltype(array)) == 3ul * sizeof(void*));
            static_assert(std::is_same<int, typename decltype(array)::value_type>::value);
            assert(array.size() == 0ul);
            assert(array.capacity() == 0ul);
            assert(array.capacity_unused() == 0ul);
            assert(array.begin() == nullptr);
            assert(array.end() == nullptr);
        }
        {
            int z = 10;
            sgl::v1::array<int> array;
            array.push_back(z);

            assert(array.back() == z);
            assert(array.front() == z);
            assert(array.first_ != nullptr);
            assert(array.last_ == array.first_ + 1ul);
            assert(array.finish_ == array.first_ + decltype(array)::initial_capacity);

            for (size_t i = 1ul; i < decltype(array)::initial_capacity; ++i) {
                array.push_back(i);
            }

            assert(array.size() == decltype(array)::initial_capacity);
            assert(size_t(array.end() - array.begin()) == array.size());

            for (size_t i = 1ul; i < decltype(array)::initial_capacity; ++i) {
                assert(array[i] == int(i));
            }

            assert(array.capacity() == decltype(array)::initial_capacity);
            assert(array.capacity_unused() == 0ul);

            int x = 123;
            array.push_back(x);

            assert(array.capacity() == 2ul * decltype(array)::initial_capacity);
            assert(array.capacity_unused() + 1ul == decltype(array)::initial_capacity);

            for (size_t i = 1ul; i < decltype(array)::initial_capacity; ++i) {
                assert(array[i] == int(i));
            }
            assert(array.back() == x);
        }

        {
            sgl::v1::array<int> array;
            array.push_back(12);

            assert(array.first_ != nullptr);
            assert(array.last_ == array.first_ + 1ul);
            assert(array.finish_ == array.first_ + decltype(array)::initial_capacity);

            assert(array.size() == 1ul);
            assert(size_t(array.end() - array.begin()) == array.size());

            assert(array.capacity() == decltype(array)::initial_capacity);
            assert(array.capacity_unused() == 0ul);

            int x = 123;
            array.push_back(x);
            assert(array.capacity() == 2ul * decltype(array)::initial_capacity);
            assert(array.capacity_unused() + 1ul == decltype(array)::initial_capacity);
            assert(array.back() == x);
            assert(array.back() != array.front());
        }


        {
            sgl::v1::array<int> array;
            array.push_back(0);
        }

        {
            volatile sgl::v1::array<int> array(1000); // uninitialized_memory
        }

        {
            size_t s = 11ul;
            int value = 102;
            sgl::v1::array<int> array(s, value);
            assert(array.size() == s);
            for (size_t i = 0ul; i < s; ++i) {
                assert(array[i] == value);
            }
            assert(array.capacity() == s);
            assert(array.capacity_unused() == 0ul);
            array.push_back(303);
            assert(array.capacity() == 2ul * s);
            assert(array.size() == s + 1ul);
            assert(size_t(array.end() - array.begin()) == array.size());
        }

        {
            sgl::v1::array<int> array;
            array.insert(array.begin(), 1);
            assert(array.size() == 1ul);
            assert(array.capacity() == 1ul);
            assert(array.capacity_unused() == 0ul);
            assert(array.front() == 1);
            assert(array.back() == 1);

            array.insert(array.begin(), 2);
            assert(array.size() == 2ul);
            assert(array.capacity() == 2ul);
            assert(array.capacity_unused() == 0ul);
            assert(array.front() == 2);
            assert(array.back() == 1);

            array.insert(array.begin(), 3);
            assert(array.size() == 3ul);
            assert(array.capacity() == 4ul);
            assert(array.capacity_unused() == 1ul);
            assert(array.front() == 3);
            assert(array.back() == 1);

            size_t s = 10;
            array.insert(array.begin(), 3, s);
            assert(array.size() == s + 3ul);
            assert(array.capacity() == s + 3ul);
            assert(array.capacity_unused() == 0ul);
            assert(array.front() == 3);

            assert(std::all_of(array.begin(), array.begin() + s, [](int x) { return x == 3; }));

            assert(array[10ul] == 3);
            assert(array[11ul] == 2);
            assert(array[12ul] == 1);
            assert(array.back() == 1);
            assert(&array.back() == array.end() - 1ul);
        }

        {
            sgl::v1::array<int> array;
            int value = 3;
            size_t s = 10ul;
            array.insert(array.begin(), value, s);
            assert(array.size() == s);
            assert(array.capacity() == s);
            assert(array.capacity_unused() == 0ul);
            assert(std::all_of(array.begin(), array.begin() + s, [value](int x) { return x == value; }));
            assert(std::all_of(array.begin(), array.end(), [value](int x) { return x == value; }));
            assert(&array.back() == array.end() - 1ul);
        }

        {
            sgl::v1::array<int> array;
            size_t s = 12ul;
            array.reserve(s);
            assert(array.size() == 0ul);
            assert(array.capacity() == s);
            assert(array.capacity_unused() == s);
            int* old_addr = &array.front();
            array.push_back(1);
            assert(old_addr == &array.front());
            assert(array.front() == 1);

            size_t s1 = 3ul * s;
            array.reserve(s1);
            assert(array.size() == 1ul);
            assert(array.capacity() == s1);
            assert(array.capacity_unused() == s1 - 1ul);
            assert(array.front() == 1);
            assert(old_addr != &array.front()); // Ensure reallocation.

            assert(array.begin() == array.first_);
            assert(array.end() == array.last_);
        }

        {
            size_t s = 12;
            int value = 99;
            sgl::v1::array<int> array(s, value);
            array.clear();
            assert(array.first_ != nullptr);
            assert(array.first_ == array.last_);
            assert(array.finish_ == array.first_ + s);
            assert(array.capacity() == s);
            array.shrink_to_fit();
            assert(array.first_ == nullptr);
            assert(array.last_== nullptr);
            assert(array.finish_ == nullptr);
        }

        {
            sgl::v1::array<int> array;
            array.resize(0ul);
            assert(array.first_ == nullptr);
            assert(array.last_ == nullptr);
            assert(array.finish_ == nullptr);
        }

        {
            for (size_t s = 1ul; s < 10ul; ++s) {
                sgl::v1::array<int> array;
                array.resize(s);
                assert(array.first_ != nullptr);
                assert(array.last_ == array.first_ + s);
                assert(array.finish_ == array.first_ + s);
            }
        }

        {
            sgl::v1::array<int> array;
            for (size_t s = 1ul; s < 10ul; ++s) {
                array.resize(s);
                assert(array.first_ != nullptr);
                assert(array.last_ == array.first_ + s);
                assert(array.finish_ == array.first_ + s);
            }
        }

        {
            sgl::v1::array<int> array;
            assert(array.empty());
        }

        {
            sgl::v1::array<int> array = {1, 2, 3, 4};
            array.erase(array.begin());
            assert(array.size() == 3);
            assert(array[0] == 2);
            assert(array[1] == 3);
            assert(array[2] == 4);
        }

        {
            sgl::v1::array<int> array = {1, 2, 3, 4, 5, 6};
            array.erase(array.begin(), array.begin() + 2);
            assert(array.size() == 4);
            assert(array[0] == 3);
            assert(array[1] == 4);
            assert(array[2] == 5);
            assert(array[3] == 6);
        }

        {
            sgl::v1::array<int> array = {1, 2, 3, 4, 5, 6};
            array.erase(array.begin(), array.end());
            assert(array.size() == 0);
        }

        {
            sgl::v1::array<int> array = {1, 2, 3, 4, 5, 6};
            array.erase(array.begin(), array.begin() + (array.size() - 1ul));
            assert(array.size() == 1);
            assert(array[0] == 6);
        }

        {
            int data[] = {1, 2, 3};
            sgl::v1::array<int> array(std::begin(data), std::end(data), [](auto x) { return x * x; });
            assert(array[0] == 1);
            assert(array[1] == 4);
            assert(array[2] == 9);
        }
        */
    }
};


template<>
struct sgl::v1::array<std::string>::unittest {
    static void test() {
        {
            sgl::v1::array<std::string> array;
        }

        return;
        {
            sgl::v1::array<std::string> array;
            assert(array.first_ == nullptr);
            assert(array.last_ == nullptr);
            assert(array.finish_ == nullptr);
            assert(sizeof(decltype(array)) == 3ul * sizeof(void*));
            static_assert(std::is_same<std::string, typename decltype(array)::value_type>::value);
            assert(array.size() == 0ul);
            assert(array.capacity() == 0ul);
            assert(array.capacity_unused() == 0ul);
            assert(array.begin() == nullptr);
            assert(array.end() == nullptr);
        }

        {
            sgl::v1::array<std::string> array;
            const std::string value = "value";
            array.emplace_back(value);
            assert(array.size() == 1ul);
            assert(array.capacity() == decltype(array)::initial_capacity);
            assert(array.first_ != nullptr);
            assert(array.front() == value);
            assert(array.back() == value);
            const std::string value1 = "value1";
            array.push_back(value1);
            assert(array.front() == value);
            assert(array.back() == value1);
        }

        {
            sgl::v1::array<std::string> array;
            std::string value = "value";
            array.emplace_back(std::move(value));
            assert(array.size() == 1ul);
            assert(array.capacity() == decltype(array)::initial_capacity);
            assert(array.first_ != nullptr);
            assert(array.front() == "value");
            assert(array.back() == "value");
            std::string value1 = "value1";
            array.push_back(std::move(value1));
            assert(array.front() == "value");
            assert(array.back() == "value1");
        }

        {
            sgl::v1::array<std::string> array;
            const std::string value = "value";
            array.insert(array.begin(), value);
            assert(array.size() == 1ul);
            assert(array.capacity() == decltype(array)::initial_capacity);
            assert(array.front() == value);
            assert(array.back() == value);
            assert(array::call_default_constructor);
        }

        {
            sgl::v1::array<std::string> array;
            std::string value = "value";
            array.insert(array.begin(), std::move(value));
            assert(array.size() == 1ul);
            assert(array.capacity() == decltype(array)::initial_capacity);
            assert(array.back() == "value");
            assert(array.front() == "value");
        }

        {
            bool throws_bad_alloc = false;
            try {
                sgl::v1::array<int> array(~sgl::v1::array<int>::size_type(0));
            } catch (const std::bad_alloc&) {
                throws_bad_alloc = true;
            }
            assert(throws_bad_alloc);
        }

        {
            bool throws_bad_alloc = false;
            sgl::v1::array<int> array;
            try {
                array.resize(~sgl::v1::array<int>::size_type(0));
            } catch (const std::bad_alloc&) {
                throws_bad_alloc = true;
            }
            assert(throws_bad_alloc);
        }

        {
            bool throws_bad_alloc = false;
            sgl::v1::array<int> array;
            try {
                array.reserve(~sgl::v1::array<int>::size_type(0));
            } catch (const std::bad_alloc&) {
                throws_bad_alloc = true;
            }
            assert(throws_bad_alloc);
        }
    }
};

namespace test {
namespace class_array {
/***************** <tests> *****************/

//typedef sgl::v1::array<std::string> object_t;

void test_empty_array() {
    sgl::v1::array<int> array;
    assert(array.size() == 0);
    assert(array.capacity() == 0);
    assert(sgl::v1::array<int>::initial_capacity == 1);
    array.emplace_back(1);
    /*
    for (size_t i = 1; i <= sgl::v1::array<int>::initial_capacity; ++i) {
        array.emplace_back(i);
        assert(array.size() == i);
        assert(array.capacity() == sgl::v1::array<int>::initial_capacity);
    }
    */
}


void test_empty_array_for_string() {
    sgl::v1::array<std::string> array;
    assert(array.size() == 0);
    assert(array.capacity() == 0);
    for (size_t i = 1; i <= sgl::v1::array<int>::initial_capacity; ++i) {
        array.emplace_back("--------------------------------------------------------------------------------");
        assert(array.size() == i);
        assert(array.capacity() == sgl::v1::array<int>::initial_capacity);
    }
}

void test_with_unique_ptr() {
    sgl::v1::array<std::unique_ptr<int>> data;
    assert(data.empty());
    assert(data.size() == 0);
    assert(data.capacity() == 0);
    data.push_back(std::make_unique<int>(1));
    assert(!data.empty());
    assert(data.size() == 1);
    data.push_back(std::make_unique<int>(2));
    assert(!data.empty());
    assert(data.size() == 2);
    assert(data.capacity() == 2);
    data.push_back(std::make_unique<int>(4));
    assert(!data.empty());
    assert(data.size() == 3);
    assert(data.capacity() == 4);
    assert(*data.back() == 4);
    assert(*data.front() == 1);

    assert(*data[0] == 1);
    assert(*data[1] == 2);
    assert(*data[2] == 4);

    data.resize(6);
    assert(data.size() == 6);
    assert(data.capacity() == 6);

    assert(*data[0] == 1);
    assert(*data[1] == 2);
    assert(*data[2] == 4);
    assert(data[3] == nullptr);
    assert(data[4] == nullptr);
    assert(data[5] == nullptr);
    data.insert(data.end(), std::make_unique<int>(5));
    assert(data.size() == 7);
    assert(!data.empty());

    data.erase(data.begin());
    assert(data.size() == 6);
    assert(data.capacity() == 12);
    assert(*data[0] == 2);
    assert(*data[1] == 4);
    assert(data[2] == nullptr);
    assert(data[3] == nullptr);
    assert(data[4] == nullptr);

}


void test_assignment() {
    sgl::v1::array<int> x(16, 15);
    {
        sgl::v1::array<int> y(15, 1);
        y.reserve(64);
        y = x;
        assert(y.size() == x.size());
        assert(y.size() == 16);
        std::for_each(y.begin(), y.end(), [](auto x) { assert(x == 15); });
    }

    {
        sgl::v1::array<int> y(32, 13);
        y = x;
        assert(y.size() == x.size());
        assert(y.size() == 16);
        std::for_each(y.begin(), y.end(), [](auto x) { assert(x == 15); });
    }

    {
        sgl::v1::array<int> y(1);
        y = x;
        assert(y.size() == x.size());
        assert(y.size() == 16);
        std::for_each(y.begin(), y.end(), [](auto x) { assert(x == 15); });
    }
}


void run_unittest() {
    sgl::v1::array<int>::unittest::test();
    sgl::v1::array<std::string>::unittest::test();
}

/***************** </tests> ****************/
} // namespace class_array
} // namespace test
} // namespace v1
} // namespace sgl


int main() {
    sgl::v1::test::class_array::test_empty_array();
    sgl::v1::test::class_array::test_empty_array_for_string();
    sgl::v1::test::class_array::test_with_unique_ptr();
    sgl::v1::test::class_array::test_assignment();
    sgl::v1::test::class_array::run_unittest();

}
