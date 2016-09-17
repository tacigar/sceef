/* ============================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 * ============================================================ */

#ifndef SCEEF_VECTOR_HPP
#define SCEEF_VECTOR_HPP

#include <array>

namespace sceef {

template <class T, class N>
class Vector
        : public sceef::VectorExpression<sceef::Vector<T, N> >
{
  private:
    using ContainerType = std::array<T, N>;
    
  public:
    Vector()
            : storage_()
    {
    }

    Vector(std::initializer_list<T> initList)
            : storage_()
    {
        auto minSize = std::min(static_cast<int>(initList.size()), N);
        auto itr = std::begin(initList);

        for (int i = 0; i < minSize; i++, itr++) {
            storage_[i] = *itr;
        }
    }

    template <class Expression>
    Vector(const sceef::VectorExpression<Expression>& expression)
            : storage_()
    {
        for (int i = 0; i < N; i++) {
            storage_[i] = expression[i];
        }
    }

  private:
    ContainerType storage_;
};

} 

#endif // SCEEF_VECTOR_HPP
