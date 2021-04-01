#ifndef __CAESAR_UTILS_TYPES_HPP__
#define __CAESAR_UTILS_TYPES_HPP__

namespace caesar {

typedef unsigned char byte_t;

constexpr const int BITS_IN_BYTE = 8;

template<typename T>
struct num_bits {
    static constexpr unsigned long value =
        BITS_IN_BYTE * sizeof(T);
};

}

#endif // __CAESAR_UTILS_TYPES_HPP__
