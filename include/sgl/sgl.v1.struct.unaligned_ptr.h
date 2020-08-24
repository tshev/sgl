#pragma once

namespace sgl {
namespace v1 {

template<typename T>
struct unaligned_ptr : sgl::v1::totally_ordered<sgl::v1::unaligned_ptr<T>> {
    static constexpr const size_t alignment = 1;
    T* data;

    unaligned_ptr() = default;
    unaligned_ptr(T* data) noexcept : data(data) {}
    unaligned_ptr(const unaligned_ptr&) = default;
    unaligned_ptr& operator=(const unaligned_ptr& x) = default;

    friend
    inline
    bool operator==(unaligned_ptr x, unaligned_ptr y) noexcept {
        return x.data == y.data;
    }

    friend
    inline
    bool operator!=(unaligned_ptr x, unaligned_ptr y) noexcept {
        return !(x == y);
    }

    friend
    inline
    bool operator<(unaligned_ptr x, unaligned_ptr y) noexcept {
        return x.data < y.data;
    }

    friend
    inline
    unaligned_ptr operator+(unaligned_ptr x, size_t n) noexcept {
        return unaligned_ptr(x.data + n);
    }

    friend
    inline
    unaligned_ptr operator+(size_t n, unaligned_ptr x) noexcept {
        return unaligned_ptr(x.data + n);
    }

    friend
    inline
    unaligned_ptr operator-(unaligned_ptr x, size_t n) noexcept {
        return unaligned_ptr(x.data - n);
    }

    friend
    inline
    ptrdiff_t operator-(unaligned_ptr x, unaligned_ptr y) noexcept {
        return x.data - y.data;
    }

    unaligned_ptr& operator+=(size_t n) noexcept {
        data += n;
        return this;
    }

    unaligned_ptr& operator-=(size_t n) noexcept {
        data -= n;
        return this;
    }

    const T& operator*() const noexcept {
        return *data;
    }

    T& operator*() noexcept {
        return *data;
    }

    unaligned_ptr& operator++() noexcept {
        ++data;
        return *this;
    }

    unaligned_ptr operator++(int) noexcept {
        unaligned_ptr tmp(*this);
        ++data;
        return tmp;
    }
};

} // namespace v1
} // namespace sgl
