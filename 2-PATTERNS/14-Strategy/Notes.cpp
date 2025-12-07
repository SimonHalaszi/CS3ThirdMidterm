/*

PATTERNS
- strategy: strategy, context, push/pull for strategy

NOTES:

* strategy: strategy, context, push/pull for strategy

    Motivation:

    - Many related classes differ only be their behavior,
    behavior may need to be changed at run-time, or behavior
    uses data (such as keys/passwords) to be hidden from clients

    Pattern:

    - Strategy Pattern - Encapsulates behavior into a class
        - Strategy - Behavior (Algorithm) to be encapsulated
            - Abstract - interface to algorithm

            - Concrete - Implementation of the algorithm

        - Context - Provides interface for clients to use strategies,
        either by initializing strategies with the context
        (Pull) or by allowing clients to delegate to strategies
        (Push).
    
    - Can have two communication methods
        - Push - Context provides all needed data to strategy

        - Pull - Strategy references context and gets data it needs

        - Communication named from the perspective of the context
            - In push strategy is pushed the information from context

            - In pull strategy references context and pulls information

    - Eliminates complex subclass hierarchy for behaviors

    - Elimated if/else behavior selection in the code

    - Behavioral pattern

    Motivation from how I see it. You have a perfectly good context object
    that you would like to implement run-time handling of its data to. Instead
    of cluttering this contexts interface you establish a strategy heirarchy that
    accesses the context already existing data members via push or pull, and then
    operates on that data to accomplish a task. This keeps the context interface
    clean while potentially countless amount of strategies can now operate on its
    data. In case of push only need to add a AbstractStrategy pointer and an
    execute function that gives the relevant data. And in case of pull you just
    need to implement setter and getter functions that are probably already part
    of the interface. In both approaches the implementation is simple and leads
    to a uncluttered context with countless possibilites for data operation. Though
    I personally favour the Pull method as it simply does not clutter the context
    interface at all as the needed functionality to support strategy is most likely
    already in the context. Though push is usually prefered because only relevant
    data is given to strategy and so strategy can not be used maliciously to cause
    sideffects.

    Motivation in my words:
  
    When you have an class (context) whose interface you wouldnt want to clutter
    with algorithms and operations on its member variables. Instead you delegate
    the functionality of these algorithms at run-time to a strategy that can perform
    any number of possible operations on the data you give to it.

    Technical Details:

    AbstractStrategy defines the interface for which context will use to execute
    the strategy. ConcreteStrategt defines the actual implementation of the
    Strategy and what operation that strategy will actually perform on the data.

    In the case of pull:
        AbstractStrategy defines execute function to have no parameters and 
        a private Context* pointer to the context whose data it will operate on.
        ConcreteStrategy will pull information from the Context using this 
        pointer in the implementation of execute it defines. ConcreteStrategies
        are initialized with their context or have their context switched.

    In the case of push:
        AbstractStrategy defines execute function to have the parameters of
        the data types from context it will operate on by reference. 
        ConcreteStrategies implement the actual operation on these elements.
        Context class needs to have a private AbstractStrategy* pointer, and
        a function that executes this strategy and feeds in its private data.

	Push adds more to the Context interface while keeping a tighter leash
    on what data Strategy gets. While pull doesnt add any clutter to the 
    Context interface if getters and setters exist but will have access
    to all the clients data.

*/