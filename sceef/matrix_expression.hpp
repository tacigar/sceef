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

} // namespace sceef

#endif // SCEEF_MATRIX_EXPRESSION_HPP

