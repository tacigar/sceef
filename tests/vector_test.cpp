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

