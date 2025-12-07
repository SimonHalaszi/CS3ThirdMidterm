/*

PATTERNS
- nested classes

NOTES:

* nested classes {Studiend in PIMPL}
    - Nested class is a class declared inside another class

    - Inner class
        - Scope is the enclosing class
            - Scope limitation is the pimary purpose for this construct
            
    - If object or method is mentioned outside of enclosing class, need
    to resolve the scope

    - Can be private or public

    - Can be forward declared and then defined outside
        - If forward declared, the forward declaration should be inside
        the enclosing class definition (Elaborated type specifier does
        not work)

    - Has access to private/public members of enclosing class

    - Enclosing class has no access to private members of inner class

*/