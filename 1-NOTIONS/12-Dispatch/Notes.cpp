/*

Notions
- multiple, double dispatch

{Studied in Visitor}

NOTES:

* multiple, double dispatch
    - Static Dispatch - Compile time selection of which version
    of the polymorphic function to execute. In C++ this is done
    with scope resolution. Say...

        DerivedClass d;
        d.BaseClass::func();
        d.DerivedClass::func();

    Overload resolution is a static dispatch.
    
    - Dynamic dispatch - run-time selection
        - Single Dispatch - Selection based on type of single object, supported
        in C++ using virtual functions

        - Double Dispatch - Selection based on type of multiple objects, not
        directly support by C++ but implemented using Visitor Design Pattern
        which goes something like this...

            // At funciton invocation
            // First disptach to find correct accept override for object baseElementPtr points to
                baseElementPtr->accept(baseVisitor* v);
            
            // In function body
                v->visit(this); // Second dispatch to find correct visit override for object v point it.

        Why double dispatch? To allow you to add functionality to element without having to clutter its interface.
        Visitor can operate on an element and its data seperately by being accepted to visit. Elements interface stays
        clean, just needs to add one accept function that takes in polymorphic visitor pointer. And visitors can have
        multiple overloads for every derived version of element. Now element, and its derived classes, share a similar
        interface of operation without have to clutter their own interfaces. And now visitor provides a modular solution
        to the problem.

*/