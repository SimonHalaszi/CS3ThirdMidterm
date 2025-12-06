#pragma once

/*

PATTERNS
- decorator: decoration, component

*/

#include <iostream>

// Component
class Component {
    public: 
        // Base functionality of component class
        virtual void operation() const { std::cout << "Base" << std::endl; };

        virtual ~Component() {}
};

// A Decorator
class PrettyDecorator : public Component {
    public:
        PrettyDecorator(Component* decorating) : decorating_(decorating) {}
    
        // Added functionality by decorator
        void operation() const override { std::cout << "Pretty "; decorating_->operation(); }

        virtual ~PrettyDecorator() override { delete decorating_; }
    private:
        // Pointer to next decorator or base component
        Component* decorating_;
};
 
// A Decorator
class UglyDecorator : public Component {
    public:
        UglyDecorator(Component* decorating) : decorating_(decorating) {}

        // Added functionality by decorator
        void operation() const override { std::cout << "Ugly "; decorating_->operation(); }

        virtual ~UglyDecorator() override { delete decorating_; }
    private:
        // Pointer to next decorator or base component
        Component* decorating_;
};