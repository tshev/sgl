#include <algorithm>
#include <iostream>
#include <sgl/sgl.h>
#include <string>
#include <vector>


template <typename T>
void print_status(const char* name, const T& x, bool v) {
    if (v) {
        std::cout << "Error " << name;
    } else {
        std::cout << "Success: " << name << " " << x;
    }
    std::cout << std::endl;
}

template<typename T>
void describe(const sgl::v1::argparser& ap, const char* name) {
    auto [option, err] = ap.get<T>(name);
    print_status(name, option, err);
}

int main(int argc, char* argv[]) {
    sgl::v1::argparser ap(argc, argv);
    std::cout << ap.command() << std::endl;
    describe<int>(ap, "--x,-x");
    describe<int>(ap, "--y,-y");
    describe<bool>(ap, "-flto");
    describe<bool>(ap, "--target-help");
    describe<std::string_view>(ap, "-L");
    describe<std::string_view>(ap, "-L");

    std::cout << "direct arguments:" << std::endl;
    auto range = ap.values();

    sgl::v1::for_each(range.first, range.second, [](const auto& x) {
        std::cout << "- " << std::string_view(x.first, x.second - x.first) << std::endl;
    });
}
