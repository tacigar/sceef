/* =============================================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 * ============================================================================= */

#ifndef SCEEF_VECTOR_BASE_BOP_HPP
#define SCEEF_VECTOR_BASE_BOP_HPP

#include <cstddef>
#include <sceef/op.hpp>
#include <sceef/vector_base_expression.hpp>

namespace sceef {

	template <class LE, class Op, class RE, class Tag>
	class vector_base_bop
		: public sceef::vector_base_expression<sceef::vector_base_bop<
												   LE, Op, RE, Tag>, Tag> {
	public:
		constexpr
		vector_base_bop(const LE& lhs, const RE& rhs)
			: lhs_(lhs), rhs_(rhs) {
		}

		constexpr
		auto operator[](std::size_t index) const -> decltype(auto) {
			return Op::apply(lhs_[index], rhs_[index]);
		}
		
		constexpr
		auto at(std::size_t index) const -> decltype(auto) {
			return Op::apply(lhs_.at(index), rhs_.at(index));
		}

	private:
		const LE& lhs_;
		const RE& rhs_;
	};

	template <class LE, class RE, class Tag>
	constexpr
	auto operator+(const sceef::vector_base_expression<LE, Tag>& lhs,
				   const sceef::vector_base_expression<RE, Tag>& rhs) -> decltype(auto) {
		return sceef::vector_base_bop<LE, sceef::op::add, RE, Tag>(lhs(), rhs());
	}

	template <class LE, class RE, class Tag>
	constexpr
	auto operator-(const sceef::vector_base_expression<LE, Tag>& lhs,
				   const sceef::vector_base_expression<RE, Tag>& rhs) -> decltype(auto) {
		return sceef::vector_base_bop<LE, sceef::op::subtract, RE, Tag>(lhs(), rhs());
	}
	
} // namespace sceef

#endif // SCEEF_VECTOR_BASE_BOP_HPP
