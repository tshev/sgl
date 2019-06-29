#pragma once
namespace sgl {
namespace v1 {
template<typename S>
struct rb_tree_allocator {
  typedef S size_type;
  typedef size_type pointer;

  uint8_t* data;

  size_type* nodes_ptr;


  size_type capacity;

  sgl::array_view<size_type, size_type> freelist;

  rb_tree_allocator() = default;
  rb_tree_allocator(uint8_t* data, uint8_t* freelist, size_t capacity) : data(data), freelist(freelist), capacity(capacity) {
    this->freelist.capacity() = capacity;
    nodes_ptr = reinterpret_cast<size_type*>(data + sizeof(size_type));
  }

  rb_tree_allocator(uint8_t* data, sgl::vector_unsafe<size_type, size_type> freelist) : data(data), freelist(freelist), capacity(freelist.capacity()) {}

  size_type* size() {
    return reinterpret_cast<size_type*>(data);
  }

  size_type* header() {
    return reinterpret_cast<size_type*>(data + 2 * sizeof(size_type));
  }

  size_type* nil() {
    return reinterpret_cast<size_type*>(data + 1 * sizeof(size_type));
  }


  size_type* nodes() {
    return nodes_ptr;;
  }

  size_type allocate_node(size_type n) {
    // if (freelist.size() == 0) { throw std::bad_alloc(); }
    size_type node_id = freelist.back();
    freelist.pop_back();
    return node_id;
  }

  void deallocate_node(size_type node_id, size_type n) {
    memset(nodes() + node_id * n, 0, n);
    freelist.push_back(node_id);
  }
}; // struct rb_tree_allocator
} // namesapce v1
} // namesapce sgl
