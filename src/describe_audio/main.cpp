#include <sgl/sgl.h>
#include <fstream>
#include <filesystem>
#include <sndfile.hh>


struct audio_info {
    uint64_t in_frames = 0;
    uint32_t in_channels = 0;
    uint32_t in_samplerate = 0;
    std::string path;

    audio_info() = default;
    audio_info(const std::string& path) : path(path) {
        if (!std::filesystem::exists(path)) return;
        SndfileHandle infile_handle(path);
        if (!infile_handle || infile_handle.error() != 0 ) {
            return;
        }

        in_frames = infile_handle.frames();
        in_channels = infile_handle.channels();
        in_samplerate = infile_handle.samplerate();
    }

    double length() const {
        return in_frames / in_samplerate;
    }
};

int main(int argc, const char* argv[]) {
    sgl::v1::argparser args(argc, argv);
    auto [input, input_e] = args.get<std::string>("-i,--input");
    auto [output, output_e] = args.get<std::string>("-o,--output");
    auto [concurrency, concurrency_e] = args.get<uint32_t>("-c,--concurrency", 1);
    if (input_e || output_e) {
        std::cerr << "Correct usage: " << argv[0] << " -i input_path -o output_path [-c 1]\n";
        return 1;
    }

    if (!std::filesystem::exists(input)) {
        std::cerr << input << "not exists\n";
        return 1;
    }
    sgl::v1::mmap<char> ifstream(input.data());

    std::vector<std::string> files(std::count(ifstream.begin(), ifstream.end(), '\n'));
    sgl::v1::transform_splits(ifstream.begin(), ifstream.end(), std::begin(files), '\n', sgl::v1::f::construct<std::string>());
    std::vector<std::thread> threads;
    threads.reserve(concurrency);
    std::vector<audio_info> audio_stats(files.size());

    sgl::v1::for_each_chunk(std::begin(files), std::end(files), std::begin(audio_stats), size_t{concurrency}, [&threads](auto first0, auto last0, auto first1) {
        threads.emplace_back([&threads, first0, last0, first1] { std::transform(first0, last0, first1, sgl::v1::f::construct<audio_info>()); });
    });

    for (auto& t : threads) t.join();

    size_t batch_size = 1024 * 48;
    std::string buffer;
    buffer.reserve(batch_size);
    std::ofstream ofstream(output);
    ofstream << "path,frames,channels,samplerate,length\n";
    for (const auto& x : audio_stats) {
        buffer += x.path;
        buffer.push_back(',');

        auto n = sgl::v1::string_representation_length(x.in_frames, uint64_t(10));
        buffer.resize(buffer.size() + n);
        sgl::v1::ubase10(x.in_frames, buffer.end() - n);
        buffer.push_back(',');

        n = sgl::v1::string_representation_length(x.in_channels, uint32_t(10));
        buffer.resize(buffer.size() + n);
        sgl::v1::ubase10(x.in_channels, buffer.end() - n);
        buffer.push_back(',');

        n = sgl::v1::string_representation_length(x.in_samplerate, uint32_t(10));
        buffer.resize(buffer.size() + n);
        sgl::v1::ubase10(x.in_samplerate, buffer.end() - n);
        buffer.push_back(',');

        buffer += std::to_string(double(x.in_frames) / double(x.in_samplerate));
        buffer.push_back('\n');

        if (buffer.size() >= batch_size) {
            ofstream << buffer;
            buffer.clear();
        }
    }
    if (!buffer.empty()) {
        ofstream << buffer;
        buffer.clear();
    }
}
