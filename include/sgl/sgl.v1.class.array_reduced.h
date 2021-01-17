#pragma once

namespace sgl {
namespace v1 {

template<typename T, typename Reducer, bool parallel> 
class array_reduced {};

template<typename T, typename Reducer> 
class array_reduced<T, Reducer, false> {
    sgl::v1::array<std::pair<T, T>> values_;
    Reducer reduce_;

public:
    template<typename It>
    array_reduced(It first, It last) {
        insert(first, last);
    }

    template<typename It>
    array_reduced(It first, It last, Reducer reduce) : reduce_(reduce) {
        insert(first, last);
    }

    template<typename It, typename F>
    array_reduced(It first, It last, F func, Reducer reduce) : reduce_(reduce) {
        insert(first, last, func);
    }

    array_reduced(Reducer reduce) : reduce_(reduce) {}

    void reserve(size_t n) {
        values_.reserve(n);
    }

    void push_back(const T& value) {
        if (values_.empty()) {
            values_.emplace_back(value, value);
        } else {
            values_.emplace_back(value, reduce(values_.back().second, value));
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
