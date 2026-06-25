#include "vector2.h"
#include <ostream>
#include <cmath>

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


    Vector2 Vector2::sqrtComponents() const noexcept
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


    Vector2 Vector2::normalized() const noexcept
    {
        const double m = mag();

        if (m == 0.0)
            return {};

        return *this / m;
    }


    double Vector2::dot(const Vector2& rhs) const noexcept
    {
        return x * rhs.x
            + y * rhs.y;
    }


    double distSquared(const Vector2& p1, const Vector2& p2) noexcept
    {
        const double dx = p2.x - p1.x;
        const double dy = p2.y - p1.y;

        return dx * dx + dy * dy;
    }


    double dist(const Vector2& p1, const Vector2& p2) noexcept
    {
        return std::sqrt(distSquared(p1, p2));
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