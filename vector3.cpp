#include "vector3.h"
#include <ostream>

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


    Vector3 Vector3::operator*=(double rhs) noexcept
    {
        x *= rhs;
        y *= rhs;
        z *= rhs;

        return *this;
    }


    Vector3& Vector3::operator*(double rhs) const noexcept
    {
        Vector3 result = *this;
        result *= rhs;
        return result;
    }


    double dot(const Vector3& lhs, const Vector3& rhs) noexcept
    {
        return lhs.x * rhs.x
             + lhs.y * rhs.y
             + lhs.z * rhs.z;
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