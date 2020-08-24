#pragma once

namespace sgl {
namespace v1 {

template<typename T>
struct uptr : sgl::v1::totally_ordered<sgl::v1::uptr<T>> {
    static constexpr const size_t alignment = 1ul;
    T* data;

    uptr() = default;
    uptr(T* data) noexcept : data(data) {}
    uptr(const uptr&) = default;
    uptr& operator=(const uptr& x) = default;

    friend
    inline
    bool operator==(uptr x, uptr y) noexcept {
        return x.data == y.data;
    }

    friend
    inline
    bool operator!=(uptr x, uptr y) noexcept {
        return !(x == y);
    }

    friend
    inline
    bool operator<(uptr x, uptr y) noexcept {
        return x.data < y.data;
    }

    friend
    inline
    uptr operator+(uptr x, size_t n) noexcept {
        return uptr(x.data + n);
    }

    friend
    inline
    uptr operator+(size_t n, uptr x) noexcept {
        return uptr(x.data + n);
    }

    friend
    inline
    uptr operator-(uptr x, size_t n) noexcept {
        return uptr(x.data - n);
    }

    friend
    inline
    ptrdiff_t operator-(uptr x, uptr y) noexcept {
        return x.data - y.data;
    }

    uptr& operator+=(size_t n) noexcept {
        data += n;
        return this;
    }

    uptr& operator-=(size_t n) noexcept {
        data -= n;
        return this;
    }

    const T& operator*() const noexcept {
        return *data;
    }

    T& operator*() noexcept {
        return *data;
    }

    uptr& operator++() noexcept {
        ++data;
        return *this;
    }

    uptr operator++(int) noexcept {
        uptr tmp(*this);
        ++data;
        return tmp;
    }
};

} // namespace v1
} // namespace sgl
