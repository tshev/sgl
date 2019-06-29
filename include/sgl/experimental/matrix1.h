#pragma once
namespace sgl {
template<typename T>
struct matrix1 {
    typedef T value_type;

    std::vector<T> data_;
    size_t rows_;
    size_t cols_;

    matrix1(size_t rows, size_t cols) : data_(rows * cols), rows_(rows), cols_(cols) {}
    matrix1(size_t rows, size_t cols, const T& x) : data_(rows * cols, x), rows_(rows), cols_(cols) {}

    size_t rows() const {
        return rows_;
    }

    size_t cols() const {
        return cols_;
    }

    size_t size() const {
        return data_.size();
    }

    T& operator()(size_t i, size_t j) {
        return data_[i * cols_ + j];
    }

    const T& operator()(size_t i, size_t j) const {
        return data_[i * cols_ + j];
    }

    auto begin() {
        return std::begin(data_);
    }

    auto end() {
        return std::end(data_);
    }

}; // struct matrix1
} // namespace sgl
