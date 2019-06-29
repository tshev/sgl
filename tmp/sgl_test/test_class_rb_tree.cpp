#include "test.h"
#include "sgl.h"
#include "rb_tree.h"
#include "rb_tree_allocator.h"

template<typename V>
struct rb_tree_structure_test {

};

void test_rb_tree() {
  typedef uint32_t size_type;
  typedef uint32_t value_type;
  typedef uint32_t key_type;
  typedef sgl::reference_forward key_of_value_type;
  typedef sgl::rb_tree_allocator<size_type> allocator_type;
  typedef std::less<key_type> cmp_type;

  constexpr const size_type capacity = 50000000;
  const auto rb_tree_mem = sgl::rb_tree_mem<size_type, value_type>(capacity);

  sgl::file_descriptor nodes_file("nodes.txt", sgl::io::read_write | sgl::io::creat , 0755);
  nodes_file.truncate(rb_tree_mem.first);

  sgl::file_descriptor stack_file("stack.txt", sgl::io::read_write | sgl::io::creat , 0755);
  stack_file.truncate(rb_tree_mem.second);

  sgl::mmap<uint8_t> mmap_memory_nodes(nodes_file.raw(), rb_tree_mem.first, 0, sgl::mmap_base::prot_rw, sgl::mmap_base::map_shared);
  sgl::mmap<uint8_t> mmap_memory_stack(stack_file.raw(), rb_tree_mem.second, 0, sgl::mmap_base::prot_rw, sgl::mmap_base::map_shared);

  //std::vector<uint8_t> mmap_memory_nodes(rb_tree_mem.first);
  //std::vector<uint8_t> mmap_memory_stack(rb_tree_mem.second);


  key_of_value_type key_of_value;
  cmp_type cmp;
  allocator_type allocator(mmap_memory_nodes.data(), mmap_memory_stack.data(), capacity);
  allocator.freelist.size() = capacity;
  std::iota(std::begin(allocator.freelist), std::end(allocator.freelist), 2);

  sgl::rb_tree<key_type, value_type, key_of_value_type, cmp_type, allocator_type> rb_tree(key_of_value, cmp, allocator);
  assert(rb_tree.NIL() == 0);
  assert(rb_tree.header() == 1);

  //actual_values.reserve(capacity);

  //std::iota(std::begin(required_values), std::end(required_values), 0);
  for (size_t i = 0; i < capacity; ++i) {
    //actual_values.push_back(x); 
    rb_tree.insert(i);
    // assert(sgl::equal_ranges(std::begin(actual_values), std::end(actual_values), std::begin(rb_tree), std::end(rb_tree)));
  }
}

TESTS(
  REGISTER("rb_tree", test_rb_tree)
)
