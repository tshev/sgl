#pragma once
// experimental implementation

namespace sgl {
namespace v1 {


std::pair<uint64_t, const uint8_t*> _sgl__v1__class__array_string__decode(const uint8_t* data) {
    uint64_t value = int64_t(*data) & 0x7full;
    if ((*data >> 7) == 0) return std::make_pair(value, ++data);
    ++data;

    value |= (uint64_t(*data) & 0x7full) << 7;
    if ((*data >> 7) == 0) return std::make_pair(value, ++data);
    ++data;

    value |= (uint64_t(*data) & 0x7full) << 14;
    if ((*data >> 7) == 0) return std::make_pair(value, ++data);
    ++data;

    value |= (uint64_t(*data) & 0x7full) << 21;
    if ((*data >> 7) == 0) return std::make_pair(value, ++data);
    ++data;

    value |= (uint64_t(*data) & 0x7full) << 28;
    if ((*data >> 7) == 0) return std::make_pair(value, ++data);
    ++data;

    value |= (uint64_t(*data) & 0x7full) << 35;
    if ((*data >> 7) == 0) return std::make_pair(value, ++data);
    ++data;

    value |= (uint64_t(*data) & 0x7full) << 42;
    if ((*data >> 7) == 0) return std::make_pair(value, ++data);
    ++data;

    value |= (uint64_t(*data) & 0x7full) << 49;
    if ((*data >> 7) == 0) return std::make_pair(value, ++data);
    ++data;

    value |= (uint64_t(*data) & 0x7full) << 56;
    if ((*data >> 7) == 0) return std::make_pair(value, ++data);
    ++data;

    value |= (uint64_t(*data) & 0x7full) << 63;
    return std::make_pair(value, ++data);
}

uint8_t* _sgl__v1__class__array_string__encode(uint64_t value, uint8_t* out) {
    *out = uint64_t(0x7f) & value;
    value >>= 7;
    *out |= 0x80;
    ++out;

    *out = uint64_t(0x7f) & value;
    value >>= 7;
    if (value == 0) return ++out;
    *out |= 0x80;
    ++out;

    *out = uint64_t(0x7f) & value;
    value >>= 7;
    if (value == 0) return ++out;
    *out |= 0x80;
    ++out;

    *out = uint64_t(0x7f) & value;
    value >>= 7;
    if (value == 0) return ++out;
    *out |= 0x80;
    ++out;

    *out = uint64_t(0x7f) & value;
    value >>= 7;
    if (value == 0) return ++out;
    *out |= 0x80;
    ++out;

    *out = uint64_t(0x7f) & value;
    value >>= 7;
    if (value == 0) return ++out;
    *out |= 0x80;
    ++out;

    *out = uint64_t(0x7f) & value;
    value >>= 7;
    if (value == 0) return ++out;
    *out |= 0x80;
    ++out;

    *out = uint64_t(0x7f) & value;
    value >>= 7;
    if (value == 0) return ++out;
    *out |= 0x80;
    ++out;

    *out = uint64_t(0x7f) & value;
    value >>= 7;
    if (value == 0) return ++out;
    *out |= 0x80;
    ++out;

    *out = uint64_t(0x7f) & value;
    value >>= 7;
    ++out;
    return out;
}


template<typename T>
class array_string;


template<>
class array_string<uint64_t> {
    typedef uint64_t size_type;

    sgl::v1::array<uint8_t> position8;
    sgl::v1::array<uint16_t> position16;
    sgl::v1::array<uint32_t> position32;
    sgl::v1::array<uint64_t> position64;
    std::vector<char> data;

public:

    std::pair<char*, size_type> operator[](size_type i) {
        if (i < std::numeric_limits<uint8_t>::max()) {
            i = position8[i];
        } else if (i < std::numeric_limits<uint16_t>::max()) {
            i = position16[i];
        } else if (i < std::numeric_limits<uint32_t>::max()) {
            i = position32[i];
        } else {
            i = position64[i];
        }
        uint8_t* result = (uint8_t*)&data[i];
        auto p = sgl::v1::_sgl__v1__class__array_string__decode(result);
        std::cout << "L = " << p.first << std::endl;
        return std::make_pair((char*)p.second, p.first);
    }

    void emplace_back(const char* first) {
        emplace_back(first, std::strlen(first));
    }

    void emplace_back(const char* first, size_type n) {
        size_type batch_size = n + size_type(10);
        size_type size_old = data.size();
        size_type size_new = size_old + batch_size;

        try {
            data.resize(size_new);
            if (size_new < data.size()) {
                data.reserve(sgl::v1::max<size_type>(size_old * 2ull, size_new));
            } else if (position8.size() != size_type(std::numeric_limits<uint8_t>::max())) {
                position8.push_back(size_old); 
            } else if (position16.size() != size_type(std::numeric_limits<uint16_t>::max())) {
                position16.push_back(size_old); 
            } else if (position32.size() != size_type(std::numeric_limits<uint32_t>::max())) {
                position32.push_back(size_old); 
            } else {
                position64.push_back(size_old); 
            }
            auto out1 = (uint8_t*)&data[size_old];
            auto out = sgl::v1::_sgl__v1__class__array_string__encode(n, out1);
            sgl::v1::copy(first, first + n, (char*)out);
            data.resize((const char*)out - &data[0]);
        } catch (...) {
            data.resize(size_old);
            throw;
        }
    }
};

}
}
