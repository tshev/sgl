#pragma once

namespace sgl {
namespace v1 {

template<size_t N>    
class array_string_fixed {
    std::string data;

public:
    struct iterator {
        typedef ptrdiff_t difference_type;
        typedef std::string_view value_type;
        typedef size_t size_type;
        typedef std::string_view& reference;
        typedef std::string_view* pointer;
        typedef std::random_access_iterator_tag iterator_category;
        char* data;

        iterator() = default;
        iterator(char* data) noexcept : data(data) {}
        iterator(const char* data) noexcept : data(data) {}
        iterator(const iterator&) = default;

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

        const std::string_view operator*() const noexcept {
            size_t len = size_t(*data);
            return std::string_view(data + 1, len);
        }

        iterator& operator++() noexcept {
            data += N;
            return *this;
        }

        iterator operator++(int) noexcept {
            iterator tmp{data};
            data += N;
            return tmp;
        }

        iterator& operator--() noexcept {
            data -= N;
            return *this;
        }

        iterator operator--(int) noexcept {
            iterator tmp{data};
            data -= N;
            return tmp;
        }

        friend
        inline
        iterator operator+(iterator first, size_t n) noexcept {
            return iterator{first + N * n};
        }

        friend
        inline
        iterator operator+(size_t n, iterator first) noexcept {
            return first + n;
        }

        iterator operator+=(size_t n) noexcept {
            data += N * n;
            return *this;
        }

        friend
        inline
        iterator operator-(iterator first, size_t n) noexcept {
            return iterator{first - N * n};
        }

        friend
        inline
        difference_type operator-(iterator first, iterator last) noexcept {
            return (first.data - last.data) / N;
        }

        iterator operator-=(size_t n) noexcept {
            data -= N * n;
            return *this;
        }
    };
    typedef const iterator const_iterator;

    array_string_fixed() = default;

    void push_back(std::string_view value) {
        size_t prev_size = data.size();
        size_t new_size = data.size() + N;
        if (new_size > data.capacity()) {
            if (data.capacity() == 0) {
                data.reserve(N);
            } else {
                data.reserve(data.capacity() * 2ull);
            }
        }
        data.resize(new_size);
        data[prev_size] = char(value.size());
        std::copy(value.begin(), value.end(), &data[prev_size + 1]);
    }

    iterator begin() noexcept {
        return iterator{&data[0]};
    }

    iterator end() noexcept {
        return iterator{&data[0] + data.size()};
    }

    const std::string_view operator[](size_t i) const noexcept {
        char const* ptr = &data[i * N];
        return std::string_view(ptr + 1, size_t(*ptr));
    }
};

} // namespace v1
} // namespace sgl
