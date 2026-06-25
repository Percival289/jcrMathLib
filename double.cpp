#include <ostream>
#include <iomanip>

namespace math {

    const int doublePrecision = 1;

    std::ostream& operator<<(std::ostream& os, const double& a)
    {
        os << std::fixed << std::setprecision(doublePrecision) << a << std::endl;

        return os;
    }
}