#pragma once

namespace sgl {
namespace v1 {

template<typename Entropy>
struct sequence_generator {
    std::vector<char> values;
    Entropy rd;

    sequence_generator() {
       for (char c = 'a'; c <= 'z'; ++c) {
            values.push_back(c);
       }
       for (char c = 'A'; c <= 'Z'; ++c) {
            values.push_back(c);
       }
       for (char c = '0'; c <= '9'; ++c) {
            values.push_back(c);
       }
       constexpr const char* seq = "!@#$%^&*()_+";
       //constexpr size_t n = std::strlen(seq); // error in clang
       constexpr size_t n = 12ul;
       std::copy(seq, seq + n, std::back_inserter(values));
    }

    template<typename It>
    sequence_generator(It first, It last) : values(first, last) {}

    sequence_generator(const sequence_generator& x) : values(x.values), rd(x.rd){}

    sequence_generator& operator=(const sequence_generator& x) {
        values = x.values;
        rd = x.rd;
        return *this;
    }

    friend
    inline
    bool operator==(const sequence_generator& x, const sequence_generator& y) {
        return x.values == y.values && x.rd == y.rd;
    }

    friend
    inline
    bool operator!=(const sequence_generator& x, const sequence_generator& y) {
        return !(x == y);
    }
 
    auto begin() {
        return std::begin(values);
    }

    auto begin() const {
        return std::begin(values);
    }

    auto end() {
        return std::end(values);
    }

    auto end() const {
        return std::end(values);
    }

    char operator[](size_t i) {
        return values[i];
    }

    char operator()() {
        std::uniform_int_distribution<size_t> dis(0, values.size() - 1ul);
        return values[dis(rd)];
    }

    template<typename It>
    void operator()(It first, It last) {
        std::generate(first, last, [this]() {
            return (*this)();
        });
    }
};

} // namespace v1
} // namespace sgl
