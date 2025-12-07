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

    Motivation in my words:

    You have a class (context) that wants to change functionality based on its
    state. Instead of having messy if/else statements or switch statements you
    delegate the semantics of what happens in that state to a state object.
    Context can define methods that will result in state transitions that call
    corresponding functions of the Abstract state interface so that transition
    semantics is handled by the state interface. Context may also just have 
    function that explicity changes state. Concrete states implement per state
    functionality that determine transitions as stated above, or behavior while
    in that state. States are usually implemented as singlestons as they usually do not
    hold any data in themselves. Just logic and functionality that are delegated
    to by the context. So multiple context are free to delegate to the same state
    at the same time. If the state does hold data, dont use singleton.

    In short,

    Context holds Abstract State pointer that it delegates to to handle per state
    operations such as transitions and functionality while in that state. Context
    interface implements methods that delegate work to the Abstract state pointer.
    Abstract State interface implements abstract methods for per state transitions
    and functionality. Concrete States actually implement the per state behavior.

*/