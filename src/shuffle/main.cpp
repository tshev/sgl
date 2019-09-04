#include <sgl/sgl.h>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    if (argc < 3 || std::strcmp(argv[1], argv[2]) == 0) {
        std::cerr << "invalid input\n";
        if (argc >= 1) {
            std::cerr << "Usage: " << argv[0] << " PATH_TO_IN PATH_TO_OUT" << std::endl;
        }
        return 1;
    }
    auto indata = sgl::v1::fmmap<char>(argv[1]);
    sgl::v1::array<std::string_view> lines(std::count(indata.begin(), indata.end(), '\n'));
    sgl::v1::transform_splits(indata.begin(), indata.end(), lines.begin(), '\n', [](auto first, auto last) {
        return std::string_view(first, last - first);
    });
    std::random_device random_device;
    std::mt19937 mt(random_device());
    std::shuffle(lines.begin(), lines.end(), mt);

    sgl::v1::file_descriptor fd(argv[2], sgl::v1::io::creat | sgl::v1::io::read_write, 0644);
    std::string buffer;
    constexpr size_t block_size = 4096ul * 1024ul;
    buffer.reserve(block_size);
    for (auto line : lines) {
        buffer += line;
        buffer += '\n';
        if (buffer.length() >= block_size) {
            fd.write(buffer.data(), buffer.size());
            buffer.clear();
        }
    }
    if (!buffer.empty()) {
        fd.write(buffer.data(), buffer.size());
    }

}
