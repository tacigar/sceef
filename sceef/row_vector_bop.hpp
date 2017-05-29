/* =============================================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 * ============================================================================= */

#ifndef SCEEF_ROW_VECTOR_BOP_HPP
#define SCEEF_ROW_VECTOR_BOP_HPP

#include <sceef/row_vector_tag.hpp>
#include <sceef/vector_base_bop.hpp>

namespace sceef {
    
    template <class LE, class Op, class RE>
    using row_vector_bop = sceef::vector_base_bop<LE, Op, RE, sceef::row_vector_tag>;
    
} // namespace sceef

#endif // SCEEF_ROW_VECTOR_BOP_HPP
