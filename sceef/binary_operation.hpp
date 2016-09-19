/* ============================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 * ============================================================ */

#ifndef SCEEF_BINARY_OPERATION_HPP
#define SCEEF_BINARY_OPERATION_HPP

#include <sceef/matrix_expression.hpp>
#include <sceef/utility.hpp>
#include <sceef/vector_expression.hpp>

namespace sceef {

template <class Lhs, class Operator, class Rhs>
class VectorBinaryOperation
        : public VectorExpression<VectorBinaryOperation<Lhs, Operator, Rhs> >
{
  public:
    static_assert(Lhs::SIZE == Rhs::SIZE, "error : left size and right size are different");

    static constexpr int SIZE = Lhs::SIZE;
    
  public:
    VectorBinaryOperation(const Lhs& lhs, const Rhs& rhs)
            : lhs_(lhs), rhs_(rhs)
    {
    }

    auto operator [] (int index) const -> decltype(auto) {
        return Operator::apply(lhs_.at(index), rhs_.at(index));
    }
    
  private:
    const Lhs& lhs_;
    const Rhs& rhs_;
};

template <class Lhs, class Rhs>
auto operator + (const VectorExpression<Lhs>& lhs, const VectorExpression<Rhs>& rhs) -> decltype(auto) {
    return VectorBinaryOperation<Lhs, Add, Rhs>(lhs(), rhs());
}

template <class Lhs, class Rhs>
auto operator - (const VectorExpression<Lhs>& lhs, const VectorExpression<Rhs>& rhs) -> decltype(auto) {
    return VectorBinaryOperation<Lhs, Subtract, Rhs>(lhs(), rhs());
}

template <class Lhs, class Rhs>
auto operator * (const VectorExpression<Lhs>& lhs, const VectorExpression<Rhs>& rhs) -> decltype(auto) {
    return VectorBinaryOperation<Lhs, Multiply, Rhs>(lhs(), rhs());
}

template <class Lhs, class Rhs>
auto operator / (const VectorExpression<Lhs>& lhs, const VectorExpression<Rhs>& rhs) -> decltype(auto) {
    return VectorBinaryOperation<Lhs, Divide, Rhs>(lhs(), rhs());
}

// ============================================================

template <class Lhs, class Operator, class Rhs>
class MatrixBinaryOperation
        : public MatrixExpression<MatrixBinaryOperation<Lhs, Operator, Rhs> >
{
  public:
    static_assert(Lhs::ROW_SIZE == Rhs::ROW_SIZE, "error : left row size and right row size are different");
    static_assert(Lhs::COLUMN_SIZE == Rhs::COLUMN_SIZE, "error : left col size and right col size are different");

    static constexpr int ROW_SIZE = Lhs::ROW_SIZE;
    static constexpr int COLUMN_SIZE = Lhs::COLUMN_SIZE;

  public:
    MatrixBinaryOperation(const Lhs& lhs, const Rhs& rhs)
            : lhs_(lhs), rhs_(rhs)
    {
    }

    auto at(int i, int j) const -> decltype(auto) {
        return Operator::apply(lhs_.at(i, j), rhs_.at(i, j));
    }
    
  private:
    const Lhs& lhs_;
    const Rhs& rhs_;
};

template <class Lhs, class Rhs>
auto operator + (const MatrixExpression<Lhs>& lhs, const MatrixExpression<Rhs>& rhs) -> decltype(auto) {
    return MatrixBinaryOperation<Lhs, Add, Rhs>(lhs(), rhs());
}

template <class Lhs, class Rhs>
auto operator - (const MatrixExpression<Lhs>& lhs, const MatrixExpression<Rhs>& rhs) -> decltype(auto) {
    return MatrixBinaryOperation<Lhs, Subtract, Rhs>(lhs(), rhs());
}

template <class Lhs, class Rhs>
auto operator * (const MatrixExpression<Lhs>& lhs, const MatrixExpression<Rhs>& rhs) -> decltype(auto) {
    return MatrixBinaryOperation<Lhs, Multiply, Rhs>(lhs(), rhs());
}

template <class Lhs, class Rhs>
auto operator / (const MatrixExpression<Lhs>& lhs, const MatrixExpression<Rhs>& rhs) -> decltype(auto) {
    return MatrixBinaryOperation<Lhs, Divide, Rhs>(lhs(), rhs());
}

} // namespace sceef

#endif // SCEEF_BINARY_OPERATION_HPP
