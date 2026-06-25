#include "integration_euler.h"

namespace math {

    KinematicState2 IntegrateEuler(const KinematicState2& state, const Vector2& forces, double dt, int steps) noexcept
    {
        KinematicState2 current = state;

		// Keep looping for the number of steps specified
        for (int i = 0; i < steps; ++i)
        {
            // Update velocity: v = v + a * dt
            // where a = forces (assuming mass = 1)
            current.velocity += forces * dt;

            // Update position: x = x + v * dt
            current.position += current.velocity * dt;
        }

        current.acceleration = forces;

        return current;
    }

}