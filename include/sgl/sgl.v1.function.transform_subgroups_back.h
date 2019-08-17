#pragma once

namespace sgl {
namespace v1  {

template<typename It, typename OutputItertor, typename Predicate, typename F>
OutputItertor transform_subgroups_back(It first, It last, OutputItertor out, Predicate predicate, F f) {
        if (first == last) {
                return out; 
        }       
        auto slow = first;
        auto fast = slow;
        ++fast;
        while (fast != last) {
                if (!predicate(*slow, *fast)) {
                        *out = f(*slow);
                        ++out;
                }
                ++slow;
                ++fast;
        }       
        *out = f(*slow);
        ++out;
        return out;
}

}
}
