#include <type_traits>
#include <string>
#include <cassert>
#include <sgl/macros.h>
#include <sgl/sgl.v1.function.iota.h>
#include <sgl/sgl.v1.function.squash_subgroups_back.h>
#include <sgl/sgl.v1.function.soundex_squash.h>
#include <sgl/sgl.v1.function.soundex.h>

namespace sgl {
namespace v1 {
namespace test {
namespace function_soundex_squash {

void test() {
    std::string phrase0 = "Robert";
    std::string phrase1 = "Rubirt";
    auto m0 = sgl::v1::soundex_squash(phrase0.begin(), phrase0.end());
    auto m1 = sgl::v1::soundex_squash(phrase1.begin(), phrase1.end());
    phrase0.resize(m0 - phrase0.begin());
    phrase1.resize(m1 - phrase1.begin());
    assert(phrase0 == phrase1);
}

}
}
}
}

int main() {
    sgl::v1::test::function_soundex_squash::test();
}
