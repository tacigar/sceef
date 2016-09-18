/* ============================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 * ============================================================ */

#ifndef SCEEF_VECTOR_HPP
#define SCEEF_VECTOR_HPP

#include <sceef/vector_expression.hpp>
#include <algorithm>
#include <array>

namespace sceef {

template <class T, int N>
class Vector
        : public VectorExpression<Vector<T, N> >
{
  public:
    static constexpr int SIZE = N;
    
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
    Vector(const VectorExpression<Expression>& expression)
            : storage_()
    {
        for (int i = 0; i < N; i++) {
            storage_[i] = expression[i];
        }
    }

    T& operator [] (int index) {
        return storage_[index];
    }

    const T& operator [] (int index) const {
        return storage_[index];
    }

    template <class Expression>
    Vector<T, N>& operator = (const VectorExpression<Expression>& expression) {
        for (int i = 0; i < N; i++) {
            storage_[i] = expression[i];
        }
        return *this;
    }

    template <class Expression>
    Vector<T, N>& operator += (const VectorExpression<Expression>& expression) {
        for (int i = 0; i < N; i++) {
            storage_[i] += expression[i];
        }
        return *this;
    }

    template <class Expression>
    Vector<T, N>& operator -= (const VectorExpression<Expression>& expression) {
        for (int i = 0; i < N; i++) {
            storage_[i] -= expression[i];
        }
        return *this;
    }

    template <class Expression>
    Vector<T, N>& operator *= (const VectorExpression<Expression>& expression) {
        for (int i = 0; i < N; i++) {
            storage_[i] *= expression[i];
        }
        return *this;
    }

    template <class Expression>
    Vector<T, N>& operator /= (const VectorExpression<Expression>& expression) {
        for (int i = 0; i < N; i++) {
            storage_[i] /= expression[i];
        }
        return *this;
    }
    
  private:
    ContainerType storage_;
};

} // namespace sceef

#endif // SCEEF_VECTOR_HPP
