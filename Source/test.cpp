#include <iostream>

#include "vector2.h"
#include "vector3.h"

using namespace math;

int main()
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

    std::cout << "\n\nALL TESTS COMPLETED\n";

    return 0;
}