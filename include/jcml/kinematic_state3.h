#pragma once

#include "vector3.h"

namespace math {

	/*
    * 
    * 3D Kinematic State :
    * 
	* Holds the position, velocity, and acceleration of an object in 3D space.
    * 
    */

    struct KinematicState3
    {

		// (x, y, z) Position
        Vector3 position;

		// (x, y, z) Velocity
        Vector3 velocity;

		// (x, y, z) Acceleration
        Vector3 acceleration;

    };

}