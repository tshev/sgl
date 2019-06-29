#include <iostream>
#include <cassert>
#include <numeric>
#include <vector>
#include <unordered_map>


template<typename K, typename V>
class lru_cache {
    struct node_t {
        K value;
        size_t next = 0;
        size_t prev = 0;
    };

    struct iterator {
        typename std::unordered_map<K, std::pair<K, size_t>>::iterator position;
        lru_cache* self;

        iterator() = default;
        iterator(typename std::unordered_map<K, std::pair<K, size_t>>::iterator position, lru_cache* self) : position(position), self(self) {}
        iterator(const iterator& x) : position(x.position), self(x.self) {}

        iterator& operator=(const iterator& x) {
            position = x.position;
            self = x.self;
            return *this;
        }

        friend
        inline
        bool operator==(const iterator& x, const iterator& y) {
            return x.position == y.position;
        }

        friend
        inline
        bool operator!=(const iterator& x, const iterator& y) {
            return !(x == y);
        }

        V& operator*() {
            self->rebalance_linked_list(position->second.second); 
            return position->second.first;
        }

        iterator& operator++() {
            ++position;
            return *this;
        }

        iterator& operator--() {
            --position;
            return *this;
        }

        iterator operator++(int) {
            iterator tmp(*this);
            ++(*this);
            return tmp;
        }

        iterator operator--(int) {
            iterator tmp(*this);
            ++(*this);
            return tmp;
        }
    };

 

    std::unordered_map<K, std::pair<K, size_t>> um;
    std::vector<node_t> linked_list;
    std::vector<size_t> freelist;

    size_t min_i = 0; 
    size_t max_i = 0;

public:

    lru_cache(size_t n) : linked_list(n), um(2ul * n), freelist(n) {
        std::iota(std::begin(freelist), std::end(freelist), size_t(1ul));
    }

    bool insert(const K& key, const V& value) {
        auto last = std::end(um);
        auto position = um.find(key);

        if (position != last) {
            assert(position->second.second != 0);
            rebalance_linked_list(position->second.second);
            position->second.first = value;
            return true;
        }

        size_t i;
        if (freelist.empty()) {
            auto& min_node = get_node(min_i);
            um.erase(min_node.value);

            if (min_node.next != 0) {
                get_node(min_node.next).prev = 0;
            }

            min_node.next = 0;
            min_node.prev = 0;
            i = min_i;
            min_i = min_node.next;    
        } else {
            i = freelist.back();
            freelist.pop_back();
        }

        get_node(max_i).next = i;
        get_node(i).prev = max_i;

        if (min_i == 0) {
            min_i = i;
        }

        um.insert(position, std::make_pair(key, std::make_pair(value, i)));
        get_node(i).value = key;

        max_i = i;
        
        return false;
    }

    node_t& get_node(size_t i) {
        return linked_list[i - 1];
    }

    void rebalance_linked_list(size_t b_i) {
        // a_i <-> b_i <-> c_i <-> d_i <-> max_i  |  b
        // a->next = c; | 
        // c->prev = a; | c->prev = 0
        // b->next = NULL; | b->next = NULL
        // d->next = b; | b->next;
        // a->prev = d;

        node_t& b = get_node(b_i);
        size_t a_i = b.prev;
        size_t c_i = b.next;

        if (a_i == 0) {
            if (c_i != 0) {
                min_i = c_i;
            }
        } else {
            node_t& a = get_node(a_i);
            a.next = c_i;
        }

        if (c_i != 0) {
            node_t& c = get_node(c_i);
            c.prev = a_i;
        }

        if (max_i != 0) {
            node_t& max = get_node(max_i);
            max.next = b_i;
        }

        b.prev = max_i;
        b.next = 0;
        max_i = b_i;
     }

     V* find(const K& key) {
        auto last = std::end(um);
        auto position = um.find(key);
        if (position == last) {
            return NULL;
        } else {
            rebalance_linked_list(position->second.second);
            return &(position->second.first);
        }
     }

    bool contains(const K& key) {
        return find(key) != NULL;
    }

     auto begin() {
        return iterator(std::begin(um), this);
     }

     auto end() {
        return iterator(std::end(um), this);
     }

};


int main() {
    lru_cache<int, int> cache(100);
    cache.insert(0, 100);
    std::cout << "V = " << *cache.find(0) << std::endl;
    assert(!cache.insert(1, 12));
    std::cout << "V = " << *cache.find(1) << std::endl;
    assert(cache.insert(1, 2));
    std::cout << "V = " << *cache.find(1) << std::endl;
    assert(cache.insert(1, 2));
    std::cout << "V = " << *cache.find(1) << std::endl;

    for (auto x : cache) {
        std::cout << "> " << x << std::endl;
    }

}
