#pragma once

// Light version of iostream
#include <iosfwd>

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
        Vector2& operator+=(const Vector2& rhs) noexcept;


        // Vector2 + scalar assignment
        Vector2& operator+=(double rhs) noexcept;

        // Vector2 + Vector2
        Vector2 operator+(const Vector2& rhs) const noexcept;


        // Vector2 + scalar
        Vector2 operator+(double rhs) const noexcept;


        // SUBTRACTION


        // Vector2 - Vector2 assignment
        Vector2& operator-=(const Vector2& rhs) noexcept;


        // Vector2 - scalar assignment
        Vector2& operator-=(double rhs) noexcept;

        // Vector2 - Vector2
        Vector2 operator-(const Vector2& rhs) const noexcept;


        // Vector2 - scalar
        Vector2 operator-(double rhs) const noexcept;


        // MULTIPLICATION


        // Scalar multiplication assignment
        Vector2& operator*=(double rhs) noexcept;


        // Scalar multiplication
        Vector2 operator*(double rhs) const noexcept;


        // DIVISION


        // Scalar divion assignment
        Vector2& operator/=(double rhs) noexcept;


        // Scalar division
        Vector2 operator/(double rhs) const noexcept;


        // VECTOR OPERATIONS


        // Vector2 ^ 2
        Vector2 squared() const noexcept;


        // Component-wise square root
        Vector2 sqrt() const noexcept;


        // Magnitude Squared
        double magSquared() const noexcept;


        // Magnitude
        double mag() const noexcept;


        // Vector2 Dot Product
        double dot(const Vector2& rhs) const noexcept;

    };


    // Stream output operator, allows for vector to be written directly to streams
    std::ostream& operator<<(std::ostream&, const Vector2&);
}