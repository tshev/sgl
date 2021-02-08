#pragma once
namespace sgl {
namespace v1 {

template<typename Integer = uint64_t>
class batch {
    static constexpr uint8_t state_open = 0u;
    static constexpr uint8_t state_frozen = 1u;

    sgl::v1::mmap<char> data_;
    uint8_t* state_;
    sgl::v1::fifo_view<Integer> lifo_;

public:

    batch() = default;
    batch(batch&&) = default;
    batch(const char* path, Integer size) : data_(sgl::v1::fmmap<char>(path, size)),
                                            state_((uint8_t*)data_.begin()),
                                            lifo_(data_.begin() + 1ul, size - 1ul) {}

    bool push_back(const char* data, Integer size) {
        return lifo_.push_back(data, size);
    }

    bool empty() const {
        return lifo_.empty();
    }

    Integer size() const {
        return lifo_.size();
    }

    void clear() {
        lifo_.clear();
    }

    uint8_t set_state(uint8_t new_state) {
        uint8_t prev_state = *state_;
        *state_ = new_state;
        return prev_state;
    }

    bool frozen() const {
        return batch::state_frozen == *state_;
    }

    auto unfreeze() {
        return set_state(batch::state_open);
    }

    auto freeze() {
        return set_state(batch::state_frozen);
    }

    auto begin() {
        return lifo_.begin();
    }

    auto end() {
        return lifo_.end();
    }

    auto begin() const {
        return lifo_.begin();
    }

    auto end() const {
        return lifo_.end();
    }
};

}
}
