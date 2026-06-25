#include "vector2.h"
#include <ostream>

namespace math {

    Vector2& Vector2::operator+=(const Vector2& rhs) noexcept
    {
        x += rhs.x;
        y += rhs.y;

        return *this;
    }


    Vector2& Vector2::operator+=(double rhs) noexcept
    {
        x += rhs;
        y += rhs;

        return *this;
    }


    Vector2 Vector2::operator+(const Vector2& rhs) const noexcept
    {
        Vector2 result = *this;
        result += rhs;
        return result;
    }


    Vector2 Vector2::operator+(double rhs) const noexcept
    {
        Vector2 result = *this;
        result += rhs;
        return result;
    }


    Vector2& Vector2::operator*=(double rhs) noexcept 
    {
        x *= rhs;
        y *= rhs;

        return *this;
    }


    Vector2 Vector2::operator*(double rhs) const noexcept
    {
        Vector2 result = *this;
        result *= rhs;
        return result;
    }


    double dot(const Vector2& lhs, const Vector2& rhs) noexcept
    {
        return lhs.x * rhs.x
             + lhs.y * rhs.y;
    }


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