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

#ifndef SCEEF_MATRIX_UOP_HPP
#define SCEEF_MATRIX_UOP_HPP

#include <cstddef>
#include <sceef/matrix_expression.hpp>
#include <sceef/op.hpp>
#include <sceef/row_vector_uop.hpp>

namespace sceef {
    
    template <class Op, class E>
    class matrix_uop
        : public sceef::matrix_expression<sceef::matrix_uop<Op, E>> {
    public:
        static constexpr std::size_t SIZE = E::SIZE;
        static constexpr std::size_t COLUMN_SIZE = E::COLUMN_SIZE;
        static constexpr std::size_t ROW_SIZE = E::ROW_SIZE;

        constexpr
        matrix_uop(const E& expr): expr_(expr) {
        }

        constexpr
        auto size() const -> std::size_t {
            return SIZE;
        }

        constexpr
        auto column_size() const -> std::size_t {
            return COLUMN_SIZE;
        }

        constexpr
        auto row_size() const -> std::size_t {
            return ROW_SIZE;
        }

        constexpr
        auto operator[](std::size_t index) const -> decltype(auto) {
            return sceef::row_vector_uop<
                Op, decltype(expr_[index])>(expr_[index]);
        }
        
        constexpr
        auto at(std::size_t index) const -> decltype(auto) {
            return sceef::row_vector_uop<
                Op, decltype(expr_.at(index))>(expr_.at(index));
        }

        constexpr
        auto at(std::size_t i, std::size_t j) const -> decltype(auto) {
            return Op::apply(expr_.at(i, j));
        }
        
    private:
        const E& expr_;
    };

    template <class E>
    constexpr
    auto operator+(const sceef::matrix_expression<E>& expr)
        -> decltype(auto) {
        return sceef::matrix_uop<sceef::op::positive, E>(expr());
    }

    template <class E>
    constexpr
    auto operator-(const sceef::matrix_expression<E>& expr)
        -> decltype(auto) {
        return sceef::matrix_uop<sceef::op::negative, E>(expr());
    }
    
} // namespace sceef

#endif // SCEEF_MATRIX_UOP_HPP
