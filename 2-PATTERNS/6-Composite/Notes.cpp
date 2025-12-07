/*

PATTERNS
- composite: component, composite, leaf

NOTES:

* composite: component, composite, leaf

    Motivation and Pattern:

    - Motivation: Sometimes you have simple components that are then
    used to compose bigger more complex components. Say a person is a simple
    component, but a family is a complex component that composes people.
    So why not abstract this composing of primitive and their composites into
    the class heiarchy.

    - Composite pattern - Abstract class that represents both primitive and their
    containers
        - Allows clients to treat them uniformly (Through polymorphic component pointer)
        
        - Encodes traversal of composition into hierarchy

    - Terms
        - Component - Abstract uniform interface class for both collections (composites)
        and primitive items (leafs)
        
        - Leaf - Concrete primitive class that does not aggregate components

        - Composite - Collection that possibly consists of leaves or other composits,
        implements interface and access (traversal) to children/parents

    - Leads to a tree like structure of components

    - Frequently used with Visitor Pattern where Composite implements traversal
    while Visitor implements prrocessing of individual elements

    Motivation in my words:

    Many times small things compose larger things that agregate these small things
    and act very similar. Think, a complex shape, composes many smaller shapes, but
    both have common ground as a shape. So why not set up a common shape interface 
    for them to both inherit. Then set up an interface for large things
    to agregate their smaller components, and an interface for small things
    that dont aggregate anything. The in common shape interface allows for the client
    to treat small and big things as one. While the specialized interfaces allow
    for a more in depth operation on these components.
    
    Technical Details:

    An AbstractComponent class is declared that holds the common interface for all
    components, both components that aggregate others and components that dont. Then
    a CompositeComponent interface is declared that outlines the interface for components
    that do aggregate other components. Usually implemented as Composites having a container
    compromised of AbstractComponent* pointers. So yes composites can compose other 
    components. Then defines a LeafComponent interface for components that dont aggregate
    other components. The end result is a tree like structure of components.

    This is often combined with visitor. Because AbstractComponent can defines a simple
    abstract accept(AbstractVisitor*) function, and then Component and Leaf interfaces
    can override this so that leaf allows for visitor to visit itself and component
    allows for visitor to visit itself and all its children. Then AbstractVisitor
    simple creates overloads of visit for both Leaf and Component. Then you can have
    modular operation and traversal of the component tree like structure without having
    to clutter any of the component interfaces.

*/