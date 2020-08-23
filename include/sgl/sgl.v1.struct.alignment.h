#pragma once

namespace sgl {
namespace v1 {

template<typename T>
struct aligment {
    static constexpr const size_t value = _aligment(T{});

private:
    template<typename U, size_t N>
    constexpr
    size_t _aligment(sgl::v1::aptr<U, N>) {
        return N;
    }

    template<typename U>
    constexpr
    size_t _aligment(U*) {
        return 1ul;
    }
};

} // namespace v1
} // namespace sgl
