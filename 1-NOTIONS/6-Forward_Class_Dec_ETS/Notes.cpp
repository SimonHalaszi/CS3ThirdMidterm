/*

Notions
- (forward) class declaration, elaborated type specifier

NOTES:


* (forward) class declaration, elaborated type specifier {Studied in Observer}
    - Classic forward class declaration

    class A;

    class B {
        private:
            A* ptr_;
    };

    class A {
        ...
    };

    - Elaborated type specifier
        - Allows to state forward declaration class right
        in the place of variable declaration
            - Have to repeat for every variable declaration
            - Makes code, potentially, easier to read

    class B {
        private:
            class A* ptr_;
    };

    class A {
        ...
    };

    - NOTE: Forward-declared or Elaborated Types are incomplete. Incomplete
    types can only exist in the form of pointers or references. Abstract classes
    are another example of incomplete types.

*/