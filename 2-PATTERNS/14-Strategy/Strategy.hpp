#pragma once

/*

PATTERNS
- strategy: strategy, context, push/pull for strategy

*/

// Push_AbstractStrategy defines push strategy interface
class Push_AbstractStrategy {
    public:
        // A push strategy gets the variables it needs to operate on from context
        virtual void execute(int&) const = 0;

        virtual ~Push_AbstractStrategy() {}
};

class IntContext;

// Pull_AbstractStrategy defines pull strategy interface
class Pull_AbstractStrategy {
    public:
        Pull_AbstractStrategy(IntContext* context = nullptr)
        : context_(context) {}

        virtual void execute() = 0;

        virtual ~Pull_AbstractStrategy() {}
    protected:
        // A pull strategy keeps reference to the context is operates on
        IntContext* context_;
};

// Context object/client that uses the strategy interface
class IntContext {
    public:
        IntContext(int i = 0) 
        : i_(i), push_strategy_(nullptr) {}

        void setPushStrategy(Push_AbstractStrategy* strategy) {
            push_strategy_ = strategy;
        }

        void setInt(int i) { i_ = i; }
        int getInt() const { return i_; }

        void executePushStrategy() { push_strategy_->execute(i_); }
    
    private:
        int i_;
        Push_AbstractStrategy* push_strategy_;
};

// Concrete push Strategies
class Push_AddStrategy : public Push_AbstractStrategy {
    public:
        // Push strategy is given needed information
        void execute(int& i) const override {
            i += i;
        }
};

class Push_MultStrategy : public Push_AbstractStrategy {
    public:
        // Push strategy is given needed information
        void execute(int& i) const override {
            i *= i;
        }
};

// Concrete pull Strategies
class Pull_AddStrategy : public Pull_AbstractStrategy {
    public:
        Pull_AddStrategy(IntContext* context) 
        : Pull_AbstractStrategy(context) {}

        // Pull strategy grabs information it needs from internal context
        void execute() override {
            if(context_ == nullptr) return;
            context_->setInt(context_->getInt() + context_->getInt());
        }
};

class Pull_MultStrategy : public Pull_AbstractStrategy {
    public:
        Pull_MultStrategy(IntContext* context) 
        : Pull_AbstractStrategy(context) {}

        // Pull strategy grabs information it needs from internal context
        void execute() override {
            if(context_ == nullptr) return;
            context_->setInt(context_->getInt() * context_->getInt());
        }
};