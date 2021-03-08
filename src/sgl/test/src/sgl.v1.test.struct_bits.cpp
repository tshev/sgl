#include <sgl/sgl.h>

namespace sgl {
namespace v1 {
namespace test {
namespace struct_bits {

    void test() {
        constexpr sgl::v1::bits<8> b1({1, 1, 1, 0, 0, 0, 0, 1});
        static_assert(b1.value == uint8_t(135));

        constexpr sgl::v1::bits<8> b2({1});
        static_assert(b2.value == uint8_t(1));

        constexpr sgl::v1::bits<8> b3({1, 1});
        static_assert(b3.value == uint8_t(3));
    }

    void test8() {
        sgl::v1::bits<8> b(0);
        b[0] = 1;
        b[1] = 1;
        b[2] = 1;
        b[7] = 1;
        static_assert(std::is_same<decltype(b)::value_type, uint8_t>::value);
        assert(b == uint8_t(135));
        assert(b[0] == 1);
        assert(b[1] == 1);
        assert(b[2] == 1);
        assert(b[3] == 0);
        assert(b[4] == 0);
        assert(b[5] == 0);
        assert(b[6] == 0);
        assert(b[7] == 1);
    }

    void test16() {
        sgl::v1::bits<16> b(0);
        b[0] = 1;
        b[1] = 1;
        b[2] = 1;
        b[7] = 1;
        static_assert(std::is_same<decltype(b)::value_type, uint16_t>::value);
        assert(b == uint16_t(135));
        assert(b[0] == 1);
        assert(b[1] == 1);
        assert(b[2] == 1);
        assert(b[3] == 0);
        assert(b[4] == 0);
        assert(b[5] == 0);
        assert(b[6] == 0);
        assert(b[7] == 1);
    }

    void test32() {
        sgl::v1::bits<32> b(0);
        b[0] = 1;
        b[1] = 1;
        b[2] = 1;
        b[7] = 1;
        static_assert(std::is_same<decltype(b)::value_type, uint32_t>::value);
        assert(b == uint32_t(135));
        assert(b[0] == 1);
        assert(b[1] == 1);
        assert(b[2] == 1);
        assert(b[3] == 0);
        assert(b[4] == 0);
        assert(b[5] == 0);
        assert(b[6] == 0);
        assert(b[7] == 1);
    }

    void test64() {
        sgl::v1::bits<64> b(0);
        b[0] = 1;
        b[1] = 1;
        b[2] = 1;
        b[7] = 1;
        static_assert(std::is_same<decltype(b)::value_type, uint64_t>::value);
        assert(b == uint64_t(135));
        assert(b[0] == 1);
        assert(b[1] == 1);
        assert(b[2] == 1);
        assert(b[3] == 0);
        assert(b[4] == 0);
        assert(b[5] == 0);
        assert(b[6] == 0);
        assert(b[7] == 1);
    }

} // namespace struct_bits
} // namespace test
} // namespace v1
} // namespace sgl


int main() {
    sgl::v1::test::struct_bits::test8();
    sgl::v1::test::struct_bits::test16();
    sgl::v1::test::struct_bits::test32();
    sgl::v1::test::struct_bits::test64();
}
