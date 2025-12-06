/*

PATTERNS
- adapter: adaptee, adapter, interface; 
  class and object implementation

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include "Adapter.hpp"
#include <iostream>

int main() {
    /*
    Since both ClassAdapter and ObjectAdapter share the same AbstractAdapter interface
    we can use polymorphic pointer for them
    */
    AbstractAdapter* classAdapter = new ClassAdapter(10, 5);
    AbstractAdapter* objectAdapter = new ObjectAdapter(10, 5);

    // Wont work! Cannot use polymorphic pointer to point to derived class that inherits it privately
    // Adaptee* classAdapter = new ClassAdapter(10, 5);

    // Same interfacing for both
    std::cout << classAdapter->multiply() << std::endl;
    std::cout << objectAdapter->multiply() << std::endl;

    delete classAdapter;
    delete objectAdapter;
}