#include <iostream>
#include <vector>

template<typename K, typename V>
struct hash_table {
  void* data_;

  hash_table(void* data) : data_(data) {}

  uint64_t& capacity() {
    return *static_cast<uint64_t*>(data_);
  }

  const uint64_t& capacity() const {
    return *static_cast<const uint64_t*>(data_);
  }

  uint64_t& size() {
    return *(static_cast<uint64_t*>(data_) + 1);
  }

  const uint64_t& size() const {
    return *(static_cast<const uint64_t*>(data_) + 1);
  }

  uint64_t* table() {
    return *(static_cast<uint64_t*>(data_) + 1);
  }

  const uint64_t* table() const {
    return *(static_cast<const uint64_t*>(data_) + 1);
  }

  void hash(const K& x) {

  }

  node_type& node(uint64_t i) {

  }

  const node_type& node(uint64_t i) const {

  }

  uint64_t emplace_new(const K& key, const V& value) {

  }

  void emplace(const K& key, const V& value, uint64_t hash_value_mod) {
    // assert(hash(key) % size() == h)
    uint64_t* ht = table();
    uint64_t& cell_id = ht[hash_value_mod];
    if (cell_id == 0) {
      cell_id = emplace_new(key, value);
      return;
    }

    while (true) {
      const node_type& node_value = node(cell_id);
      if (node_value.key == key) {
        node_value.value = value;
        return;
      }
      cell_id = node_value.next;
      if (cell_id == 0) {
        node_value.next = emplace_new(key, value);
        return;
      }
    }

    if (x.key == key) {
      x.value = value;
      return;
    }
  }
};

template<typename T>
struct pp {
  typedef uint64_t pointer_diff;

  uint8_t* base;
  pointer_diff offset;
  
  pp() = default;
  pp(uint8_t* base, pointer_diff offset) : base(base), offset(offset) {}
  pp(const pp& x) : base(x.base), offset(x.offset) {}

  pp& operator=(const pp& x) {
    base = x.base;
    offset = x.offset;
  }

  friend
  inline
  bool operator==(const pp& x, const pp& y) {
    return x.addressof() == y.addressof();
  }

  friend
  inline
  bool operator!=(const pp& x, const pp& y) {
    return !(x == y);
  }

  friend
  inline
  bool operator<(const pp& x, const pp& y) {
    return x.addressof() < y.addressof();
  }

  friend
  inline
  bool operator<=(const pp& x, const pp& y) {
    return !(y < x);
  }

  friend
  inline
  bool operator>(const pp& x, const pp& y) {
    return y < x;
  }

  friend
  inline
  bool operator>=(const pp& x, const pp& y) {
    return !(x < y);
  }

  T& *operator() {
    return *reinterpret_cast<T*>(base + offset);
  }

  const T& *operator() const {
    return *reinterpret_cast<T*>(base + offset);
  }

  uint8_t* addressof() {
    return base + offset;
  }
};

pointer<uint8_t> global_persistent_storage;

template<typename K, typename V>
struct chained_hash_table {
  std::vector<uint8_t*> chunks;

  chained_hash_table() {

  }

};
int main() {
  auto pp = pload(system_memory);
}
