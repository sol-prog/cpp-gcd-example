// Use the standard library to calculate the gcd of two or more integers

#include <numeric>
#include <vector>
#include <iostream>
#include <cassert>

int main() {
    static_assert(std::gcd(0, 0) == 0);
    static_assert(std::gcd(0, 5) == 5);
    static_assert(std::gcd(5, 0) == 5);
    static_assert(std::gcd(-5, 0) == 5);
    static_assert(std::gcd(0, -8) == 8);
    static_assert(std::gcd(15, 9) == 3);
    static_assert(std::gcd(24, -8) == 8);
    static_assert(std::gcd(-9, -15) == 3);

    std::vector<int> V{-13, 26, -39, 13};
    int gcd_V = std::reduce(V.begin(), V.end(), 0, std::gcd<int, int>);
    assert(gcd_V == 13);
}
