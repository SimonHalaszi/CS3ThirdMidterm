/*

Notions
- type covariance

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include "Type_Covariance.hpp"
#include <iostream>

int main() {
    Base* ptr = new Derived(10);

    std::cout << "Base* ptr = new Derived(10);" << std::endl;
    
    std::cout << "ptr->printState(); "; ptr->printState();

    Base* copyPtr = ptr->clone();

    std::cout << "Base* copyPtr = ptr->clone();" << std::endl;
    
    std::cout << "copyPtr->printState(); "; copyPtr->printState();

    delete ptr;
    delete copyPtr;
}