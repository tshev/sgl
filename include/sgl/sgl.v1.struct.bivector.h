#pragma once

namespace sgl {
namespace v1 {
template<typename T0, typename T1>
struct bivector {
  std::vector<std::pair<T0, T1>> forward;
  std::vector<size_t> backward;

  bivector() = default;
  bivector(const bivector&) = default;

  template<typename ForwardIterator>
  bivector(ForwardIterator first, ForwardIterator last) : forward(first, last), backward(forward.size()) {
    sgl::iota(std::begin(backward), std::end(backward), 0ul, 1ul);
    sort_backwards();
  }

  void sort_backwards() {
    std::sort(std::begin(backward), std::end(backward), [this](size_t i, size_t j) {
      return forward[i] < forward[j];
    });
  }

  auto find_first(const T0& x) {
    auto pos = std::lower_bound(std::begin(forward), std::end(forward), x, [](const auto& x, const T0& y) {
      return x.first < y;
    });
    if (pos == std::end(forward)) { throw_exception(); }
    return pos;
  }

  auto find_second(const T1& x) {
    size_t offset = std::lower_bound(std::begin(backward), std::end(backward), x, [this](size_t i, const T1& y) {
      return forward[i].second < y;
    }) - std::begin(backward);
    if (offset == forward.size()) { throw_exception(); }
    return std::begin(forward) + offset;
  }

  void throw_exception() {
    throw "Can't find the element";
  }
};
} // namespace v1
} // namespace sgl
