#include <sgl/sgl.h>
struct big_t {
  int data[128];
};

template<typename ForwardIterator>
auto benchamrk_rotate(ForwardIterator first, ForwardIterator last) {
  std::cout << "benchmark_rotate\t";
  sgl::stopwatch_nanoseconds sw;
  std::rotate(first, first + 1, last);
  return sw.stop();
}

template<typename ForwardIterator>
auto benchamrk_rotate_leftmost(ForwardIterator first, ForwardIterator last) {
  std::cout << "benchmark_rotate_leftmost\t";
  sgl::stopwatch_nanoseconds sw;
  sgl::rotate_leftmost(first, last);
  return sw.stop();
}

template<typename Container>
auto benchamrk_erase_push_back(Container &data) {
  std::cout << "benchmark_erase_push_back\t";
  sgl::stopwatch_nanoseconds sw;
  auto x = std::move(data[0]);
  data.erase(std::begin(data));
  data.push_back(std::move(x));
  return sw.stop();
}

template<typename T>
auto uniform_ints(size_t n, T start, T end) {
  std::vector<T> numbers(n);
  std::random_device r;

  std::mt19937 mt{r()};
  std::uniform_int_distribution<T> normal_dist(start, end);

  std::generate_n(std::begin(numbers), n, [&]() { return normal_dist(mt); });
  return numbers;
}


int main(int argc, char* argv[]) {
  size_t n = 1000000;
  std::vector<int> data(n);
  auto first = std::begin(data);
  auto last = std::end(data);
  std::cout << benchamrk_rotate(first, last) << std::endl;
  std::cout << benchamrk_rotate_leftmost(first, last) << std::endl;
  std::cout << benchamrk_erase_push_back(data) << std::endl;
}
