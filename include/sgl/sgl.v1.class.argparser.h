#pragma once

namespace sgl {
namespace v1 {

template<typename T>
struct __value_parser__ {
    typedef bool return_type;

    template<typename It, typename U>
    typename std::enable_if<std::numeric_limits<U>::is_integer && !std::is_same<U, bool>::value, bool>::type
    operator()(It first, It last, U* x) {
        auto position = sgl::v1::parse_int(first, last, x);
        return position != last;
    }

    template<typename It>
    bool operator()(It first, It last, bool* x) {
        bool error = false;
        static_assert(sizeof(decltype(first)) == sizeof(void*));
        std::string_view sv(first, last - first);
        if (first == last || sv == "true" || sv == "True" || (sv.size() == 1ul && *first == '1')) {
            *x = true;
        } else if (first != last && (sv == "false" || sv == "False" || (sv.size() == 1ul && *first == '0'))) {
            *x = false;
        } else {
           error = true;
        }

        return error;
    }

    template <typename It>
    bool operator()(It f, It l, std::string_view* x) {
        *x= std::string_view(f, l - f);
        return false;
    }

    template <typename It>
    bool operator()(It f, It l, std::string* x) {
        *x= std::string(f, l - f);
        return false;
    }

};


class argparser {
  public:
    typedef char* iterator;
    typedef const char* const_iterator;

    typedef std::pair<const_iterator, const_iterator> key_type;
    typedef std::pair<const_iterator, const_iterator> value_type;
    typedef std::pair<key_type, value_type> key_value_type;

  private:
    std::string command_string;
    std::vector<value_type> raw_value_ranges;
    std::vector<key_value_type> key_value_ranges;

  public:
    argparser(int argc, const char* argv[]) {
        size_t n = sgl::v1::size_cmd(argc, argv);
        command_string.resize(n);
        sgl::v1::copy_cmd_args(argc, argv, std::begin(command_string));
        parse();
    }

    template <typename ForwardIterator>
    argparser(ForwardIterator first, ForwardIterator last) : command_string(first, last) {
        parse();
    }

    argparser(std::string expression) : command_string(std::move(expression)) {
        parse();
    }

    argparser& operator=(const argparser& x) {
        command_string = x.command_string;
        auto xf0 = x.command_string.data();
        auto first_cs = command_string.data();

        for (const auto& pair : raw_value_ranges) {
            raw_value_ranges.emplace_back(first_cs + (pair.first - xf0), first_cs +  (pair.second - xf0));
        }

        for (const auto& pop : key_value_ranges) {
            const auto& a = pop.first;
            const auto& b = pop.second;
            key_value_ranges.emplace_back(
                std::make_pair(first_cs + (a.first - xf0), first_cs + (a.second - xf0)),
                std::make_pair(first_cs + (b.first - xf0), first_cs + (b.second - xf0))
            );
        }

        return *this;
    }

    friend
    inline
    bool operator==(const argparser& x, const argparser& y) {
        return x.command_string == y.command_string;
    }

    friend
    inline
    bool operator!=(const argparser& x, const argparser& y) {
        return !(x == y);
    }

    friend
    inline
    bool operator<(const argparser& x, const argparser& y) {
        return x.command_string < y.command_string;
    }

    iterator begin() {
        return command_string.data();
    }

    const_iterator begin() const {
        return command_string.data();
    }

    iterator end() {
        return begin() + command_string.size();
    }

    const_iterator end() const {
        return begin() + command_string.size();
    }

    void parse() {
        sgl::v1::parse_program_options(begin(), end(), std::back_inserter(raw_value_ranges),
                                       std::back_inserter(key_value_ranges));
        std::sort(std::begin(key_value_ranges), std::end(key_value_ranges), [](const auto& x, const auto& y) {
            return std::lexicographical_compare(x.first.first, x.first.second, y.first.first, y.first.second);
        });
    }

    template <typename Parser, typename Iterator>
    auto parse_key_value(const char* str, Parser parse, Iterator it) const {
        return parse_key_value(str, str + std::strlen(str), parse, it);
    }

    template <typename Parser, typename Iterator>
    std::pair<size_t, bool> parse_key_value(const char* first0, const char* last0, Parser parse, Iterator ival) const {
        size_t count = 0;
        bool error = false;
        while (first0 != last0) {
            const_iterator last = sgl::v1::find(first0, last0, ',');

            typedef std::pair<const_iterator, const_iterator> pair_type;

            auto [lb, ub] = sgl::v1::equal_range(
                std::begin(key_value_ranges), std::end(key_value_ranges),
                pair_type(first0, last),
                sgl::v1::lexicographical_comparison<const_iterator, const_iterator>{},
                [](const auto &x) { return x.first; });

            if (lb != std::end(key_value_ranges) && sgl::v1::equal(sgl::v1::begin(lb->first), sgl::v1::end(lb->first), first0, last)) {
                count += ub - lb;
                error |= parse(sgl::v1::begin(lb->second), sgl::v1::end(lb->second), ival);
            }

            first0 = last;
            if (first0 != last0) {
                ++first0;
            }
        }
        return {count, error};
    }

    template <typename T>
    std::pair<T, bool> get(const char* str) const {
        T result;
        auto [count, error] = parse_key_value(str, __value_parser__<T>(), &result); 
        return {result, error};
    }

    template <typename T>
    std::pair<T, bool> get(const char* str, const T& default_value) const {
        T result;
        auto [count, error] = parse_key_value(str, __value_parser__<T>(), &result); 
        if (count == 0) {
            return {default_value, false};
        }
        return {result, error};
    }

    auto values() const {
        return std::make_pair(std::begin(raw_value_ranges), std::end(raw_value_ranges));
    }
};
} // namespace v1
} // namespace sgl
