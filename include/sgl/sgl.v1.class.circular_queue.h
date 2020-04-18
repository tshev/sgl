#pragma once

namespace sgl {
namespace v1 {

template<typename T, typename Allocator>
class circular_queue_base {
protected:
    T* data_first_;
    T* data_last_;

    T* first_;
    T* last_;
    std::allocator<T> allocator;

    circular_queue_base() : data_first_(nullptr), first_(nullptr), last_(nullptr) {}

    circular_queue_base(size_t capacity) : data_first_(allocate(capacity)), data_last_(data_first_ + capacity), first_(data_first_), last_(data_first_) {}

    circular_queue_base(size_t capacity, size_t n) : data_first_(allocate(capacity)), data_last_(data_first_ + capacity), first_(data_first_), last_(data_first_ + n) {
        sgl::v1::uninitialized_construct_range(first_, last_);
    }
    circular_queue_base(size_t capacity, size_t n, const T& val) : data_first_(allocate(capacity)), data_last_(data_first_ + capacity), first_(data_first_), last_(data_first_ + n) {
        sgl::v1::uninitialized_construct_range(first_, last_, val);
    }


    T* allocate(size_t n) {
        return allocator.allocate(n);
    }

    void deallocate(T* p, size_t n) {
        return allocator.deallocate(p, n);
    }

    ~circular_queue_base() {
        if (first_ < last_) {
            sgl::v1::destruct(first_, last_);
        } else if (last_ < first_) {
            sgl::v1::destruct(first_, data_last_);
            sgl::v1::destruct(data_first_, last_);
        } else if (first_ == last_ && first_  != data_first_) {
            sgl::v1::destruct(data_first_, data_last_);
        }
        deallocate(data_first_, data_last_ - data_first_);
    }
};


template<typename T>
class circular_queue_base<T, std::allocator<T>> {
protected:
    T* data_first_;
    T* data_last_;

    T* first_;
    T* last_;

    circular_queue_base() : data_first_(nullptr), first_(nullptr), last_(nullptr) {}

    circular_queue_base(size_t capacity) : data_first_(allocate(capacity)), data_last_(data_first_ + capacity), first_(data_first_), last_(data_first_) {}

    circular_queue_base(size_t capacity, size_t n) : data_first_(allocate(capacity)), data_last_(data_first_ + capacity), first_(data_first_), last_(data_first_ + n) {
        sgl::v1::uninitialized_construct_range(first_, last_);
    }

    circular_queue_base(size_t capacity, size_t n, const T& val) : data_first_(allocate(capacity)), data_last_(data_first_ + capacity), first_(data_first_), last_(data_first_ + n) {
        sgl::v1::uninitialized_construct_range(first_, last_, val);
    }

    ~circular_queue_base() {
        if (data_first_ != nullptr) {
            if (first_ < last_) {
                sgl::v1::destruct(first_, last_);
            } else if (last_ < first_) {
                sgl::v1::destruct(first_, data_last_);
                sgl::v1::destruct(data_first_, last_);
            } else if (first_ == last_ && first_  != data_first_) {
                sgl::v1::destruct(data_first_, data_last_);
            }
            deallocate(data_first_, data_last_ - data_first_);
        }
    }

    T* allocate(size_t n) {
        std::allocator<T> allocator;
        return allocator.allocate(n);
    }

    void deallocate(T* p, size_t n) {
        std::allocator<T> allocator;
        return allocator.deallocate(p, n);
    }
};


template<typename T, typename Allocator = std::allocator<T>>
class circular_queue : circular_queue_base<T, Allocator> {
    // implementation with a hole
private:
    typedef circular_queue_base<T, Allocator> base_type;

public:
    circular_queue() : base_type() {}

    circular_queue(size_t capacity) : base_type(capacity) {}

    circular_queue(size_t capacity, size_t n) : base_type(capacity, n) {}

    circular_queue(size_t capacity, size_t n, const T& val) : base_type(capacity, n, val) {}

    bool empty() {
        return base_type::data_first_ == base_type::first_ == base_type::last_;
    }

    size_t capacity() const {
        return base_type::data_last_ - base_type::data_first_;
    }

    size_t size() const {
        if (base_type::first_ < base_type::last_) {
            return base_type::last_ - base_type::first_;
        } else if (base_type::last_ < base_type::first_) {
            return (base_type::data_last_ - base_type::first_) + (base_type::last_ - base_type::data_first_);
        }
        if (base_type::first_ == base_type::last_ == base_type::data_first_) {
            return 0;
        } else {
            return base_type::data_last_ -  base_type::data_first_;
        }
    }
    
    bool push_back(const T& value) {
        if (base_type::first_ < base_type::last_) {
            if (base_type::last_ < base_type::data_last_) {
                sgl::v1::uninitialized_construct(*base_type::last_, value);
                ++base_type::last_;
                return true;
            }
            if (base_type::data_first_ < base_type::first_) { // place for a hole
                base_type::last_ = base_type::data_first_;
                sgl::v1::uninitialized_construct(*base_type::last_, value);
                ++base_type::last_;
                return true;
            }
            return false;
        }
        if (base_type::last_ < base_type::first_ || base_type::first_ == base_type::last_ == base_type::data_first_) { // place for a hole
            sgl::v1::uninitialized_construct(*base_type::last_, value);
            ++base_type::last_;
            return true;
        }
        return false;
    }

    void pop_front() {
        // assert empty();
        if (base_type::first_ < base_type::data_last_) {
            sgl::v1::destruct(*base_type::first_);
            ++base_type::first_;
            return;
        }
        base_type::first_ = base_type::data_first_;
        ++base_type::first_;
    }
};


template<typename T, typename Allocator>
class circular_queue_with_hole_base {
protected:
    T* data_first_;
    T* data_last_;

    T* first_;
    T* last_;
    std::allocator<T> allocator;

    circular_queue_with_hole_base() : data_first_(nullptr), first_(nullptr), last_(nullptr) {}
    circular_queue_with_hole_base(size_t capacity) : data_first_(allocate(capacity)), data_last_(data_first_ + capacity), first_(data_first_), last_(data_first_) {}
    circular_queue_with_hole_base(size_t capacity, size_t n) : data_first_(allocate(capacity)), data_last_(data_first_ + capacity), first_(data_first_), last_(data_first_ + n) {
        sgl::v1::uninitialized_construct_range(first_, last_);
    }
    circular_queue_with_hole_base(size_t capacity, size_t n, const T& val) : data_first_(allocate(capacity)), data_last_(data_first_ + capacity), first_(data_first_), last_(data_first_ + n) {
        sgl::v1::uninitialized_construct_range(first_, last_, val);
    }


    T* allocate(size_t n) {
        return allocator.allocate(n);
    }

    void deallocate(T* p, size_t n) {
        return allocator.deallocate(p, n);
    }
};


template<typename T>
class circular_queue_with_hole_base<T, std::allocator<T>> {
protected:
    T* data_first_;
    T* data_last_;

    T* first_;
    T* last_;

    circular_queue_with_hole_base() : data_first_(nullptr), first_(nullptr), last_(nullptr) {}
    circular_queue_with_hole_base(size_t capacity) : data_first_(allocate(capacity)), data_last_(data_first_ + capacity), first_(data_first_), last_(data_first_) {}
    circular_queue_with_hole_base(size_t capacity, size_t n) : data_first_(allocate(capacity)), data_last_(data_first_ + capacity), first_(data_first_), last_(data_first_ + n) {
        sgl::v1::uninitialized_construct_range(first_, last_);
    }
    circular_queue_with_hole_base(size_t capacity, size_t n, const T& val) : data_first_(allocate(capacity)), data_last_(data_first_ + capacity), first_(data_first_), last_(data_first_ + n) {
        sgl::v1::uninitialized_construct_range(first_, last_, val);
    }


    T* allocate(size_t n) {
        std::allocator<T> allocator;
        return allocator.allocate(n);
    }

    void deallocate(T* p, size_t n) {
        std::allocator<T> allocator;
        return allocator.deallocate(p, n);
    }
};


template<typename T, typename Allocator = std::allocator<T>>
class circular_queue_with_hole : circular_queue_with_hole_base<T, Allocator> {
    // implementation with a hole
private:
    typedef circular_queue_with_hole_base<T, Allocator> base_type;
public:
    circular_queue_with_hole() : base_type() {}
    circular_queue_with_hole(size_t capacity) : base_type(capacity + 1ul) {}
    circular_queue_with_hole(size_t capacity, size_t n) : base_type(capacity + 1ul, n) {}
    circular_queue_with_hole(size_t capacity, size_t n, const T& val) : base_type(capacity + 1ul, n, val) {}
    
    bool push_back(const T& x) {
        if (base_type::first_ <= base_type::last_) {
            if (base_type::last_ + 1 < base_type::data_last_) {
                sgl::v1::uninitialized_construct(*base_type::last_, x);
                ++base_type::last_;
                return true;
            }
            if (base_type::data_first_ + 1 < base_type::first_) { // fence
                base_type::last_ = base_type::data_first_; 
                sgl::v1::uninitialized_construct(*base_type::last_, x);
                ++base_type::last_;
                return true;
            }
            return false;
        }
        if (base_type::last_ + 1 < base_type::first_) {
            sgl::v1::uninitialized_construct(*base_type::last_, x);
            ++base_type::last_;
            return true;
        }
        return false;
    }

    bool push_front(const T& x) {
        if (base_type::first_ <= base_type::last_) {
            if (base_type::first_ == base_type::data_first_) {
                if (base_type::data_last_ != base_type::first_ + 1) {
                    base_type::first_ = base_type::data_last_ - 1;
                    sgl::v1::uninitialized_construct(*base_type::first_, x);
                    return true;
                }
                return true;
            } else {
                --base_type::first_;
                sgl::v1::uninitialized_construct(*base_type::first_, x);
                return true;
            }
        }
        if (base_type::last_ + 1 == base_type::first_) {
            return false;
        }
        --base_type::first_;
        sgl::v1::uninitialized_construct(*base_type::first_, x);
        return true;
    }

    void pop_front() {
        sgl::v1::destruct(*base_type::first_);
        ++base_type::first_;
        if (base_type::first_ == base_type::last_) {
            base_type::first_ = base_type::data_first_;
            base_type::last_ = base_type::data_first_;
        } else if (base_type::first_ + 1 == base_type::data_last_) {
            base_type::first_ = base_type::data_first_;
        }
    }


    T& front() {
        return *base_type::first_;
    }

    const T& front() const {
        return *base_type::first_;
    }

    bool empty() const {
        return base_type::first_ == base_type::last_;
    }

    bool full() const {
        return (base_type::last_ + 1 == base_type::data_last_) || (base_type::last_ + 1 == base_type::first_) ;
    }

    size_t size() const {
        if (base_type::last_ < base_type::first_) {
            return (base_type::last_ - base_type::data_first_) + (base_type::data_last_ - base_type::first_);
        } else {
            return base_type::last_ - base_type::first_;
        }
    }

    size_t capacity() const {
        if (base_type::data_first_ == nullptr) { return 0; }
        return base_type::data_last_ - base_type::data_first_ - 1ul;
    }

    void test() {
        circular_queue_with_hole<int> cq(2);
        assert(cq.size() == 0);
        assert(cq.capacity() == 2);
        assert(cq.push_back(1));
        assert(cq.size() == 1);
        assert(cq.push_back(2));
        assert(cq.size() == 2);
        assert(cq.full());
        assert(cq.front() == 1);
        assert(cq.size() == 2);
        assert(!cq.push_back(3));
        cq.pop_front();
        assert(cq.size() == 1);
        assert(cq.front() == 2);
        cq.pop_front();
        assert(cq.empty());
        assert(cq.size() == 0);
        assert(!cq.full());
    }
    void test1() {
        circular_queue_with_hole<int> cq(2);
        assert(cq.size() == 0);
        assert(cq.capacity() == 2);
        assert(cq.empty());
        assert(cq.push_front(1));
        assert(cq.size() == 1);
        assert(cq.front() == 1);
        assert(cq.push_front(2));
    }

};

} // namespace v1
} // namespace sgl
