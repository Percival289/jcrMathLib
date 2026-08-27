#include "integration_euler.h"

namespace jcml {

    KinematicState2 IntegrateEuler(KinematicState2& state, double dt) noexcept
    {

        state.velocity += state.acceleration * dt;
        state.position += state.velocity;

        return state;
    }

}