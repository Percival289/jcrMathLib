#pragma once

#include "vector2.h"
#include "vector3.h"
#include <sstream>
#include <iomanip>
#include <string>

namespace math {


    /*
    * 
    * Convert double to string:
    *
    * Precision - difits after decimal place (or after conversion to scientific notation)
    * 
    */
    inline std::string to_string(double value, int precision = 3, bool sci_notation = false) {

        std::ostringstream ss;

        if (sci_notation) {
            ss << std::scientific;
        }
        else {
            ss << std::fixed;
        }

        ss << std::setprecision(precision)
            << value;

        return ss.str();

    }

}