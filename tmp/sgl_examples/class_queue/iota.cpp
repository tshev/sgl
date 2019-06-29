#include <sgl/sgl.h>
#include <numeric>
int main() {
  const size_t n = 1000000000ul;
  sgl::queue<uint64_t> values(n);
  std::iota(std::begin(values), std::end(values), 0);
  std::cout << std::accumulate(std::begin(values), std::end(values), 0ul) << std::endl;
}
