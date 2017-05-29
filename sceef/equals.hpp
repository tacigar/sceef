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

#ifndef SCEEF_EQUALS_HPP
#define SCEEF_EQUALS_HPP

#include <algorithm>
#include <cmath>
#include <limits>
#include <type_traits>

namespace sceef {

    template <class T>
    auto fuzzy_equals(T lhs, T rhs) -> decltype(auto) {
        auto max_value = std::max(std::abs(lhs), std::abs(rhs));
        return std::abs(lhs - rhs) <=
            std::numeric_limits<T>::epsilon() * max_value;
    }

    template <class T>
    auto equals(T lhs, T rhs)
        -> typename std::enable_if<std::is_floating_point<T>::value, bool>::type {
        return fuzzy_equals(lhs, rhs);
    }

    template <class T>
    auto equals(T lhs, T rhs)
        -> typename std::enable_if<std::is_integral<T>::value, bool>::type {
        return lhs == rhs;
    }

} // namespace sceef

#endif // SCEEF_EQUALS_HPP
