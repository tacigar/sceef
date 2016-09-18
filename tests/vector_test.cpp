#include <vector>
#include <utility>
#include <gtest/gtest.h>
#include <sceef/vector.hpp>
#include <sceef/vector_expression.hpp>
#include <sceef/binary_operation.hpp>

TEST(VectorTest, VectorSizeTest) {
    std::vector<std::pair<sceef::Vector>, int> tests = {
        {sceef::Vector<int, 3>(), 3},
        {sceef::Vector<int, 5>(), 5},
    }
    for (const auto& test : tests) {
        EXPECT_EQ(test.first.SIZE, test.second);
    }
}

