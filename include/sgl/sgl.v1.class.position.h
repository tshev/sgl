#pragma once

namespace sgl {
namespace v1 {

template<typename T>
class position : sgl::v1::totally_ordered<position<T>> {
    T value;
public:
    position() = default;
    position(const T& value) noexcept(sgl::v1::is_nothrow_copyable<T>::value) : value(value)  {}
    position(const position& x) = default;

    friend
    inline
    bool operator==(const position& x, const position& y) {
        return x.value == y.value;
    }

    friend
    inline
    bool operator!=(const position& x, const position& y) {
        return !(x == y);
    }

    friend
    inline
    bool operator<(const position& x, const position& y) {
        return x.value < y.value;
    }

    position& operator++() noexcept {
        ++value;
        return *this;
    }

    position operator++(int) noexcept {
        position tmp(*this);
        ++(*this);
        return tmp;
    }

    const T& operator*() const {
        return value;
    }
    
}; // class position

} // namespace v1
} // namespace sgl
