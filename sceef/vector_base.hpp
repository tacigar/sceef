/* =============================================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 * ============================================================================= */

#ifndef SCEEF_VECTOR_BASE_HPP
#define SCEEF_VECTOR_BASE_HPP

#include <algorithm>
#include <array>
#include <cstddef>
#include <initializer_list>
#include <sceef/vector_base_expression.hpp>

namespace sceef {

	template <class T, std::size_t N, class Tag>
	class vector_base
		: public sceef::vector_base_expression<sceef::vector_base<
												   T, N, Tag>, Tag> {
	public:
		constexpr
		vector_base(): elements_() {
		}

		constexpr
		vector_base(std::initializer_list<T> initlist): elements_() {
			auto min_size = std::min(initlist.size(), N);
			auto itr = initlist.begin();

			for (auto i = 0; i < min_size; ++i, ++itr) {
				elements_[i] = *itr;
			}
		}

		template <class E>
		constexpr
		vector_base(const sceef::vector_base_expression<E, Tag> &expr): elements_() {
			for (auto i = 0; i < N; ++i) {
				elements_[i] = expr[i];
			}
		}

		constexpr
		auto size() -> decltype(auto) {
			return N;
		}
		
		constexpr
		auto operator[](std::size_t index) -> T& {
			return elements_[index];
		}

		constexpr
		auto operator[](std::size_t index) const -> const T& {
			return elements_[index];
		}

		constexpr
		auto at(std::size_t index) -> T& {
			return elements_.at(index);
		}

		constexpr
		auto at(std::size_t index) const -> const T& {
			return elements_.at(index);
		}

		template <class E>
		constexpr
		auto operator=(const sceef::vector_base_expression<E, Tag>& expr)
			-> decltype(auto) {
			for (auto i = 0; i < N; ++i) {
				elements_[i] = expr[i];
			}
			return *this;
		}

		template <class E>
		constexpr
		auto operator+=(const sceef::vector_base_expression<E, Tag>& expr)
			-> decltype(auto) {
			for (auto i = 0; i < N; ++i) {
				elements_[i] += expr[i];
			}
			return *this;
		}

		template <class E>
		constexpr
		auto operator-=(const sceef::vector_base_expression<E, Tag>& expr)
			-> decltype(auto) {
			for (auto i = 0; i < N; ++i) {
				elements_[i] -= expr[i];
			}
			return *this;
		}

	private:
		std::array<T, N> elements_;
	};
	
} // namespace sceef

#endif // SCEEF_VECTOR_BASE_HPP
