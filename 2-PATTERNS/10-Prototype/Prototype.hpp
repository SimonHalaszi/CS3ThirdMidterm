#pragma once

/*

PATTERNS
- prototype: clone

*/

#include <iostream>

// AbstarctInterface that outlines prototyping interface
class AbstractInterface {
    public:
        /*
        Virtual clone function with Polymorphic AbstractInterface 
        pointer is core of prototype design pattern.
        */
        virtual AbstractInterface* clone() = 0;
        
        virtual void printState() = 0;
        
        virtual ~AbstractInterface() {}
};

class IntPrototype : public AbstractInterface {
    public:
        IntPrototype(int i = 0) : i_(i) {}
        
        // Clone implementation will vary for concrete prototypes
        // Uses type covariance
        IntPrototype* clone() override {
            printState(); std::cout << ". Is getting cloned.";
            return new IntPrototype(i_);
        }

        void printState() override {
            std::cout << "IntPrototype with state: " << i_;
        }

    private:
        int i_;
};

class CharPrototype : public AbstractInterface {
    public:
        CharPrototype(char c = 0) : c_(c) {}
        
        // Clone implementation will vary for concrete prototypes
        // Uses type covariance
        CharPrototype* clone() override {
            printState(); std::cout << ". Is getting cloned.";
            return new CharPrototype(c_);
        }

        void printState() override {
            std::cout << "CharPrototype with state: " << c_;
        }

    private:
        char c_;
};