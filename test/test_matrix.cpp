/* =============================================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 * ============================================================================= */

#include <vector>
#include <utility>
#include <gtest/gtest.h>
#include <sceef/sceef.hpp>

TEST(test_matrix, size) {
    std::vector<
        std::pair<std::pair<int, int>, std::pair<int, int>>> tests = {
        {{sceef::matrix<int, 2, 3>().size(), 2},
         {sceef::matrix<int, 2, 3>().at(0).size(), 3}},
    };
    for (auto i = 0; i < tests.size(); ++i) {
        ASSERT_EQ(tests[i].first.first, tests[i].first.second)
            << "i = " << i << ": in first";
        ASSERT_EQ(tests[i].second.first, tests[i].second.second)
            << "i = " << i << ": in second";
    }
}

TEST(test_matrix, access) {
    std::vector<std::vector<std::vector<int>>> tests = {
        {{1, 2}, {2, 3}, {4, 5}},
        {{0, 0}, {0, 0}, {0, 0}},
    };

    for (auto i = 0; i < tests.size(); ++i) {
        { // operator[]
            sceef::matrix<int, 3, 2> mat;
            for (auto j = 0; j < mat.size(); ++j) {
                for (auto k = 0; k < mat[j].size(); ++k) {
                    mat[j][k] = tests[i][j][k];
                }
            }
            
            for (auto j = 0; j < mat.size(); ++j) {
                for (auto k = 0; k < mat[j].size(); ++k) {
                    ASSERT_EQ(mat[j][k], tests[i][j][k]);
                }
            }
        }

        { // at(std::size_t)
            sceef::matrix<int, 3, 2> mat;
            for (auto j = 0; j < mat.size(); ++j) {
                for (auto k = 0; k < mat[j].size(); ++k) {
                    mat.at(j).at(k) = tests[i][j][k];
                }
            }
            
            for (auto j = 0; j < mat.size(); ++j) {
                for (auto k = 0; k < mat[j].size(); ++k) {
                    ASSERT_EQ(mat.at(j).at(k), tests[i][j][k]);
                }
            }
        }

        { // at(std::size_t, std::size_t)
            sceef::matrix<int, 3, 2> mat;
            for (auto j = 0; j < mat.size(); ++j) {
                for (auto k = 0; k < mat[j].size(); ++k) {
                    mat.at(j, k) = tests[i][j][k];
                }
            }
            
            for (auto j = 0; j < mat.size(); ++j) {
                for (auto k = 0; k < mat[j].size(); ++k) {
                    ASSERT_EQ(mat.at(j, k), tests[i][j][k]);
                }
            }
        }
    }
}
