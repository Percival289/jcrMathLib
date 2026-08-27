#pragma once

#include <ostream>
#include <cmath>

namespace jcml {

	/*
	* Vector3 (x,y,z):
	*
	*	Represents a point or direction in 3-dimensional space.
	*
	*	Example:
	*
	*		Vector3 position{ 10.0, 20.0, 12.0 };
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
		Vector3& operator+=(const Vector3& rhs) noexcept
		{
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;

			return *this;
		}


		// Vector3 + scalar assignment
		Vector3& operator+=(double rhs) noexcept
		{
			x += rhs;
			y += rhs;
			z += rhs;

			return *this;
		}
		

		// Vector3 + Vector3
        Vector3 operator+(const Vector3& rhs) const noexcept
        {
            Vector3 result = *this;
            result += rhs;
            return result;
        }


		// Vector3 + scalar
        Vector3 operator+(double rhs) const noexcept
        {
            Vector3 result = *this;
            result += rhs;
            return result;
        }



		// SUBTRACTION


		// Vector3 - Vector3 assignment
        Vector3& operator-=(const Vector3& rhs) noexcept
        {
            x -= rhs.x;
            y -= rhs.y;
            z -= rhs.z;

            return *this;
        }


		// Vector3 - scalar assignment
        Vector3& operator-=(double rhs) noexcept
        {
            x -= rhs;
            y -= rhs;
            z -= rhs;

            return *this;
        }


		// Vector3 - Vector3
        Vector3 operator-(const Vector3& rhs) const noexcept
        {
            Vector3 result = *this;
            result -= rhs;
            return result;
        }


		// Vector3 - scalar
        Vector3 operator-(double rhs) const noexcept
        {
            Vector3 result = *this;
            result -= rhs;
            return result;
        }


		// MULTIPLICATION


		// Scalar multiplication assignment
        Vector3& operator*=(double rhs) noexcept
        {
            x *= rhs;
            y *= rhs;
            z *= rhs;

            return *this;
        }

		// Scalar multiplication
		Vector3 operator*(double rhs) const noexcept
        {
            Vector3 result = *this;
            result *= rhs;
            return result;
        }


		// DIVISION


		// Scalar division assignment
        Vector3& operator/=(double rhs) noexcept
        {
            x /= rhs;
            y /= rhs;
            z /= rhs;

            return *this;
        }


		// Scalar division
        Vector3 operator/(double rhs) const noexcept
        {
            Vector3 result = *this;
            result /= rhs;
            return result;
        }


		// VECTOR OPERATIONS


		// Vector3 ^ 2
		[[nodiscard]]
        Vector3 squared() const noexcept
        {
            return {
                x * x,
                y * y,
                z * z
            };
            
        }


		// Component-wise square root
		[[nodiscard]]
        Vector3 sqrtComponents() const noexcept
        {
            return {
                std::sqrt(x),
                std::sqrt(y),
                std::sqrt(z)
            };
        }


		// Magnitude squared
		[[nodiscard]]
        double magSquared() const noexcept
        {
            return x * x
                + y * y
                + z * z;
        }


		// Magnitude
		[[nodiscard]]
        double mag() const noexcept
        {
            return std::sqrt(magSquared());
        }


		// Normalized vector (unit vector)
		[[nodiscard]]
        Vector3 normalized() const noexcept
        {
            const double m = mag();

            if (m == 0.0)
                return {};

            return *this / m;
        }


		// Vector3 Dot Product
		[[nodiscard]]
        double dot(const Vector3& rhs) const noexcept
        {
            return x * rhs.x
                + y * rhs.y
                + z * rhs.z;
        }


		// Vector3 Cross Product
		[[nodiscard]]
        Vector3 cross(const Vector3& rhs) const noexcept
        {
            return {
                y * rhs.z - z * rhs.y,
                z * rhs.x - x * rhs.z,
                x * rhs.y - y * rhs.x
            };
        }


	};


	// Angle 3D (euler angles)

	// Vector2 Distance Squared
	[[nodiscard]]
	double distSquared(const Vector3& p1, const Vector3& p2) noexcept
	{
		const double dx = p2.x - p1.x;
		const double dy = p2.y - p1.y;
		const double dz = p2.z - p1.z;

		return dx * dx + dy * dy + dz * dz;
	}

	// Vector3 Distance
	[[nodiscard]]
	double dist(const Vector3& p1, const Vector3& p2) noexcept
	{
		return std::sqrt(distSquared(p1, p2));
	}


	// Clean vector output for iostream
	std::ostream& operator<<(std::ostream& os, const Vector3& vec)
    {
        os << "[ "
            << vec.x
            << ", "
            << vec.y
            << ", "
            << vec.z
            << " ]";

        return os;
    }
}