#pragma once

#include "state2.h"
#include "vector2.h"

namespace math {

    /// <summary>
    /// Integrates a kinematic state forward in time using Euler integration.
    /// </summary>
    /// <param name="state">The current kinematic state</param>
    /// <param name="forces">The sum of forces applied to the object</param>
    /// <param name="dt">Time step for each integration step</param>
    /// <param name="steps">Number of integration steps to perform</param>
    /// <returns>The new kinematic state after integration</returns>
    KinematicState2 IntegrateEuler(const KinematicState2& state, const Vector2& forces, double dt, int steps) noexcept;
}