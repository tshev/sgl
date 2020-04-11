#pragma once
namespace sgl {
namespace v1 {

std::optional<uint64_t> parse_storage_capacity(const char* timeout) {
    size_t n = std::strlen(timeout);
    uint64_t v = 0;
    auto last = timeout + n;
    auto e = sgl::v1::parse_uint(timeout, last, &v);
    if (e == timeout) {
        return {};
    }

    if (last == e) {
        return v;
    }

    if (last - e == 1 && *e == 'G') {
        return v * 1024 * 1024 * 1024;
    }

    if (last - e == 1 && *e == 'M') {
        return v * 1024 * 1024;
    }
    return {};
}

}
}
