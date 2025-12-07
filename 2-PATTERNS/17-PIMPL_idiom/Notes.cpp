/*

PATTERNS
- PIMPL idiom, motivation, handle/body

NOTES:

* PIMPL idiom, motivation, handle/body
    - C++ does not provide ways to hide class implementation
    details/data: Private part has to be declared
        - Clients include header file with class definition:
        exposed to implementation

    - Pointer to Implementation (PIMPL) idiom: AKA opaque pointer,
    d-pointer, cheshire cat idiom
        - In private (implementation) section of class provide
        reference (pointer) to actual implementation

        - When interface (public) methods are inbokes, invoke
        corresponding implementation methods using the pointer

        - Actual implementation class is defined and implemented
        in seperate file

    - Terms:
        - Handle - Class with exposed interface
        
        - Body - Implementation class

    - Specifics 
        - Body needs to be forward declared
        
        - Body is dynamically allocated - need to implement big
        three

        - Good practice is to nest body inside handle

    - Advantages
        - Encapsulated implementation, allows body modification
        without need to modify handle

        - Speeds up compilation, provides binary compatibility

    - Could be used in Memento and Bridge design pattern

    Motivation in my words:
  
    When you want to hide the actual functionality of a class from a client

    Technical Details:

    Similar to bridge there is a Body and Handle. Handle class defines functions
    that delegate all the work to the Body class. This Body class is privately
    declared inside of the Handle class and is implemented in a seperate file.
    The implementation of this Body class is responsibile for the actual state
    and functionality of the object and everything it does. Where as Handle
    just held a pointer to a dynamically allocated Body and delegated all the
    work. 

    Why is it like this?

    Well the Body is privately declared in the Handle so that the client can
    not create their own Body, only a Handle class can internally do that.
    As for the seperate file thing, thats so if the client goes to check out
    "Handle.hpp" they will see no actual implementation there. Just delegation
    of work to the Body.

    Note: Really the only thing Bridge in this have in common is the name Handle
    and Body, and that Handle delegates to Body. Otherwise the similarities arent
    really there. Bridge deals with potentially many Bodies that can be handled
    by a Handle and the run-time changing of this. Where as PIMPL just focues
    on using one Body to hide Handle implementation. Bridge does not attempt to 
    hide anything about the Body implementation.

    As for why anyone would do this? Its not just gatekeepy.

    If you make changes to the actual implementation Body then you only need to
    recompile the file that contains the Body implementation. Since nothing about
    the PIMPL file or the potentially large main file changes. So you have created
    a system that is capable of have wide spanning code base changes without
    having to recompile your codebase.

*/