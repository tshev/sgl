#include <iostream>
#include <memory>
#include <sgl/sgl.h>

int main() {
    using std::swap;
    sgl::array<int> values0(0, 0);
    sgl::array<int> values1(1, 33);
    swap(values0, values1);
    values1.resize(10, 1111);


    for (auto x : values0) {
        std::cout << x << std::endl;
    }
    std::cout << "--\n";
    for (auto x : values1) {
        std::cout << x << std::endl;
    }

}
