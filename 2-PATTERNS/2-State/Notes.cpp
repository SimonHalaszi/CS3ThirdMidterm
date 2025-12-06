/*

PATTERNS
- state: context, state abstract/concrete

NOTES:

* state: context, state abstract/concrete

    Motivation and Pattern:    

    - Problem - Object's behavior depends on a state it is in
        - Usually implemented as a sequence of cases of a switch statement
            - This is in elegant, difficult to observe and modify

    - State design pattern - Provides extensibility and cleaner interface to
    state transitions
        - Context - "Concentrator" class whose objects actually have states,
        passes operations to the state class
            - Not aware of the number and relationships between states
            
            Clients interact with context

        - State - Abstract class representing state with the set of abstract
        operations on states

        - Concrete states - Implement abstract operations, including changing
        of the state
            - Usually implemented as singletons - Object may be in only one
            state. States are only focused on being delegated to for functionality.
            They dont carry a payload. So we dont need to worry about many different
            context conflicting eachother while using the only instance.

    - State is a behavioral design pattern - Prescribes behavior between objects
        - Object design pattern - uses object composition
            - Class design pattern (like Template Method) uses class hierachy

    
    Context only needs to handle generic state changes and a singular state pointer.
    This generic state change just needs to delegate the corresponding state change to
    the state pointer.

    Actual semantics of the state changes implemented by each individual concrete state,
    as well as the behavior of the context based on that state.

    Allows for more dynamic and modular behavior in state changes of an object. 

    And if implemented also means that the context can have potentially many states with
    potentially many different behaviors. Leading to even more complex and deep classes.

*/