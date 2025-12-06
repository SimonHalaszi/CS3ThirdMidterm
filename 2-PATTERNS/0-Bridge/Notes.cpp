/*

PATTERNS
- bridge: delegation, handle, body

NOTES:

* bridge: delegation, handle, body
    
    Motivation:
    
    - Typically, abstract interfaces are implemented using concrete implementation
    through inheritance
        - May not be flexible enough: permanently binds implementation of
        functionality to interface
    
    Pattern:
    
    - Decouples interface hierarchy from implementation hierarchy through
    delegation (pointer)
        - Abstract interface class, called the handle, refers to abstract
        implementor class, called the body.
        
        - Abstractions have concrete derived classes

        - Allows for runtime switching of implementation
    
    - Is a structural design pattern - controls relationships between classes

*/