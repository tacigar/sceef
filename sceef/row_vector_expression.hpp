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

#ifndef SCEEF_ROW_VECTOR_EXPRESSION_HPP
#define SCEEF_ROW_VECTOR_EXPRESSION_HPP

#include <sceef/row_vector_tag.hpp>
#include <sceef/vector_base_expression.hpp>

namespace sceef {

    template <class Derived>
    using row_vector_expression =
        sceef::vector_base_expression<Derived, sceef::row_vector_tag>;
    
} // namespace sceef

#endif // SCEEF_ROW_VECTOR_EXPRESSION_HPP
