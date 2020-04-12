#pragma once
// TODO: think about imperfect invariant: (position_first() == position_last()) => (full || empty)

namespace sgl {
namespace v1 {
template<typename S = uint64_t>
class circular_fifo_view {
public:
    typedef S size_type;   

    static constexpr size_type data_offset = sizeof(circular_fifo_view::size_type) * 4ul;
private: 
    char* storage_;
    size_type storage_capacity_;;


public:
    circular_fifo_view() = default;
    circular_fifo_view(char* data, size_type data_size) : storage_(data), storage_capacity_(data_size) {
        init_position(position_first());
        init_position(position_last());
        if (alignment() == 0) {
            alignment() = storage_capacity_;
        }

        //std::cout << position_first() << " " << position_last() << " " << size() << " " << alignment() << " " << storage_capacity_<< std::endl;
    }

    void init_position(size_type &x) {
        if (x == 0) {
            x = circular_fifo_view::data_offset;
        }
    }

    size_type& size() {
        return *(size_type*)storage_;
    }

    const size_type& size() const {
        return *(size_type*)storage_;
    }

    size_type& alignment() {
        return *((size_type*)storage_ + 1ul);
    }

    const size_type& alignment() const {
        return *((size_type*)storage_ + 1ul);
    }

    size_type& position_first() {
        return *((size_type*)storage_ + 2ul);
    }

    const size_type& position_first() const {
        return *((size_type*)storage_ + 2ul);
    }

    size_type& position_last() {
        return *((size_type*)storage_ + 3ul);
    }

    const size_type& position_last() const {
        return *((size_type*)storage_ + 3ul);
    }

    size_type max_offset() {
        return storage_capacity_ - circular_fifo_view::data_offset;
    }

    bool empty() const {
        auto pfirst = position_first();
        auto plast = position_last();
        return pfirst == plast && pfirst == circular_fifo_view::data_offset;
    }

    void clear() {
        position_first() = circular_fifo_view::data_offset; 
        position_last() = circular_fifo_view::data_offset; 
        size() = 0ul;
    }

    void _insert(size_type i, const char* data, size_type size) {
        char* output = storage_ + i;
        *(size_type*)(output) = size;
        output += sizeof(size_type);
        std::copy(data, data + size, output);
    }

    void log() {
       // std::cout << "Insert into " << position_first() << " " << position_last() << " " << alignment() << " " << storage_capacity_ << std::endl;
    }

    bool push_back(const char* data, size_type size) {
        /*
         * std::cout << std::string(data, size) + "\t" << size << std::endl;
         * std::cout << "F = " << position_first() << std::endl;
         * :std::cout << "NP = " << new_position_last << std::endl << std::endl;;
        */
        /// b1 | b0
        //      ^
        size_type new_position_last = position_last() + sizeof(size_type) + size;
        if (position_first() < position_last()) {
            if (new_position_last <= this->storage_capacity_) {
                _insert(position_last(), data, size);
                position_last() = new_position_last;

                if (new_position_last > alignment()) { // doublecheck
                    alignment() = new_position_last; 
                }

                ++(this->size());
                return true;
            } else {
                new_position_last = circular_fifo_view::data_offset + sizeof(size_type) + size; 
                if (new_position_last > position_first()) { return false; }
                alignment() = position_last();

                _insert(circular_fifo_view::data_offset, data, size);
                position_last() = new_position_last;
                ++(this->size());
                return true;
            }
            return false;
        } else {
            if (new_position_last <= position_first() || (empty() && new_position_last <= storage_capacity_)) {
                _insert(circular_fifo_view::data_offset, data, size);
                position_last() = new_position_last;
                ++(this->size());
                return true;
            }   
            return false;
        }
    }

    template<typename T>
    bool push_back(const T& value) {
        static_assert(std::is_pod<T>::value, "Supports only pods"); // not enough
        return push_back((const char*)&value, sizeof(T));
    }

    bool push_back(const std::string& data) {
        return push_back(data.data(), data.size());
    }

    std::pair<char*, size_type> front() {
        size_type pfirst = position_first();
        char* out = storage_ + pfirst;
        size_type n = *((size_type*)out);
        out += sizeof(size_type);
        return {out, n};
    }

    std::pair<const char*, size_type> front() const {
        size_type pfirst = position_first();
        const char* out = storage_ + pfirst;
        size_type n = *((size_type*)out);
        out += sizeof(size_type);
        return {out, n};
    }

    std::pair<char*, size_type> pop_front() {
        char* out = storage_ + position_first();
        size_type n = *((size_type*)out);
        out += sizeof(size_type);

        size_type new_position_first = position_first() + sizeof(size_type) + n;

        if (new_position_first >= alignment()) {
            alignment() = storage_capacity_; 
            position_first() = circular_fifo_view::data_offset;
        } else {
            position_first() = new_position_first;
        }
        --(this->size());
        if (position_first() == position_last()) {
            assert(this->size() == 0);
            position_first() = circular_fifo_view::data_offset;
            position_last() = circular_fifo_view::data_offset;
        }
        return {out, n};
    }
};





} // namespace v1
} // namespace sgl
