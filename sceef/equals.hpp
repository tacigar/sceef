/* =============================================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 * ============================================================================= */

#ifndef SCEEF_EQUALS_HPP
#define SCEEF_EQUALS_HPP

#include <algorithm>
#include <cmath>
#include <limits>
#include <type_traits>

namespace sceef {

	template <class T>
	auto fuzzy_equals(T lhs, T rhs) -> decltype(auto) {
		auto max_value = std::max(std::abs(lhs), std::abs(rhs));
		return std::abs(lhs - rhs) <=
			std::numeric_limits<T>::epsilon() * max_value;
	}

	template <class T>
	auto equals(T lhs, T rhs)
		-> typename std::enable_if<std::is_floating_point<T>::value,
								   bool>::type {
		return fuzzy_equals(lhs, rhs);
	}

	template <class T>
	auto equals(T lhs, T rhs)
		-> typename std::enable_if<std::is_integral<T>::value, bool>::type {
		return lhs == rhs;
	}

} // namespace sceef

#endif // SCEEF_EQUALS_HPP
