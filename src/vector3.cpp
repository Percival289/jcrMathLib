#include "jcml/vector3.h"
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

    Vector3 operator*(double lhs, const Vector3& rhs) noexcept
    {
        return rhs * lhs;
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


    Vector3 Vector3::sqrtComponents() const noexcept
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


    Vector3 Vector3::normalized() const noexcept
    {
        const double m = mag();

        if (m == 0.0)
            return {};

        return *this / m;
    }


    double Vector3::dot(const Vector3& rhs) const noexcept
    {
        return x * rhs.x
             + y * rhs.y
             + z * rhs.z;
    }


    Vector3 Vector3::cross(const Vector3& rhs) const noexcept
    {
        return {
            y * rhs.z - z * rhs.y,
            z * rhs.x - x * rhs.z,
            x * rhs.y - y * rhs.x
        };
    }


    double distSquared(const Vector3& p1, const Vector3& p2) noexcept
    {
        const double dx = p2.x - p1.x;
        const double dy = p2.y - p1.y;
        const double dz = p2.z - p1.z;

        return dx * dx + dy * dy + dz * dz;
    }


    double dist(const Vector3& p1, const Vector3& p2) noexcept
    {
        return std::sqrt(distSquared(p1, p2));
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