#include "sgl.h"
#include "rb_tree.h"
#include "rb_tree_allocator.h"
#include <vector>

struct key_of_value {
  template<typename T>
  T& operator()(T& x) {
    return x;
  }

};


// TODO think about
int main(int argc, char *argv[]) {
  bool read_from_disk = false;
  if (argc > 1) read_from_disk = true;
  if (read_from_disk) {
    std::cout << "Reading from disk...\n";
  } else {
    std::cout << "Inserting to the disk...\n";
  }

  const size_t n = 10;

  typedef int key_t ;
  typedef int value_t; 
  typedef uint32_t size_type;

  constexpr size_t node_size = 4 * std::max(sizeof(value_t), sizeof(size_type)) + sizeof(value_t);

  size_t required_memmory_rb_tree = (n + 2) * node_size + 3 * sizeof(size_type) ;
  sgl::file_descriptor rb_tree_external_memmory_rb_tree("rb_tree_external_memmory_rb_tree.txt", sgl::io::read_write | sgl::io::creat, 0755);
  rb_tree_external_memmory_rb_tree.truncate(required_memmory_rb_tree);
  auto rb_tree_external_memmory_rb_tree_stat = rb_tree_external_memmory_rb_tree.stat();
  sgl::mmap<uint8_t> memmory_rb_tree(rb_tree_external_memmory_rb_tree.raw(), rb_tree_external_memmory_rb_tree_stat.st_size, 0, sgl::mmap_base::prot_rw, sgl::mmap_base::map_shared);


  const size_t required_stack_size = sizeof(size_type) * n + 2 * sizeof(size_type) + 2 * sizeof(value_t);
  sgl::file_descriptor stack_file("stack.txt", sgl::io::read_write | sgl::io::creat, 0755);
  stack_file.truncate(required_stack_size);

  sgl::mmap<uint8_t> memmory_stack(stack_file.raw(), stack_file.stat().st_size, 0, sgl::mmap_base::prot_rw, sgl::mmap_base::map_shared);
  sgl::vector_unsafe<size_type, size_type> free_nodes(memmory_stack.begin());
  if (free_nodes.size() == 0) {
    free_nodes = sgl::vector_unsafe<size_type, size_type>(memmory_stack.begin(), n + 2);
  }
  //std::iota(std::begin(free_nodes), std::end(free_nodes), 0);

  std::cout <<  "Free nodes size: " << free_nodes.size() << std::endl;
  std::cout <<  "Free nodes contents: ";
  for (auto x : free_nodes) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
  

  sgl::rb_tree_allocator<size_type> rb_tree_allocator(memmory_rb_tree.data(), required_memmory_rb_tree, &free_nodes, sizeof(size_type));
  sgl::rb_tree<key_t, value_t, key_of_value, std::less<key_t>, sgl::rb_tree_allocator<size_type>, size_type> rb_tree(key_of_value{}, std::less<key_t>{}, rb_tree_allocator);
  static_assert(sizeof(decltype(rb_tree)::rb_tree_node) == node_size, "Invalid padding");


  std::cout << "Size of rb_tree = " << rb_tree.size() << std::endl;

  if (!read_from_disk) {
    for (value_t i = 1; i != n; ++i) {
      rb_tree.insert(i);
    }
  }
  rb_tree.erase(rb_tree.begin());

  std::cout << "Contents of the rbtree: ";
  for (auto x : rb_tree) {
    std::cout << x << " ";
  }
  std::cout << std::endl;


  std::cout <<  "Free nodes size: " << free_nodes.size() << std::endl;
  std::cout <<  "Free nodes contents: ";
  for (auto x : free_nodes) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
}
