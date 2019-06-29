#include <iostream>

struct chained_posting_list0 {
  typedef uint64_t word_t;
  typedef uint64_t index_type;
  typedef uint8_t frequencey_type;

  typedef uint64_t size_type;


  index_type first_document_id;
  index_type last_document_id;
  void* data; 

  chained_posting_list0(void* data) : data(data) {}

  size_type& capacity() {
    return *static_cast<size_type*>(data);
  }

  const size_type& capacity() const {
    return *static_cast<const size_type*>(data);
  }

  size_type& size() {
    return *(static_cast<size_type*>(data) + 1);
  }

  const size_type& size() const {
    return *(static_cast<const size_type*>(data) + 1);
  }

  bool full() const {
    capacity()
    return true;
  }

  constexpr
  bool size_pair() {

  }

  bool try_push_back(const index_type& document_id, const frequencey_type frequency) {
    return false;
  }
};

struct posting_list {

};

int main()  {
  constexpr uint64_t size = 100;
  uint64_t data[size];
  data[0] = size * sizeof(*data);
  data[1] = 0;

  chained_posting_list0 cpl(data);
  std::cout << "capacity: " << cpl.capacity() << std::endl;
  std::cout << "size: " << cpl.size() << std::endl;

}
