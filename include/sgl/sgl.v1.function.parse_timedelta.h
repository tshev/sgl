#pragma once
namespace sgl {
namespace v1 {

std::optional<std::chrono::nanoseconds> parse_timedelta(const char* timeout) {
    size_t n = std::strlen(timeout);
    uint64_t v = 0;
    auto last = timeout + n;
    auto e = sgl::v1::parse_uint(timeout, last, &v);
    if (e == timeout) {
        return {};
    }
    if (e == last || (last - e == 1 && *e == 's')) {
        return std::chrono::seconds(v);
    }
    if (last - e == 2 && e[0] == 'n' && e[1] == 's') {
        return std::chrono::nanoseconds(v);
    }
    return {};
}

}
}
