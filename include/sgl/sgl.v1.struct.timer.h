
#pragma once

namespace sgl {
namespace v1 {

template<typename Unit = std::chrono::nanoseconds, typename Clock = std::chrono::high_resolution_clock>
struct timer : sgl::v1::totally_ordered<timer<Unit, Clock>> {
    typedef Unit unit_type;
    typedef Clock clock_type;

    Unit period;
    std::chrono::time_point<Clock> start;

    timer() = default;
    timer(const timer&) = default;
    timer(Unit period, std::chrono::time_point<Clock> start) : period(period), start(start) {}

    friend
    inline
    bool operator==(const timer& x, const timer& y) {
        return x.period == y.period && x.start == y.start;
    }

    friend
    inline
    bool operator!=(const timer& x, const timer& y) {
        return !(x == y);
    }

    friend
    inline
    bool operator<(const timer& x, const timer& y) {
        return x.period < y.period || (!(y.period < x.period) && x.start < y.start);
    }

    bool operator()(std::chrono::time_point<Clock> time_point) const {
        return (time_point - start) < period;
    }

    bool operator()() const {
        return operator()(Clock::now());
    }

    void reset(std::chrono::time_point<Clock> start) {
        this->start = start;
    }

    void reset() {
        this->start = Clock::now();
    }
};

} // namespace v1
} // namespace sgl
