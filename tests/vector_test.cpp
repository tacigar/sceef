#include <vector>
#include <utility>
#include <gtest/gtest.h>
#include <sceef/vector.hpp>
#include <sceef/vector_expression.hpp>
#include <sceef/binary_operation.hpp>

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
