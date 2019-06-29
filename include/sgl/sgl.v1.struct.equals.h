#pragma once
namespace sgl {
namespace v1 {

template<typename T>
struct equals {
    bool operator()(const T& x, const T& y) const {
        return x == y;
    }
};

}
}
