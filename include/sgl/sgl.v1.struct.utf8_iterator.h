// this is garbage, don't use it
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

template<typename ForwardIterator>
bool utf8__len_2(ForwardIterator first) {

}

template<typename ForwardIterator>
struct utf8_iterator {
    ForwardIterator iterator;

    utf8_iterator() = default;

    utf8_iterator(ForwardIterator iterator) : iterator(iterator) {}

    utf8_iterator(const utf8_iterator& x) : iterator(x.iterator) {}

    utf8_iterator& operator=(const utf8_iterator& x) {
        iterator = x.iterator;
        return *this;
    }

    friend
    inline
    bool operator==(const utf8_iterator& x, const utf8_iterator& y) {
        return x.iterator == y.iterator;
    }

    friend
    inline
    bool operator!=(const utf8_iterator& x, const utf8_iterator& y) {
        return !(x == y);
    }

    friend
    inline
    bool operator<(const utf8_iterator& x, const utf8_iterator& y) {
        return x.iterator < y.iterator;
    }

    friend
    inline
    bool operator<=(const utf8_iterator& x, const utf8_iterator& y) {
        return !(y < x);
    }

    friend
    inline
    bool operator>(const utf8_iterator& x, const utf8_iterator& y) {
        return y < x;
    }

    friend
    inline
    bool operator>=(const utf8_iterator& x, const utf8_iterator& y) {
        return !(x < y);
    }

    utf8_iterator& operator++() {
       typedef typename std::iterator_traits<ForwardIterator>::value_type T;
       typedef typename std::make_unsigned<T>::type U; 

       U b0 = *iterator;
       ++iterator;
       
       if ((b0 >> 7) == 0) {
         return *this;
       }

       U b1 = *iterator;
       ++iterator;
       if ((b0 >> 5) == 6 && (b1 >> 6) == 2) {
         return *this;
       }
       U b2 = *iterator;
       ++iterator;
       if ((b0 >> 4) == 14 && (b1 >> 6) == 2 && (b2 >> 6) == 2) {
         return *this;
       }
       U b3 = *iterator;
       if ((b0 >> 3) == 30 && (b1 >> 6) == 2 && (b2 >> 6) == 2 && (b3 >> 6) == 2) {
         return *this;
       }
       throw std::runtime_error("bad\n");
    }

    auto operator*() {
        return std::addressof(*iterator);
    }
};


auto begin_utf8(const char* x) {
  return utf8_iterator<const char*>(x);
}


auto begin_utf8(char* x) {
  return utf8_iterator<char*>(x);
}


auto begin_utf8(const std::string& x) {
  return utf8_iterator<std::string::const_iterator>(std::begin(x));
}


auto begin_utf8(std::string& x) {
  return utf8_iterator<std::string::iterator>(std::begin(x));
}


auto end_utf8(const std::string& x) {
  return utf8_iterator<std::string::const_iterator>(std::end(x));
}


auto end_utf8(std::string& x) {
  return utf8_iterator<std::string::iterator>(std::end(x));
}

/*
int main() {
    std::string x = "Привxетx ∮ E⋅da = Q,  n → ∞, ∑ f(i) = ∏ g";
    std::for_each(begin_utf8(x), end_utf8(x), [](auto x) {
        std::cout << x << std::endl;
    });
}
*/
