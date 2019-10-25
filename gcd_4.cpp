// Example of using the standard library gcd implementation
#include <numeric>
#include <array>
#include <iostream>

int main() {
    std::array data{-13, 26, -39, 13};
    std::cout << "gcd(data) = " << std::reduce(data.begin(), data.end(), 0, std::gcd<int,int>) << " Expected : 13\n";
}
