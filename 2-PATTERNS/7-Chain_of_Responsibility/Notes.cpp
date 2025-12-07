/*

PATTERNS
- chain of responsibility: handler, successor

NOTES:

* chain of responsibility: handler, successor

    Motivation and Pattern:

    - Have the (handlers) able to handle a request
        - With limited abilities to handle it (responsibility)

        - If one handler cannot handle request, needs to pass it on to successor

    - This chain of responsibility is formed at run-time and maintained by
    the base handler

    - Base class keeps track of the chain of handlers
        - Dispatches to successor handler if previous pushes it up

    - Behavioral pattern

    Results in forwardly linked list at run-time where if first handler
    can not handle the request in its override, it then consults the base 
    implementation which will proceed to the successor handler if it exist, if not 
    does not proceed marking the end of the chain of responsibility. 
    
    Dont need to do the whole using previous override trick, but then would
    need to recode that logic in every handleRequest override.

    Motivation in my words:

    When you want functionality of a function to be handled differently at
    run-time depending on some sort of priority (responsibility) of the
    inputted data
    
    Technical Details:

    A BaseHandler is declared that defines a BaseHandler* successor. BaseHandler
    also defines a virtual function that handles the data given to it. In the 
    BaseHandle implementation this function just checks if the successor exists
    and if it does it will delegate the functionality to it. If it does not the
    chain stops and nothing was able to handle the data. The classes that derive
    the BaseHandler then override this function. If the inputted data meets
    their responsibility condition then they handle the request. If it does not
    then the derived handler calls the base implementation of the handle function
    with the data. Successor that was defined in base class will either point to 
    another derived successor that may be able to handle the request. The chain
    of responsibility checks follows logically.

*/