#pragma once

namespace sgl {
namespace v1 {
template<typename T, typename Clock=typename std::chrono::system_clock>
struct stopwatch {
  typedef Clock clock_type;
  typedef T time_unit_type;
  typedef std::chrono::time_point<clock_type> time_point;
  time_point time;

  stopwatch() : time(now()) {}

  auto start() {
    time = now(); 
  }

  auto stop() {
    return std::chrono::duration_cast<time_unit_type>(now() - time).count();
  }

  time_point now() const {
    return std::chrono::system_clock::now();
  }
};

typedef stopwatch<std::chrono::nanoseconds> stopwatch_nanoseconds;
typedef stopwatch_nanoseconds swns;
typedef stopwatch_nanoseconds sw;

template<typename F, typename R>
size_t measure(F &&f, R &result) {
  stopwatch_nanoseconds stopwatch;
  result = f();
  return stopwatch.stop();
}

template<typename F, typename R>
size_t measure_nano(F &&f, R &result) {
  stopwatch_nanoseconds stopwatch;
  result = f();
  return stopwatch.stop();
}


template<typename F>
size_t measure(F &&f) {
  stopwatch_nanoseconds stopwatch;
  f();
  return stopwatch.stop();
}
} // namespace v1
} // namespace sgl
