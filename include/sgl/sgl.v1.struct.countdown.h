#pragma once
namespace sgl {
namespace v1 {
template<typename N>
struct countdown : sgl::v1::totally_ordered<sgl::v1::countdown<N>> {
    N value; 

    countdown() : value(0) {}
    countdown(N n) : value(n) {}
    countdown(const countdown&) = default;

    friend
    inline
    bool operator==(const countdown& x, const countdown& y) {
        return x == y;
    }

    friend
    inline
    bool operator!=(const countdown& x, const countdown& y) {
        return !(x == y);
    }

    friend
    inline
    bool operator<(const countdown& x, const countdown& y) {
        return x.value < y.value;
    }

    bool operator()() {
        if (value == 0) {
            return false;
        }
        --value;
        return true;
    }
};
} // namespace v1
} // namespace sgl
