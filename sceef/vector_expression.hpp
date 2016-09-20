/* ============================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 * ============================================================ */

#ifndef SCEEF_VECTOR_EXPRESSION_HPP
#define SCEEF_VECTOR_EXPRESSION_HPP

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

} // namespace sceef

#endif // SCEEF_VECTOR_EXPRESSION_HPP
