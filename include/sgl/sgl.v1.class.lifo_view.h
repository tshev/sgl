#pragma once

namespace sgl {
namespace v1 {

template<typename S = uint64_t>
class lifo_view {
    typedef S size_type;
    static constexpr size_type data_offset = sizeof(lifo_view::size_type) * 2;

    char* storage_;
    S storage_size_;

public:
    class iterator {
        char* data_;
    public:
        typedef std::pair<char*, size_type> value_type;

        iterator() = default;
        iterator(char* data) : data_(data) {}
        iterator(const iterator&) = default;

        iterator& operator++() noexcept {
            data_ -= sizeof(size_type);
            size_type size = sgl::v1::as_ref<size_type>(data_);
            data_ -= size;
            return *this;
        }

        std::pair<char*, size_type> operator*() noexcept {
            size_type size = sgl::v1::as_ref<size_type>(data_ - sizeof(size_type));
            return {data_ -  sizeof(size_type) - size, size};
        }

        std::pair<const char*, size_type> operator*() const noexcept {
            size_type size = sgl::v1::as_ref<size_type>(data_ - sizeof(size_type));
            return {data_ -  sizeof(size_type) - size, size};
        }

        friend
        inline
        bool operator==(const iterator& x, const iterator& y) {
            return x.data_ == y.data_;
        }

        friend
        inline
        bool operator!=(const iterator& x, const iterator& y) {
            return !(x == y);
        }
    };

    lifo_view() = default;

    lifo_view(char* data, size_type size) : storage_(data), storage_size_(size) {
        init_position(offset());
    }

    const S& offset() const {
       return sgl::v1::as_ref<S>(storage_); 
    }

    S& offset() {
       return sgl::v1::as_ref<S>(storage_); 
    }

    const S& size() const {
       return sgl::v1::as_ref<S>(storage_ + sizeof(size_type)); 
    }

    S& size() {
       return sgl::v1::as_ref<S>(storage_ + sizeof(size_type)); 
    }

    void init_position(size_type &x) {
        if (x == 0) {
            x = lifo_view::data_offset;
        }
    }

    bool empty() const {
        return lifo_view::data_offset == offset();
    }

    bool push_back(const char* data, size_type data_size) {
        size_type block_size = data_size + sizeof(size_type);
        size_type current_offset = offset();
        size_type new_offset = current_offset + block_size;

        if (new_offset >= storage_size_) {
            return false;
        }

        char* out = std::copy(data, data + data_size, storage_ + current_offset);
        sgl::v1::as_ref<size_type>(out) = data_size;
        offset() = new_offset;
        ++size();
        return true;
    }

    auto begin() {
        return iterator(storage_ + offset());
    }

    auto end() {
        return iterator(storage_ + lifo_view::data_offset); 
    }

    void clear() {
        offset() = lifo_view::data_offset;
    }
};

} // namespace v1
} // namespace sgl
