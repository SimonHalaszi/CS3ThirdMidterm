#pragma once

/*

PATTERNS
- state: context, state abstract/concrete

*/

#include <iostream>
#include <string>

class AbstractState;

// Context
class Context {
    public:
        Context() : Context(nullptr) {}
        Context(AbstractState* state) : state_(state) {}

        // Context generic state changes
        void left();
        void right();

        void changeState(AbstractState* state) { state_ = state; }

        // Context behavior
        void reportState();
    private:
        // AbstractState polymorphic pointer that Context delegates to for state changes and behavior
        AbstractState* state_;

};

// AbstractState interface. Has the same interface as the Context for a one to one mapping.
class AbstractState {
    public:
        // Abstract state changes (Semantics to be implemented in actual states)
        virtual void left(Context*) = 0;
        virtual void right(Context*) = 0;

        void changeState(Context* context, AbstractState* state) {
            context->changeState(state);
        }

        // Abstract state behavior (Semantics to be implemented in actual states)
        virtual void reportState() = 0;
};

// Concrete State. Implements AbstractState interface.
class Left : public AbstractState {
    public:
        // Concrete state changes (Semantics of actual state changes implemented in concrete states)
        void left(Context* c) override;
        void right(Context* c) override;        
    
        static AbstractState* instance() {
            static AbstractState* onlyInstance = new Left;
            return onlyInstance;
        }

        // Concrete state behavior (Semantics of actual state behavior implemented in concrete states)
        void reportState() override;
};

class Center : public AbstractState {
    public:
        static AbstractState* instance() {
            static AbstractState* onlyInstance = new Center;
            return onlyInstance;
        }

        void left(Context* c) override;
        void right(Context* c) override;
        void reportState() override;
};

class Right : public AbstractState {
    public:
        static AbstractState* instance() {
            static AbstractState* onlyInstance = new Right;
            return onlyInstance;
        }

        void left(Context* c) override;
        void right(Context* c) override;
        void reportState() override;
};

// Left overrides

// Concrete state changes (Semantics of actual state changes implemented in concrete states)
void Left::left(Context* c) { changeState(c, Left::instance()); }
void Left::right(Context* c) { changeState(c, Center::instance()); }

// Concrete state behavior (Semantics of actual state behavior implemented in concrete states)
void Left::reportState() { std::cout << "Left" << std::endl; }

// Center overrides
void Center::left(Context* c) { changeState(c, Left::instance()); }
void Center::right(Context* c) { changeState(c, Right::instance()); }
void Center::reportState() { std::cout << "Center" << std::endl; }

// Right overrides
void Right::left(Context* c) { changeState(c, Center::instance()); }
void Right::right(Context* c) { changeState(c, Right::instance()); }
void Right::reportState() { std::cout << "Right" << std::endl; }

// Context implementation

// Context just delegates corresponding state changes through polymorphic state pointer
void Context::left() { state_->left(this); }
void Context::right() { state_->right(this); }

// Context just delegates state behavior through polymorphic state pointer
void Context::reportState() { std::cout << "Context: "; state_->reportState(); }