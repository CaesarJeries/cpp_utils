#include <iostream>

#include "pow2.hpp"

using namespace caesar;

int main() {
    unsigned long values[] = {
        pow2<0>::value,
        pow2<1>::value,
        pow2<2>::value,
        pow2<3>::value,
        pow2<4>::value,
        pow2<31>::value,
        pow2<32>::value,
        pow2<63>::value,
        //pow2<64>::value // uncomment to test the static_assert
    };

    std::cout << "Size of unsigned long: " << sizeof(unsigned long) << std::endl;

    std::cout << "Printing values:\n";
    for (auto value : values) {
        std::cout << value << std::endl;
    }

    return 0;
}
