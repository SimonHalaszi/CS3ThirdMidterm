#pragma once

#include <iostream>

// Also an Example of the Prototype Design Pattern
// Allows for copying of objects that are interacted with polymorphically

// Abstract Base Class // Abstract Prototype (Prototype Interface)
class Base {
    public:
        Base() : Base(0) {}
        Base(int i) : var_(i) {}

        // Virtual cloning method
        virtual Base* clone() = 0;
        virtual void printState() = 0;

        virtual ~Base() {}

    protected:
        int var_;
};

// Concrete Derived Class // Concrete Prototype (Concrete Interface)
class Derived : public Base {
    public:
        Derived() : Base(0) {}
        Derived(int i) : Base(i) {}

        // Copy Constructor
        Derived(const Derived& copy) { var_ = copy.var_; }

        // Concrete cloning method
        // Notice clone return type went from Base* to Derived* via type covariance
        Derived* clone() override {
            // Return new dynamically allocated copy using type covariance
            return new Derived(*this);
        }

        void printState() override {
            std::cout << "Derived Class State: " << var_ << std::endl;
        }
};


