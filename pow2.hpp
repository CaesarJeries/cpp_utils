#ifndef __CAESAR_UTILS_POW2_HPP__
#define __CAESAR_UTILS_POW2_HPP__

#include "types.hpp"


namespace caesar {



template<int N>
struct pow2 {

    static_assert(N < (sizeof(unsigned long) * num_bits<byte_t>::value),
                  "Overflow detected");

    static constexpr unsigned long value = 
        pow2<N - 1>::value << 1;
};


template<>
struct pow2<0> {
    static constexpr unsigned long value = 1ul;
};

}

#endif // __CAESAR_UTILS_POW2_HPP__
