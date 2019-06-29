#include "sgl.h"
#include <list>

namespace sgl {
    using namespace sgl::v1;
}

struct object_t {
    object_t() { std::cout << "object_t::object_t()\n"; }
    object_t(const object_t& x) { std::cout << "object_t::object_t(const object_t&)\n"; }
    object_t(object_t&& x) { std::cout << "object_t::object_t(object_t&&)\n"; }
    ~object_t() {
        std::cout << "object_t::~object_t()\n";
    }
};

template<typename C>
struct benchmark_accumulate {
    size_t n;
    C container0;
    C container1;

    benchmark_accumulate(size_t n, size_t s0, size_t s1) : n(n), container0(2) {
        //sgl::v1::generate_bm(std::begin(container0), std::end(container0), s0);
        //sgl::v1::generate_bm(std::begin(container1), std::end(container1), s1);
    }

    sgl::v1::nsui64 operator()() {
        typedef typename C::value_type T;
        sgl::v1::swns sw;
        for (size_t i = 0; i < n; ++i) {
            container0.push_back(T(i));
        }
        auto result = sgl::v1::nsui64(sw.stop());
        volatile T _ = sgl::v1::accumulate(std::begin(container0), std::end(container0), T(0), std::plus<T>());
        std::cout << _ << std::endl;
        return result;
    }

};

struct a {
    a() { std::cout << "a::a()\n"; }
    a(const a&) { std::cout << "a::a(const a&)\n"; }
    virtual ~a() { std::cout << "a::~a()\n"; }
};

struct b : a {
    b() { std::cout << "b::b()\n"; }
    b(const b&) { std::cout << "b::b(const b&)\n"; }
    virtual ~b() { std::cout << "b::~b()\n"; }
};



int main() {
    /*
    sgl::v1::array<size_t> sizes = {1024 * 1024};
    std::cout << "# Accumulate\n";

    std::cout << "sgl::v1::array<double>" << std::endl;


    for (auto size : sizes) {
        std::cout << benchmark_accumulate<sgl::v1::array<double>>(size, 1, 2)() << std::endl;
    }

    std::cout << "sgl::v1::linked_list<double>" << std::endl;
    for (auto size : sizes) {
        std::cout << benchmark_accumulate<sgl::v1::linked_list<double>>(size, 1, 2)() << std::endl;
    }

    std::cout << "std::list<double>" << std::endl;
    for (auto size : sizes) {
        std::cout << benchmark_accumulate<std::list<double>>(size, 1, 2)() << std::endl;
    }
    */

    /*
    sgl::v1::array<int> values;
    values.push_back(3);
    values.push_back(3);
    values.insert(std::begin(values), 2, 4);
    for (auto x : values) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << values.capacity() << std::endl;
    */
    sgl::v1::array<int> values;
    values.push_back(100);
    values.push_back(101);
    sgl::v1::array<int> values2;
    values2.reserve(100);
    values2 = values;


    //sgl::linked_list<object_t> values;
    //values.push_back(object_t());
    //std::cout << "x\n";
}
