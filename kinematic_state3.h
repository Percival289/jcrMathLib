#pragma once

#include "vector3.h"

namespace math {

    struct KinematicState3
    {

        // Positional
        Vector3 position;
        Vector3 velocity;
        Vector3 acceleration;


        // Rotational motion

        /*
        Vector3 angPosition;
        Vector3 angVelocity;
        Vector3 angAcceleration;
        */
       
    };

}