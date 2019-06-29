#pragma once
namespace sgl {
namespace v1 {
template<typename T>
union union_bytes {
	T value;
	signed uint8_t data[sizeof(T)];
};

template<typename T>
// requires(POD(T))
struct bytes {
	typedef T value_type;

	union_bytes<T> value;

	bytes() = default;

	bytes(const T& x) {
		value.value = x;
	}

	operator T() {
		return value.value;
	}

	bytes(const bytes& x) {
		value.value = x.value;
	}	

	bytes& operator=(const bytes& x) {
		value.value = x.value;
		return *this;
	}

	friend
	inline
	bool operator==(const bytes& x, const bytes& y) {
		return x.value.value == y.value.value;
	}

	friend
	inline
	bool operator!=(const bytes& x, const bytes &y) {
		return !(x == y);
	}

  friend
  inline
  bool operator<(const bytes& x, const bytes& y) {
    return x.value.value < y.value.value;
  }

  friend
  inline
  bool operator<=(const bytes& x, const bytes& y) {
    return !(y < x);
  }

  friend
  inline
  bool operator>(const bytes& x, const bytes& y) {
    return y < x;
  }

  friend
  inline
  bool operator>=(const bytes& x, const bytes& y) {
    return !(x < y);
  }

	template<typename Ostream>
	friend
	inline
	Ostream& operator<<(Ostream& cout, const bytes& x) {
    // TODO: not portable
		for (auto val : x.value.data) {
			cout << val;
		}
		return cout;
	}

	template<typename Istream>
	friend
	inline
	Istream& operator>>(Istream& cin, bytes& x) {
    // TODO: not portable
		for (auto& val : x.value.data) {
			cin >> val;
		}
		return cin;
	}

	~bytes() = default;
};
} // namespace v1
} // namespace sgl
