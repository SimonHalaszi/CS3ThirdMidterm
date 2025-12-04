/*

Notions
- (forward) class declaration, elaborated type specifier

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

// forward declaration of class
class A;

class B {
    private:
        A* aPtr_;
        // elaborated type specifier
        class C* cPtr_;
};

class A {
    // Definition
};

class C {
    // Definition
};

int main() {
    // This is more just a fun fact, so look at the syntax, and appreciate it
}