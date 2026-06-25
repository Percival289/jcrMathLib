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


    Vector2& Vector2::operator-=(const Vector2& rhs) noexcept
    {
        x -= rhs.x;
        y -= rhs.y;

        return *this;
    }


    Vector2& Vector2::operator-=(double rhs) noexcept
    {
        x -= rhs;
        y -= rhs;

        return *this;
    }


    Vector2 Vector2::operator-(const Vector2& rhs) const noexcept
    {
        Vector2 result = *this;
        result -= rhs;
        return result;
    }


    Vector2 Vector2::operator-(double rhs) const noexcept
    {
        Vector2 result = *this;
        result -= rhs;
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


    Vector2& Vector2::operator/=(double rhs) noexcept
    {
        x /= rhs;
        y /= rhs;

        return *this;
    }


    Vector2 Vector2::operator/(double rhs) const noexcept
    {
        Vector2 result = *this;
        result /= rhs;
        return result;
    }


    Vector2 Vector2::squared() const noexcept
    {
        return {
            x * x,
            y * y
        };

    }


    Vector2 Vector2::sqrt() const noexcept
    {
        return {
            std::sqrt(x),
            std::sqrt(y)
        };
    }


    double Vector2::magSquared() const noexcept
    {
        return x * x
            + y * y;
    }


    double Vector2::mag() const noexcept
    {
        return std::sqrt(magSquared());
    }


    double Vector2::dot(const Vector2& rhs) const noexcept
    {
        return x * rhs.x
            + y * rhs.y;
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