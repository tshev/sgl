namespace sgl {
namespace v1 {

template<typename T, typename IO>
class async_dense_matrix {
    typedef IO::size_type size_type;
    size_type rows_;
    size_type cols_;

    sgl::v1::matrix<T> cache_;

    std::vector<bool> page_cache_;
    std::vector<bool> page_cache_;

    async_dense_matrix(size_type rows, size_type cols, size_type cache_size, IO io) {

    }


    template<typename It, typename Output>
    Output operator()(It first, It It last, Output output) {
        bool cache_hit = sgl::v1::all(fist, last, [this](auto x) { return prefetch(x); });
        if (cache_hit) {
            sgl::v1::for_each(fist, last, [this, &output](auto row) {
                output = sgl::v1::copy_n(fetch(rows), cols_, output);
            });
        } else {
            async_copy(first, rows, output);
        }
        return output;
    }

    auto aio_return() {

    }
};

}
}

int main() {
    async_dense_matrix am; 
    std::vector<uint64_t> rows;
    sgl::v1::matrix<float> matrix;
    am(rows.begin(), rows.end(), matrix.begin());
 
    
}
