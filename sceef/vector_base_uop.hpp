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

#ifndef SCEEF_VECTOR_BASE_UOP_HPP
#define SCEEF_VECTOR_BASE_UOP_HPP

namespace sceef {

    template <class Op, class E, class Tag>
    class vector_base_uop
        : public sceef::vector_base_expression<sceef::vector_base_uop<Op, E, Tag>, Tag> {
    public:
        static constexpr std::size_t SIZE = E::SIZE;

        constexpr
        vector_base_uop(const E& expr): expr_(expr) {
        }

        constexpr
        auto size() const -> std::size_t {
            return SIZE;
        }

        constexpr
        auto operator[](std::size_t index) const -> decltype(auto) {
            return Op::apply(expr_[index]);
        }
        
        constexpr
        auto at(std::size_t index) const -> decltype(auto) {
            return Op::apply(expr_.at(index));
        }

    private:
        const E& expr_;
    };

    template <class E, class Tag>
    constexpr
    auto operator+(const sceef::vector_base_expression<E, Tag>& expr)
        -> decltype(auto) {
        return sceef::vector_base_uop<sceef::op::positive, E, Tag>(expr());
    }

    template <class E, class Tag>
    constexpr
    auto operator-(const sceef::vector_base_expression<E, Tag>& expr)
        -> decltype(auto) {
        return sceef::vector_base_uop<sceef::op::negative, E, Tag>(expr());
    }
    
} // namespace sceef

#endif // SCEEF_VECTOR_BASE_UOP_HPP
