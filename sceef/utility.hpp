/* ============================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 * ============================================================ */

#ifndef SCEEF_UTILITY_HPP
#define SCEEF_UTILITY_HPP

#include <algorithm>
#include <cmath>
#include <limits>
#include <type_traits>

struct Add {
    template <class T>
    static T apply(T lhs, T rhs) {
        return lhs + rhs;
    }
};

struct Subtract {
    template <class T>
    static T apply(T lhs, T rhs) {
        return lhs - rhs;
    }
};

struct Multiply {
    template <class T>
    static T apply(T lhs, T rhs) {
        return lhs * rhs;
    }
};

struct Divide {
    template <class T>
    static T apply(T lhs, T rhs) {
        return lhs / rhs;
    }
};

struct Positive {
    template <class T>
    static T apply(T value) {
        return value;
    }
};

struct Negative {
    template <class T>
    static T apply(T value) {
        return -value;
    }
};

// ============================================================

template <class T>
bool fuzzyEquals(T lhs, T rhs) {
    static_assert(std::is_floating_point<T>::value == true && std::is_floating_point<T>::value == true,
                  "Arguments must be floating point number");
    T max = std::max(std::abs(lhs), std::abs(rhs));
    return std::abs(lhs - rhs) <= std::numeric_limits<T>::epsilon() * max;
}

template <class T>
typename std::enable_if<std::is_floating_point<T>::value, bool>::type
equals(T lhs, T rhs) {
    return fuzzyEquals(lhs, rhs);
}

template <class T>
typename std::enable_if<std::is_integral<T>::value, bool>::type
equals(T lhs, T rhs) {
    return lhs == rhs;
}

#endif // SCEEF_UTILITY_HPP
