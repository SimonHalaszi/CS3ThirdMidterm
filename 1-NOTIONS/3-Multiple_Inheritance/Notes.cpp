/*

Notions
- multiple inheritance; private vs. public inheritance, 
  making a private method of base class public

{Studied in Adapter}

NOTES:

* multiple inheritance {Studied in Adapter}
    - May inherit from multiple classes

* private vs. public inheritance {Studied in Adapter}
    - Public Inheritance - Allows to inherit the interface:
    is-a relationship
        - Abstract functions of base class - only interface
    
        - Concrete functions of base class - both interface
        and implementation

        - By default public features of base class are
        now public in this class

    - Private Inheritance - Allows to inherit implementation,
    interface is not inherited to clients (by default)
        - Features may be added to interface with using

        - By default public features of base class are now
        private in this class

* making a private method of base class public {Studied in Adapter}
    - If inheriting a private base class feature, it may be made public
    by stating this in public portion of dervied class definition:
    
    using BaseClass::BaseClassFeature;

*/