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
    typedef const_pointer const_iterator;
    typedef size_t size_type;

    Allocator allocator;
    pointer first_ = nullptr;
    pointer last_ = nullptr;
    pointer finish_ = nullptr;

    array_base() = default;

    array_base(size_type n) : first_(allocate(n)), last_(first_ + n), finish_(last_) {}
    array_base(T* first, T* last, T* finish) : first_(first), last_(last), finish_(finish) {}

    array_base(size_type n, Allocator a) : allocator(std::move(a)), first_(allocate(n)), last_(first_ + n), finish_(last_) {}

    pointer allocate(size_type n) {
        return allocator.allocate(n);
    }

    void deallocate(pointer data) {
        allocator.deallocate(data, finish_ - first_);
    }

    void deallocate() {
        if (first_ != nullptr) {
            deallocate_unguarded();
        }
    }

    void deallocate_unguarded() {
        deallocate(first_);
    }

    void detach() {
        first_ = nullptr;
        last_ = nullptr;
        finish_ = nullptr;
    }

    ~array_base() {
        deallocate();
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

    array_base(T* first, T* last, T* finish) : first_(first), last_(last), finish_(finish) {}

    pointer allocate(size_type n) {
        return std::allocator<T>().allocate(n);
    }

    void deallocate(pointer data) { std::allocator<T>().deallocate(data, finish_ - first_); }

    void deallocate() {
        if (first_ != finish_) {
            deallocate_unguarded();
        }
    }
    void deallocate_unguarded() {
        deallocate(first_);
    }
    void detach() {
        first_ = nullptr;
        last_ = nullptr;
        finish_ = nullptr;
    }

    ~array_base() {
        deallocate();
    }
};


template<typename T, bool>
struct optional_default_construct {
    void operator()(T* first, T* last) const {
        sgl::v1::default_construct(first, last);
    }
};

template<typename T>
struct optional_default_construct<T, false> {
    void operator()(T* first, T* last) const noexcept {}
};


template<typename T, bool>
struct optional_destroy {
    void operator()(T* first) const {
        sgl::v1::destruct(first);
    }

    void operator()(T* first, T* last) const {
        sgl::v1::destruct(first, last);
    }
};

template<typename T>
struct optional_destroy<T, false> {
    void operator()(T* first) const noexcept {}
    void operator()(T* first, T* last) const noexcept {}
};


template<typename T, bool>
struct _uninitialized_copy_or_move {
    T* operator()(T* first, T* last, T* out) const {
        return sgl::v1::uninitialized_copy(first, last, out);
    }

    T* operator()(T* first, T* last, T* out, const T& value) const {
        return sgl::v1::uninitialized_copy(first, last, out, value);
    }

    T* operator()(T* first, T* last, T* out, T&& value) const {
        return sgl::v1::uninitialized_copy(first, last, out, std::move(value));
    }
};

template<typename T>
struct _uninitialized_copy_or_move<T, false> {
    T* operator()(T* first, T* last, T* out) const {
        return sgl::v1::uninitialized_move(first, last, out);
    }

    T* operator()(T* first, T* last, T* out, const T& value) const {
        return sgl::v1::uninitialized_move(first, last, out, value);
    }

    T* operator()(T* first, T* last, T* out, T&& value) const {
        return sgl::v1::uninitialized_move(first, last, out, std::move(value));
    }
};




template<typename T, typename A = std::allocator<T>, bool ctor = !sgl::v1::is_trivial<T>::value>
class array : protected sgl::v1::array_base<T, A> {
public:
    static bool constexpr const invoke_default_constructor = ctor;

    typedef array_base<T, A> base_type;
    typedef typename base_type::value_type value_type;
    typedef typename base_type::size_type size_type;
    typedef typename base_type::pointer pointer;
    typedef typename base_type::const_pointer const_pointer;
    typedef typename base_type::iterator iterator;
    typedef typename base_type::const_iterator const_iterator;
    typedef std::random_access_iterator_tag iterator_category;

private:
    struct prefer_copy {
        static constexpr const bool value = std::is_trivial<T>::value || !std::is_move_constructible<T>::value || (std::is_copy_constructible<T>::value && !std::is_nothrow_move_constructible<T>::value);
    };

public:
    array() : base_type() {}

    array(size_type n) : base_type(n) {
        sgl::v1::optional_default_construct<T, ctor>()(base_type::first_, base_type::last_);
    }

    array(size_type n, A allocator) : base_type(n, std::move(allocator)) {
        sgl::v1::optional_default_construct<T, ctor>()(base_type::first_, base_type::last_);
    }

    array(size_type n, const value_type& value) : base_type(n) {
        sgl::v1::uninitialized_fill(base_type::first_, base_type::last_, value);
    }

    array(size_type n, const value_type& value, A allocator) : base_type(n, std::move(allocator)) {
        sgl::v1::uninitialized_fill(base_type::first_, base_type::last_, value);
    }

    template<typename It>
    array(It first, It last) : base_type(sgl::v1::distance(first, last)) {
        static_assert(std::is_same<typename std::decay<typename std::iterator_traits<It>::value_type>::type, T>::value, "invalid type");
        sgl::v1::uninitialized_copy(first, last, base_type::first_);
    }

    template<typename It>
    array(It first, It last, A allocator) : base_type(sgl::v1::distance(first, last), std::move(allocator)) {
        static_assert(std::is_same<typename std::decay<typename std::iterator_traits<It>::value_type>::type, T>::value, "invalid type");
        sgl::v1::uninitialized_copy(first, last, base_type::first_);
    }


    template<typename It, typename UnaryFunction>
    array(It first, It last, UnaryFunction unary_function) : base_type(sgl::v1::distance(first, last)) {
        static_assert(std::is_same<typename std::decay<typename std::iterator_traits<It>::value_type>::type, T>::value, "invalid type");
        sgl::v1::uninitialized_transform(first, last, base_type::first_, unary_function);
    }

    template<typename It, typename UnaryFunction>
    array(It first, It last, UnaryFunction unary_function, A allocator) : base_type(sgl::v1::distance(first, last), std::move(allocator)) {
        static_assert(std::is_same<typename std::decay<typename std::iterator_traits<It>::value_type>::type, T>::value, "invalid type");
        sgl::v1::uninitialized_transform(first, last, base_type::first_, unary_function);
    }

    ~array() {
        optional_destroy<T, prefer_copy::value>()(base_type::first_, base_type::last_);
    }

    const_iterator begin() const {
        return base_type::first_;
    }

    iterator begin() {
        return base_type::first_;
    }

    const_iterator end() const {
        return base_type::last_;
    }

    iterator end() {
        return base_type::last_;
    }

    const T* data() const {
        return base_type::first_;
    }

    T* data() {
        return base_type::first_;
    }

    const T& back() const {
        return *(base_type::last_ - 1);
    }

    T& back() {
        return *(base_type::last_ - 1);
    }

    void pop_back() {
        --base_type::last_; 
        optional_destroy<T, !sgl::v1::is_trivial<T>::value>()(base_type::last_);
    }

    const T& front() const {
        return *(base_type::first_);
    }

    T& front() {
        return *(base_type::first_);
    }

    const T& operator[](size_type i) const {
        return base_type::first_[i];
    }

    T& operator[](size_type i) {
        return base_type::first_[i];
    }


    size_type size() const {
        return base_type::last_ - base_type::first_;
    }

    size_type capacity() const {
        return base_type::finish_ - base_type::first_;
    }

    size_type reallocation_capacity() const {
        if (base_type::first_ != base_type::finish_) {
            return (base_type::finish_ - base_type::first_) << 1ull;
        }
        return 1ull;
    }

    void push_back_unguarded(const value_type& value) {
        sgl::v1::construct(base_type::last_, value);
        ++base_type::last_;

    }

    void push_back_unguarded(value_type&& value) {
        sgl::v1::construct(base_type::last_, std::move(value));
        ++base_type::last_;

    }

    void push_back(const value_type& value) {
        if (base_type::last_ != base_type::finish_) {
            this->push_back_unguarded(value);
        } else {
            this->push_back_realocate(value);
        }
    }

    void push_back(value_type&& value) {
        std::cout << prefer_copy::value << std::endl;
        if (base_type::last_ != base_type::finish_) {
            this->push_back_unguarded(std::move(value));
        } else {
            this->push_back_realocate(std::move(value));
        }
    }

    void push_back_realocate(const value_type& value) {
        size_type capacity_new = reallocation_capacity();
        pointer first_new = base_type::allocate(capacity_new);
        if (first_new == nullptr) {
            throw std::bad_alloc();
        }
        pointer last_new;
        try {
            last_new = this->uninitialized_copy_or_move(first_new, value);
        } catch (...) {
            base_type::deallocate(first_new);
            throw;
        }
        optional_destroy<T, !sgl::v1::is_trivial<T>::value>()(base_type::first_, base_type::last_);
        base_type::deallocate();
        base_type::first_ = first_new;
        base_type::last_ = last_new;
        base_type::finish_ = first_new + capacity_new;
    }

    void push_back_realocate(value_type&& value) {
        size_type capacity_new = reallocation_capacity();
        pointer first_new = base_type::allocate(capacity_new);
        if (first_new == nullptr) {
            throw std::bad_alloc();
        }
        pointer last_new;
        try {
            last_new = this->uninitialized_copy_or_move(first_new, std::move(value));
        } catch (...) {
            base_type::deallocate(first_new);
            throw;
        }
        optional_destroy<T, !sgl::v1::is_trivial<T>::value>()(base_type::first_, base_type::last_);
        base_type::deallocate();
        base_type::first_ = first_new;
        base_type::last_ = last_new;
        base_type::finish_ = first_new + capacity_new;
    }


    template<typename... Args>
    void emplace_back_realocate(Args&&... args) {
        size_type capacity_new = reallocation_capacity();
        pointer first_new = base_type::allocate(capacity_new);
        if (first_new == nullptr) {
            throw std::bad_alloc();
        }
        pointer last_new;
        try {
            last_new = this->uninitialized_copy_or_move(first_new, std::forward<Args>(args)...);
        } catch (...) {
            base_type::deallocate(first_new);
            throw;
        }
        optional_destroy<T, !sgl::v1::is_trivial<T>::value>()(base_type::first_, base_type::last_);
        base_type::deallocate();
        base_type::first_ = first_new;
        base_type::last_ = last_new;
        base_type::finish_ = first_new + capacity_new;
    }

    void reserve(size_type capacity_new) {
        if (capacity() < capacity_new) {
            this->reserve_unguarded(capacity_new);
        }
    }

    template<typename... Args>
    void emplace_back(Args&&... args) {
        if (base_type::last_ == base_type::finish_) {
            this->reserve_unguarded(this->reallocation_capacity());
        }
        sgl::v1::construct(base_type::last_, std::forward<Args>(args)...);
        ++base_type::last_;
    }

    std::pair<iterator, iterator> insert(iterator position, const value_type& value, size_type n) {
        const size_type n_free = base_type::finish_ - base_type::last_;
        if (n <= n_free) {
            size_type n_tail = base_type::last_ - position;
            if (n < n_tail) {
                sgl::v1::uninitialized_copy(base_type::last_ - n, base_type::last_, base_type::last_);
                sgl::v1::copy(position, base_type::last_ - n, position + n);
                sgl::v1::fill(position, position + n, value);
            } else {
                sgl::v1::uninitialized_copy(position, base_type::last_, position + n);
                sgl::v1::fill(position, position + n_tail, value);
                sgl::v1::uninitialized_fill(position + n_tail, position + n, value);
            }
            base_type::last_ += n;
            return {position, position + n};
        } else {
            size_type capacity_new = size() + sgl::v1::max(n, size());
            pointer first_new = base_type::allocate(capacity_new);
            if (first_new == nullptr) {
                if (size() + n < capacity_new) {
                    capacity_new = size() + n;
                    first_new = base_type::allocate(capacity_new);
                    if (first_new == nullptr) {
                        throw std::bad_alloc();
                    }
                } else {
                    throw std::bad_alloc();
                }
            }
            pointer middle = sgl::v1::uninitialized_copy(base_type::first_, position, first_new);
            pointer last = middle + n;
            sgl::v1::uninitialized_fill(middle, last, value);
            pointer last_new = sgl::v1::uninitialized_copy(position, base_type::last_, last);

            optional_destroy<T, !sgl::v1::is_trivial<T>::value>()(base_type::first_, base_type::last_);
            base_type::deallocate(base_type::first_);

            base_type::first_ = first_new;
            base_type::last_ = last_new;
            base_type::finish_ = first_new + capacity_new;
            return {middle, last};
        }
    }

    template<typename It>
    typename std::enable_if<std::is_base_of<std::forward_iterator_tag, typename std::iterator_traits<It>::iterator_category>::value, std::pair<iterator, iterator> >::type
    insert_n(iterator position, It first, size_type n) {
        const size_type n_free = base_type::finish_ - base_type::last_;
        if (n_free < n) {
            size_type capacity_new = size() + sgl::v1::max(n, size());
            pointer first_new = base_type::allocate(capacity_new);
            if (first_new == nullptr) {
                if (size() + n < capacity_new) {
                    capacity_new = size() + n;
                    first_new = base_type::allocate(capacity_new);
                    if (first_new == nullptr) {
                        throw std::bad_alloc();
                    }
                } else {
                    throw std::bad_alloc();
                }
            }
            pointer position_first = sgl::v1::uninitialized_copy(base_type::first_, position, first_new);
            pointer position_last = sgl::v1::uninitialized_copy_n(first, n, position_first).second;
            pointer last_new = sgl::v1::uninitialized_copy(position, base_type::last_, position_last);

            optional_destroy<T, !sgl::v1::is_trivial<T>::value>()(base_type::first_, base_type::last_);
            base_type::deallocate(base_type::first_);

            base_type::first_ = first_new;
            base_type::last_ = last_new;
            base_type::finish_ = first_new + capacity_new;
            return {position_first, position_last};
        } else {
            size_type n_tail = base_type::last_ - position;
            if (n < n_tail) {
                sgl::v1::uninitialized_copy(base_type::last_ - n, base_type::last_, base_type::last_);
                sgl::v1::copy(position, base_type::last_ - n, position + n);
                sgl::v1::copy_n(first, n, position);
            } else {
                sgl::v1::uninitialized_copy(position, base_type::last_, position + n);
                sgl::v1::uninitialized_copy_n(sgl::v1::copy_n(first, n_tail, position).first, n - n_tail, base_type::last_);
            }
            base_type::last_ += n;
            return {position, position + n};
        }
    }

    pointer allocate(size_type& n, size_type n_min) {
        pointer first_new = base_type::allocate(n);
        if (first_new != nullptr || n >= n_min) {
            return first_new;
        }
        n = n_min;
        return base_type::allocate(n);
    }

    template<typename It>
    typename std::enable_if<std::is_base_of<std::forward_iterator_tag, typename std::iterator_traits<It>::iterator_category>::value, std::pair<iterator, iterator> >::type
    insert(iterator position, It first, It last) {
        if (first == last) return {position, position};
        const size_type n = std::distance(first, last);
        const size_type n_free = base_type::finish_ - base_type::last_;
        if (n <= n_free) {
            size_type n_tail = base_type::last_ - position;
            if (n < n_tail) {
                sgl::v1::uninitialized_copy(base_type::last_ - n, base_type::last_, base_type::last_);
                sgl::v1::copy(position, base_type::last_ - n, position + n);
                sgl::v1::copy(first, last, position);
            } else {
                sgl::v1::uninitialized_copy(position, base_type::last_, position + n);
                sgl::v1::uninitialized_copy(sgl::v1::copy_n(first, n_tail, position).first, last, base_type::last_);
            }
            base_type::last_ += n;
            return {position, position + n};
        } else {
            size_type capacity_new = size() + sgl::v1::max(n, size());
            pointer first_new = base_type::allocate(capacity_new);
            if (first_new == nullptr) {
                if (size() + n < capacity_new) {
                    capacity_new = size() + n;
                    first_new = base_type::allocate(capacity_new);
                    if (first_new == nullptr) {
                        throw std::bad_alloc();
                    }
                } else {
                    throw std::bad_alloc();
                }
            }
            pointer position_first = sgl::v1::uninitialized_copy(base_type::first_, position, first_new);
            pointer position_last = sgl::v1::uninitialized_copy(first, last, position_first);
            pointer last_new = sgl::v1::uninitialized_copy(position, base_type::last_, position_last);

            optional_destroy<T, !sgl::v1::is_trivial<T>::value>()(base_type::first_, base_type::last_);
            base_type::deallocate(base_type::first_);

            base_type::first_ = first_new;
            base_type::last_ = last_new;
            base_type::finish_ = first_new + capacity_new;
            return {position_first, position_last}; 
        }
    }

    void reserve_unguarded(size_type capacity_new) {
        pointer first_new = base_type::allocate(capacity_new);
        if (first_new == nullptr) {
            throw std::bad_alloc();
        }
        pointer last_new;
        try {
            last_new = this->uninitialized_copy_or_move(first_new);
        } catch (...) {
            base_type::deallocate(first_new);
            throw;
        }
        optional_destroy<T, !sgl::v1::is_trivial<T>::value>()(base_type::first_, base_type::last_);
        base_type::deallocate();
        base_type::first_ = first_new;
        base_type::last_ = last_new;
        base_type::finish_ = first_new + capacity_new;
    }

    T* uninitialized_copy_or_move(T* out) {
        return _uninitialized_copy_or_move<T, prefer_copy::value>()(base_type::first_, base_type::last_, out);
    }

    T* uninitialized_copy_or_move(T* out, const T& value) {
        return _uninitialized_copy_or_move<T, prefer_copy::value>()(base_type::first_, base_type::last_, out, value);
    }

    T* uninitialized_copy_or_move(T* out, T&& value) {
        return _uninitialized_copy_or_move<T, prefer_copy::value>()(base_type::first_, base_type::last_, out, std::move(value));
    }
};


} // namespace v1
} // namespace sgl
