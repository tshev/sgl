#pragma once
namespace sgl {
namespace v1 {

template<typename T>
struct identity {
    const T& operator()(const T& x) const { return x; }
    T& operator()(T& x) const { return x; }
};

}
}
