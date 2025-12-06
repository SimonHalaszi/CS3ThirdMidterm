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

*/