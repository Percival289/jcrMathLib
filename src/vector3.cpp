#include "jcml/vector3.h"
#include <ostream>
#include <cmath>

namespace math {





















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































}