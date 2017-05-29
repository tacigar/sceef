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

#ifndef SCEEF_OP_HPP
#define SCEEF_OP_HPP

namespace sceef {

    namespace op {

        struct add {
            template <class T>
            constexpr
            static auto apply(T lhs, T rhs) -> decltype(auto) {
                return lhs + rhs;
            }
        };

        struct subtract {
            template <class T>
            constexpr
            static auto apply(T lhs, T rhs) -> decltype(auto) {
                return lhs - rhs;
            }
        };

        struct multiply {
            template <class T>
            constexpr
            static auto apply(T lhs, T rhs) -> decltype(auto) {
                return lhs * rhs;
            }
        };

        struct divide {
            template <class T>
            constexpr
            static auto apply(T lhs, T rhs) -> decltype(auto) {
                return lhs / rhs;
            }
        };
        
        struct positive {
            template <class T>
            constexpr
            static auto apply(T value) -> decltype(auto) {
                return value;
            }
        };

        struct negative {
            template <class T>
            constexpr
            static auto apply(T value) -> decltype(auto) {
                return -value;
            }
        };
        
    } // namespace op
    
} // namespace sceef

#endif // SCEEF_OP_HPP
