#pragma once
// TODO
// emplace
// erase
// fix typename
// std::enable_if<!std::is_arithmetic<ForwardIterator>::value>::type
// assign(ForwardIterator first, ForwardIterator last) {

namespace sgl {
namespace v1 {

template <typename T, typename Allocator>
class array_base {
  protected:
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef pointer iterator;
    typedef const const_pointer const_iterator;
    typedef size_t size_type;

    Allocator allocator;
    pointer first_ = nullptr;
    pointer last_ = nullptr;
    pointer finish_ = nullptr;

    array_base() = default;

    array_base(size_type n) : first_(allocate(n)), last_(first_ + n), finish_(last_) {}

    array_base(size_type n, Allocator a) : allocator(a), first_(allocate(n)), last_(first_ + n), finish_(last_) {}

    pointer allocate(size_type n) {
        return allocator.allocate(n);
    }

    void deallocate(pointer data) {
        allocator.deallocate(data, finish_ - first_);
    }

    void destructor_array_base() {
        if (first_ != nullptr) {
            deallocate(first_);
        }
    }

    void detach() {
        first_ = nullptr;
        last_ = nullptr;
        finish_ = nullptr;
    }

    ~array_base() {
        destructor_array_base();
    }
};

template <typename T>
class array_base<T, std::allocator<T>> {
  protected:
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef pointer iterator;
    typedef const_pointer const_iterator;
    typedef size_t size_type;

    T* first_ = nullptr;
    T* last_ = nullptr;
    T* finish_ = nullptr;

    array_base() = default;

    array_base(size_type n) : first_(allocate(n)), last_(first_ + n), finish_(last_) {}

    array_base(size_type n, std::allocator<T> a)
        : first_(std::allocator<T>().allocate(n)), last_(first_ + n), finish_(last_) {}

    pointer allocate(size_type n) {
        return std::allocator<T>().allocate(n);
    }

    void deallocate(pointer data) { std::allocator<T>().deallocate(data, finish_ - first_); }

    void destructor_array_base() {
        if (first_ != finish_) {
            deallocate(first_);
        }
    }

    void detach() {
        first_ = nullptr;
        last_ = nullptr;
        finish_ = nullptr;
    }

    ~array_base() {
        destructor_array_base();
    }
};

template <typename T, typename Allocator = std::allocator<T>,
          bool skip_default_constructor_and_destructor = std::is_pod<T>::value>
class array : array_base<T, Allocator>, totally_ordered<array<T, Allocator, skip_default_constructor_and_destructor>> {
    struct prefer_move {
        // move nothrow move constructible resources and non-regular types
        static constexpr const bool value =
            (std::is_move_constructible<T>::value && !std::is_copy_constructible<T>::value) ||
            (std::is_nothrow_move_constructible<T>::value && !std::is_nothrow_copy_constructible<T>::value);
    };

  public:
    static constexpr const bool default_construct_data = skip_default_constructor_and_destructor;

    typedef array_base<T, Allocator> base_type;
    typedef typename base_type::value_type value_type;
    typedef typename base_type::size_type size_type;
    typedef typename base_type::pointer pointer;
    typedef typename base_type::const_pointer const_pointer;
    typedef typename base_type::iterator iterator;
    typedef typename base_type::const_iterator const_iterator;
    typedef std::random_access_iterator_tag iterator_category;

    static constexpr size_type initial_capacity = 1;

  public:
    array() : base_type() {}

    template<typename It>
    requires(sgl::v1::input_iterator(It) && sgl::v1::readable(It))
    array(typename std::enable_if<std::is_base_of<std::forward_iterator_tag, typename std::iterator_traits<It>::iterator_category>::value, It>::type first, It last) : base_type(std::distance(first, last)) {
        sgl::v1::uninitialized_copy(first, last, begin());
    }

    template<typename It>
    requires(sgl::v1::input_iterator(It) && sgl::v1::readable(It))
    array(typename std::enable_if<std::is_base_of<std::forward_iterator_tag, typename std::iterator_traits<It>::iterator_category>::value, It>::type first, It last, Allocator a) : base_type(std::distance(first, last), a) {
        sgl::v1::uninitialized_copy(first, last, begin());
    }

    template<typename It>
    requires(sgl::v1::input_iterator(It) && sgl::v1::readable(It))
    array(It first, It last) : array(typename std::iterator_traits<It>::iterator_tag{}, first, last) {}

    template<typename It>
    requires(sgl::v1::input_iterator(It) && sgl::v1::readable(It))
    array(It first, It last, Allocator a) : array(typename std::iterator_traits<It>::iterator_tag{}, first, last, a) {}


    template<typename It, typename UnaryFunction>
    requires(sgl::v1::input_iterator(It) && sgl::v1::readable(It) && sgl::v1::unary_function(UnaryFunction))
    array(typename std::enable_if<std::is_base_of<std::forward_iterator_tag, typename std::iterator_traits<It>::iterator_category>::value, It>::type first, It last, UnaryFunction unary_function) : base_type(std::distance(first, last)) {
        sgl::v1::uninitialized_transform(first, last, begin(), unary_function);
    }

    template<typename It, typename UnaryFunction>
    requires(sgl::v1::input_iterator(It) && sgl::v1::readable(It) && sgl::v1::unary_function(UnaryFunction))
    array(typename std::enable_if<std::is_base_of<std::forward_iterator_tag, typename std::iterator_traits<It>::iterator_category>::value, It>::type first, It last, UnaryFunction unary_function, Allocator a) : base_type(std::distance(first, last), a) {
        sgl::v1::uninitialized_copy(first, last, begin(), unary_function);
    }

    template<typename It, typename UnaryFunction>
    requires(sgl::v1::input_iterator(It) && sgl::v1::readable(It) && sgl::v1::unary_function(UnaryFunction))
    array(It first, It last, UnaryFunction unary_function) : array(typename std::iterator_traits<It>::iterator_tag{}, first, last, unary_function) {}

    template<typename It, typename UnaryFunction>
    requires(sgl::v1::input_iterator(It) && sgl::v1::readable(It) && sgl::v1::unary_function(UnaryFunction))
    array(It first, It last, UnaryFunction unary_function, Allocator allocator) : array(typename std::iterator_traits<It>::iterator_tag{}, first, last, unary_function, allocator) {}

    array(size_type n) : base_type(n) {
        if constexpr (!skip_default_constructor_and_destructor) {
            sgl::v1::uninitialized_default_construct(begin(), end());
        }
    }

    array(size_type n, const value_type& value) : base_type(n) {
        sgl::v1::uninitialized_fill(begin(), end(), value);
    }

    array(size_type n, Allocator a) : base_type(n, a) {
        if constexpr (!skip_default_constructor_and_destructor) {
            sgl::v1::uninitialized_default_construct(begin(), end());
        }
    }

    array(size_type n, const value_type& value, Allocator a) : base_type(n, a) {
        sgl::v1::uninitialized_fill(begin(), end(), value);
    }

    array(std::initializer_list<value_type> x) : base_type(x.size()) {
        sgl::v1::uninitialized_copy(x.begin(), x.end(), begin());
    }

    array(const array& x) : base_type(x.size()) {
        sgl::v1::uninitialized_copy(x.begin(), x.end(), begin());
    }

    array(array&& x) : base_type::first_(x.first_), base_type::last_(x.last_), base_type::finish_(x.finish_) {
        x.detach();
    }

    array& operator=(const array& x) {
        // if (std::addressof(x) == this) { return *this; } // Don't like it, but the behavior should be `identical` to built-in types 
        if constexpr (std::is_nothrow_copy_constructible<value_type>::value) {
            const size_type c0 = capacity();
            const size_type c1 = x.capacity();
            if (c0 < c1) {
                array tmp(x);
                swap(tmp);
                return *this;
            } else {
                const size_type s0 = size();
                const size_type s1 = x.size();
                if (s0 < s1 ) {
                    const_pointer middle = x.begin() + s0;
                    base_type::last_ = std::uninitialized_copy(middle, x.end(), std::copy(x.begin(), middle, begin()));
                } else {
                    pointer last_new = std::copy(x.begin(), x.end(), begin());
                    if constexpr (!skip_default_constructor_and_destructor) {
                        sgl::v1::destruct(base_type::last_, last_new);
                    }
                    base_type::last_ = last_new;
                }
                return *this;
            }
        } else {
            array tmp(x);
            swap(tmp);
            return *this;
        }
    }

    array& operator=(array&& x) {
        if (std::addressof(x) == this) { return *this; } // unavoidable // Don't like it, but the behavior should be `identical` to built-in types 
        this->~array();
        base_type::first_ = x.first_;
        base_type::last_ = x.last_;
        base_type::finish_ = x.finish_;
        x.detach();

        return *this;
    }

    ~array() {
        destructor_array();
    }

    friend
    inline
    bool operator==(const array& x, const array& y) {
        return x.size() == y.size() && sgl::v1::equal(x.begin(), x.end(), y.begin());
    }

    friend
    inline
    bool operator!=(const array& x, const array& y) {
        return !(x == y);
    }

    friend
    inline
    bool operator<(const array& x, const array& y) {
        return std::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
    }

    void destructor_array() {
        if constexpr (!skip_default_constructor_and_destructor) {
            sgl::v1::destruct(begin(), end());
        }
    }

    size_type capacity() const {
        return base_type::finish_ - base_type::first_;
    }

    size_type size() const {
        return base_type::last_ - base_type::first_;
    }

    size_type capacity_unused() {
        return base_type::finish_ - base_type::last_;
    }

    iterator begin() {
        return base_type::first_;
    }

    const_iterator begin() const {
        return base_type::first_;
    }

    iterator end() {
        return base_type::last_;
    }

    const_iterator end() const {
        return base_type::last_;
    }

    void reserve(size_type n) {
        if (capacity() < n) {
            reserve_unguarded(n);
        }
    }

    const_pointer data() const {
        return base_type::first_;
    }
    pointer data() {
        return base_type::first_;
    }

    void shrink_to_fit() {
        const size_type s = size();
        if (s == 0ul) {
            this->~array();
            base_type::detach();
        } else {
            reserve_unguarded(s);
        }
    }

    void resize_to_larger(size_type n) {
        if (capacity() < n) {
            reserve_unguarded(n);
        }
        if constexpr (!skip_default_constructor_and_destructor) {
            base_type::last_ = sgl::v1::uninitialized_default_construct(base_type::last_, base_type::first_ + n);
        } else {
            base_type::last_ = base_type::first_ + n;
        }
    }

    void resize_to_larger(size_type n, const value_type& x) {
        if (capacity() < n) {
            reserve_unguarded(n);
        }
        base_type::last_ = sgl::v1::uninitialized_fill(base_type::last_, base_type::first_ + n, x);
    }

    void resize_to_smaller(size_type n) {
        if constexpr (!skip_default_constructor_and_destructor) {
            sgl::v1::destruct(begin() + n, end());
        }
        base_type::last_ = base_type::first_ + n;
    }

    void resize(size_type n) {
        if (size() < n) {
            resize_to_larger(n);
        } else {
            resize_to_smaller(n);
        }
    }

    void resize(size_type n, const value_type& x) {
        if (size() < n) {
            resize_to_larger(n, x);
        } else {
            resize_to_smaller(n);
        }
    }

    void reserve() {
        const size_type current_capacity = capacity();
        if (current_capacity == 0) {
            reserve_unguarded(array::initial_capacity);
        } else {
            reserve_unguarded(current_capacity * 2ull);
        }
    }

    iterator insert(iterator position, value_type&& x) {
        const size_type offset = position - begin();

        if (base_type::last_ == base_type::finish_) {
            allocate_copy_range_value_range(multiplicative_resize(capacity(), array::initial_capacity), position, std::move(x));
        } else {
            insert_unguarded(position, std::move(x));
        }

        return begin() + offset;
    }

    void insert_unguarded(iterator position, value_type&& x) {
        if (end() == position) {
            sgl::v1::construct_at(base_type::last_, std::move(x));
        } else {
            if constexpr (prefer_move::value) {
                sgl::v1::uninitialized_move(end() - 1ul, end(), end());
                std::move_backward(position, end() - 1ul, end()); // move_backward
            } else {
                std::uninitialized_copy(end() - 1ul, end(), end());
                std::copy_backward(position, end() - 1ul, end()); // move_backward
            }
            *position = std::move(x);
        }
        ++base_type::last_;
    }

    iterator insert(iterator position, const value_type& x) {
        const size_type offset = position - begin();

        if (base_type::last_ == base_type::finish_) {
            const size_type initial_size = size();
            const size_type initial_capacity = capacity();
            allocate_copy_range_value_range(multiplicative_resize(initial_capacity, array::initial_capacity), position, x);
        } else {
            insert_unguarded(position, x);
        }
        return begin() + offset;
    }

    void insert_unguarded(iterator position, const value_type& x) {
        if (end() == position) {
            sgl::v1::construct_at(base_type::last_, x);
        } else {
            std::uninitialized_copy(end() - 1ul, end(), end());
            std::copy_backward(position, end() - 1ul, end());
            *position = x;
        }
        ++base_type::last_;
    }

    iterator insert(iterator position, const value_type& x, size_type n) {
        const size_type offset = position - begin();
        if (capacity_unused() < n) {
            const size_type initial_size = size();
            const size_type initial_capacity = capacity();
            allocate_copy_range_value_range(std::max(n + initial_size, multiplicative_resize(initial_capacity, array::initial_capacity)), position, x, n);
        } else {
            insert_unguarded(position, x, n);
        }
        return begin() + offset;
    }

    void insert_unguarded(iterator position, const value_type& x, size_type n) {
        if (n < size_type(end() - position)) {
            std::uninitialized_copy(end() - n, end(), end());
            std::copy_backward(position, end() - n, end());
            std::fill(position, position + n, x);
        } else {
            std::uninitialized_copy(position, end(), position + n);
            std::fill(position, end(), x);
            std::uninitialized_fill_n(end(), n - (end() - position), x);
        }
        base_type::last_ += n;
    }

    void push_back(const value_type& x) {
        if (base_type::last_ == base_type::finish_) {
            reserve();
        }
        push_back_unguarded(x);
    }

    void push_back_unguarded(const value_type& x) {
        sgl::v1::construct_at(base_type::last_, x);
        ++base_type::last_;
    }

    void push_back(value_type&& x) {
        if (base_type::last_ == base_type::finish_) {
            reserve();
        }
        push_back_unguarded(std::move(x));
    }

    void push_back_unguarded(value_type&& x) {
        sgl::v1::construct_at(base_type::last_, std::move(x));
        ++base_type::last_;
    }

    void emplace_back(const value_type& x) {
        if (base_type::last_ == base_type::finish_) {
            reserve();
        }
        emplace_back_unguarded(x);
    }

    void emplace_back_unguarded(const value_type& x) {
        sgl::v1::construct_at(base_type::last_, x);
        ++base_type::last_;
    }

    void emplace_back(value_type&& x) {
        if (base_type::last_ == base_type::finish_) {
            reserve();
        }
        emplace_back_unguarded(std::move(x));
    }

    void emplace_back_unguarded(value_type&& x) {
        sgl::v1::construct_at(base_type::last_, std::move(x));
        ++base_type::last_;
    }

    template <typename... Args>
    void emplace_back(Args&&... x) {
        if (base_type::last_ == base_type::finish_) {
            reserve();
        }
        emplace_back_unguarded(std::forward<Args>(x)...);
    }

    template <typename... Args>
    void emplace_back_unguarded(Args&&... x) {
        sgl::v1::construct_at(base_type::last_, std::forward<Args>(x)...);
        ++base_type::last_;
    }

    bool empty() const {
        return base_type::first_ == base_type::last_;
    }

    value_type& operator[](size_type i) {
        return base_type::first_[i];
    }

    const value_type& operator[](size_type i) const {
        return base_type::first_[i];
    }

    void reallocate_assign(size_type n, const value_type& x) {
        T* data = base_type::allocate(n);
        if (data == nullptr) { throw std::bad_alloc(); }
        if constexpr (std::is_nothrow_copy_constructible<T>::value) {
            base_type::last_ = sgl::v1::uninitialized_fill(data, data + n, x);
        } else {
            try {
                base_type::last_ = sgl::v1::uninitialized_fill(data, data + n, x);
            } catch (...) {
                base_type::deallocate(data);
                throw;
            }
        }

        ~array();

        base_type::first_ = data;
        base_type::finish_ = base_type::last_;
    }

    void assign(size_type n, const value_type& x) {
        const size_type s = size();
        if (s < n) {
            reallocate_assign(n, x);
        } else {
            if constexpr (std::is_nothrow_copy_assignable<T>::value) {
                if constexpr (!skip_default_constructor_and_destructor) {
                    sgl::v1::destruct(begin() + n, end());
                }
                base_type::last_ = base_type::first_ + n;
                std::fill(begin(), begin() + n, x);
            } else {
                reallocate_assign(n, x);
            }
        }
    }

    template<typename It>
    void assign_move(It first, It last) {
        allocate_move_swap(std::distance(first, last), first, last);
    }

    template <typename ForwardIterator>
    // typename sgl::v1::enable_if_forward_iterator<ForwardIterator>::type
    typename std::enable_if<!std::is_arithmetic<ForwardIterator>::value>::type
    assign(ForwardIterator first, ForwardIterator last) {
        allocate_copy_swap(std::distance(first, last), first, last);
    }

    T& front() {
        return *base_type::first_;
    }

    const T& front() const {
        return *base_type::first_;
    }

    T& back() {
        return *(base_type::last_ - 1ul);
    }

    const T& back() const {
        return *(base_type::last_ - 1ul);
    }

    void pop_back() {
        --base_type::last_;
    }

    iterator erase(iterator position) { // const_iterator. C++11, What?
        std::move(position + 1ul, end(), position);
        --base_type::last_;
        if constexpr (!skip_default_constructor_and_destructor) {
            sgl::v1::destruct(base_type::last_);
        }
        return position;
    }

    iterator erase(iterator f, iterator l) {
        if constexpr (skip_default_constructor_and_destructor) {
            base_type::last_ = std::move(l, end(), f);
        } else {
            iterator last_new = std::move(l, end(), f);
            sgl::v1::destruct(last_new, end());
            base_type::last_ = last_new;
        }
        return f;
    }

    friend
    inline
    void swap(array& x, array& y) {
        std::swap(x.first_, y.first_);
        std::swap(x.last_, y.last_);
        std::swap(x.finish_, y.finish_);
    }

    void swap(array& y) {
        std::swap(base_type::first_, y.first_);
        std::swap(base_type::last_, y.last_);
        std::swap(base_type::finish_, y.finish_);
    }

    void clear() {
        if constexpr (!skip_default_constructor_and_destructor) {
            sgl::v1::destruct(begin(), end());
        }
        base_type::last_ = base_type::first_;
    }

    friend struct unittest;
    struct unittest;

  private:

    void reserve_unguarded(size_type new_capacity) {
        T* data = base_type::allocate(new_capacity);
        if (data == nullptr) { throw std::bad_alloc(); }

        if constexpr (prefer_move::value) {
            if constexpr (std::is_nothrow_move_constructible<T>::value) {
                base_type::last_ = std::uninitialized_move(begin(), end(), data);
            } else {
                try {
                    base_type::last_ = std::uninitialized_move(begin(), end(), data);
                } catch (...) {
                    // leaves array objects in a partially formed state
                    base_type::deallocate(data);
                    throw;
                }
            }
        } else {
            if constexpr (std::is_nothrow_copy_constructible<T>::value) {
                base_type::last_ = std::uninitialized_copy(begin(), end(), data);
            } else {
                try {
                    base_type::last_ = std::uninitialized_copy(begin(), end(), data);
                } catch (...) {
                    base_type::deallocate(data);
                    throw;
                }
            }
        }
        this->~array();

        base_type::first_ = data;
        base_type::finish_ = data + new_capacity;
    }

    template<typename It>
    void allocate_copy_swap(size_type new_capacity, It first, It last) {
        T* data = base_type::allocate(new_capacity);
        if (data == nullptr) { throw std::bad_alloc(); }
        if constexpr (std::is_nothrow_copy_constructible<T>::value) {
            base_type::last_ = std::uninitialized_copy(first, last, data);
        } else {
            try {
                base_type::last_ = base_type::last_ = std::uninitialized_copy(first, last, data);
            } catch (...) {
                base_type::deallocate(data);
                throw;
            }
        }
        this->~array();

        base_type::first_ = data;
        base_type::finish_ = data + new_capacity;
    }

    template<typename It>
    void allocate_move_swap(size_type new_capacity, It first, It last) {
        T* data = base_type::allocate(new_capacity);
        if (data == nullptr) { throw std::bad_alloc(); }
        if constexpr (std::is_nothrow_move_constructible<T>::value) {
             base_type::last_ = std::uninitialized_move(first, last, data);
        } else {
            try {
                base_type::last_ = std::uninitialized_move(first, last, data);
            } catch (...) {
                base_type::deallocate(data);
                throw;
            }
        }
        this->~array();

        base_type::first_ = data;
        base_type::finish_ = data + new_capacity;
    }

    void allocate_copy_range_value_range(size_type new_capacity, iterator position, const value_type& x) {
        T* data = base_type::allocate(new_capacity);
        if (data == nullptr) { throw std::bad_alloc(); }
        //size_type offset = position - begin();

        if constexpr (prefer_move::value) {
            if constexpr (std::is_nothrow_move_constructible<T>::value) {
                base_type::last_ = sgl::v1::uninitialized_move_range_value_range(base_type::first_, position, base_type::last_, x, data);
            } else {
                try {
                    base_type::last_ = sgl::v1::uninitialized_move_range_value_range(base_type::first_, position, base_type::last_, x, data);
                } catch (...) {
                    base_type::deallocate(data);
                    throw;
                }
            }
        } else {
            if constexpr (std::is_nothrow_copy_constructible<T>::value) {
                base_type::last_ = sgl::v1::uninitialized_copy_range_value_range(base_type::first_, position, base_type::last_, x, data);
            } else {
                try {
                    base_type::last_ = sgl::v1::uninitialized_copy_range_value_range(base_type::first_, position, base_type::last_, x, data);
                } catch (...) {
                    base_type::deallocate(data);
                    throw;
                }
            }
        }
        this->~array();
        base_type::first_ = data;
        base_type::finish_ = data + new_capacity;
    }

    void allocate_copy_range_value_range(size_type new_capacity, iterator position, value_type&& value) {
        T* data = base_type::allocate(new_capacity);
        if (data == nullptr) { throw std::bad_alloc(); }
        //size_type offset = position - begin();

        if constexpr (prefer_move::value) {
            if constexpr (std::is_nothrow_move_constructible<T>::value) {
                base_type::last_ = sgl::v1::uninitialized_move_range_value_range(base_type::first_, position, base_type::last_, std::move(value), data);
            } else {
                try {
                    base_type::last_ = sgl::v1::uninitialized_move_range_value_range(base_type::first_, position, base_type::last_, std::move(value), data);
                } catch (...) {
                    base_type::deallocate(data);
                    throw;
                }
            }
        } else {
            if constexpr (std::is_nothrow_copy_constructible<T>::value) {
                base_type::last_ = sgl::v1::uninitialized_copy_range_value_range(base_type::first_, position, base_type::last_, std::move(value), data);
            } else {
                try {
                    base_type::last_ = sgl::v1::uninitialized_copy_range_value_range(base_type::first_, position, base_type::last_, value, data);
                } catch (...) {
                    base_type::deallocate(data);
                    throw;
                }
            }
        }
        this->~array();
        base_type::first_ = data;
        base_type::finish_ = data + new_capacity;
    }

    void allocate_copy_range_value_range(size_type new_capacity, iterator position, const value_type& value, size_type n) {
        T* data = base_type::allocate(new_capacity);
        if (data == nullptr) { throw std::bad_alloc(); }
        //size_type offset = position - begin();

        if constexpr (prefer_move::value) {
            if constexpr (std::is_nothrow_move_constructible<T>::value) {
                base_type::last_ = sgl::v1::uninitialized_move_range_value_range(base_type::first_, position, base_type::last_, value, n, data);
            } else {
                try {
                    base_type::last_ = sgl::v1::uninitialized_move_range_value_range(base_type::first_, position, base_type::last_, value, n, data);
                } catch (...) {
                    base_type::deallocate(data);
                    throw;
                }
            }
        } else {
            if constexpr (std::is_nothrow_move_constructible<T>::value) {
                base_type::last_ = sgl::v1::uninitialized_copy_range_value_range(base_type::first_, position, base_type::last_, value, n, data);
            } else {
                try {
                    base_type::last_ = sgl::v1::uninitialized_copy_range_value_range(base_type::first_, position, base_type::last_, value, n, data);
                } catch (...) {
                    base_type::deallocate(data);
                    throw;
                }
            }
        }
        this->~array();
        base_type::first_ = data;
        base_type::finish_ = data + new_capacity;
    }
};

} // namespace v1
} // namespace sgl
