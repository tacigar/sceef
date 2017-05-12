/* =============================================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 * 
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 * ============================================================================= */

#ifndef SCEEF_MATRIX_UOP_HPP
#define SCEEF_MATRIX_UOP_HPP

#include <cstddef>
#include <sceef/matrix_expression.hpp>
#include <sceef/op.hpp>
#include <sceef/row_vector_uop.hpp>

namespace sceef {
	
	template <class Op, class E>
	class matrix_uop
		: public sceef::matrix_expression<sceef::matrix_uop<Op, E>> {
	public:
		constexpr
		matrix_uop(const E& expr): expr_(expr) {
		}

		constexpr
		auto operator[](std::size_t index) const -> decltype(auto) {
			return sceef::row_vector_uop<
				Op, decltype(expr_[index])>(expr_[index]);
		}
		
		constexpr
		auto at(std::size_t index) const -> decltype(auto) {
			return sceef::row_vector_uop<
				Op, decltype(expr_.at(index))>(expr_.at(index));
		}

		constexpr
		auto at(std::size_t i, std::size_t j) const -> decltype(auto) {
			return Op::apply(expr_.at(i, j));
		}
		
	private:
		const E& expr_;
	};

	template <class E>
	constexpr
	auto operator+(const sceef::matrix_expression<E>& expr)
		-> decltype(auto) {
		return sceef::matrix_uop<sceef::op::positive, E>(expr());
	}

	template <class E>
	constexpr
	auto operator-(const sceef::matrix_expression<E>& expr)
		-> decltype(auto) {
		return sceef::matrix_uop<sceef::op::negative, E>(expr());
	}
	
} // namespace sceef

#endif // SCEEF_MATRIX_UOP_HPP