#pragma once
// FIXME It does not work yet

/*

Red-black tree class, designed for use in implementing STL
associative containers (set, multiset, map, and multimap). The
insertion and deletion algorithms are based on those in Cormen,
Leiserson, and Rivest, Introduction to Algorithms (MIT Press, 1990),
except that

(1) the header cell is maintained with links not only to the root
but also to the leftmost node of the tree, to enable constant time
begin(), and to the rightmost node of the tree, to enable linear time
performance when used with the generic set algorithms (set_union,
etc.);

(2) when a node being deleted has two children its successor node is
relinked into its place, rather than copied, so that the only
iterators invalidated are those referring to the deleted node.

*/

namespace sgl {
namespace v1 {
template<typename T, typename S>
size_t rb_tree_mem_nodes(size_t n) {
  struct node {
    uint8_t color;
    S root;
    S left;
    S right;
    T v;
  };
  return (n + 2) * sizeof(node) + sizeof(S);
};

template<typename T, typename S>
size_t vector_unsafe_mem(size_t n) {
  return sizeof(T) * n + sizeof(S) * 2; 
}

struct reference_forward {
  template<typename T>
  T& operator()(T& x) {
    return x;
  }

  template<typename T>
  const T& operator()(const T& x) {
    return x;
  }

};

template<typename T, typename S>
std::pair<S, S> rb_tree_mem(size_t n){
  std::pair<S, S> result;
  result.first = sgl::v1::rb_tree_mem_nodes<T, S>(n);
  result.second = sgl::v1::array_view<T, S>(n); 
  return result;
}

template<typename T, typename S, typename C>
struct rb_tree_node {
    typedef C color_type; 
    typedef S size_type;
    typedef T value_type;

    color_type color_field = 0;
    size_type parent_link = 0;
    size_type left_link = 0;
    size_type right_link = 0;
    value_type value_field;
};


template<class Key, class Value, class KeyOfValue, class Compare, class Allocator>
struct rb_tree {
  struct iterator;

  typedef uint8_t color_type;
  typedef typename Allocator::size_type size_type;
  typedef size_type link_type;
  typedef Value value_type;
  typedef Key key_type;
  typedef std::pair<iterator, bool> pair_iterator_bool;
  typedef Compare cmp_type;

  static constexpr color_type black = 0;
  static constexpr color_type red = 1;

  typedef rb_tree_node<Value, size_type, color_type> node_type;

  struct iterator  {
    rb_tree* tree;
    size_type node_id;

    iterator() = default;
    iterator(rb_tree *tree, size_type node_id) : tree(tree), node_id(node_id) { }
    iterator(const iterator& x) : tree(x.tree), node_id(x.node_id) { }

    iterator& operator=(const iterator& x) {
      tree = x.tree;
      node_id = x.node_id;
    }

    friend
    inline
    bool operator==(const iterator& x, const iterator& y) {
      return x.node_id == y.node_id;
    }

    friend
    inline
    bool operator!=(const iterator& x, const iterator& y) {
      return !(x == y);
    }

    friend
    inline
    bool operator<(const iterator& x, const iterator& y) {
      return x.node_id < y.node_id;
    }

    value_type& operator*() {
      return tree->get_node(node_id).value_field;
    }

    const value_type& operator*() const {
      return tree->get_node(node_id).value_field;
    }

    iterator& operator++() {
      size_type right_node_id = tree->right(node_id);

      if (right_node_id != tree->NIL()) {
        node_id = right_node_id;
        for (size_type left_node_id = tree->left(node_id); left_node_id != tree->NIL(); left_node_id = tree->left(node_id)) {
          node_id = left_node_id;
        }
      } else {
        size_type y = tree->parent(node_id);
        while (node_id == tree->right(y)) {
          node_id = y;
          y = tree->parent(y);
        }
        if (tree->right(node_id) != y) { // necessary because of rightmost
          node_id = y;
        }
      }
      return *this;
    }

    iterator operator++(int) {
      iterator tmp = *this;
      ++(*this);
      return tmp;
    }

    iterator& operator--() {
      // check for header
      if (tree->color(node_id) == red && tree->parent(tree->parent(node_id)) == node_id) {
        // return rightmost
        node_id = tree->right(node_id); 
      } else if (tree->left(node_id) != tree->NIL()) {
        size_type y = tree->left(node_id);
        while (tree->right(y) != tree->NIL()) {
          y = tree->right(y);
        }
        node_id = y;
      } else {
        size_type y = tree->parent(node_id);
        while (node_id == tree->left(y)) {
          node_id = y;
          y = tree->parent(y);
        }
        node_id = y;
      }
      return *this;
    }

    iterator operator--(int) {
      iterator tmp = *this;
      --*this;
      return tmp;
    }
  };

  KeyOfValue key_of_value;
  Compare compare;
  Allocator allocator;

  size_type* P_NIL_NODE_ID;
  size_type* p_header_node_id;

  void init() {
    // root is a parent of header

    if (this->node_count() == 0) {
      if (NIL() == 0) {
        color(NIL()) = black;
        parent(NIL()) = 0;
        left(NIL()) = 0;
        right(NIL()) = 0;
      }

      color(header()) = red;
      root() = NIL();
      leftmost() = header();
      rightmost() = header();
    }
  }

  rb_tree() = default;
  rb_tree(KeyOfValue key_of_value, Compare compare, Allocator allocator) :
    key_of_value(key_of_value),
    compare(compare),
    allocator(allocator)
    //P_NIL_NODE_ID(allocator.nil())
    //p_header_node_id(allocator.header())
  { init(); }


  size_type node_count() const {
    return allocator.busy_nodes_count();
  }

  size_type size() const {
        return node_count();
  }

  node_type& root_node() {
    return get_node(root());
  }

  node_type& begin_node() {
    return get_node(begin());
  }

  key_type& key(size_type node_id) {
    return key_of_value(get_node(node_id).value_field);
  }

  color_type& color(size_type x) {
    return get_node(x).color_field;
  }

  size_type& parent(size_type x) {
    return get_node(x).parent_link;
  }

  size_type& left(size_type x) {
    return get_node(x).left_link;
  }

  size_type& right(size_type x) {
    return get_node(x).right_link;
  }

  size_type header() {
    return 1;
  }

  size_type& root() {
    return parent(header());
  }

  size_type& leftmost() {
    return left(header());
  }

  size_type& rightmost() {
    return right(header());
  }

  size_type maximum(size_type x) {
    while (right(x) != NIL()) {
      x = right(x);
    }
    return x;
  }

  size_type minimum(size_type x) {
    while (left(x) != NIL()) {
      x = left(x);
    }
    return x;
  }

  pair_iterator_bool insert(const value_type& v) {
    size_type y = header();
    size_type x = root();

    bool comp = true;

    while (x != NIL()) {
      y = x;
      comp = compare(key_of_value(v), key(x));
      if (comp) {
        x = left(x);
      } else {
        x = right(x);
      }
    }
    iterator j = iterator(this, y);
    if (comp) {
      if (j == begin()) {
        return pair_iterator_bool(insert_intrusive(x, y, v), true);
      } else {
        --j;
      }
    }
    
    if (compare(key(j.node_id), key_of_value(v))) {
      return pair_iterator_bool(insert_intrusive(x, y, v), true);
    }

    return pair_iterator_bool(j, false);
    /*
    // finish it here

    size_t node_id = allocator.allocate_node(sizeof(rb_tree_node));
    allocate_node(node_id).value_field = 3;
    return node_id;
    */
  }

  iterator insert_intrusive(size_type x, size_type y, const value_type& v) {
    size_type z = allocate_node();
    get_node(z).value_field = v;

    if (y == header() || x != NIL() || compare(key_of_value(v), key(y))) {
      left(y) = z;
      if (y == header()) {
        root() = z;
        rightmost() = z;
      } else if (y == leftmost()) {
        leftmost() = z;
      }
    } else {
      right(y) = z;
      if (y == rightmost()) {
        rightmost() = z;
      }
    }

    parent(z) = y;
    left(z) = NIL();
    right(z) = NIL();
    x = z;
    color(x) = red;
    while (x != root() && color(parent(x)) == red) { // assert(color(NIL()) == red)
      if (parent(x) == left(parent(parent(x)))) {
        y = right(parent(parent(x)));
        if (color(y) == red) {
          color(parent(x)) = black;
          color(y) = black;
          color(parent(parent(x))) = red;
          x = parent(parent(x));
        } else {
          if (x == right(parent(x))) {
            x = parent(x);
            rotate_left(x);
          }
          color(parent(x)) = black;
          color(parent(parent(x))) = red;
          rotate_right(parent(parent(x)));
        }
      } else {
        y = left(parent(parent(x)));
        if (color(y) == red) {
          color(parent(x)) = black;
          color(y) = black;
          color(parent(parent(x))) = red;
          x = parent(parent(x));
        } else {
          if (x == left(parent(x))) {
            x = parent(x);
            rotate_right(x);
          }
          color(parent(x)) = black;
          color(parent(parent(x))) = red;
          rotate_left(parent(parent(x)));
        }
      }
    }
    color(root()) = black;
    return iterator(this, z);
  }

  void erase(iterator position) {
    link_type z = position.node_id;
    link_type y = z;
    link_type x;
    if (left(y) == NIL()) {
      x = right(y);
    } else if (right(y) == NIL()) {
      x = left(y);
    } else {
      y = right(y);
      while (left(y) != NIL()) {
        y = left(y);
      }
      x = right(y);
    }
    if (y != z) { // relink y in place of z
      parent(left(z)) = y;
      left(y) = left(z);
      if (y != right(z)) {
        parent(x) = parent(y); // possibly x == NIL
        left(parent(y)) = x;   // y must be a left child
        right(y) = right(z);
        parent(right(z)) = y;
      } else
        parent(x) = y; // needed in case x == NIL
      if (root() == z) {
        root() = y;
      } else if (left(parent(z)) == z) {
        left(parent(z)) = y;
      } else {
        right(parent(z)) = y;
      }
      parent(y) = parent(z);
      std::swap(color(y), color(z));
      y = z;
      // y points to node to be actually deleted
    } else {                 // y == z
      parent(x) = parent(y); // possibly x == NIL
      if (root() == z) {
        root() = x;
      } else if (left(parent(z)) == z) {
        left(parent(z)) = x;
      } else {
        right(parent(z)) = x;
      }
      if (leftmost() == z) {
        if (right(z) == NIL()) { // left(z) must be NIL also
          leftmost() = parent(z);
          // makes leftmost() == header if z == root()
        } else {
          leftmost() = minimum(x);
        }
      }
      if (rightmost() == z) {
        if (left(z) == NIL()) { // right(z) must be NIL also
          rightmost() = parent(z);
          // makes rightmost() == header if z == root()
        } else { // x == left(z)
          rightmost() = maximum(x);
        }
      }
    }

    if (color(y) != red) {
      while (x != root() && color(x) == black)
        if (x == left(parent(x))) {
          link_type w = right(parent(x));
          if (color(w) == red) {
            color(w) = black;
            color(parent(x)) = red;
            rotate_left(parent(x));
            w = right(parent(x));
          }
          if (color(left(w)) == black && color(right(w)) == black) {
            color(w) = red;
            x = parent(x);
          } else {
            if (color(right(w)) == black) {
              color(left(w)) = black;
              color(w) = red;
              rotate_right(w);
              w = right(parent(x));
            }
            color(w) = color(parent(x));
            color(parent(x)) = black;
            color(right(w)) = black;
            rotate_left(parent(x));
            break;
          }
        } else { // same as then clause with "right" and "left" exchanged
          link_type w = left(parent(x));
          if (color(w) == red) {
            color(w) = black;
            color(parent(x)) = red;
            rotate_right(parent(x));
            w = left(parent(x));
          }
          if (color(right(w)) == black && color(left(w)) == black) {
            color(w) = red;
            x = parent(x);
          } else {
            if (color(left(w)) == black) {
              color(right(w)) = black;
              color(w) = red;
              rotate_left(w);
              w = left(parent(x));
            }
            color(w) = color(parent(x));
            color(parent(x)) = black;
            color(left(w)) = black;
            rotate_right(parent(x));
            break;
          }
        }
      color(x) = black;
    }
    allocator.deallocate_node(y, sizeof(node_type));
  }

  void __erase(size_type x) {
    while (x != NIL()) {
      __erase(right(x));
      link_type y = left(x);
      allocator.deallocate_node(x, sizeof(node_type));
      x = y;
    }
  }

  void rotate_left(size_type x) {
    link_type y = right(x);
    right(x) = left(y);
    if (left(y) != NIL()) {
      parent(left(y)) = x;
    }
    parent(y) = parent(x);
    if (x == root()) {
      root() = y;
    } else if (x == left(parent(x))) {
      left(parent(x)) = y;
    } else {
      right(parent(x)) = y;
    }
    left(y) = x;
    parent(x) = y;
  }

  void rotate_right(size_type x) {
    link_type y = left(x);
    left(x) = right(y);
    if (right(y) != NIL()) {
      parent(right(y)) = x;
    }
    parent(y) = parent(x);
    if (x == root()) {
      root() = y;
    } else if (x == right(parent(x))) {
      right(parent(x)) = y;
    } else {
      left(parent(x)) = y;
    }
    right(y) = x;
    parent(x) = y;
  }

  node_type& get_node(size_type i) {
    return reinterpret_cast<node_type*>(allocator.nodes())[i];
  }

  iterator begin() {
    return iterator(this, leftmost());
  }

  iterator end() {
    return iterator(this, header());
  }

  size_type allocate_node() {
    size_type node_id = allocator.allocate_node(sizeof(node_type));
    // if (node_id == 0 || node_id == 1) { std::runtime_error("invalid allocator\n"); }
    return node_id;
  }

  iterator extremum() {
    return iterator(this, leftmost());
  }

  size_type NIL() {
    return 0;
  }
};
} // namespace v1
} // namespace sgl
