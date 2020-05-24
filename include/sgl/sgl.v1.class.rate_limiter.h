#pragma once

namespace sgl {
namespace v1 {

class rate_limiter {
public:
    typedef std::chrono::high_resolution_clock clock_type;
    typedef clock_type::time_point time_point_type;

private:
    size_t max_actions_count_;
    std::chrono::nanoseconds period_;

    size_t count_;
    time_point_type start_;

public:
    rate_limiter() noexcept = default;
    rate_limiter(size_t max_actions_count, std::chrono::nanoseconds period) noexcept
        : max_actions_count_(max_actions_count)
        , period_(period)
        , count_(0ul)
        , start_(clock_type::now()) {}

    rate_limiter(const rate_limiter& x) = default;

    friend
    inline
    bool operator==(const rate_limiter& x, const rate_limiter& y) noexcept {
        return x.max_actions_count_ == y.max_actions_count_ && x.period_ == y.period_ && x.count_ == y.count_ && x.start_ == y.start_;
    }

    friend
    inline
    bool operator!=(const rate_limiter& x, const rate_limiter& y) noexcept {
        return !(x == y);
    }


    bool wait(time_point_type now) const noexcept {
      if (now - start_ < period_) {
            return count_ < max_actions_count_;
      }
      return true;
    }

    bool try_use(time_point_type now) noexcept {
        if (now - start_ < period_) {
            if (count_ < max_actions_count_) {
                ++count_;
                return true;
            } else {
                return false;
            }
        }
        start_ = now;
        count_ = 1ul;
        return true;
    }

    bool try_use() noexcept {
        return try_use(clock_type::now());
    }
};

} // namespace v1
} // namespace sgl
