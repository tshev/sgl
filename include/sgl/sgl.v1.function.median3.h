#pragma once

namespace sgl {
namespace v1 {

/*
template<typename T>
inline
const T& median3(const T& x, const T& y, const T& z) {
        if (y < x) {
                if (!(z <  x)) return x;
                if (z < y) return y;
                return z;
        }
        if (!(z < y)) return y;
        if (z < x) return x;
        return z;
}

int a[] = {1, 2, 3};
void test(int* a) {
	while (true) {
		int* b[] = {&a[0], &a[1], &a[2]};
		std::stable_sort(&b[0], &b[0] + 3, (auto x, auto y) { return *x < *y; });
		assert(&sgl::v1::median3(a[0], a[1], a[2]) == b[1]);
		if (!std::next_permutation(a[0], a[1], a[2])) break;
	}
}
int b[] = {1, 2, 2};
test(b);
int c[] = {2, 2, 2};
test(c);
*/

template<typename T, typename Pred>
inline
const T& median3(const T& x, const T& y, const T& z, Pred pred) {
        if (pred(y, x)) {
                if (!pred(z,  x)) return x;
                if (pred(z, y)) return y;
                return z;
        }
        if (!pred(z, y)) return y;
        if (pred(z, x)) return x;
        return z;
}


template<typename T>
inline
T& median3(T& x, T& y, T& z) {
        if (y < x) {
                if (!(z <  x)) return x;
                if (z < y) return y;
                return z;
        }
        if (!(z < y)) return y;
        if (z < x) return x;
        return z;
}

template<typename T, typename Pred>
inline
T& median3(T& x, T& y, T& z, Pred pred) {
        if (pred(y, x)) {
                if (!pred(z,  x)) return x;
                if (pred(z, y)) return y;
                return z;
        }
        if (!pred(z, y)) return y;
        if (pred(z, x)) return x;
        return z;
}

} // namespace v1
} // namespace sgl
