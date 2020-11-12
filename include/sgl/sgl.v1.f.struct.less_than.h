#pragma once
namespace sgl {
namespace v1 {

template<typename T>
struct less_than {
    T value;

    less_than() = default;
    less_than(const less_than&) = default;
    less_than(const T& value) : value(value) {}

    friend
    inline
    bool operator==(const less_than& x, const less_than& y) {
        return x.value == y.value;
    }

    friend
    inline
    bool operator!=(const less_than& x, const less_than& y) {
        return !(x == y);
    }

    friend
    inline
    bool operator<(const less_than& x, const less_than& y) {
        return x.value < y.value;
    }

    friend
    inline
    bool operator<=(const less_than& x, const less_than& y) {
        return !(y < x);
    }

    friend
    inline
    bool operator>(const less_than& x, const less_than& y) {
        return y < x;
    }

    friend
    inline
    bool operator>=(const less_than& x, const less_than& y) {
        return !(x < y);
    }

    bool operator()(const T& x) const {
        return x < value;
    }
};

} // namespace v1
} // namespace sgl
