#pragma once

constexpr int gcd_iterative(int a, int b);
constexpr int gcd_recursive(int a, int b);

static inline constexpr int euclid_gcd_iterative(int a, int b);
static constexpr int euclid_gcd_recursive(int a, int b);
static inline constexpr void swap(int &a, int &b);

// Calculate the gcd of two integers using an iterative implementation of Euclid's algorithm
constexpr int gcd_iterative(int a, int b) {
    // Use the fact that gcd(a, b) = gcd(|a|, |b|)
    // to cover both positive and negative integers
    if(a < 0) a = -a;
    if(b < 0) b = -b;
    // Use the fact that gcd(a, b) = gcd(b, a) and gcd(a, 0) = gcd(0, a) = a.
    // Obs. this covers the case gcd(0, 0) = 0 too
    if(a == 0) return b;
    if(b == 0) return a;

    // Use the Euclid algorithm to calculate gcd
    return euclid_gcd_iterative(a, b);
}

static inline constexpr int euclid_gcd_iterative(int a, int b) {
    while(a > 0) {
        if(a < b) {
            swap(a, b);
        }
        a = a % b;
    }
    return b;
}

// Calculate the gcd of two integers using a recursive implementation of Euclid's algorithm
constexpr int gcd_recursive(int a, int b) {
    // Use the fact that gcd(a, b) = gcd(|a|, |b|)
    // to cover both positive and negative integers
    if(a < 0) a = -a;
    if(b < 0) b = -b;
    // Use the fact that gcd(a, b) = gcd(b, a) and gcd(a, 0) = gcd(0, a) = a.
    // Obs. this covers the case gcd(0, 0) = 0 too
    if(a == 0) return b;
    if(b == 0) return a;

    // Use the Euclid algorithm to calculate gcd
    return euclid_gcd_recursive(a, b);
}

static constexpr int euclid_gcd_recursive(int a, int b) {
    if(a > 0) {
        if(a < b) {
            swap(a, b);
        }
        return euclid_gcd_recursive(a % b, b);
    }
    return b;
}

static inline constexpr void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
