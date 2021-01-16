#pragma once

namespace sgl {
namespace v1 {

template<typename T, typename Cmp>
class ordered_stack_base {
protected:
    Cmp cmp;

    ordered_stack_base(Cmp cmp) : cmp(cmp) {}

    T& min(T& x, T& y) {
        return sgl::v1::min(x, y, cmp);
    }

    const T& min(T& x, T& y) const {
        return sgl::v1::min(x, y, cmp);
    }
};

template<typename T>
class ordered_stack_base<T, sgl::v1::f::less<T>> {
protected:
    ordered_stack_base(sgl::v1::f::less<T> _) {}

    T& min(T& x, T& y) {
        return sgl::v1::min(x, y);
    }

    const T& min(T& x, T& y) const {
        return sgl::v1::min(x, y);
    }
};


template<typename T, typename Cmp = sgl::v1::less<T>> 
class ordered_stack : sgl::v1::ordered_stack_base<T, Cmp> {
    typedef sgl::v1::ordered_stack_base<T, Cmp> base_type;
    sgl::v1::array<std::pair<T, T>> values_;

public:
    template<typename It>
    ordered_stack(It first, It last) {
        insert(first, last);
    }

    template<typename It, typename F>
    ordered_stack(It first, It last, F func) {
        insert(first, last, func);
    }

    ordered_stack(Cmp cmp) : base_type(cmp) {}

    void reserve(size_t n) {
        values_.reserve(n);
    }

    void push_back(const T& value) {
        if (values_.empty()) {
            values.emplace_back(value, value);
        } else {
            values.emplace_back(value, base_type::min(values.back().second, value));
        }
    }

    template<typename It>
    void insert(It first, It last) {
        sgl::v1::for_each(first, last, [this](const T& value) {
            this->push_back(value);
        });
    }

    template<typename It, typename F>
    void insert(It first, It last, F func) {
        sgl::v1::for_each(first, last, [this, &func](const T& value) {
            this->push_back(func(value));
        });
    }

    void pop_back() {
        values_.pop_back();
    }

    T& back() {
        return values_.front().first;
    }

    const T& back() const {
        return values_.front().first;
    }

    const T& min_element() const {
        return values_.back().second;
    }
};

} // namespace v1
} // namespace sgl
