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
        : public sceef::vector_base_expression<sceef::vector_base<T, N, Tag>, Tag> {
    public:
        static constexpr std::size_t SIZE = N;

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
        auto size() const -> decltype(auto) {
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

        template <class U>
        constexpr
        auto operator*=(U value) -> decltype(auto) {
            for (auto i = 0; i < N; ++i) {
                elements_[i] *= value;
            }
            return *this;
        }

        template <class U>
        constexpr
        auto operator/=(U value) -> decltype(auto) {
            for (auto i = 0; i < N; ++i) {
                elements_[i] /= value;
            }
            return *this;
        }
            

    private:
        std::array<T, N> elements_;
    };
    
} // namespace sceef

#endif // SCEEF_VECTOR_BASE_HPP
