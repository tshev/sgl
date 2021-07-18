#pragma once
// experimental implementation
// TODO: think about sink(x) = source(x)

namespace sgl {
namespace v1 {

std::pair<uint64_t, uint8_t*> _sgl__v1__class__array_string__decode(uint8_t* data) {
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

    struct iterator : sgl::v1::totally_ordered<iterator> {
        char* data;

        iterator() = default;

        iterator(char* data) noexcept : data(data) {}

        iterator(const iterator& x) noexcept : data(x.data) {}

        iterator& operator=(const iterator& x) noexcept {
            data = x.data;
            return *this;
        }

        friend
        inline
        bool operator==(iterator x, iterator y) {
            return x.data == y.data;
        }

        friend
        inline
        bool operator!=(iterator x, iterator y) {
            return !(x == y);
        }

        friend
        inline
        bool operator<(iterator x, iterator y) noexcept {
            return x.data < y.data;
        }

        iterator& operator++() noexcept {
            auto d = sgl::v1::_sgl__v1__class__array_string__decode(reinterpret_cast<uint8_t*>(data));
            data = reinterpret_cast<char*>(d.second + d.first);
            return *this;
        }

        iterator operator++(int) noexcept {
            iterator tmp(*this);
            ++(*this);
            return tmp;
        }

        const std::pair<char*, size_type> operator*() noexcept {
            auto p = sgl::v1::_sgl__v1__class__array_string__decode(reinterpret_cast<uint8_t*>(data));
            return std::make_pair(reinterpret_cast<char*>(p.second), p.first);
        }

        const std::pair<const char*, size_type> operator*() const noexcept {
            auto p = sgl::v1::_sgl__v1__class__array_string__decode(reinterpret_cast<const uint8_t*>(data));
            return std::make_pair(reinterpret_cast<const char*>(p.second), p.first);
        }
    };

    array_string() = default;

    array_string(const array_string&) = default;

    array_string& operator=(const array_string&) = default;

    void reserve(size_type n, decltype(data)::size_type l) {
        if (n <= std::numeric_limits<uint8_t>::max()) {
            position8.reserve(n);
            data.reserve(l);
            return;
        }
        position8.reserve(std::numeric_limits<uint8_t>::max());
        n -= std::numeric_limits<uint8_t>::max();

        if (n <= std::numeric_limits<uint16_t>::max()) {
            position16.reserve(n);
            data.reserve(l);
            return;
        }
        position16.reserve(std::numeric_limits<uint16_t>::max());
        n -= std::numeric_limits<uint16_t>::max();

        if (n <= std::numeric_limits<uint32_t>::max()) {
            position32.reserve(n);
            data.reserve(l);
            return;
        }
        position32.reserve(std::numeric_limits<uint32_t>::max());
        n -= std::numeric_limits<uint32_t>::max();

        if (n <= std::numeric_limits<uint64_t>::max()) {
            position64.reserve(n);
            data.reserve(l);
            return;
        }
        position64.reserve(std::numeric_limits<uint64_t>::max());
    } 

    void reserve(size_type n) {
        reserve(n, n);
    }
    
    const std::pair<char*, size_type> operator[](size_type i) {
        if (i < std::numeric_limits<uint8_t>::max()) {
            i = position8[i];
        } else if (i < std::numeric_limits<uint16_t>::max()) {
            i = position16[i];
        } else if (i < std::numeric_limits<uint32_t>::max()) {
            i = position32[i];
        } else {
            i = position64[i];
        }

        auto result = reinterpret_cast<uint8_t*>(&data[i]);
        auto decoding_result = sgl::v1::_sgl__v1__class__array_string__decode(result);
        return std::make_pair(reinterpret_cast<char*>(decoding_result.second), decoding_result.first);
    }

    const std::pair<const char*, size_type> operator[](size_type i) const {
        if (i < std::numeric_limits<uint8_t>::max()) {
            i = position8[i];
        } else if (i < std::numeric_limits<uint16_t>::max()) {
            i = position16[i];
        } else if (i < std::numeric_limits<uint32_t>::max()) {
            i = position32[i];
        } else {
            i = position64[i];
        }

        auto result = reinterpret_cast<const uint8_t*>(&data[i]);
        auto decoding_result = sgl::v1::_sgl__v1__class__array_string__decode(result);
        return std::make_pair(reinterpret_cast<const char*>(decoding_result.second), decoding_result.first);
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
            auto out1 = reinterpret_cast<uint8_t*>(&data[size_old]);
            auto out = sgl::v1::_sgl__v1__class__array_string__encode(n, out1);
            sgl::v1::copy(first, first + n, reinterpret_cast<char*>(out));
            data.resize((const char*)out - &data[0] + n);
        } catch (...) {
            data.resize(size_old);
            throw;
        }
    }

    void emplace_back(const std::string& value) {
        emplace_back(value.data(), value.size());
    }
};

} // namespace v1
} // namespace sgl
