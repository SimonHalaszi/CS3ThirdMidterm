/*

PATTERNS
- facade: facade, subsystem

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include "Facade.hpp"
#include <string>

int main() {
    // Facade with clean interface
    Facade facade;

    facade.printBoolClass(false, 540);
    facade.printBoolClass(true, 10);
    facade.printCharClass('d', 43);
    facade.printStringClass("Hello There", 54);

    // Much cleaner for client to use than this alternative

    BoolClass bc(false, 540);
    bc.print();
    bc.setBool(true);
    bc.setInt(10);
    bc.print();
}