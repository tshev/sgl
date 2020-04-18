#pragma once

namespace sgl {
namespace v1 {

template<typename Integer = uint64_t>
class fifo_view {
    typedef Integer size_type;

    char* storage_;
    size_type storage_capacity_;

public:
    class iterator : public sgl::v1::totally_ordered<iterator> {
        char* data_;

    public:
        iterator() = default;
        iterator(const iterator& x) = default;
        iterator(char* data) noexcept : data_(data) {}

        friend
        inline
        bool operator==(const iterator x, const iterator y) {
            return x.data_ == y.data_;
        }

        friend
        inline
        bool operator!=(const iterator x, const iterator y) {
            return !(x == y);
        }

        friend
        inline
        bool operator<(const iterator x, const iterator y) {
            return x.data_ < y.data_;
        }

        std::pair<char*, size_type> operator*() noexcept {
            size_type size = sgl::v1::as_ref<size_type>(data_);
            return {data_ + sizeof(size_type), size};
        }

        std::pair<const char*, size_type> operator*() const noexcept {
            size_type size = sgl::v1::as_ref<size_type>(data_);
            return {data_ + sizeof(size_type), size};
        }

        iterator& operator++() noexcept {
            size_type size = sgl::v1::as_ref<size_type>(data_);
            data_ += size + sizeof(size_type);
            return *this;
        }

        iterator operator++(int) noexcept {
            iterator tmp(data_);
            ++(*this);
            return tmp;
        }
    };

    fifo_view() = default;

    fifo_view(char* storage, size_type capacity) : storage_(storage), storage_capacity_(capacity) {
        if (position_first() == 0) {
            init();
        }
    }

    void init() {
        position_first() = size_type(2) * sizeof(size_type);
        position_last() = size_type(2) * sizeof(size_type);
    }

    size_type& position_first() {
        return sgl::v1::as_ref<size_type>(storage_);
    }

    const size_type& position_first() const {
        return sgl::v1::as_ref<size_type>(storage_);
    }

    size_type& position_last() {
        return sgl::v1::as_ref<size_type>(storage_ + sizeof(size_type));
    }

    const size_type& position_last() const {
        return sgl::v1::as_ref<size_type>(storage_ + sizeof(size_type));
    }

    void rebalance() {
        std::copy(storage_ + position_first(), storage_ + position_last(), storage_ + 2 * sizeof(size_type));
        size_type n = position_last() - position_first();
        position_first() = 2 * sizeof(size_type);
        position_last() = position_first() + n;
    }

    bool push_back(const char* data, size_type size) {
        if (position_last() + size + sizeof(size_type) > storage_capacity_) {
            if (sizeof(size_type) * 3 + size <= position_first()) {
                rebalance();
            } else { 
                return false;
            }
        }
        auto plast = position_last();
        sgl::v1::as_ref<size_type>(storage_ + plast) = size;
        position_last() = std::copy(data, data + size, storage_ + sizeof(size_type) + plast) - storage_;
        return true;
    }

    template<typename T>
    bool push_back(const T& value) {
        return push_back((const char*)&value, sizeof(T));
    }

    bool empty() const {
        return position_first() == position_last();
    }

    std::pair<char*, size_type> pop_front() {
        size_type pfirst = position_first();
        size_type size = sgl::v1::as_ref<size_type>(storage_ + pfirst);
        position_first() += size + sizeof(size_type);
        return {storage_ + pfirst + sizeof(size_type), size};
    }

    std::pair<const char*, size_type> front() const {
        auto pfirst = position_first();
        return {storage_ + pfirst + sizeof(size_type), sgl::v1::as_ref<size_type>(storage_ + pfirst)};
    }

    std::pair<char*, size_type> front() {
        auto pfirst = position_first();
        return {storage_ + pfirst + sizeof(size_type), sgl::v1::as_ref<size_type>(storage_ + pfirst)};
    }

    iterator begin() {
        return iterator(storage_ + position_first());
    }

    const iterator begin() const {
        return iterator(storage_ + position_first());
    }

    iterator end() {
        return iterator(storage_ + position_last());
    }

    const iterator end() const {
        return iterator(storage_ + position_last());
    }

    void clear() {
        init();
    }
};

} // namespace v1
} // namespace sgl
