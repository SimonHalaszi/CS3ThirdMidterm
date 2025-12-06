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

*/