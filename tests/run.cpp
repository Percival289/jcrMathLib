#include <jcml/jcml.h>

#include <iostream>

using namespace jcml;

int main() {
    Vector3 a(8,-4,3);
    Vector3 b(5,0,-9);
    Vector3 c(6,9,-2);

    /*
    std::cout << "\n\na + b:    " << a + b;
    std::cout << "\n\n4a + 2b:  " << a * 9.0 + b * 3.0;
    std::cout << "\n\n|a|:      " << a.magReadable();
    std::cout << "\n\n|a - b|:  " << (a-b).magReadable();
    */

    std::cout << "\n\nnorm:     " << c.normalizedReadable();
}