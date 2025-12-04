/*

Notions
- base/derived classes, inheritance, virtual functions, pure virtual
  functions, abstract classes, access methods invoking overriden
  function in an overriding function

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include "Inheritance.hpp"

int main() {
    Base* ptr;

    ptr = new Derived(10);

    ptr->func();

    delete ptr;

    ptr = new DerivedAgain(20);

    ptr->func();

    delete ptr;

    DerivedAgain dAObj(30);

    dAObj.func();

    dAObj.Derived::func(); // Invoking Derived override of func() using scope resolution
}