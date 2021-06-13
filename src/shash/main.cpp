#include <sgl/sgl.h>
#include <cstdio>

int main(int argc, char* argv[]) {
    if (argc != 3) { std::cerr << "BAD ARGS\n"; return 1; }
    std::string_view str(argv[1]);
    uint64_t mod; 
    sgl::v1::parse_uint(argv[2], argv[2] + std::strlen(argv[2]), &mod);
    printf("%lu\n", std::hash<std::string_view>()(str) % mod);
}
