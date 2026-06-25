#pragma once

#include <iosfwd>

namespace math {
	struct Vector3 {

		double x{};
		double y{};
		double z{};

		constexpr Vector3() noexcept = default;

		constexpr Vector3(double x, double y, double z) noexcept : x(x), y(y) {}

		Vector3 operator+(const Vector3& rhs) const noexcept;

		Vector3 operator+(double rhs) const noexcept;

		Vector3& operator+=(const Vector3& rhs) noexcept;

		Vector3& operator+=(double rhs) noexcept;
	};

	Vector3 operator+(double lhs, const Vector3& rhs) noexcept;

	double dot(const Vector3& lhs, const Vector3& rhs) noexcept;

	std::ostream& operator<<(std::ostream&, const Vector3&);
}