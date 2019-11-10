#pragma once

namespace sgl {
namespace v1 {

template<typename T, typename S = uint32_t>
class continuous_inclosed_queue_span {
    typedef T value_type;
    typedef S size_type;
    typedef int8_t byte_type;
    byte_type* _memory;

public:
    continuous_inclosed_queue_span() = default;

    continuous_inclosed_queue_span(byte_type* _memory) : _memory(_memory) {}

    continuous_inclosed_queue_span(byte_type* _memory, size_t n) : _memory(_memory) {
        capacity() = (n - 3ul * sizeof(size_type)) / sizeof(T);
        offset() = 0;
        size() = 0;
    }

    continuous_inclosed_queue_span(char* _memory, size_t n) : _memory(reinterpret_cast<byte_type*>(_memory)) {
        capacity() = (n - 3ul * sizeof(size_type)) / sizeof(T);
        offset() = 0;
        size() = 0;
    }

    // continuous_inclosed_queue_span(const byte_type* _memory) : _memory(_memory) {}
    // continuous_inclosed_queue_span(const char* _memory) : _memory(reinterpret_cast<const byte_type*>(_memory)) {}

    const S& capacity() const {
        return *reinterpret_cast<const size_type*>(_memory);
    }

    S& capacity() {
        return *reinterpret_cast<size_type*>(_memory);
    }

    const S& offset() const {
        return *reinterpret_cast<const size_type*>(_memory + sizeof(S));
    }

    S& offset() {
        return *reinterpret_cast<size_type*>(_memory + sizeof(S));
    }

    const S& size() const {
        return *reinterpret_cast<const size_type*>(_memory + 2ul * sizeof(S));
    }

    S& size() {
        return *reinterpret_cast<size_type*>(_memory + 2ul * sizeof(S));
    }

    const T* data() const {
        return reinterpret_cast<const T*>(_memory + 3ul * sizeof(S));
    }

    T* data() {
        return reinterpret_cast<T*>(_memory + 3ul * sizeof(S));
    }

    bool push_back(const T& value) {
        S& current_size = size();
        S& current_offset = offset();
        S& current_capacity = capacity();

        if (current_size == current_capacity) {
            return false;
        }

        T* first = data();
        S i = current_offset + current_size;
        if (i < current_capacity) {
            first[i] = value;
        } else {
            first[i - current_capacity] = value;
        }

        if (current_offset == current_capacity) {
            current_offset = 0;
        }

        ++current_size;
        return true;
    }

    size_type back_index() const {
        size_type i = offset() + size() - 1ul;
        size_type c = capacity();
        if (i < c) {
            return i;
        } 
        return i - c;
    }

    size_type front_index() const {
        return offset();
    }

    T& front() {
        return data()[front_index()];
    }
    
    const T& front() const {
        return data()[front_index()];
    }

    void pop_front() {
        size_type& offset_ = offset();
        --size();
        if (offset_ == capacity()) {
            offset_ = 0ul;
        } else {
            ++offset_;
        }
    }

    T& back() {
        return data()[back_index()];
    }

    const T& back() const {
        return data()[back_index()];
    }

    template<typename It>
    It copy(It first, It last) const {
        T* first1 = data();
        size_type current_offset = offset();
        size_type current_size = size();
        size_type n0 = std::min(current_size, capacity() - current_offset);

        T* first0 = first1 + current_offset;
        T* last0 = first0 + n0;
        size_type n = last - first;

        if (n0 < n) {
            first = std::copy(first0, last0, first);
            auto last1 = first1 + std::min(current_size - n0, last - first);
            return std::copy(first1, last1, first);
        }
        return std::copy(first0, last0, first);
    }

    template<typename OutputStream>
    friend
    inline
    OutputStream& operator<<(OutputStream& out, const continuous_inclosed_queue_span& cqv) {
        auto first = cqv.data();
        size_type n0 = std::min(cqv.size(), cqv.capacity() - cqv.offset());
        auto middle = first + cqv.offset();

        std::copy(middle, middle + n0, std::ostream_iterator<T>(out, " "));
        std::copy(first, first + (cqv.size() - n0), std::ostream_iterator<T>(out, " "));
        return out;
    }
};

}  // namespace v1
}  // namespace sgl
