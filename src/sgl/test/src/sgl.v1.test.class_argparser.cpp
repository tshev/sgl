#include <sgl/sgl.h>
#include <cassert>
namespace sgl {
namespace v1 {
namespace test {
void test0() {
    sgl::v1::argparser ap("g++ -I path/to/something -flto true");
    auto [v_I, e_I] = ap.get<std::string_view>("-I");
    assert(e_I == false);
    assert(v_I == "path/to/something");
    auto [v_flto, e_flto] = ap.get<bool>("--flto,-flto");
    assert(e_flto == false);
    assert(v_flto == true);
}
} // namespace test
} // namespace v1
} // namespace sgl
int main() {
    sgl::v1::test::test0();
}
