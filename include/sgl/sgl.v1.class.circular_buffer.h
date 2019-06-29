#pragma once
namespace sgl {
namespace v1 {
template<typename T>
/**
 * @brief circular_buffer - fixed size data structure which perform circular push back operation
*/
class circular_buffer {
public:
  typedef size_t size_type;
  typedef T value_type;

private:
  std::vector<T> data_vector;
  size_t size_;
  size_t position_;

public:
  circular_buffer(size_t n) : data_vector(n), size_(0), position_(0) {}

  template<typename Q>
  void push_back(Q &&x) {
    data_vector[position_] = std::forward<Q>(x);
    if (size_ == data_vector.size()) {
      ++position_;
      if (position_ == size_) { position_ = 0; }
    } else {
      ++size_;
      ++position_;
      if (position_ == capacity()) { position_ = 0; }
    }
  }

  void pop_back() {
    --size_;
    if (position_ == 0) {
      position_ = capacity() - 1;
    } else {
      --position_;
    }
  }

  T& back() {
    if (position_ == 0) {
      return data_vector.back();
    } else {
      return data_vector[position_ - 1];
    }
  }

  const T& back() const {
    if (position_ == 0) {
      return data_vector.back();
    } else {
      return data_vector[position_ - 1];
    }
  }

  size_type front_pos() const {
    if (position_ < size_) {
      return capacity() + position_ - size_;
    }
    return position_ - size_;
  }

  T& front() {
    return data_vector[front_pos()];
  }

  const T& front() const {
    return data_vector[front_pos()];
  }

  size_type size() const {
    return size_;
  }

  size_type capacity() const {
    return data_vector.size();
  }

  template<typename Output> 
  friend
  Output& operator<<(Output &cout, circular_buffer &data_vector) {
    for (const auto &x : data_vector.data_vector) { cout << x << " "; }
    return cout;
  }
}; // class circular_buffer
} // namespace v1
} // namespace sgl
