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
        - Single Dispatch - Selection based on a single object, supported
        in C++ using virtual functions

        - Double Dispatch - Selection based on multiple objects, not
        directly support by C++ but implemented using Visitor Design Pattern
        which goes something like this...

            // At funciton invocation
            // First disptach to find correct accept override for object baseElementPtr points to
                baseElementPtr->accept(baseVisitor* v);
            
            // In function body
                v->visit(this); // Second dispatch to find correct visit override for object v point it.

*/