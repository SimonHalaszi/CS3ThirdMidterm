/*

Notions
- C++11 enum classes

NOTES:

* C++11 enum classes {Studied in Prototype}
    - Enumeration: A type whose values are distinct constants
    called enumerators

    - Unscoped enumeration declaration (before C++11)
        enum UnscopedEnums {enum1, enum2, enum3};

    - Whats twong with unscoped enumeration?
        - enumerators are unscoped (Name collision):
            enum UnscopedEnums1 {enum1, enum2, enum3};

            enum UnscopedEnums2 {enum3, enum4, enum5}; // is illegal
        
        - enumerators are untyped (Unrelated enums can be treated as same type)
            UnscopedEnums1 myEnum1 = enum1; UnscopedEnums2 myEnum2 = enum4;
            if(myEnum1 != myEnum2) // is legal

    - Scoped enumeration
        enum class ScopedEnums {enum1, enum2, enum3};

        - Now enumerations are scoped and typed.
        
        - Can be refered to using a scope ScopedEnums::enum1

        - C++20: may import enumerator with using to later omit scope

*/