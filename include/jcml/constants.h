#pragma once

/*
    Contains a list of relevant constants for physics/engineering/math etc.
    Values are not rounded

    // TODO: Find a way to organize these
*/

namespace jcml::constants
{
    inline constexpr double pi              = 3.14159265358979323846;
    inline constexpr double tau             = 2.0 * pi;
    inline constexpr double half_pi         = pi * 0.5;

    inline constexpr double deg_to_rad      = pi / 180.0;
    inline constexpr double rad_to_deg      = 180.0 / pi;

    inline constexpr double e               = 2.71828182845904523536;

    inline constexpr double sqrt2     = 1.41421356237309504880;
    inline constexpr double sqrt3     = 1.73205080756887729353;

    inline constexpr double inv_pi     = 1.0 / pi;
    inline constexpr double inv_tau    = 1.0 / tau;

    inline constexpr double ln2       = 0.69314718055994530942;
    inline constexpr double ln10      = 2.30258509299404568402;

    inline constexpr double log2e     = 1.44269504088896340736;
    inline constexpr double log10e   = 0.43429448190325182765;

    // m/s^2
    constexpr double g = 9.80665;
}