/*

PATTERNS
- bridge: delegation, handle, body

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include "Bridge.hpp"

int main() {
    // Bridge design patterns allow for polymorphic handles
    AbstractHandle* handle = new NamedHandle("Handle", new IntBody(1));

    // Delegating to handle to do something
    handle->func();

    // Bridge design pattern allows for runtime change in functionality
    handle->changeBody(new CharBody('A'));

    // Delegating to handle to do something
    handle->func();

    // Body can also function on its own
    // Bridge design pattern also allows for polymorphic body pointers, thats how the implementation works
    AbstractBody* intBody = new IntBody(10);
    intBody->doSomething();
    delete intBody;

    // Clean up handle which deletes its currently held body
    delete handle;
}