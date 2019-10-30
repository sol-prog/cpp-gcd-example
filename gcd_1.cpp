// Program to find the greated common divisor of two or more integers
/*
- The gcd of two or more integers, that are not all zero, is the largest positive integer that divides all these numbers.
- Examples:
    gcd(9, 15) = 3
    gcd(9, 15, 21) = 3
    gcd(5, 15) = 5

- Properties of the gcd function:
    0. gcd(0, 0) = 0
    1. gcd(a, b) = gcd(b, a)
    2. gcd(a, b) = gcd(-a, b)
    3. gcd(a, b) = gcd(|a|, |b|)
    4. gcd(a, 0) = |a|

- Euclid's algorithm to find the gcd of two positive numbers:
    if a > b then
        gcd(a, b) = gcd(a - b, b)
        ...
        gcd(0, b)

- Example:
    gcd(15, 9):
    gcd(15, 9) = gcd(15 - 9, 9)
    gcd(6, 9) = gcd(9, 6)               // Swap the numbers if a < b (when first number is less than second)
    gcd(9, 6) = gcd(9 - 6, 6)
    gcd(3, 6) = gcd(6, 3)               // Swap the numbers
    gcd(6, 3) = gcd(6 - 3, 3)
    gcd(3, 3) = gcd(3 - 3, 3)
    gcd(0, 3) = 3
    ==========================
    gcd(15, 9) = 3
*/

constexpr int gcd_euclid_iterative(int a, int b);
constexpr int gcd_euclid_recursive(int a, int b);
constexpr  void swap(int &a, int &b);

constexpr int gcd(int a, int b) {
    // Use property 3
    if(a < 0) a = -a;
    if(b < 0) b = -b;

    // Use properties 0, 1 and 4
    if(a == 0) return b;
    if(b == 0) return a;

    return gcd_euclid_recursive(a, b);
}

constexpr  void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// Iterative implementation
constexpr int gcd_euclid_iterative(int a, int b) {
    while(a > 0) {
        if(a < b) {
            swap(a, b);
        }
        a = a % b;
    }
    return b;
}

// Recursive implementation
constexpr int gcd_euclid_recursive(int a, int b) {
    if(a > 0) {
        if(a < b) {
            swap(a, b);
        }
        return gcd_euclid_recursive(a % b, b);
    }
    return b;
}

int main() {
    static_assert(gcd(0, 0) == 0);
    static_assert(gcd(0, 5) == 5);
    static_assert(gcd(5, 0) == 5);
    static_assert(gcd(-5, 0) == 5);
    static_assert(gcd(0, -8) == 8);
    static_assert(gcd(15, 9) == 3);
    static_assert(gcd(24, -8) == 8);
    static_assert(gcd(-9, -15) == 3);
}
