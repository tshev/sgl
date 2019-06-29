#include <random>
#include <vector>
#include <unordered_map>
#include <cstring>

#include "../sgl/sgl.h"
template<typename T>
auto uniform_ints(size_t n, T start, T end) {
  std::vector<T> numbers(n);
  std::random_device r;

  std::mt19937 mt{r()};
  std::uniform_int_distribution<T> normal_dist(start, end);

  std::generate_n(std::begin(numbers), n, [&]() { return normal_dist(mt); });
  return numbers;
}

template<typename InputIterator>
double bm_unordered_map(InputIterator first, InputIterator last) {
  sgl::stopwatch_nanoseconds sw;
  std::unordered_map<uint32_t, size_t> frequencies;
  sgl::for_each(first, last, [&frequencies](auto x) {
    ++frequencies[x];
  });
  auto speed = sw.stop();
  volatile auto f = frequencies[0];
  return speed;
}

template<typename InputIterator>
size_t bm_frequencies(InputIterator first, InputIterator last) {
  sgl::stopwatch_nanoseconds sw;
  std::sort(first, last);
  std::vector<sgl::pair<int32_t, uint32_t>> frequencies(last - first);
  sgl::frequencies(first, last, std::begin(frequencies));
  auto speed = sw.stop();
  volatile auto f = frequencies[0];
  return speed;
}

template<typename ForwardIterator>
sgl::pair<double, double> mean_derivation(ForwardIterator first, ForwardIterator last) {
  double n = std::distance(first, last);
  double sum = sgl::accumulate(first, last, 0.0, [](double r, auto x) { return r + x; });
  double mean = sum / n;
  double variance = sgl::accumulate(first, last, 0.0, [mean](auto r, auto x) { return r + sgl::square(x - mean); }) / n;
  double norm_nsec = 1000;
  return std::make_pair(mean / norm_nsec, variance / norm_nsec);
}

uint32_t uint32_from_bytes(const char* src, uint8_t n) {
  uint32_t result = 0;
  memcpy(&result, src, n);
  return result;
}

template<typename InputIterator, typename OutputIterator>
OutputIterator int32_ngrams(size_t n, InputIterator first, InputIterator last, OutputIterator out) {
  sgl::transform(first, last, out, [n](const auto &x) { return from_bytes(&x, n); });
}

int main() {
  auto data = uniform_ints(2 * 4 * 8000, uint32_t{0}, uint32_t{40000});

  size_t n_runs = 10000;
  std::cout << n_runs << std::endl;
  std::vector<size_t> timings_0;
  std::vector<size_t> timings_1;
  while (n_runs-- > 0) {
    auto numbers = data;
    auto first = std::begin(numbers);
    auto last = std::end(numbers);
    timings_0.push_back(bm_unordered_map(first, last));
    timings_1.push_back(bm_frequencies(first, last));
  }

  auto r0 = mean_derivation(std::begin(timings_0), std::end(timings_0));
  auto r1 = mean_derivation(std::begin(timings_1), std::end(timings_1));
  std::cout << r0.first << " " << std::sqrt(r0.second) << " ";
  std::cout << r1.first << " " << std::sqrt(r1.second) << std::endl;

  const char* str = "aaaabc dsldasjlasjdlasd jwieewabc";
  const size_t n = 3;
  const size_t size = strlen(str);
  std::vector<int32_t> words(size + 1 - n);
  int32_ngrams(3, str, str + size, std::begin(words));
  for (auto x : words) { std::cout << x << std::endl; }
  std::cout << size << std::endl;
}
