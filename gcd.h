#pragma once

#include <stdexcept>

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

    return gcd_euclid_iterative(a, b);
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
