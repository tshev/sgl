#pragma once
namespace sgl {
namespace v1 {
#define SGL_OPTIMIZE_QUEUE
template<typename T, typename Allocator = std::allocator<T>>
struct queue_base {
  typedef T value_type;
  typedef Allocator allocator_type;

  typedef size_t size_type;
  typedef size_t difference_type;

  typedef T& reference;
  typedef const T& const_reference;

  typedef value_type* pointer;
  typedef const value_type* const_pointer;

  typedef pointer iterator;
  typedef const_pointer const_iterator;

  // TODO: remove default allocator as a member
  Allocator allocator_;

  pointer data_ = 0;
  pointer data_first_ = 0;
  pointer data_last_ = 0;
  pointer data_end_ = 0;

  queue_base() = default;
  queue_base(size_type n) : data_(allocate(n)), data_first_(data_), data_last_(data_ + n), data_end_(data_last_) {}

  ~queue_base() {
    if (data_ != 0) {
      deallocate(data_, capacity());
    }
  }

  size_type size() const {
    return data_last_ - data_first_;
  }

  size_type capacity() const {
    return data_end_ - data_;
  }

  size_type free_slots() const {
    return data_end_ - data_last_;
  }


  pointer allocate(size_type n) {
    return allocator_.allocate(n);
  }

  void deallocate(pointer data, size_type n) {
    allocator_.deallocate(data, n);
  }

  void destroy(pointer x) {
    allocator_.destroy(x);
  }

  void construct(pointer ptr, const T& x) {
    return allocator_.construct(ptr, x);
  }

  void construct(pointer ptr, T&& x) {
    return allocator_.construct(ptr, std::move(x));
  }
};

template<typename T, typename Allocator = std::allocator<T>, bool value_type_has_destructor = true>
struct queue : public queue_base<T, Allocator> {
  typedef queue_base<T, Allocator> base_type;

  typedef typename base_type::value_type value_type;
  typedef typename base_type::allocator_type allocator_type;

  typedef typename base_type::size_type size_type;
  typedef typename base_type::difference_type difference_type;

  typedef typename base_type::reference reference;
  typedef typename base_type::const_reference const_reference;

  typedef typename base_type::pointer pointer;
  typedef typename base_type::const_pointer const_pointer;

  typedef typename base_type::iterator iterator;
  typedef typename base_type::const_iterator const_iterator;

  static constexpr const size_type capacity_initial = 2;

  queue() = default;

  queue(size_type n) : base_type::queue_base(n) {
    if constexpr_if (value_type_has_destructor) {
        std::uninitialized_fill(begin(), end(), value_type());
    }
  }

  queue(size_type n, const T& value) : base_type::queue_base(n) {
    std::uninitialized_fill(begin(), end(), value);
  }

  template<typename ForwardIterator, typename = typename std::iterator_traits<ForwardIterator>::iterator_category>
  queue(ForwardIterator first, ForwardIterator last) : base_type::queue_base(std::distance(first, last)) {
    std::uninitialized_copy(first, last, begin());
  }

  queue(std::initializer_list<value_type> il) : base_type::queue_base(il.size()) {
    std::uninitialized_copy(il.begin(), il.end(), begin());
    std::copy(il.begin(), il.end(), begin());
  }

  queue(const queue& x) : queue(std::begin(x), std::end(x)) {}

  queue(queue&& x) : base_type::data_(x.data_), base_type::data_first_(x.data_first_), base_type::data_last_(x.data_last_), base_type::data_end_(x.data_end_) {
    x.data_ = 0;
  }

  queue& operator=(const queue& x) {
    // TODO: optimize
    queue tmp(x);
    swap(tmp);
    return *this;
  }

  queue& operator=(queue&& x) {
    base_type::data_ = x.data_;
    base_type::data_first_ = x.data_first_;
    base_type::data_last_ = x.data_last_;
    base_type::data_end_ = x.data_end_;
    x.data_ = 0;
    return *this;
  }

  friend
  inline
  bool operator==(const queue& x, const queue& y) {
    return x.size() == y.size() && sgl::v1::equal_ranges(x.begin(), x.end(), y.begin());
  }

  friend
  inline
  bool operator!=(const queue& x, const queue& y) {
    return !(x == y);
  }

  ~queue() {
    //std::cout << "~queue\n";
    for (auto& x : *this) {
        sgl::v1::destruct(x);
    }
  }

  void swap(queue& y) {
    std::swap(base_type::data_, y.data_);
    std::swap(base_type::data_first_, y.data_first_);
    std::swap(base_type::data_last_, y.data_last_);
    std::swap(base_type::data_end_, y.data_end_);
  }

  void clear() {
    std::for_each(begin(), end(), [](auto &x) { base_type::destory(x); });
    base_type::data_last_ = base_type::data_first_;
  }

  void resize(size_type n) {
    if (base_type::capacity() < n) {
      change_capacity(n);
      sgl::v1::uninitialized_default_construct(end(), begin() + n); 
      base_type::data_last_ = begin() + n;
    } else {
      if constexpr_if (value_type_has_destructor) {
        if (n < base_type::size()) {
          sgl::v1::destruct(begin() + n, end());
        } else {
          sgl::v1::uninitialized_default_construct(end(), begin() + n); 
        }
      }
      base_type::data_last_ = begin() + n;
    }
  }

  void resize(size_type n, const value_type& x) {
    if (base_type::capacity() < n) {
      change_capacity(n);
      std::uninitialized_fill(end(), begin() + n, x);
      base_type::data_last_ = begin() + n;
    } else {
      if constexpr_if (value_type_has_destructor) {
        if (n < base_type::size()) {
            sgl::v1::destruct(begin() + n, end());
        } else {
          std::uninitialized_fill(end(), begin() + n, x);
        }
      } else {
        if (base_type::size() < n) {
          std::uninitialized_fill(end(), begin() + n, x);
        }
      }
      base_type::data_last_ = begin() + n;
    }
  }

  void reserve(size_type n) {
    size_type current_capacity = base_type::capacity();
    if (current_capacity < n) {
      if (current_capacity  == 0) {
        base_type::data_ = base_type::allocate(n);
        base_type::data_first_ = base_type::data_;
        base_type::data_last_ = base_type::data_;
        base_type::data_end_ = base_type::data_ + n;
      } else {
        change_capacity(n);
      }
    }
  }

  value_type& operator[](size_type i) {
    return base_type::data_first_[i];
  }

  const value_type& operator[](size_type i) const {
    return base_type::data_first_[i];
  }

  void push_back(const value_type& x) {
    if (base_type::data_last_ == base_type::data_end_) { // size == capacity
      change_capacity();
    }
    base_type::construct(base_type::data_last_, x);
    ++base_type::data_last_;
  }

  iterator insert(iterator pos, const value_type& x) {
    // TODO RESOLVE: If the objects are not TriviallyCopyable, the behavior of memcpy is not specified and may be undefined. 
    // for memcpy and memmove
    if (base_type::data_last_ == base_type::data_end_) {
        
        const size_type current_size = base_type::size();
        const size_type current_capacity = base_type::capacity();
        if (current_size < (current_capacity >> 1ul)) {
            size_type n = pos - base_type::data_first_;
            //omemmove(static_cast<void*>(base_type::data_), base_type::data_first_, n * sizeof(value_type)); // TODO BIG WARNING: undefined behavior
            sgl::v1::uninitialized_move(begin(), begin() + n, base_type::data_);
            iterator insertion_point = base_type::data_ + n;
            base_type::construct(pos, x);
            //memmove(static_cast<void*>(insertion_point + 1), pos + 1, (base_type::data_last_ - pos) * sizeof(value_type));  // TODO BIG WARNING: undefined behavior
            sgl::v1::uninitialized_move(pos + 1, end(), insertion_point + 1);
            return insertion_point;
        } else {
            const size_type capacity = base_type::capacity();
            const size_type new_capacity = std::max(1ul, capacity + capacity_initial);
            pointer new_data = base_type::allocate(new_capacity);
            try {
                size_type pos_offset = pos - base_type::data_first_;
                uninitialized_copy_range_value_range(base_type::data_first_, pos, base_type::data_last_, x, new_data); // copy constructor of `x` might throw an exception
                base_type::data_ = new_data;
                base_type::data_first_ = new_data;
                base_type::data_last_ = base_type::data_first_ + current_size + 1ul;
                base_type::data_end_ = new_data + new_capacity;
                return base_type::data_first_ + pos_offset;
            } catch(...) {
                // We should not call pos->~T();
                base_type::deallocate(new_data, base_type::capacity());
                throw;
            }
        }
    } else {
      // if (nothrow_move_assignable) { std::copy_backward(pos, end(), end() + 1ul); }
      //memmove(static_cast<void*>(pos + 1), pos, (base_type::data_last_ - pos) * sizeof(value_type));  // TODO BIG WARNING: undefined behavior
      // TODO Possible crazry bug in case of post-invariant
      std::move_backward(pos, end(), end() + 1);
      base_type::construct(pos, x);
      ++base_type::data_last_;
      return pos;
    }
  }

  void erase(iterator first) {
      // repeat myself, but save 1 comparison of iterators
      //iterator last = first + 1ul; 
      base_type::destroy(first);
      // undefined behavior
      //memmove(static_cast<void*>(first), static_cast<void*>(last), (base_type::data_last_ - last) * sizeof(value_type));
      sgl::v1::uninitialized_move(first + 1, end(), first);
      //return pos; // never return what a client knows
  }

  void erase(iterator first, iterator last) {
      std::for_each(first, last, [](value_type& x) {
        base_type::destroy(&x);
      });
      // undefined behavior
      //memmove(static_cast<void*>(first), static_cast<void*>(last), (base_type::data_last_ - last) * sizeof(value_type));
      sgl::v1::uninitialized_move(last, end(), first);
      //return first; // never return what a client knows
  }

  value_type& back() {
    return *(end() - 1ul);
  }

  const value_type& back() const noexcept {
    return *(end() - 1ul);
  }

  value_type& front() noexcept {
    return *begin();
  }

  const value_type& front() const noexcept {
    return *begin();
  }

  void pop_front() noexcept {
    base_type::destroy(&front());
    ++base_type::data_first_;
  }

  void pop_back() noexcept {
    base_type::destroy(&back());
    --base_type::data_last_;
  }

  iterator begin() noexcept {
    return base_type::data_first_;
  }

  iterator end() noexcept {
    return base_type::data_last_;
  }

  const_iterator begin() const noexcept {
    return base_type::data_first_;
  }

  const_iterator end() const noexcept {
    return base_type::data_last_;
  }

  void change_capacity() {
    if (base_type::data_ == base_type::data_end_) { // capacity() == 0
      base_type::data_ = base_type::allocate(capacity_initial);
      base_type::data_first_ = base_type::data_;
      base_type::data_last_ = base_type::data_first_; // don 
      base_type::data_end_ = base_type::data_ + capacity_initial;
    } else {
      size_type current_capacity = base_type::capacity();
      size_type current_size = base_type::size();
      if (current_size < half_non_negative(current_capacity)) {
        shift_data();
      } else {
        change_capacity(current_capacity + current_capacity);
      }
    }
  }

  void shift_data() noexcept(std::is_nothrow_move_assignable<value_type>::value) {
    constexpr bool precondition = std::is_nothrow_move_assignable<value_type>::value;
    if constexpr_if (precondition) {
      base_type::data_last_ = sgl::v1::shift_left(base_type::data_, begin(), end()); // cannot throw
      base_type::data_first_ = base_type::data_;
    } else {
      change_capacity(base_type::size());
    }
  }

  void change_capacity(size_type n) {
    // works because all date members are pointing to the same data
    size_type size = base_type::size();
    pointer data_old = base_type::data_;
    size_type capacity = base_type::capacity();
    //std::cout << base_type::data_ << std::endl;
    base_type::data_ = allocate_and_move(begin(), end(), n); // throws
    base_type::data_first_ = base_type::data_;
    base_type::deallocate(data_old, capacity); // nothrow
    base_type::data_last_ = base_type::data_first_ + size;
    base_type::data_end_ = base_type::data_ + n;
    //std::cout << base_type::data_ << std::endl;
  }

  pointer allocate_and_move(pointer first, pointer last, size_type n) {
    assert(std::distance(first, last) <= n);
    pointer data_new = base_type::allocate(n);
    if (std::is_nothrow_move_assignable<value_type>::value) {
      std::move(first, last, data_new);
      return data_new;
    } else {
      try {
        sgl::v1::uninitialized_move(first, last, data_new);
        return data_new;
      } catch(...) {
        base_type::deallocate(data_new, n);
        throw;
      }
    }
  }
}; // struct queue
} // namespace v1
} // namespace sgl
