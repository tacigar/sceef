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
        sceef::Vector<int, 3> lhs;
        sceef::Vector<int, 3> rhs;
        sceef::Vector<int, 3> res;
    };

    std::vector<TestCase> tests = {
        {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}},
        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
        {{10, 10, 10}, {-10, -10, -10}, {0, 0, 0}},
        {{-1, -2, -3}, {-4, -5, -6}, {-5, -7, -9}},
    };
    
    for (const auto& test :tests) {
        // for evaluation, type must be placed.
        sceef::Vector<int, 3> tmp = test.lhs + test.rhs;
        for (int i = 0; i < 3; i++) {
            ASSERT_EQ(tmp[i], test.res[i]);
        }
    }
}
