#pragma once

#include <ostream>
#include <sstream>
#include <string>

#include <cmath>

// TODO: Convert to template

namespace jcml {

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
        Vector2 operator+(double rhs) const noexcept
        {
            Vector2 result = *this;
            result += rhs;
            return result;
        }


        // SUBTRACTION


        // Vector2 - Vector2 assignment
        Vector2& operator-=(const Vector2& rhs) noexcept
        {
            x -= rhs.x;
            y -= rhs.y;

            return *this;
        }


        // Vector2 - scalar assignment
        Vector2& operator-=(double rhs) noexcept
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


        // Negation
        Vector2 operator-() const noexcept
        {
            return {
                -x,
                -y
            };
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


        // Scalar division assignment
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


        // Component-wise square
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


        [[nodiscard]]
        std::string magReadable() const
        {
            double m = mag();
            std::ostringstream oss;
            if (floor(m) == m) {
                // Magnitude is a whole number, show that
                oss << m;
            } else {
                // Magnitude is an irrational number, show a readable version instead
                oss << "sqrt(" << magSquared() << ")";
            }

            return oss.str();
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


        // Normalized vector READABLE (unit vector)
        [[nodiscard]]
        std::string normalizedReadable() const noexcept
        {
            double m = mag();
            std::ostringstream oss;
            if (floor(m) == m) {
                // Magnitude is a whole number, show that

                oss << "[ " 
                    << this->x << "/" << m
                    << ", "
                    << this->y << "/" << m
                    << " ]";

            } else {
                // Magnitude is an irrational number, show a readable version instead

                oss << "[ "
                << this->x << "/" << "sqrt(" << magSquared() << ")"
                << ", "
                << this->y << "/" << "sqrt(" << magSquared() << ")"
                << " ]";

            }

            return oss.str();
        }

        
        // Vector2 Dot Product
        [[nodiscard]]
        double dot(const Vector2& rhs) const noexcept
        {
            return x * rhs.x
                + y * rhs.y;
        }


    };


    // TODO: Angle 2D between 2 vectors


    // Vector2 Distance Squared
    [[nodiscard]]
    inline double distSquared(const Vector2& p1, const Vector2& p2) noexcept
    {
        const double dx = p2.x - p1.x;
        const double dy = p2.y - p1.y;

        return dx * dx + dy * dy;
    }


    // Vector2 Distance
    [[nodiscard]]
    inline double dist(const Vector2& p1, const Vector2& p2) noexcept
    {
        return std::sqrt(distSquared(p1, p2));
    }


    // Stream output operator, allows for vector to be written directly to streams
    inline std::ostream& operator<<(std::ostream& os, const Vector2& vec)
    {
        os << "[ "
            << vec.x
            << ", "
            << vec.y
            << " ]";

        return os;
    }
}