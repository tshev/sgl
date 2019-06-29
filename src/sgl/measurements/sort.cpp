#include <sgl/sgl.h>

template<typename T>
struct sort_comparison {
    T* data;

    sort_comparison(T& x) : data(&x) {}
    sort_comparison(const sort_comparison&) = default;

    void operator()(size_t& t0, size_t& t1) {
        T heap = *data;
        std::make_heap(std::begin(heap), std::end(heap));
        {
            sgl::v1::swns sw;
            std::sort_heap(std::begin(heap), std::end(heap));
            t0 = sw.stop();
        }
        heap = *data;
        std::make_heap(std::begin(heap), std::end(heap));
        {
            sgl::v1::swns sw;
            std::sort(std::begin(heap), std::end(heap));
            t1 = sw.stop();
        }
    }
};

int main() {
    size_t n = 3210;
    std::vector<uint32_t> values(n);
    sgl::v1::generate_bm(std::begin(values), std::end(values));

    size_t m = 100ul;
    sgl::v1::array<size_t> a(m);
    sgl::v1::array<size_t> b(m);
    sgl::v1::for_each(std::begin(a), std::end(a), std::begin(b), sort_comparison<decltype(values)>(values));
    std::nth_element(std::begin(a), std::begin(a) + m / 2, std::end(a));
    std::nth_element(std::begin(b), std::begin(b) + m / 2, std::end(b));
    std::cout << double(a[m / 2]) / b[m / 2] << std::endl;
}
