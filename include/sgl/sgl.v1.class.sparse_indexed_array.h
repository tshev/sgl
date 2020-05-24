#pragma once

namespace sgl {
namespace v1 {

template<typename T>
// sorted_array {}
class sparse_indexed_array {
    std::set<std::pair<size_t, size_t>> sparse_index_; // index in array, size
    std::vector<T> data_;
    size_t block_size_;

public:
    sparse_indexed_array() = default;
    sparse_indexed_array(size_t block_size) : block_size_(block_size) {}

    void push_back(const T& value) {
            auto position_cell = sparse_index_.find(value);
                (position_cell->second < block_size_)
    }
}

}
