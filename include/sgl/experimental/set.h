#pragma once

#include "rb_tree.h"
/*
namespace sgl {

template<class Key, class Compare, typename Allocator>
class set : sgl::totally_ordered<sgl::set<Key, Compare, Allocator>> {
public:
  // typedefs:

  typedef Key key_type;
  typedef Key value_type;
  typedef Compare key_compare;
  typedef Compare value_compare;

public:
  typedef rb_tree<key_type, value_type, ident<value_type, key_type>, key_compare, Allocator> rep_type;
  rep_type t; // red-black tree representing set

public:
  typedef rep_type::const_reference reference;
  typedef rep_type::const_reference const_reference;
  typedef rep_type::const_iterator iterator;
  typedef rep_type::const_iterator const_iterator;
  typedef rep_type::const_reverse_iterator reverse_iterator;
  typedef rep_type::const_reverse_iterator const_reverse_iterator;
  typedef rep_type::size_type size_type;
  typedef rep_type::difference_type difference_type;

  // allocation/deallocation

  set(const Compare& comp = Compare()) : t(comp, false) {}

  set(const value_type* first, const value_type* last, const Compare& comp = Compare()) : t(comp, false) {
    for (const value_type* i = first; i != last; ++i) {
      t.insert(*i);
    }
  }

  set(const sgl::set& x) : t(x.t, false) {}

  sgl::set& operator=(const sgl::set& x) {
    t = x.t;
    return *this;
  }

  friend
  inline
  bool operator=(const sgl::set& x, const sgl::set& y) {
    return x.size() == y.size() && std::equal(x.begin(), x.end(), y.begin());
  }

  friend
  inline
  bool operator!=(const sgl::set& x, const sgl::set& y) {
    return !(x == y);
  }

  friend
  inline
  bool operator<(const set& x, const set& y) {
    return lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
  }

  // accessors:

  key_compare key_comp() const {
    return t.key_comp();
  }

  value_compare value_comp() const {
    return t.key_comp();
  }

  iterator begin() const {
    return t.begin();
  }

  iterator end() const {
    return t.end();
  }

  reverse_iterator rbegin() const {
    return t.rbegin();
  }

  reverse_iterator rend() const {
    return t.rend();
  }

  bool empty() const {
    return t.empty();
  }

  size_type size() const {
    return t.size();
  }

  size_type max_size() const {
    return t.max_size();
  }

  void swap(sgl::set& x) {
    t.swap(x.t);
  }

  // insert/erase
  typedef sgl::pair<iterator, bool> pair_iterator_bool;
  // typedef done to get around compiler bug

  pair_iterator_bool insert(const value_type& x) {
    sgl::pair<rep_type::iterator, bool> p = t.insert(x);
    return sgl::pair<iterator, bool>(p.first, p.second);
  }

  iterator insert(iterator position, const value_type& x) {
    return t.insert((rep_type::iterator&)position, x);
  }

  void insert(const value_type* first, const value_type* last) {
    for (const value_type* i = first; i != last; ++i)
      t.insert(*i);
  }

  void erase(iterator position) {
    t.erase((rep_type::iterator&)position);
  }

  size_type erase(const key_type& x) {
    return t.erase(x);
  }

  void erase(iterator first, iterator last) {
    t.erase((rep_type::iterator&)first, (rep_type::iterator&)last);
  }

  // set operations:

  iterator find(const key_type& x) const {
    return t.find(x);
  }

  size_type count(const key_type& x) const {
    return t.count(x);
  }

  iterator lower_bound(const key_type& x) const {
    return t.lower_bound(x);
  }

  iterator upper_bound(const key_type& x) const {
    return t.upper_bound(x);
  }

  typedef sgl::pair<iterator, iterator> pair_iterator_iterator;
  // typedef done to get around compiler bug
  pair_iterator_iterator equal_range(const key_type& x) const {
    return t.equal_range(x);
  }
};

} // namespace sgl
*/
