/*

Notions
- resource pool: reasons, situations

{Studied in Flyweight}

NOTES:

* resource pool: reasons, situations
    - pool - collection of resources to be kept ready to use
        - rather than acquired (allocated) when needed and 
        released (deallocated) when done
    
    - reasons
        - resource savings on acquisition and release
        - predictable time to obtain resources
    
    - situations
        - expensive to compute objects (graphics, fonts, bitmaps)
        - high rate of requests, predictable concurrent number of requests,
        can pre allocate these objects before request.
    
    - examples
        - thread pools

        - memory (RAM) pools

        - connection pools

    - Deeper why? Say you have objects that are read only and take up a gb
    of memory. These things are huge! If these objects are used often by multiple
    resources it would be very convenient to store them in a resource pool! Instead
    of allocating and deallocating them in memory everytime. Another example, say
    you have other large objects that are consumable by the objects that use them.
    Resource pool can preallocate these objects while it waits for objects to grab them.
    Making resource acquisition more responsive. Flyweight pattern is an implementation
    of resource pools given the first case. Second case is a seperate non-canonical 
    design pattern.

*/