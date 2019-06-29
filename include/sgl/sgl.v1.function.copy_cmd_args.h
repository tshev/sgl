#pragma once
namespace sgl {
namespace v1 {

template <typename OutputIterator>
OutputIterator copy_cmd_args(int argc, char* argv[], OutputIterator out) {
    for (int i = 0; i < argc; ++i) {
        auto first = argv[i];
        auto last = first + strlen(first);
        auto eq = sgl::v1::find(first, last, '=');
        if (eq == last) {
            if (*first == '-') {
                out = sgl::v1::copy(first, last, out);
            } else {
                *out = '"';
                ++out;
                out = sgl::v1::copy(first, last, out);
                *out = '"';
                ++out;
            }
        } else {
            out = sgl::v1::copy(first, eq, out);
            *out = *eq;
            ++out;
            ++eq;
            *out = '"';
            ++out;
            out = sgl::v1::copy(eq, last, out);
            *out = '"';
            ++out;
        }
        *out = ' ';
        ++out;
    }
    return out;
}


} // namespace sgl
} // namespace sgl
