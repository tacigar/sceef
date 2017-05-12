/* ============================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 * ============================================================ */

#ifndef SCEEF_VECTOR_EXPRESSION_HPP
#define SCEEF_VECTOR_EXPRESSION_HPP

#include <iostream>

namespace sceef {

	template <class Derived>
	class VectorExpression {
	public:
		static constexpr int SIZE = Derived::SIZE;

	public:
		auto at(int index) -> decltype(auto) {
			return (static_cast<Derived&>(*this)).at(index);
		}

		auto at(int index) const -> decltype(auto) {
			return (static_cast<const Derived&>(*this)).at(index);
		}

		auto operator () () -> decltype(auto) {
			return static_cast<Derived&>(*this);
		}

		auto operator () () const -> decltype(auto) {
			return static_cast<Derived const&>(*this);
		}
	};

	template <class Lhs, class Rhs>
	bool operator == (const VectorExpression<Lhs>& lhs, const VectorExpression<Rhs>& rhs) {
		static_assert(Lhs::SIZE == Rhs::SIZE, "error : left size and right size are different");

		for (int i = 0; i < Lhs::SIZE; i++) {
			if (!equals(lhs.at(i), rhs.at(i))) {
				return false;
			}
		}
		return true;
	}

	template <class Lhs, class Rhs>
	bool operator != (const VectorExpression<Lhs>& lhs, const VectorExpression<Rhs>& rhs) {
		return !(lhs == rhs);
	}

	template <class Expression>
	auto operator << (std::ostream& os, const VectorExpression<Expression>& expression) -> decltype(auto) {
		os << "{ ";
		for (int i = 0; i < Expression::SIZE; i++) {
			os << expression.at(i) << ' ';
		}
		os << "}";
	}

} // namespace sceef

#endif // SCEEF_VECTOR_EXPRESSION_HPP
