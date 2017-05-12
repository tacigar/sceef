/* =============================================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 * ============================================================================= */

#ifndef SCEEF_MATRIX_EXPRESSION_HPP
#define SCEEF_MATRIX_EXPRESSION_HPP

#include <cstddef>

namespace sceef {

	template <class Derived>
	class matrix_expression {
	public:
		constexpr
		auto operator[](std::size_t index) -> decltype(auto) {
			return (static_cast<Derived&>(*this)).operator[](index);
		}

		constexpr
		auto operator[](std::size_t index) const -> decltype(auto) {
			return (static_cast<const Derived&>(*this)).operator[](index);
		}

		constexpr
		auto at(std::size_t index) -> decltype(auto) {
			return (static_cast<Derived&>(*this)).at(index);
		}

		constexpr
		auto at(std::size_t index) const -> decltype(auto) {
			return (static_cast<const Derived&>(*this)).at(index);
		}

		constexpr
		auto at(std::size_t i, std::size_t j) -> decltype(auto) {
			return (static_cast<Derived&>(*this)).at(i, j);
		}

		constexpr
		auto at(std::size_t i, std::size_t j) const -> decltype(auto) {
			return (static_cast<const Derived&>(*this)).at(i, j);
		}

		constexpr
		auto operator()() -> decltype(auto) {
			return static_cast<Derived&>(*this);
		}

		constexpr
		auto operator()() const -> decltype(auto) {
			return static_cast<const Derived&>(*this);
		}
	};

	template <class LE, class RE>
	auto operator==(const sceef::matrix_expression<LE>& lhs,
					const sceef::matrix_expression<RE>& rhs) -> decltype(auto) {
		for (auto i = 0; i < lhs.size(); ++i) {
			if (lhs[i] != rhs[i]) {
				return false;
			}
		}
		return true;
	}

	template <class LE, class RE>
	auto operator!=(const sceef::matrix_expression<LE>& lhs,
					const sceef::matrix_expression<RE>& rhs) -> decltype(auto) {
		return !(lhs == rhs);
	}
	
} // namespace sceef

#endif // SCEEF_MATRIX_EXPRESSION_HPP
