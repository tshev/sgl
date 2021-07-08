#pragma once

namespace sgl {
namespace v1 {

template<typename T>
struct _ceil_pow2 {
    T operator()(T value, size_t bit_count) const {
        --value;
        for (size_t i = 1; i < bit_count; i <<= 1) {
            value |= value >> i;
        }
        return ++value;
    }

    T operator()(T value) const {
        --value;
        int i = 1;
        while (true) {
            T shifted = value >> i;
            if (sgl::v1::zero(shifted)) return ++value;
            i *= 2;
            value |= shifted;
        }
        // unreachable
        return value;
    }
};

template<>
struct _ceil_pow2<uint64_t> {
    uint64_t operator()(uint64_t value) const noexcept {
        --value;
        value |= value >> 1;
        value |= value >> 2;
        value |= value >> 4;
        value |= value >> 8;
        value |= value >> 16;
        value |= value >> 32;
        return ++value;
    }
};

template<>
struct _ceil_pow2<int64_t> {
    int64_t operator()(int64_t value) const noexcept {
        --value;
        value |= value >> 1;
        value |= value >> 2;
        value |= value >> 4;
        value |= value >> 8;
        value |= value >> 16;
        value |= value >> 32;
        return ++value;
    }
};


template<>
struct _ceil_pow2<uint32_t> {
    uint32_t operator()(uint32_t value) const noexcept {
        --value;
        value |= value >> 1;
        value |= value >> 2;
        value |= value >> 4;
        value |= value >> 8;
        value |= value >> 16;
        return ++value;
    }
};

template<>
struct _ceil_pow2<int32_t> {
    int32_t operator()(int32_t value) const noexcept {
        --value;
        value |= value >> 1;
        value |= value >> 2;
        value |= value >> 4;
        value |= value >> 8;
        value |= value >> 16;
        return ++value;
    }
};

template<>
struct _ceil_pow2<uint16_t> {
    uint16_t operator()(uint16_t value) const noexcept {
        --value;
        value |= value >> 1;
        value |= value >> 2;
        value |= value >> 4;
        value |= value >> 8;
        return ++value;
    }
};

template<>
struct _ceil_pow2<int16_t> {
    int16_t operator()(int16_t value) const noexcept {
        --value;
        value |= value >> 1;
        value |= value >> 2;
        value |= value >> 4;
        value |= value >> 8;
        return ++value;
    }
};

template<>
struct _ceil_pow2<uint8_t> {
    uint8_t operator()(uint8_t value) const noexcept {
        --value;
        value |= value >> 1;
        value |= value >> 2;
        value |= value >> 4;
        return ++value;
    }
};

template<>
struct _ceil_pow2<int8_t> {
    int8_t operator()(int8_t value) const noexcept {
        --value;
        value |= value >> 1;
        value |= value >> 2;
        value |= value >> 4;
        return ++value;
    }
};

template<typename N>
inline
N ceil_pow2(const N& value) noexcept {
    return sgl::v1::_ceil_pow2<N>()(value);
}

template<typename N>
inline
N ceil_pow2(const N& value, size_t bit_count) noexcept {
    return sgl::v1::_ceil_pow2<N>()(value, bit_count);
}

}
}
