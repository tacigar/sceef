/* ============================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 * ============================================================ */

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
