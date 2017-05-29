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

#ifndef SCEEF_VECTOR_BASE_BOP_HPP
#define SCEEF_VECTOR_BASE_BOP_HPP

#include <cstddef>
#include <sceef/op.hpp>
#include <sceef/vector_base_expression.hpp>

namespace sceef {

    template <class LE, class Op, class RE, class Tag>
    class vector_base_bop
        : public sceef::vector_base_expression<sceef::vector_base_bop<LE, Op, RE, Tag>, Tag> {
    public:
        static_assert(LE::SIZE == RE::SIZE, "left hand's size != right hand's size.");
        static constexpr std::size_t SIZE = LE::SIZE;

        constexpr
        vector_base_bop(const LE& lhs, const RE& rhs)
            : lhs_(lhs), rhs_(rhs) {
        }

        constexpr
        auto size() const -> std::size_t {
            return SIZE;
        }

        constexpr
        auto operator[](std::size_t index) const -> decltype(auto) {
            return Op::apply(lhs_[index], rhs_[index]);
        }
        
        constexpr
        auto at(std::size_t index) const -> decltype(auto) {
            return Op::apply(lhs_.at(index), rhs_.at(index));
        }

    private:
        const LE& lhs_;
        const RE& rhs_;
    };

    template <class LE, class RE, class Tag>
    constexpr
    auto operator+(const sceef::vector_base_expression<LE, Tag>& lhs,
                   const sceef::vector_base_expression<RE, Tag>& rhs) -> decltype(auto) {
        return sceef::vector_base_bop<LE, sceef::op::add, RE, Tag>(lhs(), rhs());
    }

    template <class LE, class RE, class Tag>
    constexpr
    auto operator-(const sceef::vector_base_expression<LE, Tag>& lhs,
                   const sceef::vector_base_expression<RE, Tag>& rhs) -> decltype(auto) {
        return sceef::vector_base_bop<LE, sceef::op::subtract, RE, Tag>(lhs(), rhs());
    }
    
} // namespace sceef

#endif // SCEEF_VECTOR_BASE_BOP_HPP
