#pragma once

namespace sgl {
namespace v1 {

template<typename T, size_t N>
struct aligned_ptr : sgl::v1::totally_ordered<sgl::v1::aligned_ptr<T, N>> {
    static constexpr const size_t alignment = N;
    T* data;

    aligned_ptr() = default;
    aligned_ptr(T* data) noexcept : data(data) {}
    aligned_ptr(const aligned_ptr&) = default;
    aligned_ptr& operator=(const aligned_ptr& x) = default;

    friend
    inline
    bool operator==(aligned_ptr x, aligned_ptr y) noexcept {
        return x.data == y.data;
    }

    friend
    inline
    bool operator!=(aligned_ptr x, aligned_ptr y) noexcept {
        return !(x == y);
    }

    friend
    inline
    bool operator<(aligned_ptr x, aligned_ptr y) noexcept {
        return x.data < y.data;
    }

    friend
    inline
    aligned_ptr operator+(aligned_ptr x, size_t n) noexcept {
        return aligned_ptr(x.data + n);
    }

    friend
    inline
    aligned_ptr operator+(size_t n, aligned_ptr x) noexcept {
        return aligned_ptr(x.data + n);
    }

    friend
    inline
    aligned_ptr operator-(aligned_ptr x, size_t n) noexcept {
        return aligned_ptr(x.data - n);
    }

    friend
    inline
    ptrdiff_t operator-(aligned_ptr x, aligned_ptr y) noexcept {
        return x.data - y.data;
    }

    aligned_ptr& operator+=(size_t n) noexcept {
        data += n;
        return this;
    }

    aligned_ptr& operator-=(size_t n) noexcept {
        data -= n;
        return this;
    }

    const T& operator*() const noexcept {
        return *data;
    }

    T& operator*() noexcept {
        return *data;
    }

    aligned_ptr& operator++() noexcept {
        ++data;
        return *this;
    }

    aligned_ptr operator++(int) noexcept {
        aligned_ptr tmp(*this);
        ++data;
        return tmp;
    }
};

} // namespace v1
} // namespace sgl#pragma once
