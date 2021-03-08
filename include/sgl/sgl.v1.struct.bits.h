#pragma once

namespace sgl {
namespace v1 {

template<size_t N>
struct bits : sgl::v1::totally_ordered<bits<N>> {
    typedef typename sgl::v1::uint<N>::value_type value_type;
    value_type value;

    struct true_t {};
    struct false_t {};

    class proxy_type {
        bits* proxy;
        value_type i;
        
    public: 
        proxy_type() = default;

        proxy_type(const proxy_type&) = default;

        proxy_type(bits* proxy, value_type i) noexcept : proxy(proxy), i(i) {}

        friend
        inline
        constexpr
        bool operator==(const proxy_type& x, const proxy_type& y) noexcept {
            return x.proxy == y.proxy && x.i == y.i;
        }

        friend
        inline
        constexpr
        bool operator!=(const proxy_type& x, const proxy_type& y) noexcept {
            return !(x == y);
        }

        operator bool() const noexcept {
            return proxy->value & (value_type(1) << i);
        }

        proxy_type& operator=(bool v) noexcept {
            proxy->set(i, v);
            return *this;
        }

        proxy_type& operator=(false_t x) noexcept {
            proxy->set(i, x);
            return *this;
        }

        proxy_type& operator=(true_t x) noexcept {
            proxy->set(i, x);
            return *this;
        }
    };

    constexpr bits() = default;

    constexpr bits(value_type value) noexcept : value(value) {}

    constexpr bits(std::initializer_list<int> v) : value(0){
        size_t i = 0;
        for (auto x : v) {
            if (x)
                value = value | (value_type(1) << i);
            ++i;
        }
    }

    constexpr bits(const bits&) = default;

    friend
    inline
    constexpr
    bool operator==(bits x, bits y) noexcept {
        return x.value == y.value;
    }

    friend
    inline
    constexpr
    bool operator!=(bits x, bits y) noexcept {
        return !(x == y);
    }

    friend
    inline
    constexpr
    bool operator<(bits x, bits y) noexcept {
        return x.value < y.value;
    }

    template<value_type I>
    constexpr
    bool get() const noexcept {
        return value & (value_type(1) << I);
    }

    constexpr
    bool get(value_type i) const noexcept {
        return value & (value_type(1) << i);
    }

    constexpr
    void set(value_type i, true_t) noexcept {
        value = value | (value_type(1) << i);
    }

    constexpr
    void set(value_type i, false_t) noexcept {
        value = value & (~(value_type(1) << i));
    }

    constexpr
    void set(value_type i, bool x) noexcept {
        if (x) set(i, true_t{});
        else set(i, false_t{});
    }

    template<value_type i>
    constexpr
    void set(true_t) noexcept {
        value = value | (value_type(1) << i);
    }

    template<value_type i>
    constexpr
    void set(false_t) noexcept {
        value = value & (~(value_type(1) << i));
    }

    proxy_type operator[](value_type i) noexcept {
        return proxy_type{this, i};
    }

    proxy_type operator[](value_type i) const noexcept {
        return proxy_type{this, i};
    }

    true_t one() const noexcept {
        return true_t();
    }

    false_t zero() const noexcept {
        return false_t();
    }
}; // struct bits

} // namespace v1
} // namespace sgl
