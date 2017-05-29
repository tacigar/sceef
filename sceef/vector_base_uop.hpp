/* =============================================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 * ============================================================================= */

#ifndef SCEEF_VECTOR_BASE_UOP_HPP
#define SCEEF_VECTOR_BASE_UOP_HPP

namespace sceef {

    template <class Op, class E, class Tag>
    class vector_base_uop
        : public sceef::vector_base_expression<sceef::vector_base_uop<Op, E, Tag>, Tag> {
    public:
        static constexpr std::size_t SIZE = E::SIZE;

        constexpr
        vector_base_uop(const E& expr): expr_(expr) {
        }

        constexpr
        auto size() const -> std::size_t {
            return SIZE;
        }

        constexpr
        auto operator[](std::size_t index) const -> decltype(auto) {
            return Op::apply(expr_[index]);
        }
        
        constexpr
        auto at(std::size_t index) const -> decltype(auto) {
            return Op::apply(expr_.at(index));
        }

    private:
        const E& expr_;
    };

    template <class E, class Tag>
    constexpr
    auto operator+(const sceef::vector_base_expression<E, Tag>& expr)
        -> decltype(auto) {
        return sceef::vector_base_uop<sceef::op::positive, E, Tag>(expr());
    }

    template <class E, class Tag>
    constexpr
    auto operator-(const sceef::vector_base_expression<E, Tag>& expr)
        -> decltype(auto) {
        return sceef::vector_base_uop<sceef::op::negative, E, Tag>(expr());
    }
    
} // namespace sceef

#endif // SCEEF_VECTOR_BASE_UOP_HPP
