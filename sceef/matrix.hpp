/* ============================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 * ============================================================ */

#ifndef SCEEF_MATRIX_HPP
#define SCEEF_MATRIX_HPP

#include <sceef/matrix_expression.hpp>
#include <array>

namespace sceef {

template <class T, int N, int M>
class Matrix
        : public MatrixExpression<Matrix<T, N, M> >
{
  public:
    static constexpr int ROW_SIZE = M;
    static constexpr int COLUMN_SIZE = N;
    
  private:
    using RowType = std::array<T, M>;
    using StorageType = std::array<RowType, N>;
    
  public:
    Matrix()
            : storage_()
    {
    }

    Matrix(std::initializer_list<std::initializer_list<T> > initList)
            : storage_()
    {
        auto minColSize = std::min(static_cast<int>(initList.size()), N);
        auto itrCol = std::begin(initList);

        for (int i = 0; i < minColSize; i++, itrCol++) {
            auto minRowSize = std::min(static_cast<int>(itrCol->size()), M);
            auto itrRow = std::begin(*itrCol);

            for (int j = 0; j < minRowSize; j++, itrRow++) {
                storage_[i][j] = *itrRow;
            }
        }
    }
    
    template <class Expression>
    Matrix(const MatrixExpression<Expression>& expression)
            : storage_()
    {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                storage_[i][j] = expression.at(i, j);
            }
        }
    }

    RowType& operator [] (int index) {
        return storage_[index];
    }

    const RowType& operator [] (int index) const {
        return storage_[index];
    }

    T& at(int i, int j) {
        return storage_[i][j];
    }

    const T& at(int i, int j) const {
        return storage_[i][j];
    }
    
    template <class Expression>
    auto operator = (const MatrixExpression<Expression>& expression) -> decltype(auto) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                storage_[i][j] = expression.at(i, j);
            }
        }
        return *this;
    }

    template <class Expression>
    auto operator += (const MatrixExpression<Expression>& expression) -> decltype(auto) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                storage_[i][j] += expression.at(i, j);
            }
        }
        return *this;
    }

    template <class Expression>
    auto operator -= (const MatrixExpression<Expression>& expression) -> decltype(auto) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                storage_[i][j] -= expression.at(i, j);
            }
        }
        return *this;
    }

    template <class Expression>
    auto operator *= (const MatrixExpression<Expression>& expression) -> decltype(auto) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                storage_[i][j] *= expression.at(i, j);
            }
        }
        return *this;
    }

    template <class Expression>
    auto operator /= (const MatrixExpression<Expression>& expression) -> decltype(auto) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                storage_[i][j] /= expression.at(i, j);
            }
        }
        return *this;
    }

  private:
    StorageType storage_;
};

} // namespace sceef

#endif // oSCEEF_MATRIX_HPP

