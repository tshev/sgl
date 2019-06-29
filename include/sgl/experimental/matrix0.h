namespace sgl {

template<typename T>
size_t matrix0_data_size(size_t n) {
    return sizeof(T*) * n + n * sizeof(T);
}

template<typename T, typename Allocator = typename std::allocator<char>>
class matrix0 {
    Allocator allocator;
    size_t rows_;
    size_t cols_;
    T* data_;
    T** pointers_;
public:
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;

    struct iterator2d : sgl::totally_ordered<iterator2d> {
        T* data;
        size_t cols_n;
        size_t stride;

        iterator2d() : data(nullptr) {}
        iterator2d(T* data, size_t cols_n, size_t stride) : data(data), cols_n(cols_n), stride(stride) {}
        iterator2d(const iterator2d& x) : data(x.data), cols_n(x.cols_n), stride(x.stride) {}

        friend
        inline
        bool operator==(const iterator2d& x, const iterator2d& y) {
          return x.data == y.data;
        }

        friend
        inline
        bool operator!=(const iterator2d& x, const iterator2d& y) {
          return !(x == y);
        }

        friend
        inline
        bool operator<(const iterator2d& x, const iterator2d& y) {
          return x.data < y.data;
        }

        T* begin() {
          return data;
        }

        T* end() {
          return data + cols_n;
        }

        const T* begin() const {
          return data;
        }

        const T* end() const {
          return data + cols_n;
        }

        iterator2d& operator++() {
          data += stride;
          return *this;
        }

        iterator2d& operator--() {
          data -= stride;
          return *this;
        }

        iterator2d& successor0() {
          data += stride;
          return *this;
        }

        iterator2d& successor1() {
          data += 1;
          return *this;
        }
    };

    matrix0(size_t rows, size_t cols) : rows_(rows), cols_(cols) {
        size_t size_ = size();
        size_t data_memory = sizeof(T) * size_;
        size_t pointer_memory = sizeof(T*) * size_;
        char* raw_data = allocator.allocate(data_memory + pointer_memory);
        data_ = reinterpret_cast<T*>(raw_data);
        pointers_ = reinterpret_cast<T**>(raw_data + data_memory);
        fill_pointers();
    }

    matrix0(size_t rows, size_t cols, const T& x) : matrix0(rows, cols) {
        std::fill(begin(), end(), x);
    }

    matrix0(const matrix0& x) : rows_(x.rows_), cols_(x.cols_) {
        size_t size_ = size();
        size_t data_memory = sizeof(T) * size_;
        size_t pointer_memory = sizeof(T*) * size_;
        char* raw_data = allocator.allocate(data_memory + pointer_memory);
        data_ = reinterpret_cast<T*>(raw_data);
        pointers_ = reinterpret_cast<T**>(raw_data + data_memory);
        std::copy(x.data_, x.data_ + size_, data_);
        fill_pointers();
    }

    matrix0(matrix0 &&x) : rows_(x.rows_), cols_(x.cols_), data_(x.data_), pointers_(x.pointers_) {
        x.data_ = nullptr;
    }

    matrix0& operator=(const matrix0& x) {
        matrix0 tmp(x);
        swap(tmp);
        return *this;
    }

    matrix0& operator=(matrix0&& x) {
        swap(x);
        return *this;
    }

    T* begin() {
        return data_;
    }

    const T* begin() const {
        return data_;
    }

    T* end() {
        return data_ + size();
    }

    const T* end() const {
        return data_ + size();
    }

    iterator2d begin2d() {
        return iterator2d(data(), rows_, rows_);
    }

    iterator2d end2d() {
        return iterator2d(data() + size(), rows_, rows_);
    }

    void fill_pointers() {
        transform_with_step(data_, cols_, pointers_, pointers_ + rows_, [](auto &x) { return &x;});
    }

    size_t size() const {
        return cols_ * rows_;
    }

    size_t rows() const {
        return rows_;
    }

    size_t cols() const {
        return cols_;
    }

    T& operator()(size_t i, size_t j) {
        return pointers_[i][j];
    }

    const T& operator()(size_t i, size_t j) const {
        return pointers_[i][j];
    }

    T* data() {
        return data_;
    }

    const T* data() const {
        return data_;
    }

    ~matrix0() {
        if (data_ != nullptr) {
            allocator.deallocate(reinterpret_cast<char*>(data_), size());
        }
    }

    void swap(matrix0& y) {
        //std::swap(x.allocator, y.allocator);
        std::swap(data_, y.data_);
        std::swap(pointers_, y.pointers_);
        std::swap(rows_, y.rows_);
        std::swap(cols_, y.cols_);
    }
};
} // namespace sgl
