#pragma once

namespace sgl {
namespace v1 {

template<typename T = uint64_t>
struct nanoseconds {
    typedef T value_type;

    T value;

    nanoseconds(const T& value) noexcept : value(value) {}
    nanoseconds(const nanoseconds& x) noexcept : value(x.value) {}

    nanoseconds& operator=(const nanoseconds& x) noexcept {
      value = x.value;
    }

    friend
    inline
    bool operator==(const nanoseconds& x, const nanoseconds& y) noexcept {
        return x.value == y.value;
    }

    friend
    inline
    bool operator<(const nanoseconds& x, const nanoseconds& y) noexcept {
        return x.value < y.value;
    }

    friend
    inline
    bool operator<=(const nanoseconds& x, const nanoseconds& y) noexcept {
        return !(y < x);
    }

    friend
    inline
    bool operator>(const nanoseconds& x, const nanoseconds& y) noexcept {
        return y < x;
    }

    friend
    inline
    bool operator>=(const nanoseconds& x, const nanoseconds& y) noexcept {
        return !(x < y);
    }

    friend
    inline
    nanoseconds operator+(const nanoseconds& x, const nanoseconds& y) {
        return nanoseconds(x.value + y.value);
    }

    friend
    inline
    nanoseconds operator-(const nanoseconds& x, const nanoseconds& y) {
        return nanoseconds(x.value - y.value);
    }

    template<typename U>
    friend
    inline
    typename std::enable_if<std::is_arithmetic<U>::value, nanoseconds>::type
    operator*(const nanoseconds& x, const U& y) {
        return nanoseconds(x.value * y);
    }

    template<typename U>
    friend
    inline
    typename std::enable_if<std::is_arithmetic<U>::value, nanoseconds>::type
    operator*(const U& x, const nanoseconds& y) {
        return nanoseconds(x * y.value);
    }

    template<typename U>
    friend
    inline
    typename std::enable_if<std::is_arithmetic<U>::value, nanoseconds>::type
    operator/(const nanoseconds& x, const U& y) {
        return nanoseconds(x.value / y);
    }

    template<typename Ostream>
    friend
    inline
    Ostream& operator<<(Ostream& ostream, const nanoseconds& x) {
        ostream << x.value;
        return ostream;
    }

    template<typename Istream>
    friend
    inline
    Istream& operator>>(Istream& istream, const nanoseconds& x) {
        istream >> x.value;
        return istream;
    }
};

typedef nanoseconds<uint64_t> nsui64;

} // namespace v1
} // namespace sgl
