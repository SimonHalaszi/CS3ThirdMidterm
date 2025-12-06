/*

PATTERNS
- chain of responsibility: handler, successor

NOTES:

* chain of responsibility: handler, successor

    Motivation and Pattern:

    - Have the (handlers) able to handle a request
        - With limited abilities to handle it (responsibility)

        - If one handler cannot handle request, needs to pass it on to next

    - This chain of responsibility is formed at run-time and maintained by
    the base handler

    - Base class keeps track of the chain of handlers
        - Dispatches to next handler if previous pushes it up

    - Behavioral pattern

    Results in forwardly linked list at run-time where if first handler
    can not handle the request in its override, it then consults the base 
    implementation which will proceed to the next handler if it exist, if not 
    does not proceed marking the end of the chain of responsibility. 
    
    Dont need to do the whole using previous override trick, but then would
    need to recode that logic in every handleRequest override.

*/