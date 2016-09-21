/* ============================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 * ============================================================ */

#ifndef SCEEF_PRODUCT_EXPRESSION_HPP
#define SCEEF_PRODUCT_EXPRESSION_HPP

namespace sceef {

template <class Lhs, class Rhs>
class MatrixProduct
        : public MatrixExpression<MatrixProduct<Lhs, Rhs> >
{
  public:
    static_assert(Lhs::ROW_SIZE == Rhs::COLUMN_SIZE, "error : left row size and right col size are different");
    static_assert(Lhs::COLUMN_SIZE == Rhs::ROW_SIZE, "error : left col size and right row size are different");

    static constexpr int ROW_SIZE = Rhs::ROW_SIZE;
    static constexpr int COLUMN_SIZE = Lhs::COLUMN_SIZE;

  public:
    MatrixProduct(const Lhs& lhs, const Rhs& rhs)
            : lhs_(lhs), rhs_(rhs)
    {
    }

    auto at(int i, int j) const -> decltype(auto) {
        decltype(lhs_.at(0, 0)) sum = 0;
        for (int k = 0; k < Lhs::ROW_SIZE; k++) {
            sum += lhs_.at(i, k) * rhs_.at(k, j);
        }
        return sum;
    }
    
  private:
    const Lhs& lhs_;
    const Rhs& rhs_;
};

} // namespace sceef

#endif // SCEEF_PRODUCT_EXPRESSION_HPP
