#pragma once

#include <iosfwd>

namespace math {

	/*
	* Vector3 (x,y,z):
	*
	*	Represents a point or direction in 3-dimensional space.
	*
	*	Example:
	*
	*		Vector2 position{ 10.0, 20.0, 12.0 };
	*
	*	position.x = 10.0
	*	position.y = 20.0
	*	position.z = 12.0
	*
	*/
	struct Vector3 {

		// Init to zero vector by default

		// X Component
		double x{};
		// Y Component
		double y{};
		// Z Component
		double z{};


		/*
		* Default Constructor
		* 
		* Allows for creation of zero vector:
		* 
		*	Vector3 v;  ->  v = { 0, 0, 0 }
		*/

		constexpr Vector3() noexcept = default;


		/*
		* Component constructor
		* 
		* Allows for creation of vector from components:
		* 
		*	Vector3 v( 1.0, 2.0, 4.0);
		*/

		constexpr Vector3(double x, double y, double z) noexcept : x(x), y(y), z(z) {}


		// ADDITION


		// Vector3 + Vector3 assignment
		Vector3& operator+=(const Vector3& rhs) noexcept;


		// Vector3 + scalar assignment
		Vector3& operator+=(double rhs) noexcept;
		

		// Vector3 + Vector3
		Vector3 operator+(const Vector3& rhs) const noexcept;


		// Vector3 + scalar
		Vector3 operator+(double rhs) const noexcept;


		// SUBTRACTION


		// Vector3 - Vector3 assignment
		Vector3& operator-=(const Vector3& rhs) noexcept;


		// Vector3 - scalar assignment
		Vector3& operator-=(double rhs) noexcept;


		// Vector3 - Vector3
		Vector3 operator-(const Vector3& rhs) const noexcept;


		// Vector3 - scalar
		Vector3 operator-(double rhs) const noexcept;


		// MULTIPLICATION


		// Scalar multiplication assignment
		Vector3& operator*=(double rhs) noexcept;

		// Scalar multiplication
		Vector3 operator*(double rhs) const noexcept;


		// DIVISION


		// Scalar division assignment
		Vector3& operator/=(double rhs) noexcept;


		// Scalar division
		Vector3 operator/(double rhs) const noexcept;


		// VECTOR OPERATIONS


		// Vector3 ^ 2
		Vector3 squared() const noexcept;


		// Component-wise square root
		Vector3 sqrt() const noexcept;


		// Magnitude squared
		double magSquared() const noexcept;


		// Magnitude
		double mag() const noexcept;


		// Vector3 Dot Product
		double dot(const Vector3& rhs) const noexcept;


		// Vector3 Cross Product
		Vector3 cross(const Vector3& rhs) const noexcept;

	};


	// Clean vector output for iostream
	std::ostream& operator<<(std::ostream&, const Vector3&);
}