/*

Notions
- C++11 style type casting, static_cast vs. dynamic_cast; 
  reinterpret_cast; const_cast

{Studied in Bridge}

NOTES:

* C++11 style type casting {Studied in Bridge}
    - typeof_cast<new_type>(expression)

* static_cast vs. dynamic_cast {Studied in Bridge}
    - static_cast<new_type>(expression) - Compile time casting
    (early binding for pointers, wont check if polymorphic pointer
    is actually to object of class its being casted to)

    - dynamic_cast<new_type>(expression) - Run time casting (vtable
    is consulted), if incorrect returns nullptr and throws std::bad_cast for references.
    Must be ran an polymorphic types. If base class doesnt have virtuals,
    vtable not generated, and dynamic_cast wont compile. new_type must be pointer or reference.
        
        Uses cases given: Dr1 and Dr2 derive from Base and OtherClass is not related at all...

        Base* ptr = new Dr1;

        Dr1* dr1ptr;
        Dr2* dr2ptr;
        Base* baseptr;

        OtherClass* ocptr;

        dr1ptr = dynamic_cast<Dr1*>(ptr); // Success returns dynamically allocated obj
        dr2ptr = dynamic_cast<Dr2*>(ptr); // Illegal returns nullptr

        baseptr = dynamic_cast<Base*>(dr1ptr); // Succes, returns dynamically allocated obj

        baseptr = dynamic_cast<Base*>(ptr); // Succes, returns dynamically allocated obj, though redundant

        ocptr = dynamic_cast<OtherClass*>(ptr); // Illegal returns nullptr

        Given Base was never actually a polymorphic interface (Did not have virtuals) then...

        dr1ptr = dynamic_cast<Dr1*>(ptr); // Would not even compile. Putting non polymorphic pointer into cast is compile-time error
        
    - reinterpret_cast<new_type>(expression) - No type checking, potentially unsafe.
    Compile time reinterpretting of the literal bytes of a object into another type.
    If expression object is longer in byte length than new_type the extra bytes get
    dropped. new_type must be pointer or reference.

    - const_cast<new_type> - adds const-ness to a non const variable, and can safely
    remove this added const-ness. Removing const-ness from a const variable, will be unsafe
    and is undefined. new_type must be pointer or reference. Primary use case is getting
    rid of const modifier if non-const variable was passed into function by const reference.

* Old-Stlye casting {Studied in Bridge}
    - newtype(expression) or (newtype)expression

    - Tries static -> dynamic -> reinterpret
        - Since it eventually goes to reinterpret it is unsafe

*/