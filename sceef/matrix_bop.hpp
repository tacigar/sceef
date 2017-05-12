/* =============================================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 * ============================================================================= */

#ifndef SCEEF_MATRIX_BOP_HPP
#define SCEEF_MATRIX_BOP_HPP

#include <sceef/matrix_expression.hpp>
#include <sceef/op.hpp>
#include <sceef/row_vector_bop.hpp>

namespace sceef {

	template <class LE, class Op, class RE>
	class matrix_bop
		: public sceef::matrix_expression<sceef::matrix_bop<LE, Op, RE>> {
	public:
		constexpr
		matrix_bop(const LE& lhs, const RE& rhs)
			: lhs_(lhs), rhs_(rhs) {
		}

		constexpr
		auto operator[](std::size_t index) const -> decltype(auto) {
			return sceef::row_vector_bop<
				decltype(lhs_[index]), Op, decltype(rhs_[index])>
				(lhs_[index], rhs_[index]);
		}

		constexpr
		auto at(std::size_t index) const -> decltype(auto) {
			return sceef::row_vector_bop<
				decltype(lhs_.at(index)), Op, decltype(rhs_.at(index))>
				(lhs_.at(index), rhs_.at(index));
		}

		constexpr
		auto at(std::size_t i, std::size_t j) const -> decltype(auto) {
			return Op::apply(lhs_.at(i, j), rhs_.at(i, j));
		}

	private:
		const LE& lhs_;
		const RE& rhs_;
	};

	template <class LE, class RE>
	constexpr
	auto operator+(const sceef::matrix_expression<LE>& lhs,
				   const sceef::matrix_expression<RE>& rhs) -> decltype(auto) {
		return sceef::matrix_bop<LE, sceef::op::add, RE>(lhs(), rhs());
	}

	template <class LE, class RE>
	constexpr
	auto operator-(const sceef::matrix_expression<LE>& lhs,
				   const sceef::matrix_expression<RE>& rhs) -> decltype(auto) {
		return sceef::matrix_bop<LE, sceef::op::subtract, RE>(lhs(), rhs());
	}
	
} // namespace sceef

#endif // SCEEF_MATRIX_BOP_HPP