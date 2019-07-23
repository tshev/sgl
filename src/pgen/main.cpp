#include <random>
#include <iostream>
#include <cstring>
#include <sgl/sgl.h>


int main(int argc, char* argv[]) {
    const char* usage = (
        "Usage: app [--size N]\n"
        "--size,--length SIZE    size_t    length of the password. Default 32."
    );

    sgl::v1::argparser ap(argc, argv);

    auto [help, help_error] = ap.get<bool>("--help,-h", false);
    if (help) {
        std::cout << usage << std::endl;
        std::exit(0);
    }

    auto [length, length_error] = ap.get<size_t>("--size,--length", 32);

    if (length_error) {
        std::cout << "length_error" << std::endl << usage << std::endl;
        std::exit(1);
    }

    std::string password(length, char(0));
    sgl::v1::sequence_generator<std::random_device> pg;
    pg(std::begin(password), std::end(password));
    std::cout << password << std::endl;
}
