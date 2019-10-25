#include "gcd.h"

#include <iostream>
#include <vector>
#include <stdexcept>

int gcd(const std::vector<int> &V) {
    if(V.size() < 2) {
        throw std::runtime_error("Error! Input vector must have at least 2 elements");
    }

    int gcd_tmp{};
    for(const auto &elem : V) {
        gcd_tmp = gcd_iterative(gcd_tmp, elem);
    }
    return gcd_tmp;
}

int main() {
    std::vector V{15, 9, 21};
    std::cout << "gcd(V) = " << gcd(V) << " Expected 3!\n";

    V.emplace_back(-17);
    std::cout << "gcd(V) = " << gcd(V) << " Expected 1!\n";
}
