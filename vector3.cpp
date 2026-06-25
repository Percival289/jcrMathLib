#include "vector3.h"
#include <ostream>
#include <cmath>

namespace math {

    Vector3& Vector3::operator+=(const Vector3& rhs) noexcept
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;

        return *this;
    }


    Vector3& Vector3::operator+=(double rhs) noexcept
    {
        x += rhs;
        y += rhs;
        z += rhs;

        return *this;
    }


    Vector3 Vector3::operator+(const Vector3& rhs) const noexcept
    {
        Vector3 result = *this;
        result += rhs;
        return result;
    }


    Vector3 Vector3::operator+(double rhs) const noexcept
    {
        Vector3 result = *this;
        result += rhs;
        return result;
    }


    Vector3& Vector3::operator-=(const Vector3& rhs) noexcept
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;

        return *this;
    }


    Vector3& Vector3::operator-=(double rhs) noexcept
    {
        x -= rhs;
        y -= rhs;
        z -= rhs;

        return *this;
    }


    Vector3 Vector3::operator-(const Vector3& rhs) const noexcept
    {
        Vector3 result = *this;
        result -= rhs;
        return result;
    }


    Vector3 Vector3::operator-(double rhs) const noexcept
    {
        Vector3 result = *this;
        result -= rhs;
        return result;
    }


    Vector3& Vector3::operator*=(double rhs) noexcept
    {
        x *= rhs;
        y *= rhs;
        z *= rhs;

        return *this;
    }


    Vector3 Vector3::operator*(double rhs) const noexcept
    {
        Vector3 result = *this;
        result *= rhs;
        return result;
    }


    Vector3& Vector3::operator/=(double rhs) noexcept
    {
        x /= rhs;
        y /= rhs;
        z /= rhs;

        return *this;
    }


    Vector3 Vector3::operator/(double rhs) const noexcept
    {
        Vector3 result = *this;
        result /= rhs;
        return result;
    }


    Vector3 Vector3::squared() const noexcept
    {
        return {
            x * x,
            y * y,
            z * z
        };
        
    }


    Vector3 Vector3::sqrt() const noexcept
    {
        return {
            std::sqrt(x),
            std::sqrt(y),
            std::sqrt(z)
        };
    }


    double Vector3::magSquared() const noexcept
    {
        return x * x
             + y * y
             + z * z;
    }


    double Vector3::mag() const noexcept
    {
        return std::sqrt(magSquared());
    }


    double Vector3::dot(const Vector3& rhs) const noexcept
    {
        return lhs.x * rhs.x
             + lhs.y * rhs.y
             + lhs.z * rhs.z;
    }


    Vector3 cross(const Vector3& lhs, const Vector3& rhs) noexcept
    {
        return {
            lhs.y * rhs.z - lhs.z * rhs.y,
            lhs.z * rhs.x - lhs.x * rhs.z,
            lhs.x * rhs.y - lhs.y * rhs.x
        };
    }


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