#pragma once
// TODO: think about imperfect invariant: (position_first() == position_last()) => (full || empty)

namespace sgl {
namespace v1 {
template<typename S = uint64_t>
class fifo_view {
public:
    typedef S size_type;   

    static constexpr size_type data_offset = sizeof(fifo_view::size_type) * 4ul;
private: 
    char* storage_;
    size_type storage_size_;;


public:
    fifo_view() = default;
    fifo_view(char* data, size_type data_size) : storage_(data), storage_size_(data_size) {
        init_position(position_first());
        init_position(position_last());
    }

    void init_position(size_type &x) {
        if (x == 0) {
            x = fifo_view::data_offset;
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
        return storage_size_ - fifo_view::data_offset;
    }

    bool empty() const {
        auto pfirst = position_first();
        auto plast = position_last();
        return pfirst == plast && pfirst == fifo_view::data_offset;
    }

    bool push_back(const char* data, size_type size) {
        size_type pback = position_last();
        size_type new_position_last = pback + sizeof(size_type) + size;
        /*
        std::cout << std::string(data, size) + "\t" << size << std::endl;
        std::cout << "F = " << position_first() << std::endl;
        std::cout << "Position = " << pback << std::endl;
        std::cout << "NP = " << new_position_last << std::endl << std::endl;;
        */

        if (new_position_last <= this->storage_size_) {
            char* output = storage_ + pback;
            *(size_type*)(output) = size;
            output += sizeof(size_type);
            std::copy(data, data + size, output);
            position_last() = new_position_last;
            if (new_position_last >= position_first()) { // doublecheck
                alignment() = new_position_last; 
            }
            ++(this->size());
            return true;
        }
        new_position_last = fifo_view::data_offset + sizeof(size_type) + size; 
        if (new_position_last > position_first()) { return false; } // doublecheck

        char* output = storage_ + fifo_view::data_offset;
        *(size_type*)output = size;
        output += sizeof(size_type);
        std::copy(data, data + size, output);
        position_last() = new_position_last;
        ++(this->size());
        return true;
    }

    template<typename T>
    bool push_back(const T& value) {
        static_assert(std::is_pod<T>::value, "Supports only pods");
        return push_back((const char*)&value, sizeof(T));
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
        size_type pfirst = position_first();
        char* out = storage_ + pfirst;
        size_type n = *((size_type*)out);
        out += sizeof(size_type);
        size_type new_position_first = pfirst + sizeof(size_type) + n;
        //std::cout << "LL = " << position_first() << std::endl;
        //std::cout << "RR = " << position_last() << std::endl;
        if (new_position_first >= alignment()) {
            if (new_position_first == position_last()) {
                position_last() = fifo_view::data_offset;
            }
            //assert(size() == 1ul);
            position_first() = fifo_view::data_offset;
            //position_first() = storage_size_;
        } else {
            position_first() = new_position_first;
        }
        --(this->size());
        return {out, n};
    }
};





} // namespace v1
} // namespace sgl
