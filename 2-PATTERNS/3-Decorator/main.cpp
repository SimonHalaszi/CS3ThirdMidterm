/*

PATTERNS
- decorator: decoration, component

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include "Decorator.hpp"

int main() {
    // Base component
    Component* base = new Component();
    base->operation();

    // Pretty decorator using polymorphic component pointer. Allocated using base.
    Component* pretty = new PrettyDecorator(base);
    pretty->operation();

    // Ugly decorator using polymorphic component pointer. Allocated using pretty.
    Component* uglyPretty = new UglyDecorator(pretty);
    uglyPretty->operation();

    delete uglyPretty;

    /*
    Base component and decorators share the same interface. And the functionality of 
    this interface is extended by decorators at run-time.
    */
}