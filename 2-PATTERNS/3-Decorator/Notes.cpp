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

    Motivation in my words:

    When you need to layer functionality on top of an object form this layer
    of functionality by delegating to the next object that adds it in a chain
    of functionality additions.

    Often times you want to layer functionality onto a class. Instead of
    inheriting this class and adding more, which isnt flexible and cant
    be dont at run-time, you can use decorator. Decorator forms a run-time
    backwardly linked list of functionality. Where decorators, that inherit
    a common base component, reference other components (which may be decorators
    or the base component). When a decorator invokes its decoration function,
    it does the funcionality it adds, then delegates to the component it
    references to to additional decoration or to end the decoration if the
    component is the base component.

    In short,

    Base component defines virtual function that decorators will override.
    Decorators inherit the base compoonent interface and override this
    function to add additional functionality (decoration). Decorators also
    hold a Base Component pointer so that they can delegate to the next
    decorator for the functionality it adds. Since base component doesnt delegate,
    the traversal of decoration down this linked list ends at it.

*/