#include "integration_euler.h"

namespace math {

    KinematicState2 IntegrateEuler(KinematicState2& state, double dt) noexcept
    {

        state.velocity += state.acceleration * dt;
        state.position += state.velocity;

        return state;
    }

}