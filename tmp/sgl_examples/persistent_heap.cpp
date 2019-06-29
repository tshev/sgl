#include <sgl/sgl.h>
#include <iostream>
namespace scl {

template<typename T>
struct disk_allocator {
  disk_allocator(const char* path) {
    int path_access = access(path, 0);
    int error = errno;

    if (path_access == 0) {
      sgl::file_descriptor metadata(path);
    } else {
    }
  }
};

template<typename T, typename A = disk_allocator<T>>
struct persistent_heap {
  struct free_heap {

  };

  typedef A allocator_type;
  std::vector<T*> heaps;
  allocator_type allocator;

  persistent_heap(const char* path) : allocator(path) {}

  void push(const T& x) {
    auto first = std::begin(heaps);
    auto last = std::end(heaps);
    auto position = std::find_if(first, last, free_heap{});
    if (position == last) {
      if (first == last) {
        storage_block = allocator.allocate();
      } else  {
        starage_block = allocator.allocate(first, last);
      }
    }
  }

  template<typename ForwardIterator>
  ForwardIterator partial_sort_n(ForwardIterator first, size_t n) {

  }
};

struct persistent_auction {
  sgl::persistent_hash<sgl::persitent_string, sgl::disk_allocator> current_bids;
  sgl::persistent_hash<sgl::persitent_string, sgl::disk_allocator> waiting_list;

  rt_auction(const char* storage);

  template<typename ForwardIterator>
  void find(const char* ) {}
};

struct rta {
  persistent_auction auction;
  std::unordered_map<std::string, std::pair<size, std::vectir<bid>>> bids_cache;
  std::vector<T>

};

} // namespace scl
int main() {
  const char* persistent_heap_metadata = "/tmp/metadata";
  auto first_hash = std::begin(data);
  auto last_hash = std::end(data);
  auto position_hash= data.find("trending");
  if (position_hash)

  typedef int bid_type;
  scl::persistent_heap<bid_type> persistent_heap(persistent_heap_metadata);
  std::vector<bid_type> winners(10);
  auto first = std::begin(winners);
  auto last = persitent_heap.partial_sort_n(first, winners.size());

  sgl::file_descriptor fd("tmp", sgl::io::creat, 0600);
  fd.truncate(1000);
}
