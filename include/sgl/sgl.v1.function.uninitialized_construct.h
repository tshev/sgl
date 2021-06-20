#pragma once
namespace sgl {
namespace v1 {

template<typename T>
void uninitialized_construct(T* first, T* last) {
    auto it = first;
    try {
        while (first != last) {
            sgl::v1::construct(first);        
            ++first;
        }
    } catch(...) {
        while (it != first) {
            sgl::v1::destruct(it);
            ++first;
        }
    }

}


} // namespace v1
} // namespace sgl
