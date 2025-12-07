/*

PATTERNS
- prototype: clone

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include "Prototype.hpp"
#include <iostream>

int main() {
    // Concrete prototypes can be interfaced differently
    IntPrototype ip(10);
    ip.printState(); std::cout << std::endl;
    
    CharPrototype* cp = new CharPrototype('c');
    cp->printState(); std::cout << std::endl;

    // AbstractInterface pointer can be used to handle all concrete clones
    AbstractInterface* ai = ip.clone();
    std::cout << std::endl;
    
    ai->printState(); std::cout << std::endl;
    delete ai;

    ai = cp->clone();
    std::cout << std::endl;

    ai->printState(); std::cout << std::endl;
    delete ai;

    delete cp;

    // Can clone into pointer of derived type as well
    IntPrototype* ipClone = ip.clone();
    std::cout << std::endl;
    
    ipClone->printState(); std::cout << std::endl;
    delete ipClone;
}