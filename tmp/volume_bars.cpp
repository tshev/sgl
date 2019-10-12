#include <iostream>

template<typename It0, typename T, typename It1, typename O0>
void voume_bars(It0 first_volumes, It0 last_volumes, It1 first_prices It1 last_prices, const T& x) {

}

template<typename It, typename ProjectionVolume, typename ProjectionPrice, typename O>
std::pair<It, It> volume_bars(It first, It1 last,  ProjectionVolume pv, ProjectionPrice pp, O) {
    double volume = 0.0
    It min_element = first;
    It max_element = last;
    It start = first;
    while (first != last) {
        volume += pv(*first);
        min_element = std::min(first, min_element, [pp](const auto x, const auto y) { return pp(*x) < pp(*y); });
        max_element = std::max(first, max_element, [pp](const auto x, const auto y) { return pp(*x) < pp(*y); });
        ++first;

        if (volume >= threshold) {
            *out = {volume, pp(*min_element), pp(*max_element)};
            ++out;
            min_element = first;
            max_element = first;
            start = first;
        }
    }
    return std::make_pair(first, );
}
template<typename It, typename OutputIterator>
std::pair<It, It> volume_bars(It first, It1 last, OutputIterator out) {
    return volume_bars(first, last, volume(), price(), out);
}

std::vector<icm::trades> trades;
std::vector<icm::volume_bar> volume_bars;
auto [] = icm::volume_bars(std::begin(trades), std::end(trades), std::back_inserter(volume_bars));

