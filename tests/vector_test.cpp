/* ============================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 * ============================================================ */

#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <gtest/gtest.h>
#include <sceef/binary_operation.hpp>
#include <sceef/product_expression.hpp>
#include <sceef/unary_operation.hpp>
#include <sceef/vector.hpp>
#include <sceef/vector_expression.hpp>


TEST(VectorTest, VectorSizeTest) {
    std::vector<std::pair<int, int> > tests = {
        {sceef::Vector<int, 3>::SIZE, 3},
        {sceef::Vector<int, 10>::SIZE, 10},
        {sceef::Vector<double, 100>::SIZE, 100},
    };
    for (const auto& test : tests) {
        ASSERT_EQ(test.first, test.second);
    }
}

TEST(VectorTest, VectorAddTest) {
    struct TestCase {
        std::vector<sceef::Vector<int, 3> > operands;
        sceef::Vector<int, 3> res;
    };

    std::vector<TestCase> tests = {
        {{{1, 1, 1}, {2, 2, 2}}, {3, 3, 3}},
        {{{0, 0, 0}, {0, 0, 0}}, {0, 0, 0}},
        {{{10, 10, 10}, {-10, -10, -10}}, {0, 0, 0}},
        {{{-1, -2, -3}, {-4, -5, -6}}, {-5, -7, -9}},
    };
    
    for (const auto& test : tests) {
        sceef::Vector<int, 3> tmp = test.operands[0];
        for (int i = 1; i < test.operands.size(); i++) {
            tmp = tmp + test.operands[i];
        }
        for (int i = 0; i < 3; i++) {
            ASSERT_EQ(tmp[i], test.res[i]);
        }
    }
}

TEST(VectorTest, VectorSubtractTest) {
    struct TestCase {
        std::vector<sceef::Vector<int, 3> > operands;
        sceef::Vector<int, 3> res;
    };

    std::vector<TestCase> tests = {
        {{{1, 1, 1}, {2, 2, 2}}, {-1, -1, -1}},
        {{{0, 0, 0}, {0, 0, 0}}, {0, 0, 0}},
        {{{10, 10, 10}, {-10, -10, -10}}, {20, 20, 20}},
        {{{-1, -2, -3}, {-4, -5, -6}}, {3, 3, 3}},
    };

    for (const auto& test : tests) {
        sceef::Vector<int, 3> tmp = test.operands[0];
        for (int i = 1; i < test.operands.size(); i++) {
            tmp = tmp - test.operands[i];
        }
        for (int i = 0; i < 3; i++) {
            ASSERT_EQ(tmp[i], test.res[i]);
        }
    }
}

TEST(VectorTest, VectorUnaryOperationTest) {
    struct TestCase {
        bool isPositive;
        sceef::Vector<int, 3> operand;
        sceef::Vector<int, 3> result;
    };

    std::vector<TestCase> tests = {
        {true, {1, 2, 3}, {1, 2, 3}},
        {true, {-1, 2, -3}, {-1, 2, -3}},
        {false, {1, 2, 3}, {-1, -2, -3}},
        {false, {-1, 2, -3}, {1, -2, 3}},
    };

    for (const auto& test : tests) {
        sceef::Vector<int, 3> tmp;
        if (test.isPositive) {
            tmp = +test.operand;
        } else {
            tmp = -test.operand;
        }
        
        for (int i = 0; i < 3; i++) {
            ASSERT_EQ(tmp[i], test.result[i]);
        }
    }
}

TEST(VectorTest, VectorOStreamOperationTest) {
    struct TestCase {
        sceef::Vector<int, 3> vec;
        std::string str;
    };

    std::vector<TestCase> tests = {
        {{1, 2, 3}, "{ 1 2 3 }"},
        {{-1, -2, -3}, "{ -1 -2 -3 }"},
    };

    for (const auto& test : tests) {
        std::stringstream ss;
        ss << test.vec;
        ASSERT_EQ(ss.str(), test.str);
    }
}

TEST(VectorTest, VectorProductTest) {
    struct TestCase {
        sceef::Vector<int, 3> lhs;
        sceef::Vector<int, 3> rhs;
        int res;
    };

    std::vector<TestCase> tests = {
        {{1, 2, 3}, {4, 5, 6}, 32},
    };

    for (const auto& test : tests) {
        int p = sceef::product(test.lhs, test.rhs);
        ASSERT_EQ(p, test.res);
    }
}
