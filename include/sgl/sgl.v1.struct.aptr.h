#pragma once

namespace sgl {
namespace v1 {

template<typename T, size_t N>
struct aptr : sgl::v1::totally_ordered<sgl::v1::aptr<T, N>> {
    static constexpr const size_t alignment = N;
    T* data;

    aptr() = default;
    aptr(T* data) noexcept : data(data) {}
    aptr(const aptr&) = default;
    aptr& operator=(const aptr& x) = default;

    friend
    inline
    bool operator==(aptr x, aptr y) noexcept {
        return x.data == y.data;
    }

    friend
    inline
    bool operator!=(aptr x, aptr y) noexcept {
        return !(x == y);
    }

    friend
    inline
    bool operator<(aptr x, aptr y) noexcept {
        return x.data < y.data;
    }

    friend
    inline
    aptr operator+(aptr x, size_t n) noexcept {
        return aptr(x.data + n);
    }

    friend
    inline
    aptr operator+(size_t n, aptr x) noexcept {
        return aptr(x.data + n);
    }

    friend
    inline
    aptr operator-(aptr x, size_t n) noexcept {
        return aptr(x.data - n);
    }

    friend
    inline
    ptrdiff_t operator-(aptr x, aptr y) noexcept {
        return x.data - y.data;
    }

    aptr& operator+=(size_t n) noexcept {
        data += n;
        return this;
    }

    aptr& operator-=(size_t n) noexcept {
        data -= n;
        return this;
    }

    const T& operator*() const noexcept {
        return *data;
    }

    T& operator*() noexcept {
        return *data;
    }

    aptr& operator++() noexcept {
        ++data;
        return *this;
    }

    aptr operator++(int) noexcept {
        aptr tmp(*this);
        ++data;
        return tmp;
    }
};

} // namespace v1
} // namespace sgl
