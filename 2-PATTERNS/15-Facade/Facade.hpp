/*

PATTERNS
- facade: facade, subsystem

*/

#include <iostream>
#include <string>

// Simple Abstract Class
class AbstractClass {
    public:
        AbstractClass(int i = 0) : i_(i) {}

        void setInt(int i) { i_ = i; }

        virtual void print() = 0;
    
    protected:
        int i_;
};

// Simple Concrete Classes with slightly different implementations
class BoolClass : public AbstractClass {
    public:
        BoolClass(bool b = false, int i = 0)
        : b_(b), AbstractClass(i) {}

        void setBool(bool b) { b_ = b; }

        void print() override {
            std::cout << "BoolClass w/ ";
            if(b_) {
                std::cout << "True, ";
            }
            else {
                std::cout << "False, ";
            }
            std::cout << i_ << std::endl;
        }
    private:
        bool b_;
};

class CharClass : public AbstractClass {
    public:
        CharClass(char c = '\0', int i = 0)
        : c_(c), AbstractClass(i) {}

        void setChar(char c) { c_ = c; }

        void print() override {
            std::cout << "CharClass w/ ";
            std::cout << c_ << ", ";
            std::cout << i_ << std::endl;
        }
    private:
        char c_;
};

class StringClass : public AbstractClass {
    public:
        StringClass(std::string str = "\0", int i = 0)
        : str_(str), AbstractClass(i) {}

        void setString(std::string str) { str_ = str; }

        void print() override {
            std::cout << "StringClass w/ ";
            std::cout << str_ << ", ";
            std::cout << i_ << std::endl;
        }
    private:
        std::string str_;
};

// Facade that wraps around all these classes
class Facade {
    public:
        Facade() : bc_(), cc_(), sc_() {}

        // Simple interface for clients to use to interact with subsystem
        
        /*
        Dumbs down subsystem, otherwise client would need to know which
        type of classes exist in subsystem, and a unique function for each,
        or would have to entirely new class everytime they want to print
        a different variation
        */
        void printBoolClass(bool b, int i) {
            bc_.setBool(b);
            bc_.setInt(i);
            bc_.print();
        }
        void printCharClass(char c, int i) {
            cc_.setChar(c);
            cc_.setInt(i);
            cc_.print();
        }
        void printStringClass(std::string str, int i) {
            sc_.setString(str);
            sc_.setInt(i);
            sc_.print();
        }

    private:
        // Potentially confusing a big subsystem of classes
        BoolClass bc_;
        CharClass cc_;
        StringClass sc_;
};