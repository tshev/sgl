#pragma once
template<typename U>
inline
void* operator new(size_t n, U* pointer) {
    return pointer;
}


