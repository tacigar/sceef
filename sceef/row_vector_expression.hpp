/* =============================================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
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
