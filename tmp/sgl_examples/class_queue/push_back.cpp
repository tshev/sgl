#include <sgl/sgl.h>
#include <string>

inline
std::ostream& operator<<(std::ostream& cout, const sgl::queue<std::string>& values) {
  for (auto x : values) {
    cout << x << " ";
  }
  return cout;
}

int main() {
  sgl::queue<std::string> values;// = {"1", "2", "3", "4", "5"};
  std::cout << values << std::endl;
  std::cout << std::endl;

  values.insert(std::begin(values), "1");
  std::cout << "Values: " << values << std::endl;
  std::cout << std::endl;

}
