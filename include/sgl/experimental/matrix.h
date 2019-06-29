#pragma once
#include <algorithm>
#include <memory>
#include <vector>

namespace sgl {
namespace la {
template<typename ForwardIterator, typename OutputIterator>
OutputIterator copy_iterators_with_stride(ForwardIterator f, ForwardIterator l, OutputIterator out, size_t rows_n) {
	while (f != l) {
		*out = f;
		++out;
		std::advance(f, rows_n);
	}
	return out;

}

struct matrix_view;

template<typename T>
struct matrix {
	typedef size_t size_type;

	size_type rows_n_;
	size_type cols_n_;

	std::vector<T> data_;
	std::vector<T*> row_pointers_;

  struct iterator2d : sgl::totally_ordered<iterator2d> {
    T* data;
    size_t cols_n;
    size_t stride;

    iterator2d() {}
    iterator2d(T* data, size_t cols_n, size_t stride) : data(data), cols_n(cols_n), stride(stride) {}
    iterator2d(const iterator2d& x) : data(x.data), cols_n(x.cols_n), stride(x.stride) {}

    friend
    inline
    bool operator==(const iterator2d& x, const iterator2d& y) {
      return x.data == y.data;
    }

    friend
    inline
    bool operator!=(const iterator2d& x, const iterator2d& y) {
      return !(x == y);
    }

    friend
    inline
    bool operator<(const iterator2d& x, const iterator2d& y) {
      return x.data < y.data;
    }

    T* begin() {
      return data;
    }

    T* end() {
      return data + cols_n;
    }

    const T* begin() const {
      return data;
    }

    const T* end() const {
      return data + cols_n;
    }

    iterator2d& operator++() {
      data += stride;
      return *this;
    }

    iterator2d& operator--() {
      data -= stride;
      return *this;
    }

    iterator2d& successor0() {
      data += stride;
      return *this;
    }

    iterator2d& successor1() {
      data += 1;
      return *this;
    }
  };

  iterator2d begin2d() {
    return iterator2d(data(), rows_n_, rows_n_);
  }

  iterator2d end2d() {
    return iterator2d(data() + data_.size(), rows_n_, rows_n_);
  }

	matrix() : rows_n_(0), cols_n_(0) {}
	matrix(size_type rows_n, size_type cols_n) : rows_n_(rows_n), cols_n_(cols_n), data_(rows_n * cols_n), row_pointers_(rows_n) {
		T *f1 = &data_[0];
		copy_iterators_with_stride(f1, f1 + data_.size(), std::begin(row_pointers_), cols_n_);
	}

	matrix(size_type rows_n, size_type cols_n, const T& val) : rows_n_(rows_n), cols_n_(cols_n), data_(rows_n * cols_n, val), row_pointers_(rows_n) {
		T *f1 = &data_[0];
		copy_iterators_with_stride(f1, f1 + data_.size(), std::begin(row_pointers_), cols_n_);
	}

	matrix(const matrix &x) : rows_n_(x.rows_n_), cols_n_(x.cols_n_), data_(x.data_), row_pointers_(x.rows_n_) {
		T *f1 = &data_[0];
		copy_iterators_with_stride(f1, f1 + data_.size(), std::begin(row_pointers_), cols_n_);
	}

	matrix(matrix &&x) = default;

	matrix& operator=(const matrix &x) {
		data_ = x.data_;
		row_pointers_ = x.row_pointers_;
		rows_n_ = x.rows_n_;
		cols_n_ = x.col_n_;
		return *this;
	}

	matrix& operator=(matrix &&x) {
		data_ = std::move(x.data_);
		row_pointers_ = std::move(x.row_pointers_);
		rows_n_ = x.rows_n_;
		cols_n_ = x.col_n_;
		return *this;
	}

	friend
	inline
	bool operator==(const matrix &x, const matrix &y) {
		return x.data_ == y.data_ && x.rows_n == y.rows_n;
	}

	friend
	inline
	bool operator!=(const matrix &x, const matrix &y) {
		return !(x == y);
	}

	inline
	T& operator()(size_t i, size_t j) {
		return row_pointers_[i][j];
	}

	inline
	const T& operator()(size_t i, size_t j) const {
		return row_pointers_[i][j];
	}

	friend
	inline
	matrix operator*(const matrix &x, const matrix &y) {
		matrix z(x.rows_n_, y.cols_n_);
		for (size_t i = 0; i != x.rows_n_; ++i) {
			for (size_t j = 0; j != y.cols_n_; ++j) {
				for (size_t k = 0; k != x.cols_n_; ++k) {
					z(i, j) += x(i, k) * y(k, j);
				}
			}
		}
		return z;
	}

  T* data() {
    return data_.data();
  }

  const T* data() const {
    return data_.data();
  }



	auto begin() {
		return std::begin(data_);
	}

	auto begin() const {
		return std::begin(data_);
	}

	auto end() {
		return std::end(data_);
	}

	auto end() const {
		return std::end(data_);
	}

	void assign(size_t rows_start, size_t rows_end, size_t cols_start, size_t cols_end,
			      	const matrix &x, size_t x_rows_start, size_t y_rows_end, size_t x_cols_start, size_t x_cols_end) {
		auto &self = *this;
		size_t i = rows_start;
		size_t i_1 = x_rows_start;
		while (i != rows_end) {
			size_t j = cols_start;
			size_t j_1  = x_cols_start;
			while (j != cols_end) {
				self(i, j) = x(i_1, j_1);
				++j; ++j_1;
			}
			++i; ++i_1;
		}
	}

  friend
  iterator2d multiply(iterator2d first0, iterator2d last0, iterator2d first1, iterator2d last1, iterator2d out) {
    sgl::for_each(first0, last0, [&out, first1](auto iterator) mutable {
      std::inner_product(iterator.begin(), iterator.end(), out);
    });
    return out;
  }

	friend
	inline
	void multiply_shtrassen(const matrix &x, size_t x_rows_start, size_t x_rows_end,
                                           size_t x_cols_start, size_t x_cols_end,
									const matrix &y, size_t y_rows_start, size_t y_rows_end,
                                   size_t y_cols_start, size_t y_cols_end,
									matrix &z, size_t z_rows_start, size_t z_rows_end,
                             size_t z_cols_start, size_t z_cols_end) {
		//
		size_t threshold = 10;
		if (z_rows_end - z_rows_start < threshold || z_cols_end - z_cols_start < threshold) {
			multiply(x, x_rows_start, x_rows_end, x_cols_start, x_cols_end,
									y, y_rows_start, y_rows_end, y_cols_start, y_cols_end,
									z, z_rows_start, z_rows_end, z_cols_start, z_cols_end);

			return;
		}
		matrix p1((x_rows_end - x_rows_start) / 2, (y_cols_end - y_cols_start) / 2);
		//z11
	  multiply_shtrassen(x, x_rows_start, x_rows_start + (x_rows_end - x_rows_start) / 2,
												  x_cols_start, x_cols_start + (x_cols_end - x_cols_start) / 2,
											 y, y_rows_start, y_rows_start + (y_rows_end - y_rows_start) / 2,
												  y_cols_start, y_cols_start + (y_cols_end - y_cols_start) / 2,
											 z, z_rows_start, z_rows_start + (z_rows_end - z_rows_start) / 2,
												  z_cols_start, z_cols_start + (z_cols_end - z_cols_start) / 2);

	  multiply_shtrassen(x, x_rows_start, x_rows_start + (x_rows_end - x_rows_start) / 2,
												  x_cols_start + (x_cols_end - x_cols_start) / 2, x_cols_end,
											 y, y_rows_start + (y_rows_end - y_rows_start) / 2, y_rows_end,
												  y_cols_start, y_cols_start + (y_cols_end - y_cols_start) / 2,
											 z, z_rows_start, z_rows_start + (z_rows_end - z_rows_start) / 2,
												  z_cols_start, z_cols_start + (z_cols_end - z_cols_start) / 2);

		//z12
		multiply_shtrassen(x, x_rows_start, x_rows_start + (x_rows_end - x_rows_start) / 2,
												  x_cols_start, x_cols_start + (x_cols_end - x_cols_start) / 2,
											 y, y_rows_start, y_rows_start + (y_rows_end - y_rows_start) / 2,
												  y_cols_start + (y_cols_end - y_cols_start) / 2, y_cols_end,
											 z, z_rows_start, z_rows_start + (z_rows_end - z_rows_start) / 2,
												  z_cols_start + (z_cols_end - z_cols_start) / 2, z_cols_end);

	  multiply_shtrassen(x, x_rows_start, x_rows_start + (x_rows_end - x_rows_start) / 2,
												  x_cols_start + (x_cols_end - x_cols_start) / 2, x_cols_end,
											 y, y_rows_start + (y_rows_end - y_rows_start) / 2, y_rows_end,
												  y_cols_start + (y_cols_end - y_cols_start) / 2, y_cols_end,
											 z, z_rows_start, z_rows_start + (z_rows_end - z_rows_start) / 2,
												  z_cols_start + (z_cols_end - z_cols_start) / 2, z_cols_end);

		//z21
	  multiply_shtrassen(x, x_rows_start + (x_rows_end - x_rows_start) / 2, x_rows_end,
												  x_cols_start, x_cols_start + (x_cols_end - x_cols_start) / 2,
											 y, y_rows_start, y_rows_start + (y_rows_end - y_rows_start) / 2,
												  y_cols_start, y_cols_start + (y_cols_end - y_cols_start) / 2,
											 z, z_rows_start + (z_rows_end - z_rows_start) / 2, z_rows_end,
												  z_cols_start, z_cols_start + (z_cols_end - z_cols_start) / 2);


	  multiply_shtrassen(x, x_rows_start + (x_rows_end - x_rows_start) / 2, x_rows_end,
												  x_cols_start + (x_cols_end - x_cols_start) / 2, x_cols_end,
											 y, y_rows_start + (y_rows_end - y_rows_start) / 2, y_rows_end,
												  y_cols_start, y_cols_start + (y_cols_end - y_cols_start) / 2,
											 z, z_rows_start + (z_rows_end - z_rows_start) / 2, z_rows_end,
												  z_cols_start, z_cols_start + (z_cols_end - z_cols_start) / 2);

		//z22
	  multiply_shtrassen(x, x_rows_start + (x_rows_end - x_rows_start) / 2, x_rows_end,
												  x_cols_start, x_cols_start + (x_cols_end - x_cols_start) / 2,
											 y, y_rows_start, y_rows_start + (y_rows_end - y_rows_start) / 2,
												  y_cols_start + (y_cols_end - y_cols_start) / 2, y_cols_end,
											 z, z_rows_start + (z_rows_end - z_rows_start) / 2, z_rows_end,
												  z_cols_start, z_cols_start + (z_cols_end - z_cols_start) / 2);


	  multiply_shtrassen(x, x_rows_start + (x_rows_end - x_rows_start) / 2, x_rows_end,
												  x_cols_start + (x_cols_end - x_cols_start) / 2, x_cols_end,
											 y, y_rows_start + (y_rows_end - y_rows_start) / 2, y_rows_end,
												  y_cols_start + (y_cols_end - y_cols_start) / 2, y_cols_end,
											 z, z_rows_start + (z_rows_end - z_rows_start) / 2, z_rows_end,
												  z_cols_start, z_cols_start + (z_cols_end - z_cols_start) / 2);

	}

	friend
	inline
	void multiply(const matrix &x, size_t x_rows_start, size_t x_rows_end, size_t x_cols_start, size_t x_cols_end,
									const matrix &y, size_t y_rows_start, size_t y_rows_end, size_t y_cols_start, size_t y_cols_end,
									matrix &z, size_t z_rows_start, size_t z_rows_end, size_t z_cols_start, size_t z_cols_end) {
		for (size_t i = x_rows_start, i_1 = z_rows_start; i != x_rows_end; ++i, ++i_1) {
			for (size_t j = y_cols_start, j_1 = z_cols_start; j != y_cols_end; ++j, ++j_1) {
				for (size_t k = x_cols_start, k_1=y_rows_start; k != x_cols_end; ++k, ++k_1) {
					z(i_1, j_1) += x(i, k) * y(k_1, j);
				}
			}
		}
	}


	friend
	inline
	matrix multiply(const matrix &x, const matrix &y) {
		matrix z(x.rows_n_, y.cols_n_);
    std::cout << z.rows_n_ << " " << z.cols_n_ << std::endl;
		for (size_t i = 0; i != x.rows_n_; ++i) {
			for (size_t j = 0; j != y.cols_n_; ++j) {
				for (size_t k = 0; k != x.cols_n_; ++k) {
					z(i, j) += x(i, k) * y(k, j);
				}
			}
		}
		return z;
	}

	template<typename Plus, typename Multiply>
	friend
	inline
	matrix multiply(const matrix &x, const matrix &y, Plus plus, Multiply multiply) {
		matrix z(x.rows_n_, y.cols_n_);
		for (size_t i = 0; i != x.rows_n_; ++i) {
			for (size_t j = 0; j != y.cols_n_; ++j) {
				for (size_t k = 0; k != x.cols_n_; ++k) {
					z(i, j) = plus(z(i, j), multiply(x(i, k), y(k, j)));
				}
			}
		}
		return z;
	}
};


}
}
