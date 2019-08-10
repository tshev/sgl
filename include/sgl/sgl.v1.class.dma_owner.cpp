#pragma once

namespace sgl {
namespace v1 {

template<typename T, typename Allocator>
class dma_owner_base {
protected:
    Allocator allocator;

    T* allocate() {
        return allocator.allocate(1);
    }

    T* allocate_construct(const T& x) {
        T* pval = allocate();
        if (pval != nullptr) {
            try {
                new ((void*)pval) T(x);
            } catch(...) {
                deallocate(pval);
            }
            return pval;
        } else {
            throw std::bad_alloc;
        }
    }

    void deallocate(T* x) {
        allocator.deallocate(x, 1ul);
    }

    void destruct_deallocate(T* x) {
        x->~T();
        deallocate(x);
    }
};

template<typename T, typename A = std::allocator<T>>
class dma_owner : dma_owner_base<T, Allocator> {
    typedef dma_owner_base<T, A> base_type;
    T* value;

public:

    dma_owner(const T& x) : value(dma_owner_base::allocate_construct(x)) {}

    dma_owner(const dma_owner& x) : value(dma_owner_base::allocate_construct(*(x.value))) {}
    
    dma_owner& operator=(const dma_owner& x) {
        delete x.value;
        x.value = dma_owner_base::allocate_construct(*(x.value));
        return *this;
    }

    friend
    inline
    bool operator==(const dma_owner& x, const dma_owner& y) {
        return *(x.value) == *(y.value);
    }

    friend
    inline
    bool operator!=(const dma_owner& x, const dma_owner& y) {
        return !(x == y);
    }

    friend
    inline
    bool operator<(const dma_owner& x, const dma_owner& y) {
        return *(x.value) < *(x.value);
    }

    friend
    inline
    bool operator<=(const dma_owner& x, const dma_owner& y) {
        return !(y < x);
    }

    friend
    inline
    bool operator>(const dma_owner& x, const dma_owner& y) {
        return y < x;
    }

    friend
    inline
    bool operator>=(const dma_owner& x, const dma_owner& y) {
        return !(x < y);
    }

    friend
    inline
    void swap(dma_owner& x, dma_owner& y) {
        std::swap(x.value, y.value);
    }
};
} // namespace v1
} // namespace sgl
