#pragma once

#include "kinematic_state2.h"
#include "vector2.h"

namespace jcml {

    // TODO: Add a # of steps so dt can be constant and you can look into the future (eg. find the state x steps ahead)

    // Simple Euler integration
    KinematicState2 IntegrateEuler(KinematicState2& state, double dt) noexcept 
    {

        state.velocity += state.acceleration * dt;
        state.position += state.velocity;

        return state;
    }

}