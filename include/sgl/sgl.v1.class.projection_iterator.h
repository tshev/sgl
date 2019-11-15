#pragma once
namespace sgl {
namespace v1 {
template<typename Iterator, typename Projection>
class projection_iterator {
public:
    typedef typename std::iterator_traits<Iterator>::difference_type difference_type;
    typedef typename std::iterator_traits<Iterator>::value_type value_type;
    typedef typename std::iterator_traits<Iterator>::pointer pointer;
    typedef typename std::iterator_traits<Iterator>::reference reference;
    typedef typename std::iterator_traits<Iterator>::iterator_category iterator_category;

private:
    Iterator iterator;

public:
    projection_iterator() = default;
    projection_iterator(const Iterator& iterator) : iterator(iterator) {}
    projection_iterator(const projection_iterator&) = default;

    projection_iterator& operator=(const projection_iterator& x) {
        iterator = x.iterator;
        return *this;
    }

    friend
    inline
    bool operator==(const projection_iterator& x, const projection_iterator& y) {
        return x.iterator == y.iterator;
    }

    friend
    inline
    bool operator!=(const projection_iterator& x, const projection_iterator& y) {
        return !(x == y);
    }

    friend
    inline
    bool operator<(const projection_iterator& x, const projection_iterator& y) {
        return x.iterator < y.iterator;
    }

    friend
    inline
    bool operator<=(const projection_iterator& x, const projection_iterator& y) {
        return !(y < x);
    }

    friend
    inline
    bool operator>(const projection_iterator& x, const projection_iterator& y) {
        return y < x;
    }

    friend
    inline
    bool operator>=(const projection_iterator& x, const projection_iterator& y) {
        return !(x < y);
    }

    const value_type& operator*() const {
        return Projection()(*iterator);
    }

    value_type& operator*() {
        return Projection()(*iterator);
    }

    projection_iterator& operator++() {
        ++iterator;
        return *this;
    }

    projection_iterator operator++(int) {
        projection_iterator tmp(iterator);
        ++iterator;
        return tmp;
    }

    projection_iterator& operator--() {
        --iterator;
        return *this;
    }

    projection_iterator operator--(int) {
        projection_iterator tmp(iterator);
        --iterator;
        return tmp;
    }

    projection_iterator& operator+=(difference_type n) {
        iterator += n;
        return *this;
    }

    projection_iterator& operator-=(difference_type n) {
        iterator -= n;
        return *this;
    }

    friend
    inline
    projection_iterator operator+(const projection_iterator& projection, difference_type n) {
        return projection_iterator(projection.iterator + n);
    }

    friend
    inline
    projection_iterator operator+(difference_type n, const projection_iterator& projection) {
        return projection + n;
    }

    friend
    inline
    projection_iterator operator-(const projection_iterator& projection, difference_type n) {
        return projection.iterator - n;
    }

    friend
    inline
    difference_type operator-(const projection_iterator& x, const projection_iterator& y) {
        return x.iterator - y.iterator;
    }
};

}
}
