/* ============================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 * ============================================================ */

#ifndef SCEEF_FUNCTIONS_HPP
#define SCEEF_FUNCTIONS_HPP

namespace sceef {

	template <class Lhs, class Rhs>
	auto product(const VectorExpression<Lhs>& lhs, const VectorExpression<Rhs>& rhs) -> decltype(auto) {
		static_assert(Lhs::SIZE == Rhs::SIZE, "error : left size and right size are different");

		decltype(lhs.at(0) * rhs.at(0)) res = 0;
		for (int i = 0; i < Lhs::SIZE; i++) {
			res += lhs.at(i) * rhs.at(i);
		}
		return res;
	}

	template <class Lhs, class Rhs>
	class MatrixProduct
		: public MatrixExpression<MatrixProduct<Lhs, Rhs> > {
	public:
		static_assert(Lhs::ROW_SIZE == Rhs::COLUMN_SIZE, "error : left row size and right col size are different");
		static_assert(Lhs::COLUMN_SIZE == Rhs::ROW_SIZE, "error : left col size and right row size are different");

		static constexpr int ROW_SIZE = Rhs::ROW_SIZE;
		static constexpr int COLUMN_SIZE = Lhs::COLUMN_SIZE;

	public:
		MatrixProduct(const Lhs& lhs, const Rhs& rhs) : lhs_(lhs), rhs_(rhs) {
		}

		auto at(int i, int j) const -> decltype(auto) {
			decltype(lhs_.at(0, 0) * rhs_.at(0, 0)) sum = 0;
			for (int k = 0; k < Lhs::ROW_SIZE; k++) {
				sum += lhs_.at(i, k) * rhs_.at(k, j);
			}
			return sum;
		}

	private:
		const Lhs& lhs_;
		const Rhs& rhs_;
	};

	template <class Lhs, class Rhs>
	auto product(const MatrixExpression<Lhs>& lhs, const MatrixExpression<Rhs>& rhs) -> decltype(auto) {
		return MatrixProduct<Lhs, Rhs>(lhs(), rhs());
	}

} // namespace sceef

#endif // SCEEF_FUNCTIONS_HPP
