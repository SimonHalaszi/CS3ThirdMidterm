#pragma once

#include <iostream>

// Abstract Base Class 
class Base {
    public:
        Base() : Base(0) {}
        Base(int i) : var_(i) {}

        virtual void func() = 0;

        virtual ~Base() {}
    protected:
        int var_;
};

// Concrete Derived Class
class Derived : public Base {
    public:
        Derived() : Base() {}
        Derived(int i) : Base(i) {}

        void func() override {
            std::cout << "----------------------" << std::endl;
            std::cout << "Inside Derived Invoke" << std::endl;
            std::cout << "From Derived" << var_ << std::endl;
            std::cout << "End Derived Invoke" << std::endl;
            std::cout << "----------------------" << std::endl;
        }

        ~Derived() override {}
};

// Concrete DerivedAgain Class
class DerivedAgain : public Derived {
    public:
        DerivedAgain() : Derived() {}
        DerivedAgain(int i) : Derived(i) {}

        void func() override {
            std::cout << "----------------------" << std::endl;
            std::cout << "Inside DerivedAgain Invoke" << std::endl;
            Derived::func(); // Invoking Derived override of func() using scope resolution
            std::cout << "From DerivedAgain" << var_ << std::endl;
            std::cout << "End DerivedAgain Invoke" << std::endl;
            std::cout << "----------------------" << std::endl;
        }

        ~DerivedAgain() override {}
};

