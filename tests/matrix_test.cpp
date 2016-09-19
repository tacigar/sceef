/* ============================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 * ============================================================ */

#include <vector>
#include <utility>
#include <gtest/gtest.h>
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
