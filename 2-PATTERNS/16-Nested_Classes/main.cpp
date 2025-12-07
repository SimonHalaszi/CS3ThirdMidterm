/*

PATTERNS
- nested classes

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include "Nested.hpp"
#include <iostream>

int main() {
    // Can declare object of enclosing class
    EnclosingClass encloser(10, 14, 20);
    std::cout << encloser.addInnies() << std::endl;

    // Can declare object of inner public class
    EnclosingClass::InnerPublicClass inny(10);
    std::cout << inny.getInt() << std::endl;

    // Can NOT declare object of inner private class (Even though EnclosingClass could)
    // EnclosingClass::InnerPrivateClass inny2(10);
    // std::cout << inny.getInt() << std::endl;
}