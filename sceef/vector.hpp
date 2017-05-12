/* ============================================================
 * Copyright (c) 2016 tacigar. All rights reserved.
 * https://github.com/tacigar/sceef
 * ============================================================ */

#ifndef SCEEF_VECTOR_HPP
#define SCEEF_VECTOR_HPP

#include <algorithm>
#include <array>
#include <iterator>
#include <sceef/vector_expression.hpp>

namespace sceef {

	template <class T, int N>
	class Vector
		: public VectorExpression<Vector<T, N> > {
	public:
		static constexpr int SIZE = N;

	private:
		using ContainerType = std::array<T, N>;

	public:
		Vector() : storage_() {
		}

		Vector(std::initializer_list<T> initList) : storage_() {
			auto minSize = std::min(static_cast<int>(initList.size()), N);
			auto itr = std::begin(initList);

			for (int i = 0; i < minSize; i++, itr++) {
				storage_[i] = *itr;
			}
		}

		template <class Expression>
		Vector(const VectorExpression<Expression>& expression) : storage_() {
			for (int i = 0; i < N; i++) {
				storage_[i] = expression.at(i);
			}
		}

		T& operator [] (int index) {
			return storage_[index];
		}

		const T& operator [] (int index) const {
			return storage_[index];
		}

		T& at(int index) {
			return storage_[index];
		}

		const T& at(int index) const {
			return storage_[index];
		}

		template <class Expression>
		auto operator = (const VectorExpression<Expression>& expression) -> decltype(auto) {
			for (int i = 0; i < N; i++) {
				storage_[i] = expression.at(i);
			}
			return *this;
		}

		template <class Expression>
		auto operator += (const VectorExpression<Expression>& expression) -> decltype(auto) {
			for (int i = 0; i < N; i++) {
				storage_[i] += expression.at(i);
			}
			return *this;
		}

		template <class Expression>
		auto operator -= (const VectorExpression<Expression>& expression) -> decltype(auto) {
			for (int i = 0; i < N; i++) {
				storage_[i] -= expression.at(i);
			}
			return *this;
		}

		template <class Expression>
		auto operator *= (const VectorExpression<Expression>& expression) -> decltype(auto) {
			for (int i = 0; i < N; i++) {
				storage_[i] *= expression.at(i);
			}
			return *this;
		}

		template <class Expression>
		auto operator /= (const VectorExpression<Expression>& expression) -> decltype(auto) {
			for (int i = 0; i < N; i++) {
				storage_[i] /= expression.at(i);
			}
			return *this;
		}

	private:
		ContainerType storage_;
	};

} // namespace sceef

#endif // SCEEF_VECTOR_HPP
