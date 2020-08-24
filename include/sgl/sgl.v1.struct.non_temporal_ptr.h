#pragma once

namespace sgl {
namespace v1 {

template<typename T, size_t N>
struct non_temporal_ptr : sgl::v1::totally_ordered<sgl::v1::non_temporal_ptr<T, N>> {
    static constexpr const size_t alignment = N;
    T* data;

    non_temporal_ptr() = default;
    non_temporal_ptr(T* data) noexcept : data(data) {}
    non_temporal_ptr(const non_temporal_ptr&) = default;
    non_temporal_ptr& operator=(const non_temporal_ptr& x) = default;

    friend
    inline
    bool operator==(non_temporal_ptr x, non_temporal_ptr y) noexcept {
        return x.data == y.data;
    }

    friend
    inline
    bool operator!=(non_temporal_ptr x, non_temporal_ptr y) noexcept {
        return !(x == y);
    }

    friend
    inline
    bool operator<(non_temporal_ptr x, non_temporal_ptr y) noexcept {
        return x.data < y.data;
    }

    friend
    inline
    non_temporal_ptr operator+(non_temporal_ptr x, size_t n) noexcept {
        return non_temporal_ptr(x.data + n);
    }

    friend
    inline
    non_temporal_ptr operator+(size_t n, non_temporal_ptr x) noexcept {
        return non_temporal_ptr(x.data + n);
    }

    friend
    inline
    non_temporal_ptr operator-(non_temporal_ptr x, size_t n) noexcept {
        return non_temporal_ptr(x.data - n);
    }

    friend
    inline
    ptrdiff_t operator-(non_temporal_ptr x, non_temporal_ptr y) noexcept {
        return x.data - y.data;
    }

    non_temporal_ptr& operator+=(size_t n) noexcept {
        data += n;
        return this;
    }

    non_temporal_ptr& operator-=(size_t n) noexcept {
        data -= n;
        return this;
    }

    const T& operator*() const noexcept {
        return *data;
    }

    T& operator*() noexcept {
        return *data;
    }

    non_temporal_ptr& operator++() noexcept {
        ++data;
        return *this;
    }

    non_temporal_ptr operator++(int) noexcept {
        non_temporal_ptr tmp(*this);
        ++data;
        return tmp;
    }
};

} // namespace v1
} // namespace sgl
