namespace sgl {
namespace v1 {

template<typename... Row>
class csv {
    sgl::v1::mmap<char> data;

public:
    csv(const char* filename) : data(sgl::v1::fmmap<char>(filename)) {}

    struct iterator {
        const char* data;
        iterator() = default;
        iterator(char* data) : data(data) {}
        iterator(const char* data) : data(data) {}

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


        const char* parse(const char* data, int* x) const {
            auto first = data;
            while (*data != '\0' && *data != '\n' && *data != ',') ++data;
            sgl::v1::parse_int(first, data, x);
            ++data;
            return data;
        }

        std::tuple<Row...> operator*() const {
            const char* current = data;
            std::tuple<Row...> result;
            sgl::v1::for_each_in_tuple(result, [&, this](auto& value) {
                current = parse(current, &value);
            });
            return result;            
        }
    
        iterator& operator++() {
            while (*data != '\0' && *data != '\n') {
                ++data;
            }
            ++data;
            return *this;
        }
    };

    iterator begin() const {
        return iterator(data.begin());
    }

    iterator end() const {
        return iterator(data.end());
    }
};

}
}
