#pragma once

#include <ostream>
#include <cmath> // TODO: Implement sqrt

namespace math {

    /*
    * Vector2 (x,y):
    * 
    *   Represents a point or direction in 2-dimensional space.
    * 
    *   Example:
    * 
    *       Vector2 position{ 10.0, 20.0 };
    * 
    *   position.x = 10.0
    *   position.y = 20.0
    * 
    */
    struct Vector2 {

        // Init to zero vector by default

        // X Component
        double x{};
        // Y Component
        double y{};

        /*
        * Default Constructor
        *
        * Allows for creation of zero vector:
        *
        *	Vector2 v;  ->  v = { 0, 0 }
        */

        constexpr Vector2() noexcept = default; 


        /*
        * Component constructor
        *
        * Allows for creation of vector from components:
        *
        *	Vector2 v( 1.0, 2.0);
        */

        constexpr Vector2(double x, double y) noexcept : x(x), y(y) {}


        // ADDITION


        // Vector2 + Vector2 assignment
        Vector2& operator+=(const Vector2& rhs) noexcept
        {
            x += rhs.x;
            y += rhs.y;

            return *this;
        }


        // Vector2 + scalar assignment
        Vector2& operator+=(double rhs) noexcept
        {
            x += rhs;
            y += rhs;

            return *this;
        }

        // Vector2 + Vector2
        Vector2 operator+(const Vector2& rhs) const noexcept
        {
            Vector2 result = *this;
            result += rhs;
            return result;
        }


        // Vector2 + scalar
        Vector2 Vector2::operator+(double rhs) const noexcept
        {
            Vector2 result = *this;
            result += rhs;
            return result;
        }


        // SUBTRACTION


        // Vector2 - Vector2 assignment
        Vector2& Vector2::operator-=(const Vector2& rhs) noexcept
        {
            x -= rhs.x;
            y -= rhs.y;

            return *this;
        }


        // Vector2 - scalar assignment
        Vector2& Vector2::operator-=(double rhs) noexcept
        {
            x -= rhs;
            y -= rhs;

            return *this;
        }

        // Vector2 - Vector2
        Vector2 operator-(const Vector2& rhs) const noexcept
        {
            Vector2 result = *this;
            result -= rhs;
            return result;
        }


        // Vector2 - scalar
        Vector2 operator-(double rhs) const noexcept
        {
            Vector2 result = *this;
            result -= rhs;
            return result;
        }


        // MULTIPLICATION


        // Scalar multiplication assignment
        Vector2& operator*=(double rhs) noexcept 
        {
            x *= rhs;
            y *= rhs;

            return *this;
        }

        // Scalar multiplication
        Vector2 operator*(double rhs) const noexcept
        {
            Vector2 result = *this;
            result *= rhs;
            return result;
        }



        // DIVISION


        // Scalar divion assignment
        Vector2& operator/=(double rhs) noexcept
        {
            x /= rhs;
            y /= rhs;

            return *this;
        }

        // Scalar division
        Vector2 operator/(double rhs) const noexcept
        {
            Vector2 result = *this;
            result /= rhs;
            return result;
        }



        // VECTOR OPERATIONS


        // Vector2 ^ 2
        [[nodiscard]]
        Vector2 squared() const noexcept
        {
            return {
                x * x,
                y * y
            };

        }


        // Component-wise square root
        [[nodiscard]]
        Vector2 sqrtComponents() const noexcept
        {
            return {
                std::sqrt(x),
                std::sqrt(y)
            };
        }


        // Magnitude Squared
        [[nodiscard]]
        double magSquared() const noexcept
        {
            return x * x
                + y * y;
        }


        // Magnitude
        [[nodiscard]]
        double mag() const noexcept
        {
            return std::sqrt(magSquared());
        }



        // Normalized vector (unit vector)
        [[nodiscard]]
        Vector2 normalized() const noexcept
        {
            const double m = mag();

            if (m == 0.0)
                return {};

            return *this / m;
        }


        // Vector2 Dot Product
        [[nodiscard]]
        double dot(const Vector2& rhs) const noexcept
        {
            return x * rhs.x
                + y * rhs.y;
        }

    };


    // Angle 2D


    // Vector2 Distance
    [[nodiscard]]
    double dist(const Vector2& p1, const Vector2& p2) noexcept
    {
        return std::sqrt(distSquared(p1, p2));
    }


    // Vector2 Distance Squared
    [[nodiscard]]
    double distSquared(const Vector2& p1, const Vector2& p2) noexcept
    {
        const double dx = p2.x - p1.x;
        const double dy = p2.y - p1.y;

        return dx * dx + dy * dy;
    }


    // Stream output operator, allows for vector to be written directly to streams
    std::ostream& operator<<(std::ostream& os, const Vector2& vec)
    {
        os << "[ "
            << vec.x
            << ", "
            << vec.y
            << " ]";

        return os;
    }
}