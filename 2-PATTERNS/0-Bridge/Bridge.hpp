#pragma once

/*

PATTERNS
- bridge: delegation, handle, body

*/

#include <string>
#include <iostream>

// Abstract body interface
class AbstractBody {
    public:
        virtual void doSomething() = 0;

        virtual ~AbstractBody() {}
};

// Concrete body
class IntBody : public AbstractBody {
    public:
        IntBody() : IntBody(0) {}
        IntBody(int i) : i_(i) {}

        void doSomething() override {
            std::cout << i_ << ": int body did something." << std::endl;
        }
    
    private:
        int i_;
};

// Concrete body
class CharBody : public AbstractBody {
    public:
        CharBody() : CharBody('\0') {}
        CharBody(char c) : c_(c) {}

        void doSomething() override {
            std::cout << c_ << ": char body did something." << std::endl;
        }
    
    private:
        char c_;
};

// Abstract handle interface
class AbstractHandle {
    public:
        AbstractHandle() : AbstractHandle(nullptr) {}
        AbstractHandle(AbstractBody* impl) : impl_(impl) {}

        // Function that uses body
        virtual void func() = 0;

        void changeBody(AbstractBody* newImpl_) {
            delete impl_;
            impl_ = newImpl_;
        }

        virtual ~AbstractHandle() { delete impl_; }

    protected:
        // Pointer that delegates to body implementation
        AbstractBody* impl_;
};

class NamedHandle : public AbstractHandle {
    public:
        NamedHandle() : NamedHandle("\0", nullptr) {}
        NamedHandle(std::string str, AbstractBody* impl) : str_(str), AbstractHandle(impl) {}

        void func() override {
            std::cout << "NamedHandle Name: " << str_ << ". Delegating to concrete body" << std::endl;
            impl_->doSomething();
        }

    private:
        std::string str_;
};