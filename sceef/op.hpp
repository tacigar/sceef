/* =============================================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 * 
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 * ============================================================================= */

#ifndef SCEEF_OP_HPP
#define SCEEF_OP_HPP

namespace sceef {

	namespace op {

		struct add {
			template <class T>
			constexpr
			static auto apply(T lhs, T rhs) -> decltype(auto) {
				return lhs + rhs;
			}
		};

		struct subtract {
			template <class T>
			constexpr
			static auto apply(T lhs, T rhs) -> decltype(auto) {
				return lhs - rhs;
			}
		};

		struct multiply {
			template <class T>
			constexpr
			static auto apply(T lhs, T rhs) -> decltype(auto) {
				return lhs * rhs;
			}
		};

		struct divide {
			template <class T>
			constexpr
			static auto apply(T lhs, T rhs) -> decltype(auto) {
				return lhs / rhs;
			}
		};
		
		struct positive {
			template <class T>
			constexpr
			static auto apply(T value) -> decltype(auto) {
				return value;
			}
		};

		struct negative {
			template <class T>
			constexpr
			static auto apply(T value) -> decltype(auto) {
				return -value;
			}
		};
		
	} // namespace op
	
} // namespace sceef

#endif // SCEEF_OP_HPP
