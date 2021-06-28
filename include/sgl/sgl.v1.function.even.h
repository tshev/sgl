#pragma once
namespace sgl {
namespace v1 {

template<typename N>
inline
bool even(const N& value) {
    return value % 2 == 0;
}

}
}
