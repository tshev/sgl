#pragma once

#include "sgl.v1.class.array_bytes.h"

namespace sgl {
namespace v1 {


template<typename N>
class array_string {
    sgl::v1::array_bytes<N> value;

public:
    array_string() = default;
    array_string(const array_string&) = default;

    auto begin() {
        return value.begin();
    }

    auto begin() const {
        return value.begin();
    }

   auto end() {
        return value.end();
   }

   auto end() const {
        return value.end();
    }

    void reserve(size_t n, size_t l) {
        value.reserve(value, l);
    }

    void reserve(size_t n) {
        value.reserve(n);
    }

    std::string_view operator[](size_t i) const {
        auto pair = value[i];
        return std::string_view(pair.first, pair.second);
    } 

    void emplace_back(const char* data, size_t n) {
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


}
}
