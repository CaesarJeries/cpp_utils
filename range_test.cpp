#include <iostream>

#include "range.hpp"

int main () {
    constexpr Range<20> range;

    for (auto i : range) {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    return 0;
}