/*

Notions
- UML class, object and state diagrams

NOTES:

* UML - Notation for supporting object-oriented program development
and documentation, language independent.

* Class Diagrams - Describe classes and class relationships
    - Class denoted by rectangle with three compartments: name, 
    attributes, and methods
    
    - Feature visibility:
        - '+' public
        - '-' private
        - '#' protected
    - Method syntax: 
        visibility name (parameters): returnType

    - Class associations - Represent responsibilities between classes
        - Denoted as a line
        - Line ends at classes with roles
            - May have multiplicity indicators: 0, *, 2, i < j
        - Aggregation - Special kind of association is whole/part-of
        relation
            - Denoted as hollow diamond
        - Composition - Part object may belong to only one whole object
        and lifetimes are the same
            - Denotes as filled diamond
    - Static features - underlined

    - Inheritance in UML denoted as line with hollow triangles pointing to base class

    - << guillemet >> or French quotes are used in UML and denote a 
    stereotype - A way to extend UML
        - Way to denote a design pattern concept in a diagram
        
    - Delegation - delegator object relying upon anothe delegatee object
    to provide functionality (Request)
        - Is an arrow in UML (In our class)
        - Dashed arrow is typical for delegation, Dashed arrow represents
        dependency.

* Object Diagram
    - Shows objecs and references/pointers as the program is executed

    - Notation
        - Round Rectangle - Object
            - Top: Name of object
            - Bottom: Member references/pointers
        - Filled Circle - Next to pointer/references
        - Arrow - Coming from filled circle pointing to object it aliases

    - Useful for illustrating layered design patterns like COR or Decorator

* State Diagram - Depicts an object transitions through states
    - An objects state is the whole of its values at any given time

    - Notation
        - Filled Circle - Initial state
        - Filled Circle with Ring around it - Final State
        - Rounded Rectangle - State
            - Top: Name of state
            - Bottom: Activities done in this state
        - Arrow - transition
            - Label in sqaure brackets - name of the event causing
            transition
            
    - Useful for illustrating state design pattern
        - Context goes through states
*/