#include <sgl/sgl.h>
#include <limits>
#include <sgl/sgl.v1.function.from_string.h>
#include <sgl/sgl.v1.class.csv.h>

template<typename It>
std::ostream& print(It first, It last) {
    std::for_each(first, last, [](const auto& x) {
        std::cout << x;
    });
    return std::cout;
}
int main() {
    sgl::v1::csv<int, int, std::string> file_csv("file.csv");
    for (auto [a, b, c] : file_csv) {
        std::cout << a << " " << b << " " << c << std::endl;
    }
}
