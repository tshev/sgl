#include <vector>
#include <immintrin.h>
#include <xmmintrin.h>
#include <cassert>
#include <iostream>
#include <sgl/sgl.h>
#include <dlfcn.h>


int main() {
    size_t n = 36 * 4; 
    n = 1024ull * 1024ull * 3000ull;
    sgl::v1::stopwatch_nanoseconds sw;
    sgl::v1::array<float> a(n, 0);
    std::cout << sw.stop() << std::endl;
    float val = 3.0f;
    auto first = a.data();
    auto last = first + n;
    std::cout << a[0] << " " << a.back() << std::endl;

    #ifdef RSGL
    {
        std::cout << "sgl::v1::fill\n";
        sgl::v1::stopwatch_nanoseconds sw;
        sgl::v1::fill(first, last, val);
        std::cout << a.back() << std::endl;
        std::cout << sw.stop() << std::endl;
    }
    #endif

    
    #ifdef RSTD
    {
        std::cout << "std::fill\n";
        sgl::v1::stopwatch_nanoseconds sw;
        std::fill(first, last, val);
        std::cout << a.back() << std::endl;
        std::cout << sw.stop() << std::endl;
    }
    #endif
    #ifdef RSGL_SIMD
    {
        std::cout << "std::v1::fill<simd>\n";
        sgl::v1::stopwatch_nanoseconds sw;
        sgl::v1::fill(sgl::v1::simd_tag<false>(), first, last, val);
        std::cout << a.back() << std::endl;
        std::cout << sw.stop() << std::endl;
    }
    #endif
    assert(std::all_of(a.begin(), a.end(), [](auto x) { return x == 3.0f;}));
 
}
