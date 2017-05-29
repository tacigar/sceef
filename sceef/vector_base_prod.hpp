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

#ifndef SCEEF_VECTOR_BASE_PROD_HPP
#define SCEEF_VECTOR_BASE_PROD_HPP

namespace sceef {

    template <class LE, class LT, class RE, class RT>
    constexpr
    inline auto prod(const sceef::vector_base_expression<LE, LT>& lhs,
                     const sceef::vector_base_expression<RE, RT>& rhs) -> decltype(auto) {
        static_assert(LE::SIZE == RE::SIZE, "left hand's size != right hand's size.");
        
        decltype(lhs[0] * rhs[0]) sum = 0;
        for (auto i = 0; i < LE::SIZE; ++i) {
            sum += lhs[i] * rhs[i];
        }
        return sum;
    }
    
} // namespace sceef

#endif // SCEEF_VECTOR_BASE_PROD_HPP
