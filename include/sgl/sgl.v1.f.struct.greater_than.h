#pragma once
namespace sgl {
namespace v1 {

template<typename T>
struct greater_than {
    T value;

    greater_than() = default;
    greater_than(const greater_than&) = default;
    greater_than(const T& value) : value(value) {}

    friend
    inline
    bool operator==(const greater_than& x, const greater_than& y) {
        return x.value == y.value;
    }

    friend
    inline
    bool operator!=(const greater_than& x, const greater_than& y) {
        return !(x == y);
    }

    friend
    inline
    bool operator<(const greater_than& x, const greater_than& y) {
        return x.value < y.value;
    }

    friend
    inline
    bool operator<=(const greater_than& x, const greater_than& y) {
        return !(y < x);
    }

    friend
    inline
    bool operator>(const greater_than& x, const greater_than& y) {
        return y < x;
    }

    friend
    inline
    bool operator>=(const greater_than& x, const greater_than& y) {
        return !(x < y);
    }

    bool operator()(const T& x) const {
        return value < x;
    }
};

} // namespace v1
} // namespace sgl
