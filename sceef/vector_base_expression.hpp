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

#ifndef SCEEF_VECTOR_BASE_EXPRESSION_HPP
#define SCEEF_VECTOR_BASE_EXPRESSION_HPP

#include <cstddef>

namespace sceef {

    template <class Derived, class Tag>
    class vector_base_expression {
    public:
        constexpr
        auto size() const -> decltype(auto) {
            return (static_cast<Derived&>(*this)).size();
        }

        constexpr
        auto operator[](std::size_t index) -> decltype(auto) {
            return (static_cast<Derived&>(*this)).operator[](index);
        }

        constexpr
        auto operator[](std::size_t index) const -> decltype(auto) {
            return (static_cast<const Derived&>(*this)).operator[](index);
        }
        
        constexpr
        auto at(std::size_t index) -> decltype(auto) {
            return (static_cast<Derived&>(*this)).at(index);
        }
        
        constexpr
        auto at(std::size_t index) const -> decltype(auto) {
            return (static_cast<const Derived&>(*this)).at(index);
        }

        constexpr
        auto operator()() -> decltype(auto) {
            return static_cast<Derived&>(*this);
        }

        constexpr
        auto operator()() const -> decltype(auto) {
            return static_cast<const Derived&>(*this);
        }
    };

    template <class LE, class RE, class Tag>
    constexpr
    auto operator==(const sceef::vector_base_expression<LE, Tag>& lhs,
                    const sceef::vector_base_expression<RE, Tag>& rhs) -> decltype(auto) {
        for (auto i = 0; i < lhs.size(); ++i) {
            if (!sceef::equals(lhs[i], rhs[i])) {
                return false;
            }
        }
        return true;
    }

    template <class LE, class RE, class Tag>
    constexpr
    auto operator!=(const sceef::vector_base_expression<LE, Tag>& lhs,
                    const sceef::vector_base_expression<RE, Tag>& rhs) -> decltype(auto) {
        return !(lhs == rhs);
    }
    
} // namespace sceef

#endif // SCEEF_VECTOR_BASE_EXPRESSION_HPP
