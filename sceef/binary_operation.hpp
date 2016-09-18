/* ============================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 * ============================================================ */

#ifndef SCEEF_BINARY_OPERATION_HPP
#define SCEEF_BINARY_OPERATION_HPP

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
        return Operator::apply(lhs_[index], rhs_[index]);
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

} // namespace sceef

#endif // SCEEF_BINARY_OPERATION_HPP
