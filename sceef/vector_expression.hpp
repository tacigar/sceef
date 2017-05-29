/* =============================================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 * ============================================================================= */

#ifndef SCEEF_VECTOR_EXPRESSION_HPP
#define SCEEF_VECTOR_EXPRESSION_HPP

#include <sceef/vector_base_expression.hpp>
#include <sceef/vector_tag.hpp>

namespace sceef {

    template <class Derived>
    using vector_expression =
        sceef::vector_base_expression<Derived, sceef::vector_tag>;
    
} // namespace sceef

#endif // SCEEF_VECTOR_EXPRESSION_HPP
