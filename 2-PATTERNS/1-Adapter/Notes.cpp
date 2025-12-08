/*

PATTERNS
- adapter: adaptee, adapter, interface; 
  class and object implementation

NOTES:

* adapter: adaptee, adapter, interface; 
  class and object implementation
    
    Motivation and Pattern:

    - If have interface class and an implementation class with incompatible 
    interface
        - Why not change implementation?
            - It might be good as it is, or used elsewhere
            - Could take extra effort, better to use code as it is

    - Adapter (Wrapper) - Concrete class that inherits from interface

    - Adaptee - Implementation class whose interface is modified (adapted)

    - Two Approaches
        - Class Adapter - Uses multiple inheritance
        
        - Object Adapter - Uses delegation from adapter to adaptee

    - Structural design pattern

    Difference between Adapter and Bridge
        - Patterns look similar
        
        - Difference is in usage
            - Bridge: build new class hierachy
            - Adapter: Modify existing classes to particular use

    Motivation in my words:

    When you want to make an old interface that is "good enough" conform
    to a new purpose by obscuring its interface and using it for a new
    one.

    You have a legacy class (adaptee) that is "good enough" to accomplish a task it
    just needs a little work. Instead of redefining this whole interface and
    rewriting the code for your slight changes, you can simply inherit this
    interface, or have an object of this legacy class, and wrap a new interface
    around it for added functionality. If inherting use a private inheritance
    so client doesnt get access to old interface. If using an object of this
    legacy class make it private. Call the functions of the legacy class inside
    your new interface (the adapter) to suit your needs. End result is exactly
    what you needed without tedious recoding and work. Think std::stack adapts
    std::deque.

    In short,

    Abstract Adapter interface defines the interface that will adapt
    the interface of the adaptee. Concrete Adapter either inherits adaptee
    class privately or has private object of it, then implements the Abstract
    Adapter interface using the adaptees functionality. Makes the old
    incompatible adaptee interface compatible for the adapter interface.

*/