/*

PATTERNS
- prototype: clone

NOTES:

* prototype: clone

    Motivation and Pattern:

    - Creating objects from scratch may be undesirable
        - Too expensive

        - Little difference between newly created objects
        
        - Need to creat an object in a particular (prototype)
        state

    - Instead: Create a prototype obeject and creat a copy of
    it with a clone() operation
        - clone() returns the pointer to the copy of the prototype

    - Abstract prototype, defines prototype interface, allows
    clients to abstract from prototype details in the derived class
    implementations

    - clone() is virtual - Implemented in derived classes

    - Concrete clone may return a covariant type

    - Why can't we just use a copy constructor instead of clone()?
    Because C++ does not suppoert virtual constructors

    - Prototype is a creational pattern

    All that to say this pattern is basically how you create copy
    constructor for Abstract/Polymorphic interfaces. Which normally
    isnt possible.

    Motivation in my words:

    Copying an object is a very useful functionality. Sometimes thats
    not possible, say like in C++ where copy constructors can not be
    virtual. Prototype ensures the capability to copy dynamically
    allocated objects through polymorphic interfaces.
      
    Technical Details:

    AbstractPrototype outlines a clone() function that returns a
    AbstractPrototype* pointer. The ConcretePrototypes implements
    clone and uses type covariance to change the return type to
    its respective ConcretePrototype* pointer, then internally
    calls its own constructor to dynamically allocate a copy of itself
    using its current state. Then returns this dynamically allocated
    instance. Now you can clone objects polymorphically, either
    into a polymorphic pointer or into a concrete pointer.

*/