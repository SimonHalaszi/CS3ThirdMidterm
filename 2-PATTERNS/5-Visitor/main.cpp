/*

PATTERNS
- visitor: concrete/abstract element/visitor

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include "Visitor.hpp"
#include <iostream>

int main() {
    // Visitors
    HelloVisitor helloVisitor;
    CountingVisitor countingVisitor;

    // Polymorphic AbstractVisitor pointer that will be used to interface with concrete visitor instances
    AbstractVisitor* visitorPtr;

    // Elements
    CharElement charElement('d');
    IntElement intElement(10);

    // Polymorphic AbstractElement pointer that will be used to interface with concrete element instances
    AbstractElement* elementPtr;

    // Current element will be char element
    elementPtr = &charElement;
    
    // Current visitor will be helloVisitor
    visitorPtr = &helloVisitor;

    elementPtr->accept(visitorPtr);

    // Current visitor will be countingVisitor
    visitorPtr = &countingVisitor;

    elementPtr->accept(visitorPtr);

    // Repeat with intElement
    elementPtr = &intElement;
    visitorPtr = &helloVisitor;

    elementPtr->accept(visitorPtr);

    visitorPtr = &countingVisitor;

    // Behavior of accept changed everytime on the basis of two run-time bindings. It got doubly dispatched!
    elementPtr->accept(visitorPtr);

    std::cout << "Counting visitor visited " << countingVisitor.getAmountOfVisits() << " times." << std::endl;
}