#pragma once

/*

PATTERNS
- visitor: concrete/abstract element/visitor

*/

#include <iostream>

// Abstract Element
class AbstractElement {
    public: 
        // Accept that will take in any arbitrary visitor that inherits AbstractVisitor
        virtual void accept(class AbstractVisitor*) = 0;
};

// Abstract Visitor
class AbstractVisitor {
    public:
        // Visit overloads for all concrete elements we want to visit with this AbstractVisitor interface
        virtual void visit(class CharElement*) = 0;
        virtual void visit(class IntElement*) = 0;

        virtual ~AbstractVisitor() {}
};

// Concrete Element, with char data
class CharElement : public AbstractElement {
    public: 
        CharElement() : CharElement('\0') {}
        CharElement(char c) : c_(c) {}    

        char getChar() const { return c_; }

        void accept(class AbstractVisitor* av) {
            av->visit(this);
        }
    
    private:
        char c_;
};

// Concrete Element, with integer data
class IntElement : public AbstractElement {
    public: 
        IntElement() : IntElement(0) {}
        IntElement(int i) : i_(i) {}    

        int getInt() const { return i_; }

        void accept(class AbstractVisitor* av) {
            av->visit(this);
        }
    
    private:
        int i_;
};

// Concrete Visitor, that just operates on elements data
class HelloVisitor : public AbstractVisitor {
    public:
        // Overrides for our visit overloads
        void visit(class CharElement* ce) override {
            std::cout << "Hello CharElement! With char " << ce->getChar() << std::endl;
        }
        void visit(class IntElement* ie) override {
            std::cout << "Hello IntElement! With int " << ie->getInt() << std::endl;
        }

        ~HelloVisitor() override {}
};

// Concrete Visitor, that operates on elements data and has a state
class CountingVisitor : public AbstractVisitor {
    public:
        CountingVisitor() : i_(0) {}    

        // Overrides for our visit overloads
        void visit(class CharElement* ce) override {
            std::cout << "Im visiting a CharElement with char " << ce->getChar() << std::endl;
            ++i_;
        }
        void visit(class IntElement* ie) override {
            std::cout << "Im visiting a IntElement with int " << ie->getInt() << std::endl;
            ++i_;
        }

        int getAmountOfVisits() const { return i_; }

        ~CountingVisitor() override {}
    private:
        int i_;
};