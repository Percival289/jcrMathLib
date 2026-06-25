#pragma once

#include "vector2.h"

namespace math {

    struct KinematicState2
    {

        // Positional
        Vector2 position;
        Vector2 velocity;
        Vector2 acceleration;


        // Rotational motion

        /*
        Vector2 angPosition;
        Vector2 angVelocity;
        Vector2 angAcceleration;
        */

    };

}