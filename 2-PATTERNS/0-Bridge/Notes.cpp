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

    Motivation in my words:

    You have a class (the handle) that wants to implements a functionality and its
    associated variables. This will add clutter to this classes interface and
    might make the code harder to read. This process might also might not be
    modular. Some tasks require the same core variables and interface but need
    different specific implementations. So instead of adding this functionality
    to the class itself or creating multiple classes to acheive similar task you
    can create a new class that handles this functionality and its variables
    (the body) and gets delegated work and data for this functionality to it. 
    That way the orginal class interface remains clean while also getting new 
    modular functionality.

    In short,

    Handle class delegates to a body class for functionality, data, and operations.
    Handle can have its own class hierarchy and body can have its own class hierarchy
    for added modularity. Abstract handle class defines pointer to abstract body
    class that will be used for this delegation. Respective concrete classes implement
    specifics.

*/