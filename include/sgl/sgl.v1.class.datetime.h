#pragma once
namespace sgl {
namespace v1 {

struct day {
    typedef int64_t value_type;
    value_type value;
};
template<typename T>
T get_days(T y, T m, T d) {
    m = (m + T(9)) % T(12);
    y = y - m / T(10);
    return T(365) * y + y / T(4) - y / 100 + y / T(400) + (m * T(306) + T(5)) / T(10) + (d - 1);
}

template<typename T>
sgl::triple<T, T, T> get_y_mi_ddd(T g) {
    T y = (10000 * g + 14780) / 3652425;
    T ddd = g - (365 * y + y / 4 - y / 100 + y / 400);
    if (ddd < 0) {
        y = y - 1;
        ddd = g - (365 * y + y / 4 - y / 100 + y / 400);
    }
    T mi = (100 * ddd + 52) / 3060;
    return {y, mi, ddd};
}

template<typename T>
T get_year(const sgl::triple<T, T, T>& x) {
    return x.first + (x.second + 2) / 12;
}

template<typename T>
T get_month(const sgl::triple<T, T, T>& x) {
    return (x.second + 2) % 12 + 1;
}

template<typename T>
T get_day(const sgl::triple<T, T, T>& x) {
    return x.third - (x.second * 306 + 5) / 10 + 1;
}

struct datetime {
    typedef int64_t value_type;
    value_type timestamp;

    datetime(value_type y, value_type m, value_type d) : timestamp(get_days(y, m, d) * 24 * 3600) {}

    datetime(value_type y, value_type m, value_type d, value_type hours, value_type minutes, value_type seconds) :
        timestamp(get_days(y, m, d) * 24 * 3600 + hours * 3600 + minutes * 60 + seconds) {}

    //datetime(year y, month m, day d) : datetime(y.value, m.value, d.value)  {}

    value_type day() const {
        return sgl::get_day(sgl::get_y_mi_ddd(timestamp / 86400));
    }

    value_type month() const {
        return sgl::get_month(sgl::get_y_mi_ddd(timestamp / 86400));
    }

    value_type year() const {
        return sgl::get_year(sgl::get_y_mi_ddd(timestamp  / 86400));
    }

    value_type hour() const {
        //return timestamp / (day() * 24 * 60);
    }

    friend
    inline
    value_type operator-(const datetime& x, const datetime& y) {
        return x.timestamp - y.timestamp;
    }
};
} // namespace v1
} // namespace sgl
