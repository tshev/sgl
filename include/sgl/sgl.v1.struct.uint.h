#pragma once
namespace sgl {
namespace v1 {

template<size_t N>
struct uint;

template<>
struct uint<8> {
    typedef uint8_t value_type;
    typedef uint8_t type;
};

template<>
struct uint<16> {
    typedef uint16_t value_type;
    typedef uint16_t type;
};

template<>
struct uint<32> {
    typedef uint32_t value_type;
    typedef uint32_t type;
};

template<>
struct uint<64> {
    typedef uint64_t value_type;
    typedef uint64_t type;
};


}
}
