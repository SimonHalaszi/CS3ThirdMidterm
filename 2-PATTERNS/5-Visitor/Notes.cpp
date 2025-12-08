/*

PATTERNS
- visitor: concrete/abstract element/visitor

NOTES:

* visitor: concrete/abstract element/visitor

    Motivation and Pattern:

    - Seperates data from operations on the data by defining visitor
    class that implements the operations
        - Allows to easily add the operations since they are added to visitor

    - Participants
        - Element - Has accept(visitor) method that takes visitor as argument,
        calls visit(this) method of the visitor, element passes itself to the
        visit(element) method

        - Visitor - defines visit(element) with parameter corresponding to the
        partivular concrete element

    - When accept(visitor) is invoked, its implementation is based on type of
    concrete element

    - When visit(element) within accept(visitor) is invoked, its implementation is
    based on
        - Concrete type of the visitor
        - Concrete type of the element (pass as parameter to visit()), that is,
        the implementation depends on two objects (double dispatch)

    Behavioral Pattern

    Motivation in my words:

    You have a class (element) whose interface you dont want to clutter with a bunch of 
    functions that operate on its data. So instead of adding a bunch of functions to 
    this class you define another class (visitor) that is accepted to visit your class 
    by getting passed your class. 
    
    Technical Details:

    Define an AbstractElement interface that defines an accept function that takes in an 
    AbstractVisitor*. The AbstractVisitor interface defines a function named visit
    that will be overloaded based for each of the ConcreteElements you define. 
    This function takes in ConcreteElement*. Now in the ConcreteElements you can override 
    this accept function to call the visit function of the AbstractVisitor interface with 
    'this' pointer. ConcreteVisitors are free to override these visit overloads to have
    per ConcreteVisitor implementations details of what they do when they visit the 
    ConcreteElement.

    You now have a simple AbstractElement interface, it just defines one function
    accept, and you now have an unlimited number of possibilities of operating on all
    ConcreteElements, given a visit overload exist for them, without cluttering the interface
    at all. This is a modular approach to the problem stated in the motivation that 
    uses double dispatch (Two run-time bindings are consulted in order to determine
    what visitor override and what visit overload will be invoked).

*/