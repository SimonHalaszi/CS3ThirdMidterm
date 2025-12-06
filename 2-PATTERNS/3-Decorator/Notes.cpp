/*

PATTERNS
- decorator: decoration, component

NOTES:

* state: context, state abstract/concrete

    Motivation and Pattern:

    - Needs run-time extension (decoration) of functioanlity of
    an object (component)

    - May make new derived class, but is inflexible, what if needed 
    to change extend functionality at run-time?
        - i.e. need to add functionality a single object, not
        entire class

    - Approach: subclass decorator and then reference the original
    component
        - Decorator invokes the original component that methods
        optionally decorating it before or after invocation

    - Structural pattern

    - Componenets/Decorators can be abstract and concrete

    Think about it this way. The pattern kinda devolves into a backwards 
    linked list of functionality. Where the base component gets linked to
    by a decorator. And then the decorator gets linked to by another decorator,
    and so on. Eventually when you call the functionality on this last
    added decorator it travels down the linked list calling all the behavior
    of all the added decorators. And since the component doesnt link to anything
    the decoration ends.

*/