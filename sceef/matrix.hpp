/* ============================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 * ============================================================ */

#ifndef SCEEF_MATRIX_HPP
#define SCEEF_MATRIX_HPP

namespace sceef {

template <class T, int N, int M>
class Matrix
        : public MatrixExpression<Matrix<T, N, M> >
{
  private:
    using RowType = std::array<T, M>;
    using StorageType = std::array<RowType, N>;
    
  public:
    Matrix()
            : storage_()
    {
    }

    template <class Expression>
    Matrix(const MatrixExpression<Expression>& expression)
            : storage_()
    {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                stroage_[i][j] = expression[i][j];
            }
        }
    }

    RowType& operator [] (int index) {
        return storage_[index];
    }

    const RowType& operator [] (int index) const {
        return storage_[index];
    }

  private:
    StorageType storage_;
};

} // namespace sceef

#endif // oSCEEF_MATRIX_HPP

