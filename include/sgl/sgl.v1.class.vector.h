#pragma once

namespace sgl {
namespace v1 {
template<typename T, typename Allocator>
struct vector_base {
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;

    Allocator allocator;
    T* first_ = nullptr;
    T* last_ = nullptr;

    vector_base() = default;

    vector_base(size_t n) : first_(allocate(n)), last_(first_ + n) {}
    vector_base(size_t n, Allocator a) : allocator(a), first_(allocate(n)), last_(first_ + n) {}

    T* allocate(size_t n) {
        return allocator.allocate(n);
    }

    void deallocate(T* data) {
        allocator.deallocate(data, 0);
    }

    void destructor() {
        if (first_ != nullptr) {
            deallocate(first_);
        }
    }

    void reset() {
        first_ = nullptr;
        last_ = nullptr;
    }

    ~vector_base() {
        destructor();
    }
};

struct enable_default_constructor { bool x[0]; };
struct disable_default_constructor { bool x[0];};


template<typename T, typename Allocator = std::allocator<T>, bool skip_default_constructor_and_destructor = !std::is_pod<T>::value>
struct vector : vector_base<T, Allocator> {
    typedef vector_base<T, Allocator> base_type;
    typedef typename base_type::value_type value_type;
    typedef typename base_type::pointer pointer;
    typedef typename base_type::const_pointer const_pointer;

    vector() : base_type() {}

    vector(size_t n) : base_type(n) {
        if (!skip_default_constructor_and_destructor) { // TODO doubts
            sgl::default_construct(begin(), end());
        }
    }

    vector(size_t n, enable_default_constructor) : base_type(n) { // TODO doubts
        sgl::default_construct(begin(), end());
    }

    vector(size_t n, disable_default_constructor) : base_type(n) {} // TODO doubts

    vector(size_t n, Allocator a, enable_default_constructor) : base_type(n, a) {  // TODO doubts
        sgl::default_construct(begin(), end());
    }

    vector(size_t n, Allocator a, disable_default_constructor) : base_type(n, a) {}  // TODO doubts


    vector(size_t n, Allocator a, bool run_default_constructor) : base_type(n, a) {  // TODO doubts
        if (run_default_constructor) {
            sgl::default_construct(begin(), end());
        }
    }

    vector(size_t n, const value_type& value) : base_type(n) {
        sgl::copy_construct(begin(), end(), value);
    }

    vector(size_t n, const value_type& value, Allocator a) : base_type(n, a) {
        sgl::copy_construct(begin(), end(), value);
    }

    vector(const vector& x) : base_type(x.size()) {
        std::uninitialized_copy(x.begin(), x.end(), begin());
    }

    vector(vector&& x) : base_type::first_(x.first_), base_type::last_(x.last_) {
        x.reset();
    }

    vector& operator=(const vector& x) {
        vector tmp(x);
        swap(tmp);
        return *this;
    }

    vector& operator=(vector&& x) {
        this->~vector(); // FIXME allocator
        base_type::first_ = x.first_;
        base_type::last_ = x.last_;
        x.reset();

        return *this;    
    }

    ~vector() {
        if (skip_default_constructor_and_destructor) {
            destruct(begin(), end());
        }
    }

    size_t capacity() const {
        return size();
    }

    size_t size() const {
        return base_type::last_ - base_type::first_;
    }

    pointer begin() {
        return base_type::first_;
    }    

    const_pointer begin() const {
        return base_type::first_;
    }    

    const_pointer end() const {
        return base_type::last_;
    }    

    pointer end() {
        return base_type::last_;
    }

    void reserve(size_t n) {
        auto current_capacity = capacity();
        if (current_capacity < n) {
            reserve_and_copy(n, size(), current_capacity);
        }
    }

    void resize(size_t n) {
        size_t initial_size = size();
        if (n < initial_size) {
            auto first = begin();
            auto last = end();
            destruct(first + n, last);
            base_type::last_ = base_type::first_ + n;
        } else {
            const auto initial_capacity = capacity();
            if (initial_capacity < n) {
                reserve_and_copy(n, initial_size, n);
            }
            base_type::last_ = base_type::last_ + n;
            default_construct(base_type::first_ + initial_size, base_type::last_);
        }
    }

    void resize(size_t n, const value_type& x) {
        size_t initial_size = size();
        if (n < initial_size) {
            auto first = begin();
            auto last = end();
            destruct(first + n, last);
            base_type::last_ = base_type::first_ + n;
        } else {
            const auto initial_capacity = capacity();
            if (initial_capacity < n) {
                reserve_and_copy(n, initial_size, initial_capacity);
            }
            base_type::last_ = base_type::last_ + n;
            copy_construct(base_type::first_ + initial_size, base_type::last_, x);
        }
    }

    void push_back(const value_type& x) {
        new (base_type::last_) value_type();
        *base_type::last_ = x;
        ++base_type::last_;
    }

    void push_back(value_type&& x) {
        new (base_type::last_) value_type();
        *base_type::last_ = std::move(x);
        ++base_type::last_;
    }


    void emplace_back(const value_type& x) {
        new (base_type::last_) value_type(x);
        ++base_type::last_;
    }

    void emplace_back(value_type&& x) {
        new (base_type::last_) value_type(std::move(x));
        ++base_type::last_;
    }

    void reserve_and_copy(size_t new_capacity, size_t initial_size, size_t initial_capacity) {
        T* data = base_type::allocate(new_capacity);
        try {
            if (std::is_trivially_copyable<value_type>::value) {
                std::uninitialized_copy(begin(), end(), data);
            } else {
                sgl::uninitialized_move(begin(), end(), data);
            }
            this->~vector(); // FIXME allocator
        } catch(...) {
            base_type::deallocate(data);
            throw;
        }
        base_type::first_ = data;
        base_type::last_ = data + initial_size;
        base_type::end_ = data + new_capacity;
    }

    friend
    inline
    void swap(vector& x, vector& y) {
        std::swap(x.first_, y.first_);
        std::swap(x.last_, y.last_);
        std::swap(x.end_, y.end_);
    }

    void swap(vector& y) {
        std::swap(base_type::first_, y.first_);
        std::swap(base_type::last_, y.last_);
        std::swap(base_type::end_, y.end_);
    }
};
} // namespace v1
} // namespace sgl
