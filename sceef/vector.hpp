/* =============================================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 * ============================================================================= */

#ifndef SCEEF_VECTOR_HPP
#define SCEEF_VECTOR_HPP

#include <sceef/vector_base.hpp>
#include <sceef/vector_tag.hpp>

namespace sceef {

	template <class T, std::size_t N>
	using vector = sceef::vector_base<T, N, sceef::vector_tag>;
	
} // namespace sceef

#endif // SCEEF_VECTOR_HPP
