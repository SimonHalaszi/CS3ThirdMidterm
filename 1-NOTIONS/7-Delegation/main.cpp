/*

Notions
- delegation

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include "Delegation.hpp"
#include <iostream>

int main() {
    Delegator delegator(10, new Delegatee(10));
    std::cout << delegator.delegateToDelegatee() << std::endl;
}