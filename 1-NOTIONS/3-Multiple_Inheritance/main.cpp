/*

Notions
- multiple inheritance; private vs. public inheritance, 
  making a private method of base class public

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include "Multiple_Inheritance.hpp"

int main() {
    DerivedPublic dPubObj;

    dPubObj.funcBaseOne(); // Base class feature using public inheriting of base class interface
    dPubObj.funcBaseTwo(); // Base class feature using public inheriting of base class interface
    dPubObj.funcBaseOneProtected(); // Protected Base Class feature added to public interface using the 'using' keyword

    DerivedPrivate dPrvObj;

    dPrvObj.funcBaseOne(); // Base class feature using the 'using' keword after inherting base class interface privately
    dPrvObj.funcBaseTwo(); // Base class feature using public inheriting of base class interface
    dPrvObj.funcBaseOneProtected(); // Protected Base Class feature added to public interface using the 'using' keyword
}