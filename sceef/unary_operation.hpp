/* ============================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 * ============================================================ */

#ifndef SCEEF_UNARY_OPERATION_HPP
#define SCEEF_UNARY_OPERATION_HPP

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

    auto operator [] (int index) const -> decltype(auto) {
        return Operator::apply(operand_[index]);
    }

  private:
    const Operand& operand_;
};

} // namespace sceef

#endif // SCEEF_UNARY_OPERATION_HPP
