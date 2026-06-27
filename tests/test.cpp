#include <iostream>
#include "math.h"
#include <chrono>
#include <fstream>

using namespace math;

const bool testVectors = false;
const bool testKinematics = false;

int main()
{
    if (testVectors)
    {
        std::cout << "=========================\n";
        std::cout << "VECTOR2 TESTS\n";
        std::cout << "=========================\n\n";

        Vector2 a(1.0, 2.0);
        Vector2 b(3.0, 4.0);

        std::cout << "a = " << a << '\n';
        std::cout << "b = " << b << '\n';

        std::cout << "\nADDITION\n";
        std::cout << "a + b = " << (a + b) << '\n';
        std::cout << "a + 5 = " << (a + 5.0) << '\n';

        std::cout << "\nSUBTRACTION\n";
        std::cout << "a - b = " << (a - b) << '\n';
        std::cout << "a - 2 = " << (a - 2.0) << '\n';

        std::cout << "\nMULTIPLICATION\n";
        std::cout << "a * 2 = " << (a * 2.0) << '\n';

        std::cout << "\nDIVISION\n";
        std::cout << "a / 2 = " << (a / 2.0) << '\n';

        std::cout << "\nCOMPOUND OPERATORS\n";

        Vector2 c = a;

        c += b;
        std::cout << "c += b -> " << c << '\n';

        c = a;
        c -= b;
        std::cout << "c -= b -> " << c << '\n';

        c = a;
        c *= 2.0;
        std::cout << "c *= 2 -> " << c << '\n';

        c = a;
        c /= 2.0;
        std::cout << "c /= 2 -> " << c << '\n';

        std::cout << "\nVECTOR FUNCTIONS\n";

        std::cout << "a.squared() = "
            << a.squared() << '\n';

        Vector2 sqrtTest2(4.0, 9.0);

        std::cout << "sqrt([4,9]) = "
            << sqrtTest2.sqrtComponents() << '\n';

        std::cout << "a.magSquared() = "
            << a.magSquared() << '\n';

        std::cout << "a.mag() = "
            << a.mag() << '\n';

        std::cout << "a.normalized() = "
            << a.normalized() << '\n';

        std::cout << "a.dot(b) = "
            << a.dot(b) << '\n';

        std::cout << "distSquared(a,b) = "
            << distSquared(a, b) << '\n';

        std::cout << "dist(a,b) = "
            << dist(a, b) << '\n';



        std::cout << "\n\n=========================\n";
        std::cout << "VECTOR3 TESTS\n";
        std::cout << "=========================\n\n";

        Vector3 p(1.0, 2.0, 3.0);
        Vector3 q(4.0, 5.0, 6.0);

        std::cout << "p = " << p << '\n';
        std::cout << "q = " << q << '\n';

        std::cout << "\nADDITION\n";
        std::cout << "p + q = " << (p + q) << '\n';
        std::cout << "p + 5 = " << (p + 5.0) << '\n';

        std::cout << "\nSUBTRACTION\n";
        std::cout << "p - q = " << (p - q) << '\n';
        std::cout << "p - 2 = " << (p - 2.0) << '\n';

        std::cout << "\nMULTIPLICATION\n";
        std::cout << "p * 3 = " << (p * 3.0) << '\n';

        std::cout << "\nDIVISION\n";
        std::cout << "p / 2 = " << (p / 2.0) << '\n';

        std::cout << "\nCOMPOUND OPERATORS\n";

        Vector3 r = p;

        r += q;
        std::cout << "r += q -> " << r << '\n';

        r = p;
        r -= q;
        std::cout << "r -= q -> " << r << '\n';

        r = p;
        r *= 2.0;
        std::cout << "r *= 2 -> " << r << '\n';

        r = p;
        r /= 2.0;
        std::cout << "r /= 2 -> " << r << '\n';

        std::cout << "\nVECTOR FUNCTIONS\n";

        std::cout << "p.squared() = "
            << p.squared() << '\n';

        Vector3 sqrtTest3(1.0, 4.0, 9.0);

        std::cout << "sqrt([1,4,9]) = "
            << sqrtTest3.sqrtComponents() << '\n';

        std::cout << "p.magSquared() = "
            << p.magSquared() << '\n';

        std::cout << "p.mag() = "
            << p.mag() << '\n';

        std::cout << "p.normalized() = "
            << p.normalized() << '\n';

        std::cout << "p.dot(q) = "
            << p.dot(q) << '\n';

        std::cout << "p.cross(q) = "
            << p.cross(q) << '\n';

        std::cout << "distSquared(p,q) = "
            << distSquared(p, q) << '\n';

        std::cout << "dist(p,q) = "
            << dist(p, q) << '\n';
    }

    if (testKinematics)
    {
        std::cout << "\n\n=========================\n";
        std::cout << "KINEMATICS TESTS\n";
        std::cout << "=========================\n\n";


        // Initialize state
        KinematicState2 state = { 
            { 0, 0 },
            { 5, 10 }
        };


        // Integrator setup for testing
        double dt = 0.01;
        double t = 1000;
        double steps = t / dt; // Divide time into steps based on dt


        // Display block
        std::cout << "Initial State: " << state.position << ", " << state.velocity << ", " << state.acceleration << "\n";
        std::cout << "Acceleration: " << state.acceleration << "\n";
        std::cout << "Time Step: " << dt << " s, Steps: " << steps << "\n\n";
        auto start = std::chrono::high_resolution_clock::now();


        // Open an output file for integration
        std::ofstream outputFileEuler;
        outputFileEuler.open("out_euler.txt");
        outputFileEuler << "X,Y";


        // Euler loop
        for (int i = 0; i < steps; i++) {

            state.acceleration = { 0, -9.81 };

            state = IntegrateEuler(state, dt);

            if (state.position.y <= 0.0) {
                break;
            }

            outputFileEuler << "\n" << state.position.x << "," << state.position.y;

        }
        

        // Close output file
        outputFileEuler.close();

        
        // Final runtime block
        std::cout << "Final position: " << state.position;
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "\n\nIntegrateEuler execution time: " << duration.count()/1000 << " ms" << std::endl;



        std::cout << "\n\nALL TESTS COMPLETED\n";

        return 0;
    }

    std::cout << math::pi;

    return 0;
}