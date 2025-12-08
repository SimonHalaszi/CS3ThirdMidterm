/*

Notions
- base/derived classes, inheritance, virtual functions, pure virtual
    functions, abstract classes, access methods invoking overriden
    function in an overriding function

{Studied in Template Method} & {Studied in Chain Of Responsibility}

NOTES:

* Base/Derived Classes {Studied in Template Method}
    - Class D may inherit the features of another class B, or extend class B

    - In this case
        - B - Base Class, Superclass - Provides generalizations for class D
        - D - Derived Class, Subclass - Provides specialization of class B

* Inheritance {Studied in Template Method}
    EX:
        Class B {
            // Implementation
        };

        Class D : public B {
            // Derived from B
        };

* Virtual Functions {Studied in Template Method}
    - What if necessary to manipulate objects regardless of specifics of
    derived class?
        - Need to draw figures regardless of specific implementation of figure
        
    - Can be done through pointers (or references) to objects (Polymorphism)
        EX:
            Figure* fig1 = new Square();
            Figure* fig2 = new Triangle();
            fig1->draw();
            fig2->draw();
            
    - Which function, base or derived class draw, is invoked?

    - Early (Compile-time) binding - resolving function by compiler
        - Base class draw() would be invoked

    - Late (Run-time) binding - resolving function by program itself on
    the basis class pointed-to
        - Respective derived class draw() would be invoked

    - To enable late binding, declare function as virtual in base class
        - Function used with late-binding displays polymorphic behavior
        EX:
            class B {
                virtual void draw();
            };

    - Virtual function may be a destructor but not a constructor

    - Override specifier following function head signifies that this function
    must override a virtual base class function, if not - compile-time error.
    Overriding a virtual function means the base classes function functionality
    will be replaced by this derived class functionality when called through
    base class pointer to derived class object.

    - Final specifier following function head and override signifies that derived
    classes must not override this function further, if they try compile-time
    error.

* Pure Virtual Functions {Studied in Template Method}
    - Abstract function (method/operation) - virtual function in base class that
    defines the function signature but does not give a base class implementation.
        - Pure Virtual Function - Same name for the idea, function prototype is
        followed by '= 0'.
    - Concrete function (method/operation) - Function whose implementation is
    provided

* Abstract class {Studied in Template Method}
    - Class that has at least on abstract function
    
    - Objects of these classes can not exist. Only pointers and references to
    derived concrete class objects.

    - Concrete class - has no abstract functions
        - If derived from abstract class, has to implement all abstract functions
            - If not, derived class is also abstract

* Access methods invoking overriden function in an overriding function {Studied in Chain Of Responsibility}
    - Possible to invoke overridden function by stating scope

    EX:
        // In header
        class B {
            public:
                virtual void func();
        };

        class D : public B {
            public:
                void func() override {
                    A::func(); // Invokes base class function
                }
        };

        // In main
        B* ptr = new B; ptr->A::func();
        B b; b.A::func();

*/