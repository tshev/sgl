#include <cassert>
#include <sgl/sgl.v1.class.fifo_view.hpp>


namespace sgl {
namespace v1 {
namespace test {
namespace class_fifo_view {
    void test() {
        constexpr uint64_t block_size_size_type_size = 8ul;
        {
            std::vector<char> data(64);
            char* data_repr = &data[0];
            fifo_view<uint64_t> cq(data_repr, data.size());

            auto back0 = fifo_view<uint64_t>::data_offset;
            assert(cq.size() == 0);
            assert(cq.position_first() == back0);
            std::string s = "hi";
            assert(cq.push_back(s.data(), s.size()));
            assert(cq.position_first() == fifo_view<uint64_t>::data_offset);
            assert(cq.size() == 1);

            back0 += s.size() + block_size_size_type_size;
            assert(cq.position_last() == back0);
            s = "good";
            assert(cq.push_back(s.data(), s.size()));
            assert(cq.position_first() == fifo_view<uint64_t>::data_offset);
            assert(cq.size() == 2);
            back0 += s.size() + block_size_size_type_size;
            assert(cq.position_last() == back0);
            assert(!cq.push_back(s.data(), s.size()));
            assert(cq.position_first() == fifo_view<uint64_t>::data_offset);
            assert(cq.size() == 2);
            s = "go";
            assert(cq.push_back(s.data(), s.size()));
            assert(cq.position_first() == fifo_view<uint64_t>::data_offset);
            back0 += s.size() + block_size_size_type_size;
            assert(cq.position_last() == back0);
            assert(cq.size() == 3);

            s.resize(1);
            assert(!cq.push_back(s.data(), s.size()));
            assert(cq.size() == 3);

            auto x0 = cq.pop_front();
            s = std::string_view(x0.first, x0.second);
            assert(s == "hi");
            assert(cq.size() == 2);

            x0 = cq.pop_front();
            s = std::string_view(x0.first, x0.second);
            assert(s == "good");
            assert(cq.size() == 1);
            

            x0 = cq.pop_front();
            s = std::string_view(x0.first, x0.second);
            assert(s == "go");
            assert(cq.size() == 0);

            assert(cq.position_first() == fifo_view<uint64_t>::data_offset);
            //assert(cq.position_first() == cq.storage_size);
            //assert(cq.position_last() == cq.storage_size);
            
            s = "love";
            assert(cq.push_back(s.data(), s.size()));
            assert(cq.size() == 1ul);
            assert(cq.position_last() == fifo_view<uint64_t>::data_offset + sizeof(fifo_view<uint64_t>::size_type) + s.size());
        }

        {
            std::vector<char> data(64);
            char* data_repr = &data[0];
            fifo_view<uint64_t> cq(data_repr, data.size());

            auto back0 = fifo_view<uint64_t>::data_offset;
            assert(cq.size() == 0);
            assert(cq.position_first() == back0);
            std::string s = "hi";
            assert(cq.push_back(s.data(), s.size()));
            assert(cq.position_first() == fifo_view<uint64_t>::data_offset);
            assert(cq.size() == 1);

            back0 += s.size() + block_size_size_type_size;
            assert(cq.position_last() == back0);
            s = "good";
            cq.push_back(s.data(), s.size());
            assert(cq.position_first() == fifo_view<uint64_t>::data_offset);
            assert(cq.size() == 2);
            back0 += s.size() + block_size_size_type_size;
            assert(cq.position_last() == back0);
            assert(!cq.push_back(s.data(), s.size()));
            assert(cq.position_first() == fifo_view<uint64_t>::data_offset);
            assert(cq.size() == 2);
            s = "go";
            assert(cq.push_back(s.data(), s.size()));
            assert(cq.position_first() == fifo_view<uint64_t>::data_offset);
            back0 += s.size() + block_size_size_type_size;
            assert(cq.position_last() == back0);
            assert(cq.size() == 3);

            s.resize(1);
            assert(!cq.push_back(s.data(), s.size()));
            assert(cq.size() == 3);

            auto x0 = cq.pop_front();
            s = std::string_view(x0.first, x0.second);
            assert(s == "hi");
            assert(cq.size() == 2);
            assert(cq.position_first() == fifo_view<uint64_t>::data_offset + sizeof(fifo_view<uint64_t>::size_type) + x0.second);

            assert(cq.push_back(s.data(), s.size()));
            assert(cq.size() == 3);

            x0 = cq.pop_front();
            s = std::string_view(x0.first, x0.second);
            assert(s == "good");
            assert(cq.size() == 2);

            x0 = cq.pop_front();
            s = std::string_view(x0.first, x0.second);
            assert(s == "go");
            assert(cq.size() == 1);

            //assert(cq.position_first() == fifo_view<uint64_t>::data_offset);
            //assert(cq.position_first() == cq.storage_size);

            x0 = cq.front();
            s = std::string_view(x0.first, x0.second);
            assert(cq.size() == 1);
            assert(s == "hi");
            assert(cq.position_last() == fifo_view<uint64_t>::data_offset + sizeof(fifo_view<uint64_t>::size_type) + 2);
        }

        {
            std::vector<char> data(64);
            char* data_repr = &data[0];
            fifo_view<uint64_t> cq(data_repr, data.size());

            std::string s = "hi";
            assert(cq.push_back(s.data(), s.size()));

            s = "hello";
            assert(cq.push_back(s.data(), s.size()));

            auto x0 = cq.pop_front();
            s = std::string_view(x0.first, x0.second);
            assert(s == "hi");

            x0 = cq.pop_front();
            s = std::string_view(x0.first, x0.second);
            assert(s == "hello");
            assert(cq.size() == 0);

            s = "hello123";
            assert(cq.push_back(s.data(), s.size()));
            x0 = cq.pop_front();
            s = std::string_view(x0.first, x0.second);
            assert(s == "hello123");
            assert(cq.size() == 0);
        }
    }
} // namespace class_fifo_view
} // namespace test
} // namespace v1
} // namespace sgl

int main() {
    sgl::v1::test::class_fifo_view::test();
}
