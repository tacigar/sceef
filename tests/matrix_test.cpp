/* ============================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 * ============================================================ */

#include <vector>
#include <utility>
#include <gtest/gtest.h>
#include <sceef/binary_operation.hpp>
#include <sceef/matrix.hpp>
#include <sceef/matrix_expression.hpp>

TEST(MatrixTest, MatrixAccessTest) {
    using TestCase = std::vector<std::vector<int> >;

    std::vector<TestCase> tests = {
        {{1, 2}, {2, 3}, {4, 5}},
        {{-100, -20}, {2, 300}, {200000, 200000}},
    };

    for (const auto& test : tests) {
        sceef::Matrix<int, 3, 2> mat;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                mat[i][j] = test[i][j];
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                ASSERT_EQ(mat[i][j], test[i][j]);
            }
        }
    }
}

TEST(MatrixTest, MatrixAddTest) {
    struct TestCase {
        std::vector<sceef::Matrix<int, 3, 2> > operands;
        sceef::Matrix<int, 3, 2> res;
    };

    std::vector<TestCase> tests = {
        {{{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}},
          {{9, 9}, {8, 8}, {7, 7}, {6, 6}, {5, 5}, {4, 4}}},
         {{10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}, {10, 10}}},
    };

    for (const auto& test : tests) {
        sceef::Matrix<int, 3, 2> tmp = test.operands[0];
        for (int i = 1; i < test.operands.size(); i++) {
            tmp = tmp + test.operands[i];
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                ASSERT_EQ(tmp[i][j], test.res[i][j]);
            }
        }
    }
}