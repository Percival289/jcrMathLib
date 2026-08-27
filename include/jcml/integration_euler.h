#pragma once

#include "kinematic_state2.h"
#include "vector2.h"

namespace jcml {

    // Simple Euler integration
    KinematicState2 IntegrateEuler(KinematicState2& state, double dt) noexcept;

}