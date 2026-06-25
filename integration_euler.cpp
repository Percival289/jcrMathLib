#include "integration_euler.h"


// DEBUGGING
#include <chrono>
#include <iostream>

namespace math {

    KinematicState2 IntegrateEuler(const KinematicState2& state, const Vector2& forces, double dt, int steps) noexcept
    {
        auto start = std::chrono::high_resolution_clock::now();

        KinematicState2 current = state;

        // Pre-compute dt * forces to avoid recalculation
        const Vector2 velocityDelta = forces * dt;

        for (int i = 0; i < steps; i++)
        {

            current.velocity += velocityDelta;
            current.position += current.velocity * dt;
        }

        current.acceleration = forces;
        

		// DEBUGGING: Measure execution time
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "IntegrateEuler execution time: " << duration.count() << " microseconds" << std::endl;


        return current;
    }

}