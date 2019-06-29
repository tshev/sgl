#pragma once

namespace sgl {
namespace v1 {
extern double instrumented_base_counts[];
extern const char* instrumented_base_counter_names[];
struct instrumented_base {
  enum operations {
    n=0, copy=1, assignment=2, destructor=3, default_constructor=4, equality=5, comparison=6, construction=7
  };
  static const size_t number_ops = 8;
  static const char* counter_names[number_ops];
  static void initialize(size_t m) {
    std::fill(instrumented_base_counts, instrumented_base_counts + number_ops, 0.0);
    instrumented_base_counts[n] = double(m);
  }
  template<typename Ostream>
  static void report(Ostream &cout) {
    for (size_t i = 0; i < number_ops; ++i) {
      cout << instrumented_base_counter_names[i] << " " << instrumented_base_counts[i] << "\n";
    }
  }

  template<typename F, typename OutputIterator>
  static OutputIterator run(OutputIterator out, F &&f) {
    initialize(0);
    f();
    return std::copy(instrumented_base_counter_names, instrumented_base_counter_names + number_ops, out);
  }

  static void assertion(operations op, double val) {
    assert(instrumented_base_counts[op] == val);
  }
}; // struct instrumented_base

double instrumented_base_counts[instrumented_base::number_ops];
const char* instrumented_base_counter_names[instrumented_base::number_ops] = {"n",
                                                                              "copy",
                                                                              "assignment",
                                                                              "destructor",
                                                                              "default_constructor",
                                                                              "equality",
                                                                              "comparison",
                                                                              "construction"};

template <typename T> 
// requires(Semiregualr(T) || Regular(T) || TotallyOrdered(T))
struct instrumented :  instrumented_base {
  typedef T value_type;

  T value;
  // Conversions from T and to T:
  instrumented(const T& x) : value(x) { ++instrumented_base_counts[construction]; }

  operator T() {
    return value;
  }
  // Semiregular:
  instrumented(const instrumented& x) : value(x.value) {
    ++instrumented_base_counts[copy];
  } 
  instrumented() { ++instrumented_base_counts[default_constructor]; }
  ~instrumented() { ++instrumented_base_counts[destructor]; }
  instrumented& operator=(const instrumented& x) {  
    ++instrumented_base_counts[assignment];
    value = x.value;
    return *this;
  }
  // Regular
  friend
  bool operator==(const instrumented& x, const instrumented& y) {
    ++instrumented_base_counts[equality];
    return x.value == y.value;
  }
  friend
  bool operator!=(const instrumented& x, const instrumented& y) {
     return !(x == y);
  }
  // TotallyOrdered
  friend
  bool operator<(const instrumented& x, const instrumented& y) { 
    ++instrumented_base_counts[comparison];
    return x.value < y.value;
  }
  friend
  bool operator>(const instrumented& x, const instrumented& y) {
    return y < x;
  }
  friend
  bool operator<=(const instrumented& x, const instrumented& y) {
    return !(y < x);
  }
  friend
  bool operator>=(const instrumented& x, const instrumented& y) {
    return !(x < y);
  } 
}; // struct instrumended
} // namespace v1
} // namespace sgl
