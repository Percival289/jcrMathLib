#pragma once

/*
    Utilities that don't need their own file

        - Conversions
        - I/O functions

        etc...
*/


#include <sstream>
#include <iomanip>
#include <string>

namespace jcml {

    // TODO: Convert to scientific notation and rounding/precision in-library
    /*
    * Convert double to string:
    *
    * value (double)        - value being displayed, in raw format (eg. 1234.56)
    * precision (int)       - digits after decimal place (or after conversion to scientific notation)
    * sci_notation (bool)   - choose whether the value is shown in scientific notation (eg. 3x10^2)
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