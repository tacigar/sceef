/* =============================================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 * ============================================================================= */

#ifndef SCEEF_MATRIX_HPP
#define SCEEF_MATRIX_HPP

#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <sceef/matrix_expression.hpp>
#include <sceef/row_vector.hpp>

namespace sceef {
              
    template <class T, std::size_t N, std::size_t M>
    class matrix
        : public sceef::matrix_expression<sceef::matrix<T, N, M>> {
    public:
        static constexpr std::size_t SIZE = N;
        static constexpr std::size_t COLUMN_SIZE = N;
        static constexpr std::size_t ROW_SIZE = M;

        constexpr
        matrix(): elements_() {
        }

        constexpr
        matrix(std::initializer_list<std::initializer_list<T>> initlist)
            : elements_() {
            auto min_size = std::min(initlist.size(), N);
            auto itr = initlist.begin();
            
            for (auto i = 0; i < min_size; ++i, ++itr) {
                elements_[i] = sceef::row_vector<T, M>(*itr);
            }
        }

        template <class E>
        constexpr
        matrix(const sceef::matrix_expression<E>& expr): elements_() {
            for (auto i = 0; i < N; ++i) {
                for (auto j = 0; j < M; ++j) {
                    elements_[i][j] = expr[i][j];
                }
            }
        }

        constexpr
        auto size() const -> std::size_t {
            return N;
        }

        constexpr
        auto column_size() const -> std::size_t {
            return N;
        }

        constexpr
        auto row_size() const -> std::size_t {
            return M;
        }
        
        constexpr
        auto operator[](std::size_t index) -> sceef::row_vector<T, M>& {
            return elements_[index];
        }

        constexpr
        auto operator[](std::size_t index) const
            -> const sceef::row_vector<T, M>& {
            return elements_[index];
        }

        constexpr
        auto at(std::size_t index) -> sceef::row_vector<T, M>& {
            return elements_.at(index);
        }

        constexpr
        auto at(std::size_t index) const
            -> const sceef::row_vector<T, M>& {
            return elements_.at(index);
        }

        constexpr
        auto at(std::size_t i, std::size_t j) -> T& {
            return elements_.at(i).at(j);
        }

        constexpr
        auto at(std::size_t i, std::size_t j) const -> const T& {
            return elements_.at(i).at(j);
        }

        template <class E>
        constexpr
        auto operator=(const sceef::matrix_expression<E>& expr)
            -> decltype(auto) {
            for (auto i = 0; i < N; ++i) {
                for (auto j = 0; j < M; ++j) {
                    elements_[i][j] = expr[i][j];
                }
            }
            return *this;
        }

        template <class E>
        constexpr
        auto operator+=(const sceef::matrix_expression<E>& expr)
            -> decltype(auto) {
            for (auto i = 0; i < N; ++i) {
                for (auto j = 0; j < M; ++j) {
                    elements_[i][j] += expr[i][j];
                }
            }
            return *this;
        }

        template <class E>
        constexpr
        auto operator-=(const sceef::matrix_expression<E>& expr)
            -> decltype(auto) {
            for (auto i = 0; i < N; ++i) {
                for (auto j = 0; j < M; ++j) {
                    elements_[i][j] -= expr[i][j];
                }
            }
            return *this;
        }

        template <class U>
        constexpr
        auto operator*=(U value) -> decltype(auto) {
            for (auto i = 0; i < N; ++i) {
                for (auto j = 0; j < M; ++j) {
                    elements_[i][j] *= value;
                }
            }
            return *this;
        }

        template <class U>
        constexpr
        auto operator/=(U value) -> decltype(auto) {
            for (auto i = 0; i < N; ++i) {
                for (auto j = 0; j < M; ++j) {
                    elements_[i][j] /= value;
                }
            }
            return *this;
        }
        
    private:
        std::array<sceef::row_vector<T, M>, N> elements_;
    };
    
} // namespace sceef

#endif // SCEEF_MATRIX_HPP
