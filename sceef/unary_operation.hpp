/* ============================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 * ============================================================ */

#ifndef SCEEF_UNARY_OPERATION_HPP
#define SCEEF_UNARY_OPERATION_HPP

#include <sceef/matrix_expression.hpp>
#include <sceef/utility.hpp>
#include <sceef/vector_expression.hpp>

namespace sceef {

template <class Operator, class Operand>
class VectorUnaryOperation
        : public VectorExpression<VectorUnaryOperation<Operator, Operand> >
{
  public:
    static constexpr int SIZE = Operand::SIZE;

  public:
    VectorUnaryOperation(const Operand& operand)
            : operand_(operand)
    {
    }

    auto at(int index) const -> decltype(auto) {
        return Operator::apply(operand_.at(index));
    }

  private:
    const Operand& operand_;
};

template <class Operand>
auto operator + (const VectorExpression<Operand>& operand) -> decltype(auto) {
    return VectorUnaryOperation<Positive, Operand>(operand());
}

template <class Operand>
auto operator - (const VectorExpression<Operand>& operand) -> decltype(auto) {
    return VectorUnaryOperation<Negative, Operand>(operand());
}

// ============================================================

template <class Operator, class Operand>
class MatrixUnaryOperation
        : public MatrixExpression<MatrixUnaryOperation<Operator, Operand> >
{
  public:
    static constexpr int ROW_SIZE = Operand::ROW_SIZE;
    static constexpr int COLUMN_SIZE = Operand::COLUMN_SIZE;

  public:
    MatrixUnaryOperation(const Operand& operand)
            : operand_(operand)
    {
    }

    auto at(int i, int j) const -> decltype(auto) {
        return Operator::apply(operand_.at(i, j));
    }
    
  private:
    const Operand& operand_;
};

template <class Operand>
auto operator + (const MatrixExpression<Operand>& operand) -> decltype(auto) {
    return MatrixUnaryOperation<Positive, Operand>(operand());
}

template <class Operand>
auto operator - (const MatrixExpression<Operand>& operand) -> decltype(auto) {
    return MatrixUnaryOperation<Negative, Operand>(operand());
}

} // namespace sceef

#endif // SCEEF_UNARY_OPERATION_HPP
