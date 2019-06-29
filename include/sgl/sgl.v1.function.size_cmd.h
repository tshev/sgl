#pragma once
namespace sgl {
namespace v1 {

template<typename T>
size_t size_cmd(T argc, char* argv[]) {
    size_t size = 0ul;
    for (T i = 0; i < argc; ++i) {
        auto first = argv[i];
        auto s = *first;
        while (*first && *first != '=') {
            ++first;
            ++size;
        }
        
        if (*first == '=' || s != '-') {
            size += 2ul;
        }

        while (*first) {
            ++first;
            ++size;
        }

        ++size;
    }
    return size;
}

} // namespace sgl
} // namespace sgl
