#pragma once

#include "vector2.h"

namespace jcml {

    struct KinematicState2
    {

        // (x, y, z) Position
        Vector2 position;

        // (x, y, z) Velocity
        Vector2 velocity;

        // (x, y, z) Acceleration
        Vector2 acceleration;

    };



}