#pragma once
namespace sgl {
namespace v1 {
struct error_code : std::exception {
    int value;

    error_code() = default;

    error_code(int value) : value(value) {}

    error_code(const error_code&) = default;

    const char* what() const noexcept override {
        return "";
    }

    int message(const char* buffer, size_t n) {
        //strerror_r(value, buffer, n);
        return 0; 
    }
};
} // namespace v1
} // namespace sgl
