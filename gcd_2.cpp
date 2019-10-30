// Calculate the gcd of a collection of numbers, e.g. {3, 9, 21}
/*
- Example:
    gcd(3, 9, 21):
    gcd(3, 9) = 3;
    gcd(gcd(3, 9), 21) = gcd(3, 21) = 3
*/

#include "gcd.h"
#include <vector>
#include <stdexcept>
#include <iostream>
#include <cassert>

int gcd_group(const std::vector<int> &V) {
    if(V.size() < 2) {
        throw std::runtime_error("Error! The input vector must have at least 2 elements!");
    }
    int gcd_tmp{};
    for(const auto &elem : V) {
        gcd_tmp = gcd(gcd_tmp, elem);
    }
    return gcd_tmp;
}

int main() {
    std::vector<int> V{3, 9, 21};
    assert(gcd_group(V) == 3);

    std::vector<int> V2{-3, 15};
    assert(gcd_group(V2) == 3);

    std::vector<int> V3{8};
    assert(gcd_group(V3) == -1);
}
