#pragma once

namespace sgl {
namespace v1 {

template<typename T, typename S = size_t>
class linked_list {
public:
    typedef S size_type;
    typedef S link_type;
    typedef T value_type;
    static constexpr const size_type initial_capacity = 2;
    static constexpr const link_type null_ptr = std::numeric_limits<link_type>::max(); 

private:
    struct node_t {
        link_type left;
        link_type right;
        value_type value;
    };

public:
   typedef sgl::v1::array<node_t, std::allocator<node_t>, true> container_type;

private:
    friend struct iterator_t;

    struct iterator_t {
        typedef std::forward_iterator_tag iterator_category;
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;

        linked_list* object_ptr;
        size_type index;

        iterator_t() = default;

        iterator_t(linked_list* object_ptr, size_type index) noexcept : object_ptr(object_ptr), index(index) {}

        iterator_t(const iterator_t& x) noexcept : object_ptr(x.object_ptr), index(x.index) {}

        iterator_t& operator=(const iterator_t& x) noexcept {
            object_ptr = x.object_ptr;
            index = x.index;
            return *this;
        }

        friend
        inline
        bool operator==(const iterator_t& x, const iterator_t& y) noexcept {
            return x.index == y.index;
        }

        friend
        inline
        bool operator!=(const iterator_t& x, const iterator_t& y) noexcept {
            return !(x == y);
        }

        friend
        inline
        bool operator<(const iterator_t& x, const iterator_t& y) noexcept {
            return x.index < y.index;
        }

        friend
        inline
        bool operator<=(const iterator_t& x, const iterator_t& y) noexcept {
            return !(y < x);
        }

        friend
        inline
        bool operator>(const iterator_t& x, const iterator_t& y) noexcept {
            return y < x;
        }

        friend
        inline
        bool operator>=(const iterator_t& x, const iterator_t& y) noexcept {
            return !(x < y);
        }

        iterator_t& operator++() noexcept {
            index = object_ptr->right(index);
            return *this;
        }

        iterator_t operator++(int) noexcept {
            iterator_t tmp = {object_ptr, index};
            ++(*this);
            return tmp;
        }

        iterator_t& operator--() noexcept {
            if (object_ptr->null() == index) {
                index = object_ptr->data_front;
            } else {
                index = object_ptr->left(index);
            }
            return *this;
        }

        iterator_t operator--(int) noexcept {
            iterator_t tmp = {object_ptr, index};
            --(*this);
            return tmp;
        }

        value_type& operator*() noexcept {
            return object_ptr->node(index).value;
        }

        const value_type& operator*() const noexcept {
            return object_ptr->node(index).value;
        }
    };

    struct linked_list_link_generator {
        link_type i = 0;

        linked_list_link_generator(link_type i) noexcept : i(i) {}
        linked_list_link_generator(const linked_list_link_generator&) = default;

        link_type& operator=(const link_type& x) noexcept {
            i = x.i;
            return *this;
        }

        void operator()(node_t& x) noexcept {
            x.left = i;
            ++i;
            x.right = i + link_type(1);
        }
    };

    struct linked_list_assignment {
        link_type i = 0;
        T* data_ptr;

        linked_list_assignment() = default;
        linked_list_assignment(link_type i, T* data_ptr) noexcept : i(i), data_ptr(data_ptr) {}
        linked_list_assignment(const linked_list_assignment&) = default;

        void operator()(node_t& x) {
            sgl::v1::uninitialized_construct(x.value);
            x.left = i;
            ++i;
            x.right = i + link_type(1);
        }
    };

    struct linked_list_dc {
        link_type i = 0;
        linked_list_dc(link_type i) noexcept : i(i) {}
        linked_list_dc(const linked_list_dc&) = default;

        void operator()(node_t& x) {
            sgl::v1::uninitialized_construct(x.value);
            x.left = i;
            ++i;
            x.right = i + link_type(1);
        }
    };


public:
   typedef iterator_t iterator; 
   typedef const iterator_t const_iterator; 

private:
    container_type data_;

    link_type data_front = null();
    link_type data_back = null();

    link_type freelist_front = null();
    link_type freelist_back = null();

    size_type size_ = 0;

    void resize() {
        // assert: freelist is empty
        if (size_ == data_.size()) {
            if (size_ == size_type(0ul)) {
                data_.resize(initial_capacity); // throws
            } else {
                data_.resize(size_ * size_type(2ul)); // throws
            }
            relink_freelist(size_);
        }
    }

    link_type allocate_node() {
        resize();
        link_type result = freelist_front;
        freelist_front = right(freelist_front);
        if (freelist_front != null())  {
            left(freelist_front) = null();
        }
        return result;
    }

    link_type allocate_node(const value_type& x) {
        link_type j = allocate_node();

        if constexpr (sgl::v1::is_nothrow_semiregular<value_type>::value) {
            sgl::v1::uninitialized_construct(node(j).value, x);
        } else {
            try {
                sgl::v1::uninitialized_construct(node(j).value, x);
            } catch(...) {
                deallocate_node(j);
                throw;
            }
        }
        return j;
    }

    link_type allocate_node(value_type&& x) {
        link_type j = allocate_node();
        if constexpr (std::is_nothrow_move_constructible<value_type>::value) {
            sgl::v1::uninitialized_construct(node(j).value, std::move(x));
        } else {
            try {
                //node(j).value = std::move(x);
                sgl::v1::uninitialized_construct(node(j).value, std::move(x));
            } catch(...) {
                deallocate_node(j);
                throw;
            }
        }
        return j;
    }

    void deallocate_node(link_type x) {
        right(x) = freelist_front;
        left(x) = null();
        freelist_front = x;
    }

    void __insert_after_unguarded__(link_type position, link_type destination) noexcept {
        // x0 <-> x1 <-> x2 <-> ... <-> position <->  next <-> ... <-> null_ptr
        // x0 <-> x1 <-> x2 <-> ... <-> position <-> destination <->  next <-> ... <-> null_ptr

        right(destination) = right(position); // fill with null
        if (right(position) != null()) {
            left(right(position)) = destination;
        }
        left(destination) = position;         // link from right to left
        right(position) = destination;        // link from left to right
        data_back = destination;
    }

    void __insert_after__(link_type position, link_type destination) noexcept {
        if (size_ == 0) {
            data_front = destination;
            data_back = destination;
            left(destination) = null();
            right(destination) = null();
        } else {
            __insert_after_unguarded__(position, destination);
        }
    }


    void __push_back_unguarded__(link_type position, link_type destination) noexcept {
        // x0 <-> x1 <-> x2 <-> ... <-> position <-> null_ptr
        // x0 <-> x1 <-> x2 <-> ... <-> position <-> destination
        // right(destination) = right(position); // fill with null   # Might be faster
        right(destination) = null();        
        left(destination) = position;         // link from right to left
        right(position) = destination;        // link from left to right
        data_back = destination;
    }

    void __push_back__(link_type position, link_type destination) noexcept {
        if (size_ == 0ul) {
            data_front = destination;
            data_back = destination;
            left(destination) = null();
            right(destination) = null();
        } else {
            __push_back_unguarded__(position, destination);
        }
    }

    void __push_front_unguarded__(link_type position, link_type destination) noexcept {
        left(destination) = left(position); // fill with null
        left(position) = destination;
        right(destination) = position;
        data_front = destination;
    }

    void __push_front__(link_type position, link_type destination) noexcept {
        if (size_ == 0ul) {
            data_front = destination;
            data_back = destination;
            left(destination) = null();
            right(destination) = null();
        } else {
            __push_front_unguarded__(position, destination);
        }
    }

    link_type null() {
        return linked_list::null_ptr;
    }

    node_t& node(link_type i) {
        return data_[i];
    }

    const node_t& node(link_type i) const {
        return data_[i];
    }

    link_type& left(link_type i) {
        return node(i).left;
    }

    link_type& right(link_type i) {
        return node(i).right;
    }

public:

    linked_list() : data_front(null()), data_back(null()), freelist_front(null()), freelist_back(null()), size_(0) {}

    linked_list(size_type n) : data_(n), size_(n) {
        if (n == 0) {
            data_back = null();
            data_front = null();
            freelist_front = null();
            freelist_back = null();
            return;
        }


        auto first = data_.begin();
        sgl::v1::uninitialized_construct(first->value);
        ++first;
        std::for_each(first, data_.end(), linked_list_dc(size_type(0ul)));

        data_.front().left = null();

        if (n == size_type(1)) {
            data_.front().right = null();
        } else {
            data_.front().right = size_type(1);
        }
        data_.back().right = null();

        data_front = 0;
        data_back = n - 1;

        freelist_front = n;
        freelist_back = n;
    }

    linked_list(const linked_list& x) = default;
    linked_list(linked_list&& x) = default;

    linked_list& operator=(const linked_list& x) {
        data_ = x.data_;
        data_back = x.data_back;
        data_front = x.data_front;
        freelist_front = x.freelist_front;
        freelist_back = x.freelist_back;
        size_ = x.size_;
        return *this;
    }

    linked_list& operator=(linked_list&& x) {
        data_ = std::move(x.data_);
        data_back = x.data_back;
        data_front = x.data_front;
        freelist_front = x.freelist_front;
        freelist_back = x.freelist_back;
        size_ = x.size_;

        x.data_front = null();
        return *this;
    }

    ~linked_list() {
        for (auto& x : *this) {
            x.~value_type();
        }
     }

    friend
    inline
    bool operator==(const linked_list& x, const linked_list& y) {
        return std::equal(std::begin(x), std::end(x), std::begin(y));
    }

    friend
    inline
    bool operator!=(const linked_list& x, const linked_list& y) {
        return !(x == y);
    }

    T& operator[](size_t i) {
        return data_[i];
    }

    const T& operator[](size_t i) const {
        return data_[i];
    }

    void reserve(size_type n) {
        data_.reserve(n);
    }

    size_type size() const {
        return size_;
    }

    size_type capacity() const {
        return data_.capacity();
    }

    void relink_freelist(link_type offset) {
        // freelist is empty
        auto first = data_.begin() + offset;
        auto last = data_.end();
        ++first;
        std::for_each(first, last, linked_list_link_generator(offset));

        left(offset) = null();
        right(offset) = offset + link_type(1);

        freelist_front = offset;
        freelist_back = data_.size() - size_type(1);

        right(freelist_back) = null();
    }

    void push_back(const value_type& x) {
        size_type new_tail = allocate_node(x);
        __push_back__(data_back, new_tail);
        ++size_;
    }

    void push_back(value_type&& x) {
        size_type new_tail = allocate_node(std::move(x));
        __push_back__(data_back, new_tail);
        ++size_;
    }

    void push_front(const value_type& x) {
        size_type new_tail = allocate_node(x);
        __push_front__(data_front, new_tail);
        ++size_;
    }

    void push_front(value_type&& x) {
        size_type new_tail = allocate_node(std::move(x));
        __push_front__(data_front, new_tail);
        ++size_;
    }

    value_type& front() {
        return node(data_front).value;
    }

    const value_type& front() const {
        return node(data_front).value;
    }

    value_type& back() {
        return node(data_back).value;
    }

    const value_type& back() const {
        return node(data_back).value;
    }

    void insert_after(link_type i, const value_type& x) {
        link_type j = allocate_node(x);
        __insert_after__(i, j);
        ++size_;
    }

    void insert_after(link_type i, value_type&& x) {
        link_type j = allocate_node(std::move(x));
        __insert_after__(i, j);
        ++size_;
    }

    void insert_after(iterator position, const value_type& x) {
        insert_after(position.index, x);
    }

    void insert_after(iterator position, value_type&& x) {
        insert_after(position.index, std::move(x));
    }

    void insert(iterator position, const value_type& x) {
        if (position.index == data_front) {
            push_front(x);
        } else if (position.index == data_back){
            push_back(x);
        } else {
            insert_after(left(position.index), x);
        }
    }

    void insert(iterator position, value_type&& x) {
        if (position.index == data_front) {
            push_front(std::move(x));
        } else if (position.index == data_back){
            push_back(std::move(x));
        } else {
            insert_after(left(position.index), std::move(x));
        }
    }

    template<typename ForwardIterator>
    void insert(iterator position, ForwardIterator first, ForwardIterator last) {
        // TODO
        if (first == last) {
            return;
        }
        link_type data_front_old = data_front;

        size_type start = allocate_node(*first);

        size_type tail = start;
        ++first;

        while (first != last) {
            size_type i = allocate_node(*first);
            __push_back__(tail, i);
            tail = i;
            ++first;
        }

        if (position.index == data_front_old) {
            if (size_ == 0) {
                data_back = tail;
            } else {
                node(data_front_old).left = tail;
                node(tail).right = data_front_old;
            }
            data_front = start;
            return;
        }
        auto l = node(position.index).left;
        node(tail).right = position.index;
        node(position.index).left = tail;
        node(l).right = start;
        node(start).left = l;
    }

    iterator begin() {
        return iterator{this, data_front};
    }

    iterator end() {
        return iterator{this, null()};
    }

    const_iterator begin() const {
        return iterator{this, data_front};
    }

    const_iterator end() const {
        return iterator{this, null()};
    }
}; // class linked_list
} // namespace v1
} // namespace sgl
