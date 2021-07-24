#pragma once
// experimental implementation
// TODO: think about sink(x) = source(x)

namespace sgl {
namespace v1 {

std::pair<uint8_t*, uint64_t> _sgl__v1__class__array_bytes__decode(uint8_t* data) {
    uint64_t value = int64_t(*data) & 0x7full;
    if ((*data >> 7) == 0) return std::make_pair(++data, value);
    ++data;

    value |= (uint64_t(*data) & 0x7full) << 7;
    if ((*data >> 7) == 0) return std::make_pair(++data, value);
    ++data;

    value |= (uint64_t(*data) & 0x7full) << 14;
    if ((*data >> 7) == 0) return std::make_pair(++data, value);
    ++data;

    value |= (uint64_t(*data) & 0x7full) << 21;
    if ((*data >> 7) == 0) return std::make_pair(++data, value);
    ++data;

    value |= (uint64_t(*data) & 0x7full) << 28;
    if ((*data >> 7) == 0) return std::make_pair(++data, value);
    ++data;

    value |= (uint64_t(*data) & 0x7full) << 35;
    if ((*data >> 7) == 0) return std::make_pair(++data, value);
    ++data;

    value |= (uint64_t(*data) & 0x7full) << 42;
    if ((*data >> 7) == 0) return std::make_pair(++data, value);
    ++data;

    value |= (uint64_t(*data) & 0x7full) << 49;
    if ((*data >> 7) == 0) return std::make_pair(++data, value);
    ++data;

    value |= (uint64_t(*data) & 0x7full) << 56;
    if ((*data >> 7) == 0) return std::make_pair(++data, value);
    ++data;

    value |= (uint64_t(*data) & 0x7full) << 63;
    return std::make_pair(++data, value);
}

std::pair<const uint8_t*, uint64_t> _sgl__v1__class__array_bytes__decode(const uint8_t* data) {
    uint64_t value = int64_t(*data) & 0x7full;
    if ((*data >> 7) == 0) return std::make_pair(++data, value);
    ++data;

    value |= (uint64_t(*data) & 0x7full) << 7;
    if ((*data >> 7) == 0) return std::make_pair(++data, value);
    ++data;

    value |= (uint64_t(*data) & 0x7full) << 14;
    if ((*data >> 7) == 0) return std::make_pair(++data, value);
    ++data;

    value |= (uint64_t(*data) & 0x7full) << 21;
    if ((*data >> 7) == 0) return std::make_pair(++data, value);
    ++data;

    value |= (uint64_t(*data) & 0x7full) << 28;
    if ((*data >> 7) == 0) return std::make_pair(++data, value);
    ++data;

    value |= (uint64_t(*data) & 0x7full) << 35;
    if ((*data >> 7) == 0) return std::make_pair(++data, value);
    ++data;

    value |= (uint64_t(*data) & 0x7full) << 42;
    if ((*data >> 7) == 0) return std::make_pair(++data, value);
    ++data;

    value |= (uint64_t(*data) & 0x7full) << 49;
    if ((*data >> 7) == 0) return std::make_pair(++data, value);
    ++data;

    value |= (uint64_t(*data) & 0x7full) << 56;
    if ((*data >> 7) == 0) return std::make_pair(++data, value);
    ++data;

    value |= (uint64_t(*data) & 0x7full) << 63;
    return std::make_pair(++data, value);
}

uint8_t* _sgl__v1__class__array_bytes__encode(uint64_t value, uint8_t* out) {
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
    ++out;
    return out;
}


template<typename T>
struct _sgl__v1__class__array_bytes_position {};


template<>
struct _sgl__v1__class__array_bytes_position<uint8_t> {
    typedef size_t size_type;

    sgl::v1::array<uint8_t> position8;

    void reserve(size_type n) {
        position8.reserve(n);
    }

    size_type operator[](size_type i) const {
        return position8[i];
    }

    void push_back(size_type value) {
        position8.push_back(static_cast<uint8_t>(value)); 
    }
};


template<>
struct _sgl__v1__class__array_bytes_position<uint16_t> {
    typedef size_t size_type;

    sgl::v1::array<uint8_t> position8;
    sgl::v1::array<uint16_t> position16;

    void reserve(size_type n) {
        if (n <= std::numeric_limits<uint8_t>::max()) {
            position8.reserve(n);
            return;
        }
        position8.reserve(std::numeric_limits<uint8_t>::max());
        n -= std::numeric_limits<uint8_t>::max();
        position16.reserve(n);
    }

    size_type operator[](size_type i) const {
        if (i < std::numeric_limits<uint8_t>::max()) {
            return position8[i];
        } else {
            return position16[i];
        }
    }

    void push_back(size_type value) {
        if (position8.size() != size_type(std::numeric_limits<uint8_t>::max())) {
            position8.push_back(value); 
        } else {
            position16.push_back(value); 
        }
    }
};


template<>
struct _sgl__v1__class__array_bytes_position<uint32_t> {
    typedef size_t size_type;

    sgl::v1::array<uint8_t> position8;
    sgl::v1::array<uint16_t> position16;
    sgl::v1::array<uint32_t> position32;

    void reserve(size_type n) {
        if (n <= std::numeric_limits<uint8_t>::max()) {
            position8.reserve(n);
            return;
        }
        position8.reserve(std::numeric_limits<uint8_t>::max());
        n -= std::numeric_limits<uint8_t>::max();

        if (n <= std::numeric_limits<uint16_t>::max()) {
            position16.reserve(n);
            return;
        }
        position16.reserve(std::numeric_limits<uint16_t>::max());
        n -= std::numeric_limits<uint16_t>::max();

        position32.reserve(n);
        return;
    }

    size_type operator[](size_type i) const {
        if (i < std::numeric_limits<uint8_t>::max()) {
            return position8[i];
        } else if (i < std::numeric_limits<uint16_t>::max()) {
            return position16[i];
        } else {
            return position32[i];
        }
    }

    void push_back(size_type value) {
        if (position8.size() != size_type(std::numeric_limits<uint8_t>::max())) {
            position8.push_back(value); 
        } else if (position16.size() != size_type(std::numeric_limits<uint16_t>::max())) {
            position16.push_back(value); 
        } else {
            position32.push_back(value); 
        }
    }
};



template<>
struct _sgl__v1__class__array_bytes_position<uint64_t> {
    typedef size_t size_type;

    sgl::v1::array<uint8_t> position8;
    sgl::v1::array<uint16_t> position16;
    sgl::v1::array<uint32_t> position32;
    sgl::v1::array<uint64_t> position64;

    void reserve(size_type n) {
        if (n <= std::numeric_limits<uint8_t>::max()) {
            position8.reserve(n);
            return;
        }
        position8.reserve(std::numeric_limits<uint8_t>::max());
        n -= std::numeric_limits<uint8_t>::max();

        if (n <= std::numeric_limits<uint16_t>::max()) {
            position16.reserve(n);
            return;
        }
        position16.reserve(std::numeric_limits<uint16_t>::max());
        n -= std::numeric_limits<uint16_t>::max();

        if (n <= std::numeric_limits<uint32_t>::max()) {
            position32.reserve(n);
            return;
        }
        position32.reserve(std::numeric_limits<uint32_t>::max());
        n -= std::numeric_limits<uint32_t>::max();
        position64.reserve(n);
    }

    size_type operator[](size_type i) const {
        if (i < std::numeric_limits<uint8_t>::max()) {
            return position8[i];
        } else if (i < std::numeric_limits<uint16_t>::max()) {
            return position16[i];
        } else if (i < std::numeric_limits<uint32_t>::max()) {
            return position32[i];
        } else {
            return position64[i];
        }
    }

    void push_back(size_type value) {
        if (position8.size() != size_type(std::numeric_limits<uint8_t>::max())) {
            position8.push_back(value); 
        } else if (position16.size() != size_type(std::numeric_limits<uint16_t>::max())) {
            position16.push_back(value); 
        } else if (position32.size() != size_type(std::numeric_limits<uint32_t>::max())) {
            position32.push_back(value); 
        } else {
            position64.push_back(value); 
        }
    }
};



template<typename N>
class array_bytes {
    typedef size_t size_type;

    sgl::v1::array<char> data;
    _sgl__v1__class__array_bytes_position<N> position;


public:

    struct const_iterator : sgl::v1::totally_ordered<const_iterator> {
        const char* data;
    public:
        const_iterator() = default;
        const_iterator(const char* data) noexcept : data(data) {}
        const_iterator(const const_iterator& x) noexcept : data(x.data) {}

        const_iterator& operator=(const const_iterator& x) noexcept {
            data = x.data;
            return *this;
        }

        friend
        inline
        bool operator==(const_iterator x, const_iterator y) noexcept {
            return x.data == y.data;
        }

        friend
        inline
        bool operator!=(const_iterator x, const_iterator y) noexcept {
            return !(x == y);
        }

        friend
        inline
        bool operator<(const_iterator x, const_iterator y) noexcept {
            return x.data < y.data;
        }

        const_iterator& operator++() noexcept {
            auto decoding_result = sgl::v1::_sgl__v1__class__array_bytes__decode(reinterpret_cast<const uint8_t*>(data));
            data = reinterpret_cast<const char*>(decoding_result.first + decoding_result.second);
            return *this;
        }

        const_iterator operator++(int) noexcept {
            const_iterator tmp(*this);
            ++(*this);
            return tmp;
        }

        const std::pair<const char*, size_type> operator*() noexcept {
            auto decoding_result = sgl::v1::_sgl__v1__class__array_bytes__decode(reinterpret_cast<const uint8_t*>(data));
            return std::make_pair(reinterpret_cast<const char*>(decoding_result.first), decoding_result.second);
        }

        const std::pair<const char*, size_type> operator*() const noexcept {
            auto decoding_result = sgl::v1::_sgl__v1__class__array_bytes__decode(reinterpret_cast<const uint8_t*>(data));
            return std::make_pair(reinterpret_cast<const char*>(decoding_result.first), decoding_result.second);
        }
    };

    class iterator : sgl::v1::totally_ordered<iterator> {
        char* data;

    public:

        iterator() = default;
        iterator(char* data) noexcept : data(data) {}
        iterator(const iterator& x) noexcept : data(x.data) {}

        iterator& operator=(const iterator& x) noexcept {
            data = x.data;
            return *this;
        }

        friend
        inline
        bool operator==(iterator x, iterator y) noexcept {
            return x.data == y.data;
        }

        friend
        inline
        bool operator!=(iterator x, iterator y) noexcept {
            return !(x == y);
        }

        friend
        inline
        bool operator<(iterator x, iterator y) noexcept {
            return x.data < y.data;
        }

        iterator& operator++() noexcept {
            auto d = sgl::v1::_sgl__v1__class__array_bytes__decode(reinterpret_cast<uint8_t*>(data));
            data = reinterpret_cast<char*>(d.first + d.second);
            return *this;
        }

        iterator operator++(int) noexcept {
            iterator tmp(*this);
            ++(*this);
            return tmp;
        }

        const std::pair<char*, size_type> operator*() noexcept {
            auto decoding_result = sgl::v1::_sgl__v1__class__array_bytes__decode(reinterpret_cast<uint8_t*>(data));
            return std::make_pair(reinterpret_cast<char*>(decoding_result.first), decoding_result.second);
        }

        const std::pair<const char*, size_type> operator*() const noexcept {
            auto decoding_result = sgl::v1::_sgl__v1__class__array_bytes__decode(reinterpret_cast<const uint8_t*>(data));
            return std::make_pair(reinterpret_cast<const char*>(decoding_result.first), decoding_result.second);
        }
    };


    class const_rai_iterator {
        const array_bytes* container;
        size_type offset;

    public:
        const_rai_iterator() = default;
        const_rai_iterator(const array_bytes* container, size_type offset) : container(container), offset(offset) {}
        const_rai_iterator(const const_rai_iterator& value) = default;
        const_rai_iterator& operator=(const const_rai_iterator&) = default;

        friend
        inline
        bool operator==(const const_rai_iterator& x, const const_rai_iterator& y) {
            return x.offset == y.offset;
        }

        friend
        inline
        bool operator!=(const const_rai_iterator& x, const const_rai_iterator& y) {
            return !(x == y);
        }

        const_rai_iterator& operator++() {
            ++offset;
            return *this;
        }

        const_rai_iterator operator++(int) {
            const_rai_iterator tmp(*this);
            ++(*this);
            return tmp;
        }

        const std::pair<const char*, size_type> operator*() const {
            return container->operator[](offset);
        }
    };

    class rai_iterator {
        array_bytes* container;
        size_type offset;

    public:
        rai_iterator() = default;
        rai_iterator(array_bytes* container, size_type offset) : container(container), offset(offset) {}
        rai_iterator(const rai_iterator& value) = default;
        rai_iterator& operator=(const rai_iterator&) = default;

        friend
        inline
        bool operator==(const rai_iterator& x, const rai_iterator& y) {
            return x.offset == y.offset;
        }

        friend
        inline
        bool operator!=(const rai_iterator& x, const rai_iterator& y) {
            return !(x == y);
        }

        rai_iterator& operator++() {
            ++offset;
            return *this;
        }

        rai_iterator operator++(int) {
            rai_iterator tmp(*this);
            ++(*this);
            return tmp;
        }

        const std::pair<const char*, size_type> operator*() const {
            return container->operator[](offset);
        }
    };


    array_bytes() = default;

    array_bytes(const array_bytes&) = default;

    template<typename It>
    array_bytes(It first, It last) {
        size_type count = 0;
        size_type l = sgl::v1::accumulate(first, last, size_type(0), [&](auto r, const auto& x) {
            ++count;
            size_type n = sgl::v1::strlen(x);
            size_type ilog2_ceil = sgl::v1::ilog2_ceil(n);
            size_type result = n + ilog2_ceil;
            if (ilog2_ceil < 8) { return r + n + 1; }
            if (ilog2_ceil < 15) { return r + n + 2; }
            if (ilog2_ceil < 22) { return r + n + 3; }
            if (ilog2_ceil < 29) { return r + n + 4; }
            if (ilog2_ceil < 36) { return r + n + 5; }
            if (ilog2_ceil < 43) { return r + n + 6; }
            if (ilog2_ceil < 50) { return r + n + 7; }
            if (ilog2_ceil < 57) { return r + n + 8; }
            if (ilog2_ceil < 64) { return r + n + 9; }
            return r + n + 10;
        });
        sgl::v1::for_each(first, last, [this](const auto& x) mutable {
            this->emplace_back(x);
        });
    }

    template<typename It>
    array_bytes(It first, size_type n) : array_bytes(first, std::next(first, n)) {}

    array_bytes& operator=(const array_bytes&) = default;

    size_type content_capacity() const {
        return data.capacity();
    }

    iterator begin() {
        return iterator{&data[0]};
    }

    const_iterator begin() const {
        return const_iterator{&data[0]};
    }

    iterator end() {
        return iterator{&data[0] + data.size()};
    }

    const_iterator end() const {
        return const_iterator{&data[0] + data.size()};
    }

    void reserve(size_type n, size_type l) {
        position.reserve(n);
        data.reserve(l); 
        
    } 

    void reserve(size_type n) {
        reserve(n, 4ull * n);
    }
    
    const std::pair<char*, size_type> operator[](size_type i) {
        i = position[i];
        auto result = reinterpret_cast<uint8_t*>(&data[i]);
        auto decoding_result = sgl::v1::_sgl__v1__class__array_bytes__decode(result);
        return std::make_pair(reinterpret_cast<char*>(decoding_result.first), decoding_result.second);
    }

    const std::pair<const char*, size_type> operator[](size_type i) const {
        i = position[i];
        auto result = reinterpret_cast<const uint8_t*>(&data[i]);
        auto decoding_result = sgl::v1::_sgl__v1__class__array_bytes__decode(result);
        return std::make_pair(reinterpret_cast<const char*>(decoding_result.first), decoding_result.second);
    }

    void emplace_back(const char* data) {
        emplace_back(data, sgl::v1::strlen(data));
    }

    void emplace_back(const char* first, size_type n) {
        size_type batch_size = n + size_type(10);
        size_type size_old = data.size();
        size_type size_new = size_old + batch_size;
        std::cout << size_new << " " << data.capacity() << std::endl;
        try {
            if (size_new > data.capacity()) {
                data.reserve(sgl::v1::max<size_type>(data.capacity() * 2ull, size_new));
                data.resize(size_new);
            } else {
                data.resize(size_new);
                position.push_back(size_old);
            }
            auto out = sgl::v1::_sgl__v1__class__array_bytes__encode(n, reinterpret_cast<uint8_t*>(&data[size_old]));
            sgl::v1::copy(first, first + n, reinterpret_cast<char*>(out));
            data.resize((const char*)out - &data[0] + n);
        } catch (...) {
            data.resize(size_old);
            throw;
        }
    }
};

} // namespace v1
} // namespace sgl
