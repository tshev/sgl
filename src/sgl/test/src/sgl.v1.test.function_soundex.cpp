#include <type_traits>
#include <sgl/macros.h>
#include <sgl/sgl.v1.function.iota.h>
#include <sgl/sgl.v1.function.squash_subgroups_back.h>
#include <sgl/sgl.v1.function.soundex.h>

int main() {
    std::string phrase0 = "Robert";
    std::string phrase1 = "Rubirt";
    auto m0 = sgl::v1::soundex(phrase0.begin(), phrase0.end());
    auto m1 = sgl::v1::soundex(phrase1.begin(), phrase1.end());
    phrase0.resize(m0 - phrase.begin());
    phrase1.resize(m1 - phrase1.begin());
    assert(phrase0 == phrase1);
}
