#include <sgl/sgl.h>
#include <sgl/sgl.v1.class.csv.h>

int main() {
    sgl::v1::csv<int, int> file_csv("file.csv");
    for (auto [a, b] : file_csv) {
        std::cout << a << " " << b << std::endl;
    }

}
