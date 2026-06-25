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

    std::cout << "\nAddition\n";
    std::cout << "a + b = " << (a + b) << '\n';
    std::cout << "a + 5 = " << (a + 5.0) << '\n';;

    std::cout << "\nMultiplication\n";
    std::cout << "a * 2 = " << (a * 2.0) << '\n';

    std::cout << "\nCompound Operators\n";

    Vector2 c = a;

    c += b;
    std::cout << "c += b -> " << c << '\n';

    c = a;
    std::cout << "c -= b -> " << c << '\n';

    c = a;
    c *= 2.0;
    std::cout << "c *= 2 -> " << c << '\n';

    c = a;
    std::cout << "c /= 2 -> " << c << '\n';

    std::cout << "\nDot Product\n";
    std::cout << "dot(a,b) = "
        << dot(a,b)
        << '\n';



    std::cout << "\n\n=========================\n";
    std::cout << "VECTOR3 TESTS\n";
    std::cout << "=========================\n\n";

    Vector3 p(1.0, 2.0, 3.0);
    Vector3 q(4.0, 5.0, 6.0);

    std::cout << "p = " << p << '\n';
    std::cout << "q = " << q << '\n';

    std::cout << "\nAddition\n";
    std::cout << "p + q = " << (p + q) << '\n';
    std::cout << "p + 5 = " << (p + 5.0) << '\n';

    std::cout << "\nMultiplication\n";
    std::cout << "p * 3 = " << (p * 3.0) << '\n';

    std::cout << "\nCompound Operators\n";

    Vector3 r = p;

    r += q;
    std::cout << "r += q -> " << r << '\n';

    r = p;
    std::cout << "r -= q -> " << r << '\n';

    r = p;
    r *= 2.0;
    std::cout << "r *= 2 -> " << r << '\n';

    r = p;
    std::cout << "r /= 2 -> " << r << '\n';

    std::cout << "\nDot Product\n";
    std::cout << "dot(p,q) = "
        << dot(p,q)
        << '\n';

    std::cout << "\n\nAll tests completed.\n";

    return 0;
}