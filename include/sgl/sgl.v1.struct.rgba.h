#pragma once

namespace sgl {
namespace v1 {

template<typename N>
struct rgba : sgl::v1::totally_ordered<sgl::v1::rgba<N>> { // it might be interesting to check the impact on compilation time to decide which approach is efficient
    // TODO: think about bitfields and portable bitfields
    typedef N value_type;

    N value; 

    rgba() = default;

    template<typename Number>
    constexpr
    rgba(Number r, Number g, Number b) : value(N(r) + (N(g) << N(8)) + (N(b) << N(16))) {}

    template<typename Number>
    constexpr
    rgba(Number r, Number g, Number b, float a) : value(N(r) + (N(g) << N(8)) + (N(b) << N(16)) + (N(a * 255.0f) << N(24))) {}

    template<typename Number>
    constexpr
    rgba(Number r, Number g, Number b, Number a) : value(N(r) + (N(g) << N(8)) + (N(b) << N(16)) + (N(b) << N(24))) {}

    constexpr
    rgba(N value) : value(value) {}

    rgba(const rgba&) = default;

    rgba(rgba&&) = default;

    friend
    inline
    constexpr
    bool operator==(const rgba& x, const rgba& y) noexcept {
        return x.value == y.value;
    }

    friend
    inline
    constexpr
    bool operator!=(const rgba& x, const rgba& y) noexcept {
        return !(x == y);
    }

    friend
    inline
    constexpr
    bool operator<(const rgba& x, const rgba& y) noexcept {
        return x.value < y.value;
    }

    constexpr
    N r() const noexcept {
        return value & N(0x000000FFu);
    }

    constexpr
    void set_r(N n) noexcept {
        value = (value | N(0x000000FFu)) & n;
    }

    constexpr
    N g() const noexcept {
        return (value & N(0x0000FF00u)) >> N(8);
    }

    constexpr
    void set_g(N n) noexcept {
        value = (value | N(0x0000FF00u)) & (n << N(8));
    }

    constexpr
    N b() const noexcept {
        return (value & N(0x00FF0000u)) >> N(16);
    }

    constexpr
    void set_b(N n) noexcept {
        value = (value | N(0x00FF0000u)) & (n << N(16));
    }

    constexpr
    N a() const noexcept {
        return (value & N(0xFF000000u)) >> N(24);
    }

    constexpr
    void set_a(N n) {
        value = (value | N(0xFF000000u)) & (n << N(24));
    }

    constexpr
    float a_float() const noexcept  {
        return float((value & N(0xFF000000u)) >> N(24)) / 255.0f;
    }

    constexpr
    void set_a(float a) {
        value = (value | N(0xFF000000u)) & (N(a * 255.0f) << N(24));
    }

}; // struct rgba

} // namespace v1
} // namespace sgl
