#pragma once

namespace sgl {
namespace v1 {

template<typename It0, typename T, typename It1, typename It2, typename It3, typename It4>
auto volume_bars(It0 first_volumes, It0 last_volumes, const T& threshold, It1 first_prices, It2 out_min, It3 out_max, It4 out_volumes) {
    auto min_price = first_prices;
    auto max_price = first_prices;
    T accum = T(0);
    while (first_volumes != last_volumes) {
        accum += *first_volumes;

        // can be faster, but more tricky
        if (*first_prices < *min_price) {
            min_price = first_prices;
        } else if (*first_prices >= *max_price) {
            max_price = first_prices;
        }

        if (accum >= threshold) {
            *out_volumes = accum;
            ++out_volumes;
            accum = T(0);
            *out_min = *min_price;
            ++out_min;
            *out_max = *max_price;
            ++out_max;

            ++first_volumes;
            ++first_prices;

            min_price = first_prices;
            max_price = first_prices;
        } else {
            ++first_volumes;
            ++first_prices;
        }
    }
    return std::make_tuple(first_prices, out_min, out_max, out_volumes);
}

} // namespace v1
} // namespace sgl
