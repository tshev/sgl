#pragma once
namespace sgl {
namespace v1 {
template<typename T>
class coordinate {
    T value;
public:
    coordinate() = default;
    coordinate(const T& value) : value(value) {}
    coordinate(const coordinate& x ) : value(x.value) {}

    coordinate& operator=(const coordinate& x) {
        value = x.value;
        return *this;
    }

    coordinate& operator++() {
        ++value;
        return *this;
    }

    T operator*() const {
        return value;
    }

    friend
    inline
    bool operator==(const coordinate& x, const coordinate& y) {
        return x.value == y.value;
    }

    friend
    inline
    bool operator!=(const coordinate& x, const coordinate& y) {
        return !(x == y);
    }

    friend
    inline
    bool operator<(const coordinate& x, const coordinate& y) {
        return x.value < y.value;
    }

    friend
    inline
    bool operator<=(const coordinate& x, const coordinate& y) {
        return !(y < x);
    }

    friend
    inline
    bool operator>(const coordinate& x, const coordinate& y) {
        return y < x;
    }

    friend
    inline
    bool operator>=(const coordinate& x, const coordinate& y) {
        return !(x < y);
    }
};
}
}
