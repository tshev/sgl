namespace sgl {
namespace v1 {

template<typename It>
std::pair<It, It> csv_column(It first, It last) {
    auto fast = first;
    ++fast;

    ++first;
    auto m0 = first;
    if (fast == last) {
        return {first, fast};
    }
    ++fast;
    while (first != last) {
        if (*fast == '"') {
            if (*first == '"') {
                ++first; ++fast;
            } else {
                return {m0, fast};
            }
        } else {
            ++first; ++fast;
        }
    }
    return {m0, last};
}

template<typename It, typename Out>
Out from_csv_string(It first, It last, Out out) {
    if (first == last) { return out; }
    auto m = first;
    ++m;
    if (m == last) {
        *out = *first;
    } else {
        sgl::v1::copy_if(first, last, m, out, [](auto slow, auto fast) {return slow != fast || slow != '"';});
   }
    return out;
}


template<typename It>
It csv_step(It first, It last) {
    first = sgl::v1::find_if(first, last, [](auto x) { return x == ',' || x == '\n'; });
    if (first != last) {
        ++first;
    }
    return first;
}

template<typename... Row>
class csv {
    sgl::v1::mmap<char> data;

public:
    csv(const char* filename) : data(sgl::v1::fmmap<char>(filename)) {}

    struct iterator {
        const char* data;
        const char* last;

        iterator() = default;
        iterator(const char* data, const char* last) : data(data), last(last) {}

        iterator(const iterator&) = default;

        friend
        inline
        bool operator==(const iterator& x, const iterator& y) {
            return x.data == y.data;
        }

        friend
        inline
        bool operator!=(const iterator& x, const iterator& y) {
            return !(x == y);
        }

        std::tuple<Row...> operator*() const {
            const char* current = data;
            std::tuple<Row...> result;
            sgl::v1::for_each_in_tuple(result, [&current, this](auto& value) {
                if constexpr (std::is_same<typename std::decay<decltype(value)>::type, std::string>::value) {
                    if (current != last) {
                        if (*current == '"') {
                            auto range = sgl::v1::csv_column(current, last);
                            sgl::v1::from_csv_string(range.first, range.second, std::back_inserter(value));
                            current = csv_step(range.second, last);
                        } else {
                            auto l = sgl::v1::find_if(current, last, [](auto x) { return x == ',' || x == '\n';});
                            std::copy(current, l, std::back_inserter(value));
                            if (l != last) ++l;
                            current = l;
                        }
                    }
                } else {
                    current = csv_step(sgl::v1::from_string(current, last, &value), last);
                }
            });
            return result;
        }
        iterator& operator++() {
            data = sgl::v1::find(data, last, '\n');
            if (data != last) ++data;
            return *this;
        }
    };

    iterator begin() const {
        return iterator(data.begin(), data.end());
    }

    iterator end() const {
        return iterator(data.end(), data.end());
    }
};

}
}
