/*

PATTERNS
- PIMPL idiom, motivation, handle/body

c++ main.cpp PIMPL.cpp
./a.out > output.txt
rm ./a.out

*/

#include "PIMPL.hpp"
#include <iostream>

int main() {
    // Interface with this class normally
    Handle handle;
    handle.setData(10);
    std::cout << handle.getData() << std::endl;

    handle.setData(20);
    std::cout << handle.getData() << std::endl;

    /*
    But if I as a client try and see what is going on inside of
    "PIMPL.hpp" I learn nothing!. Only that handle delegates to
    Body. But what body actually does once getting delegated to
    is beyond me.
    */
}