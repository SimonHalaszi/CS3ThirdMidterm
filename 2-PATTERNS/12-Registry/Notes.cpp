/*

PATTERNS
- registry: canonical vs. non-canonical pattern, 
  use, implementation

NOTES:

* registry: canonical vs. non-canonical pattern, 
  use, implementation

    Motivation and Pattern:

    - Non-Canonical (Not out of Gamma et al) design pattern.
    
    - Described by Martin Fowler in "Patterns of Enterprise
    Application Architecture"

    - Well-known object that other objects use to find command
    objects and services
    
        - Used in flyweight, so that client can retrieve immutable
        expensive objects from the registry.
        
        - Also used in one of our implementations of observer
            - Where known Subjects are used to alert their set of Observers

    - Details
        - Registry is usually a global object (Static member of a class)
        
        - May be implemented as Singleton

        - Objects to be looked up register with the registry
        
        - Object lookup is performed by a key

        - Key-ed map is often used as implementation

        - May be used to pass information to objects without look up
            - As in the Observer implementation

    - Evaluation
        - Global object - creates external dependencies

        - May be preferred to passing them around as parameters
            - Say as in non-registry observer where observers must be
            initialized with the subject they want to observe

    Motivation in my words:

    Kinda already went over in depth in other patterns. But its very
    convenient to have a static registry that can map one program
    wide thing to other things.
      
    Technical Details:

	A, usually singleton, registry holds a static map of keys that
    refer to items that need to be retrieved program wide. Registry
    implements functions for removing and adding keys and their
    corresponding items from the registry.

    In Observer, Subject* keys were used to map to their corresponding
    set of Observers that Observerd their changes. And registry gave
    methods to register and deregister a Observer to a Subject, and a method
    for a Subject to notify all of its observers.

    In Flyweight, Flyweights with expensive and large intrisic data were
    keyed to by identifiers and the Registry handled the creation
    of Flyweights as they were needed and the returning of Flyweights
    that keys were put in. Though this registry did not handle removing 
    and deleting Flyweights from it.

*/