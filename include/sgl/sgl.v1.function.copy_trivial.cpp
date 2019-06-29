#include <sgl/sgl.h>
#include "sgl.v1.function.copy_trivial.h"

int main() {
    size_t n = 100000000;
    sgl::v1::array<int> values(n);
    std::iota(std::begin(values), std::end(values), 0);
    sgl::v1::array<int> out(n);
    sgl::v1::swns sw;
    //sgl::v1::copy_trivial(std::begin(values), std::end(values), std::begin(out));
    std::copy(std::begin(values), std::end(values), std::begin(out));
    std::cout << sw.stop() / 10.0e9 << std::endl;
    for (auto x : out) {
        std::cout << x << std::endl;
    }
}
