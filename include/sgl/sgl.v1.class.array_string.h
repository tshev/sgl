#pragma once

#include "sgl.v1.class.array_bytes.h"

namespace sgl {
namespace v1 {


template<typename N>
class array_string {
    sgl::v1::array_bytes<N> value;

public:
    typedef size_t size_type;
    array_string() = default;
    array_string(const array_string&) = default;

    template<typename It>
    array_string(It first, It last) {
        size_type count = 0;
        size_type l = sgl::v1::accumulate(first, last, size_type(0), [&](auto r, const auto& x) {
            ++count;
            size_type n = sgl::v1::strlen(x);
            size_type ilog2_ceil = sgl::v1::ilog2_ceil(n);
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
        reserve(count, l);

        sgl::v1::for_each(first, last, [this](const auto& x) mutable {
            this->emplace_back(x);
        });
    }

    template<typename It>
    array_string(It first, size_type n) : array_string(first, std::next(first, n)) {}

    size_type content_capacity() const {
        return value.content_capacity();
    }


    struct iterator : sgl::v1::totally_ordered<iterator> {
        typename sgl::v1::array_bytes<N>::iterator value;
    public:
        iterator() = default;
        iterator(typename sgl::v1::array_bytes<N>::iterator value) : value(value) {}
        iterator(const iterator& x) = default;

        iterator& operator=(const iterator& x) noexcept {
            value = x.value;
            return *this;
        }

        friend
        inline
        bool operator==(iterator x, iterator y) noexcept {
            return x.value == y.value;
        }

        friend
        inline
        bool operator!=(iterator x, iterator y) noexcept {
            return !(x == y);
        }

        friend
        inline
        bool operator<(iterator x, iterator y) noexcept {
            return x.value < y.value;
        }

        iterator& operator++() noexcept {
            ++value;
            return *this;
        }

        iterator operator++(int) noexcept {
            iterator tmp(*this);
            ++(*this);
            return tmp;
        }

        const std::string_view operator*() noexcept {
            auto pair = *value;
            return std::string_view(pair.first, pair.second);
        }

        const std::string_view operator*() const noexcept {
            auto pair = *value;
            return std::string_view(pair.first, pair.second);
        }
    };


    class const_iterator : sgl::v1::totally_ordered<const_iterator> {
        typename sgl::v1::array_bytes<N>::const_iterator value;
    public:
        const_iterator() = default;
        const_iterator(typename sgl::v1::array_bytes<N>::const_iterator value) : value(value) {}
        const_iterator(const const_iterator& x) = default;

        const_iterator& operator=(const const_iterator& x) noexcept {
            value = x.value;
            return *this;
        }

        friend
        inline
        bool operator==(const_iterator x, const_iterator y) noexcept {
            return x.value == y.value;
        }

        friend
        inline
        bool operator!=(const_iterator x, const_iterator y) noexcept {
            return !(x == y);
        }

        friend
        inline
        bool operator<(const_iterator x, const_iterator y) noexcept {
            return x.value < y.value;
        }

        const_iterator& operator++() noexcept {
            ++value;
            return *this;
        }

        const_iterator operator++(int) noexcept {
            const_iterator tmp(*this);
            ++(*this);
            return tmp;
        }

        const std::string_view operator*() noexcept {
            auto pair = *value;
            return std::string_view(pair.first, pair.second);
        }

        const std::string_view operator*() const noexcept {
            auto pair = *value;
            return std::string_view(pair.first, pair.second);
        }
    };


    auto begin() {
        return iterator(value.begin());
    }

    auto begin() const {
        return const_iterator(value.begin());
    }

    auto end() {
        return iterator(value.end());
    }

    auto end() const {
        return const_iterator(value.end());
    }

    void reserve(size_type n, size_type l) {
        value.reserve(n, l);
    }

    void reserve(size_type n) {
        value.reserve(n);
    }

    const std::string_view operator[](size_type i) const {
        auto pair = value[i];
        return std::string_view(pair.first, pair.second);
    } 

    void emplace_back(const char* data, size_type n) {
        value.emplace_back(data, n);
    }

    void emplace_back(const char* data) {
        value.emplace_back(data);
    }

    void emplace_back(const std::string& value) {
        this->value.emplace_back(value.data(), value.size());
    }

    void emplace_back(std::string_view value) {
        this->value.emplace_back(value.data(), value.size());
    }
};


} // namespace v1
} // namespace sgl
