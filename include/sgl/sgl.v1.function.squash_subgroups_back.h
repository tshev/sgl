#pragma once

namespace sgl {
namespace v1  {

template<typename It, typename Predicate, typename F>
It squash_subgroups_back(It first, It last, Predicate predicate, F f) {
        if (first == last) {
                return first; 
        }
        auto slow = first;
        auto fast = slow;
        ++fast;
        while (fast != last) {
                if (!predicate(*slow, *fast)) {
                        *first = f(*slow);
                        ++first;
                }
                ++slow;
                ++fast;
        }       
        *first = f(*slow);
        ++first;
        return first;
}

}
}
