#pragma once

namespace sgl {
namespace v1 {

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
    argparser(int argc, char* argv[]) {
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

    template <typename Parser>
    size_t parse_key_value(const char* str, Parser parse) const {
        return parse_key_value(str, str + std::strlen(str), parse);
    }

    template <typename Parser>
    size_t parse_key_value(const char* first0, const char* last0, Parser parse) const {
        size_t count = 0;
        while (first0 != last0) {
            const_iterator last = sgl::v1::find(first0, last0, ',');

            typedef std::pair<const_iterator, const_iterator> pair_type;

            auto [lb, ub] = sgl::v1::equal_range(
                std::begin(key_value_ranges), std::end(key_value_ranges),
                pair_type(first0, last),
                sgl::v1::lexicographical_comparison<const_iterator, const_iterator>{},
                [](const auto &x) { return x.first; });

            if (lb != std::end(key_value_ranges) && std::equal(sgl::v1::begin(lb->first), sgl::v1::end(lb->first), first0, last)) {
                count += ub - lb;
                parse(sgl::v1::begin(lb->second), sgl::v1::end(lb->second));
            }

            first0 = last;
            if (first0 != last0) {
                ++first0;
            }
        }
        return count;
    }

    template <typename T>
    typename std::enable_if<std::numeric_limits<T>::value && !std::is_same<T, bool>::value, std::pair<T, bool>>::type
    get(const char* str) const {
        T result;
        bool error = false;
        size_t count = parse_key_value(str, [&](auto first, auto last) {
            auto position = sgl::v1::parse_int(first, last, &result);
            error = position != last;
        });
        return {result, count != 1ul || error};
    }

    template <typename T>
    typename std::enable_if<std::is_same<T, std::string_view>::value, std::pair<T, bool>>::type get(const char* str) const {
        T result;
        size_t count = parse_key_value(str, [&](auto first, auto last) {
            static_assert(sizeof(decltype(first)) == sizeof(void*));
            result = std::string_view(first, last - first);
        });
        return {result, count != 1ul};
    }

    template <typename T>
    typename std::enable_if<std::is_same<T, bool>::value, std::pair<T, bool>>::type get(const char* str) const {
        T result;
        bool parsing_ambiguity = false;
        size_t count = parse_key_value(str, [&](auto first, auto last) {
            static_assert(sizeof(decltype(first)) == sizeof(void*));
            std::string_view sv(first, last - first);
            if (first == last || sv == "true" || sv == "True" || (sv.size() == 1ul && *first == '1')) {
                result = true;
            } else if (first != last && (sv == "false" || sv == "False" || (sv.size() == 1ul && *first == '0'))) {
                result = false;
            } else {
                parsing_ambiguity = true;
            }
        });
        return {result, count != 1ul || parsing_ambiguity};
    }

    const std::string& command() const {
        return command_string;
    }

    auto values() const {
        return std::make_pair(std::cbegin(raw_value_ranges), std::cend(raw_value_ranges));
    }
};
} // namespace v1
} // namespace sgl
