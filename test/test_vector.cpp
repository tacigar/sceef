/* =============================================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 * 
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 * ============================================================================= */

#include <vector>
#include <utility>
#include <gtest/gtest.h>
#include <sceef/sceef.hpp>

TEST(test_vector, size) {
	std::vector<
		std::pair<int, int>> tests = {
		{sceef::vector<int, 3>().size(), 3},
		{sceef::vector<int, 9>().size(), 9},
		{sceef::vector<float, 2>().size(), 2},
		{sceef::vector<float, 0>().size(), 0},
		{sceef::vector<double, 7>().size(), 7},
		{sceef::vector<double, 10>().size(), 10},
		{sceef::vector<double, 100>().size(), 100},
	};
	for (auto i = 0; i < tests.size(); ++i) {
		ASSERT_EQ(tests[i].first, tests[i].second) << "i = " << i;
	}
}

TEST(test_vector, uop) {
	struct test_case {
		bool is_negative;
		sceef::vector<int, 3> input;
		sceef::vector<int, 3> output;
	};

	std::vector<test_case> tests = {
		{false, {1, 2, 3}, {1, 2, 3}},
		{false, {-1, 2, -3}, {-1, 2, -3}},
		{false, {0, 0, 0}, {0, 0, 0}},
		{true, {1, 2, 3}, {-1, -2, -3}},
		{true, {-1, 2, -3}, {1, -2, 3}},
		{true, {0, 0, 0}, {0, 0, 0}},
	};

	for (auto i = 0; i < tests.size(); ++i) {
		for (auto j = 0; j < 3; j++) {
			if (tests[i].is_negative) {
				ASSERT_EQ((-(tests[i].input))[j], tests[i].output[j])
					<< "i = " << i << ", " << "j = " << j;
			} else {
				ASSERT_EQ((+(tests[i].input))[j], tests[i].output[j])
					<< "i = " << i << ", " << "j = " << j;
			}
		}
	}
}

TEST(test_vector, add) {
	struct test_case {
		std::vector<
			sceef::vector<int, 3>> input;
		sceef::vector<int, 3> output;
	};

	std::vector<test_case> tests = {
		{{{1, 1, 1}, {2, 2, 2}}, {3, 3, 3}},
		{{{1, 1, 1}, {2, 2, 2}, {3, 3, 3}}, {6, 6, 6}},
		{{{0, 0, 0}, {0, 0, 0}}, {0, 0, 0}},
		{{{1, 2, 3}, {1, 2, 3}}, {2, 4, 6}},
		{{{4, 4, 4}, {-4, -4, -4}}, {0, 0, 0}},
		{{{-1, -2, -3}, {-4, -5, -6}}, {-5, -7, -9}},
	};

	for (auto i = 0; i < tests.size(); ++i) {
		sceef::vector<int, 3> res = tests[i].input[0];
		for (auto j = 1; j < tests[i].input.size(); ++j) {
			res = res + tests[i].input[j];
		}
		for (auto j = 0; j < 3; ++j) {
			ASSERT_EQ(tests[i].output[j], res[j])
				<< "i = " << i << ", " << "j = " << j;
		}
	}
}

