/*

Notions
- type covariance

{Studied in Prototype}

NOTES:

* type covariance {Studied in Prototype}
    - Overriding virtual function of derived class may accept
    or return types of derived class (valid only for pointers and references)
        - Even if the base class virtual function specified base class
        types in its signature

        EX:
            // In Base Class
            virtual Base* create();

            // In Derived Class
            Derived* create() override;

    - This mechanism is called type covariance
    
    - This allows the derived class to have richer interface

*/