#include <sgl/sgl.h>

int main() {
	std::cout << "# program array_static" << std::endl;
	sgl::array_static<int, 3> data = {1, 2, 3};
	std::for_each(std::begin(data), std::end(data), [](auto x) { std::cout << x << std::endl; });
	std::cout << std::endl;
	std::for_each(std::rbegin(data), std::rend(data), [](auto x) { std::cout << x << std::endl; });
	sgl::string_static<10> str = "hello";
}
