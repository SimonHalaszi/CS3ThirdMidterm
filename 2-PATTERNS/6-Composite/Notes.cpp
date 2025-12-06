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

*/