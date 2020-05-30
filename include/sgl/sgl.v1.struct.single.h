#pragma once

namespace sgl {
namespace v1 {

template<typename T>
struct single {
    typedef T value_type;
    T value; 

    single() = default;
    single(single const&) = default;
    single(T const& value) noexcept : value(value) {}

    friend
    inline
    bool operator==(single const& x, single const& y) noexcept {
        return x.value == y.value;
    }

    friend
    inline
    bool operator!=(single const& x, single const& y) noexcept {
        return !(x == y);
    }
};

} // namespace v1
} // namespace sgl
