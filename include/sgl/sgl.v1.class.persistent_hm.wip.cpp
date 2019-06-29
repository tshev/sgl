#include <iostream>
#include <vector>
#include <sgl/sgl.h>
/*
enum { __stl_num_primes = 31 };

static const unsigned long __stl_prime_list[__stl_num_primes] =
{
  53ul,         97ul,         193ul,       389ul,       769ul,
  1543ul,       3079ul,       6151ul,      12289ul,     24593ul,
  49157ul,      98317ul,      196613ul,    393241ul,    786433ul,
  1572869ul,    3145739ul,    6291469ul,   12582917ul,  25165843ul,
  50331653ul,   100663319ul,  201326611ul, 402653189ul, 805306457ul, 
  1610612741ul, 3221225473ul, 4294967291ul, 8745006461ul, 18063486821ul, 31966025369ul,
};
*/
std::vector<sgl::v1::mmap<uint8_t>> __sgl__v1__global_memory_map__;
constexpr uint64_t __sgl__v1__global_memory_map__page_size__ = 4096ul * 1024ul;

void sgl__v1__global_memory_map___extend(const char* filename, size_t length) {
    //sgl::v1::file_descriptor fd(filename);
    // mmap(size_type length, int prot, int flags, int fd)
    // mmap(map_anonymous flags, size_type length = sizeof(T))
    __sgl__v1__global_memory_map__.emplace_back(
        sgl::v1::mmap<uint8_t>(sgl::v1::mmap_base::map_anonymous(MAP_SHARED), length)
   );
}


template<typename T>
struct pp : sgl::v1::totally_ordered<pp<T>> {
    uint64_t value;

    pp() {}
    pp(uint64_t value) : value(value) {}

    pp(const pp& x) : value(x.value) {}

    template<typename U>
    pp(const pp<U>& x) : value(x.value) {}


    pp& operator=(const pp& x) {
        value = x.value;
        return *this;
    }

    friend
    inline
    bool operator==(const pp& x, const pp& y) {
        return x.value == y.value;
    }

    friend
    inline
    bool operator!=(const pp& x, const pp& y) {
        return !(x == y);
    }

    friend
    inline
    bool operator<(const pp& x, const pp& y) {
        return x.value < y.value;
    }

    T& operator*() {
        uint64_t page = value / __sgl__v1__global_memory_map__page_size__;
        uint64_t page_value = value % __sgl__v1__global_memory_map__page_size__; 
        uint8_t* address = static_cast<uint8_t*>(__sgl__v1__global_memory_map__[page].data()) + page_value;
        return *reinterpret_cast<T*>(address);
    }

    const T& operator*() const {
        uint64_t page = value / __sgl__v1__global_memory_map__page_size__;
        uint64_t page_value = value % __sgl__v1__global_memory_map__page_size__; 
        const uint8_t* address = static_cast<const uint8_t*>(__sgl__v1__global_memory_map__[page].data()) + page_value;
        return *reinterpret_cast<const T*>(address);
    }

    pp& operator++() {
        value += sizeof(T);
        return *this;
    }

    pp operator++(int) {
        pp tmp(value);
        ++(*this);
        return tmp;
    }

    pp& operator--() {
        value -= sizeof(T);
        return *this;
    }

    pp operator--(int) {
        pp tmp(value);
        --(*this);
        return tmp;
    }

};

struct memory_layout {
    typedef uint64_t size_type;
    typedef std::pair<size_type, size_type> line_segment_type;
    typedef pp<uint8_t> pointer_type;

    sgl::v1::array_view<line_segment_type, size_type> line_segments_;
    pp<memory_layout> next_;

    memory_layout(uint8_t* memory, size_type length, size_type line_segments_capacity) : line_segments_(memory) {
        size_type data_offset = line_segments_capacity * 2ul * sizeof(size_type) + sizeof(size_type);
        assert(data_offset < length);

        if (line_segments_.capacity() == 0) {
            line_segments_.capacity() = line_segments_capacity;
            line_segments_.emplace_back(data_offset, length);
        }
    }

    pointer_type allocate(size_type n) {
        size_type real_size = n + sizeof(line_segment_type);
        line_segment_type line_segment = pop_segment(real_size);
        if (line_segment.second == 0) {
            return pointer_type(0);
        }
        pp<line_segment_type> segment(line_segment.first);
        *segment = line_segment;
        return pointer_type(line_segment.first + sizeof(line_segment_type));
    }

    void deallocate(pointer_type p) {
        pp<line_segment_type> line_segment_ptr(p.value);
        --line_segment_ptr;
        return push_segement(line_segment_type(*line_segment_ptr));

    }

    line_segment_type pop_segment(size_type length) {
        auto first = std::begin(line_segments_);
        auto last = std::end(line_segments_);

        auto line_segment = std::find_if(first, last, [length](const auto& x) {
            return (x.second - x.first) >= length;
        });
        if (line_segment == last) {
            return {0, 0};
        }
        line_segment->second -= length;
        return {line_segment->second, line_segment->second + length};
    }

    void push_segement(const line_segment_type& x) {
        auto& back = line_segments_.back();
        if (back.second == x.first) {
            back.second = x.second;
            return;
        }
        // TODO
    }
};


template<typename T, typename KeyProjection, typename HashFunction>
class linked_hashtable {
public:
    typedef size_t size_type;

    struct node_type;

    typedef pp<node_type> link_type;



    struct node_type {
        T value;
        link_type next = 0;

        node_type(const T& value) : value(value), next(0) {}
    };


private:
    std::vector<link_type> table_;
    std::allocator<uint8_t> allocator_;

    template<typename U>
    U* allocate(size_t n) {
        return allocator_.allocate(n * sizeof(U));
    }

public:
    linked_hashtable() = default;
    linked_hashtable(size_type n) : table_(n) {}

    size_type capacity() const {
        return table_.size();
    }

    link_type find(link_type node_link, const T& x) {
        while (node_link != 0 && get(node_link).value != x) {
         //   node_link = get(node_link)
        }
        return 0;
    }
    node_type& get(size_t i) {

    }

    void insert(const T& x, size_type hash_value) {
        link_type& bucket = table_[hash_value];
        if (bucket == 0) {
            bucket = this->allocate<node_type>(1ul);
            if (bucket == 0) {
                throw std::bad_alloc();
            }
            construct(bucket, x);
        }
        //sgl::v1::first_predecessor_unguarded(bucket, [](link_type x) { return x != 0;}, [this](link_type x) { return get(x).next; });

        link_type node_link = bucket;
        while (node_link != 0) {
            /*
            if (node->value == x) {
                node.value = x;
            }
            current = node;
            node = node->next;
            */
        }

    }

    void construct(link_type data_ptr, const T& x) {
        
    }

    link_type null() const { return 0; }

};


int main() {
    uint64_t length = 4096ul * 1024ul;
    sgl__v1__global_memory_map___extend("/tmp/storage", length);

    assert(!__sgl__v1__global_memory_map__.empty());

    uint8_t* data = __sgl__v1__global_memory_map__.front().data();
    uint64_t line_segmenets_count = 32ul;

    memory_layout _(data, length, line_segmenets_count); // just for development

    memory_layout layout(data, length, line_segmenets_count);
    for (auto x : layout.line_segments_) { std::cout << x.first << " " << x.second << std::endl; }
    pp<uint64_t> integer_ptr = layout.allocate(sizeof(int64_t));
    *integer_ptr = 64;
    std::cout << integer_ptr.value << std::endl;

    for (auto x : layout.line_segments_) { std::cout << x.first << " " << x.second << std::endl; }
    std::cout << *integer_ptr << std::endl;
    layout.deallocate(integer_ptr);
    for (auto x : layout.line_segments_) { std::cout << x.first << " " << x.second << std::endl; }
}
