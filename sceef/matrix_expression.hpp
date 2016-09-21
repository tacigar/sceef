/* ============================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 * ============================================================ */

#ifndef SCEEF_MATRIX_EXPRESSION_HPP
#define SCEEF_MATRIX_EXPRESSION_HPP

namespace sceef {

template <class Derived>
class MatrixExpression {
  public:
    static constexpr int ROW_SIZE = Derived::ROW_SIZE;
    static constexpr int COLUMN_SIZE = Derived::COLUMN_SIZE;
    
  public:
    auto at(int i, int j) -> decltype(auto) {
        return (static_cast<Derived&>(*this)).at(i, j);
    }

    auto at(int i, int j) const -> decltype(auto) {
        return (static_cast<const Derived&>(*this)).at(i, j);
    }

    auto operator () () -> decltype(auto) {
        return static_cast<Derived&>(*this);
    }

    auto operator () () const -> decltype(auto) {
        return static_cast<const Derived&>(*this);
    }
};

template <class Lhs, class Rhs>
bool operator == (const MatrixExpression<Lhs>& lhs, const MatrixExpression<Rhs>& rhs) {
    static_assert(Lhs::ROW_SIZE == Rhs::ROW_SIZE, "error : left row size and right row size are different");
    static_assert(Lhs::COLUMN_SIZE == Rhs::COLUMN_SIZE, "error : left col size and right col size are different");

    for (int i = 0; i < Lhs::COLUMN_SIZE; i++) {
        for (int j = 0; j < Lhs::ROW_SIZE; j++) {
            if (!equals(lhs.at(i), rhs.at(i))) {
                return false;
            }
        }
    }
    return true;
}

template <class Lhs, class Rhs>
bool operator != (const MatrixExpression<Lhs>& lhs, const MatrixExpression<Rhs>& rhs) {
    return !(lhs == rhs);
}

template <class Expression>
auto operator << (std::ostream& os, const MatrixExpression<Expression>& expression) -> decltype(auto) {
    os << "{ ";
    for (int i = 0; i < Expression::COLUMN_SIZE; i++) {
        os << "{ ";
        for (int j = 0; j < Expression::ROW_SIZE; j++) {
            os << expression.at(i, j) << ' ';
        }
        os << "} ";
    }
    os << "}";
}

} // namespace sceef

#endif // SCEEF_MATRIX_EXPRESSION_HPP

