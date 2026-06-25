#pragma once


// Light version of iostream
#include <iosfwd>

namespace math {

    /*
    * Vector2
    * 
    * Represents a point or direction in 2-dimensional space.
    * 
    * Example:
    * 
    *   Vector2 position{ 10.0, 20.0 };
    * 
    * position.x = 10.0
    * position.y = 20.0
    * 
    */
    struct Vector2 {

        // Init to zero vectors by default

        // X component
        double x{};


        // Y component
        double y{};


        // Default constructor
        // Allows for creation of a zero vector:
        // Vector2 v;
        constexpr Vector2() noexcept = default;


        // Component constructor
        // Allows for creation of vector from components:
        // Vector2 v( 1.0, 2.0 );
        constexpr Vector2(double x, double y) noexcept : x(x), y(y) {}


        // Vector2 + Vector2
        Vector2 operator+(const Vector2& rhs) const noexcept;


        // Vector2 + scalar
        Vector2 operator+(double rhs) const noexcept;

        
        // Vector2 addition assignment
        Vector2& operator+=(const Vector2& rhs) noexcept;


        // Double addition assignment
        Vector2& operator+=(double rhs) noexcept;

    };


    // scalar + Vector2: allows for constant to be on either side
    Vector2 operator+(double lhs, const Vector2& rhs) noexcept;


    // Vector2 dot product
    double dot(const Vector2& lhs, const Vector2& rhs) noexcept;


    // Stream output operator, allows for vector to be written directly to streams
    std::ostream& operator<<(std::ostream&, const Vector2&);
}