// Example of using the standard library gcd implementation
#include <numeric>

int main() {
    static_assert(std::gcd(15, 9) == 3);
    static_assert(std::gcd(24, -8) == 8);
    static_assert(std::gcd(5, 0) == 5);
    static_assert(std::gcd(0, 5) == 5);
    static_assert(std::gcd(0, 0) == 0);
}
