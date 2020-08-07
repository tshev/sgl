#pragma once
namespace sgl {
namespace v1 {
namespace f {

template<typename T>
struct greater {
    bool operator()(const T& x, const T& y) const {
        return y < x; 
    }
};

}
}
}
