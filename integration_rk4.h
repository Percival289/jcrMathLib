#pragma once

#include "kinematic_state2.h"
#include "vector2.h"


namespace math {

    /*
    * RK4 Integrator
    *
    * Generic fourth-order Runge-Kutta integrator.
    *
    * This integrator can be used with ANY state type,
    * provided that the state supports:
    *
    *      state + state
    *      state * scalar
    *
    * and a derivative function is supplied that returns
    * the time derivative of the state.
    *
    * Example:
    *
    *      OrbitalState state;
    *
    *      state = IntegrateRK4(
    *          state,
    *          currentTime,
    *          dt,
    *          GravityDerivative);
    *
    */

    template<typename State, typename Derivative>
    State IntegrateRK4( const State& state, double time, double dt, Derivative derivative) noexcept
    {

        const State k1 = derivative(time, state);

        const State k2 = derivative(time + dt * 0.5, state + k1 * (dt * 0.5));

        const State k3 = derivative(time + dt * 0.5, state + k2 * (dt * 0.5));

        const State k4 = derivative(time + dt, state + k3 * dt);



        /*
        * Combine slopes according to the
        * classical RK4 weighting:
        *
        * y(n+1) =
        * y(n)
        * + dt/6 *
        * (
        *      k1
        *    + 2*k2
        *    + 2*k3
        *    + k4
        * )
        */

        return state +
            (
                k1 +
                k2 * 2.0 +
                k3 * 2.0 +
                k4
                )
            * (dt / 6.0);
    }

}