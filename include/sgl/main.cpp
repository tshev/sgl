#include <memory>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <map>
#include "sgl.h"
#include "sgl.v1.struct.array_view.h"
#include "sgl.v1.class.array_static.h"
#include "sgl.v1.class.rb_tree.h"
#include <iostream>
#include <vector>
namespace sgl {
    using namespace sgl::v1;
};

template<typename T, typename S>
struct array_view_inner_allocator {
    typedef S size_type;
    sgl::v1::array_view<T, S> nodes_;
    sgl::v1::array_view<S, S> freelist_;

    array_view_inner_allocator() = default;

    array_view_inner_allocator(uint8_t* nodes_memory, uint8_t* freelist_memory) : nodes_(nodes_memory), freelist_(freelist_memory) {}

    array_view_inner_allocator(uint8_t* nodes_memory, uint8_t* freelist_memory, size_type capacity_hint) : nodes_(nodes_memory), freelist_(freelist_memory) {
        size_type capacity = freelist_.capacity();
        if (capacity == 0) {
            nodes_.capacity() = capacity_hint;
            nodes_.resize(capacity_hint);

            freelist_.capacity() = capacity_hint;
            freelist_.size() = capacity_hint;
            freelist_.resize(capacity_hint);

            std::iota(freelist_.begin(), freelist_.end(), S(0));
        }
    }

    size_type allocate_node(size_type n) {
        size_type i = freelist_.size();
        if (i <= 2) {
            throw std::runtime_error("allocate_node");
        }
        size_type position = freelist_.back();
        freelist_.pop_back();
        return position;
    }

    void deallocate_node(size_type i, size_type _) {
        freelist_.push_back(i);
    }
  
    T& get_node(size_type i) {
        return nodes_[i];
    }

    const T& get_node(size_type i) const {
        return nodes_[i];
    }

    size_type* size_ptr() {
        return freelist_.size_ptr();
    }

    size_type busy_nodes_count() const {
        return freelist_.capacity() - freelist_.size();
    }

    const size_type* size() const {
        return freelist_.size_ptr();
    }

    size_type* nil() {
        return freelist_.data();
    }

    size_type* header() {
        return freelist_.data() + 1;
    }

    T* nodes() {
        return nodes_.data();
    }
};

typedef sgl::array_static<char, 8> tiny_string;
typedef sgl::array_static<char, 32> middle_string;


int main() {
    size_t internal_memory_size = 1024ul * 1024ul;

    sgl::for_each(sgl::ep::simd(), std::begin(values), std::end(values));

    sgl::mmap<uint8_t> mmap_nodes(sgl::mmap_base::map_anonymous(MAP_SHARED), internal_memory_size); 
    sgl::mmap<uint8_t> mmap_freelist(sgl::mmap_base::map_anonymous(MAP_SHARED), internal_memory_size); 

    typedef middle_string value_type;
    typedef uint64_t size_type;
    typedef uint8_t color_type;
    typedef sgl::rb_tree_node<value_type, size_type, color_type> node;
    typedef array_view_inner_allocator<node, size_type> allocator_type;

    uint64_t rb_tree_max_size = 1000u;
    allocator_type allocator(mmap_nodes.data(), mmap_freelist.data(), rb_tree_max_size);

    typedef value_type key_type;
    typedef sgl::rb_tree<key_type, value_type, sgl::reference_forward, std::less<key_type>, allocator_type> tree_type;

    tree_type tree(sgl::reference_forward{}, std::less<key_type>{}, allocator);

    middle_string x0("abcd");
    tree.insert(x0);

    
    std::cout << tree.size() << std::endl;
}
