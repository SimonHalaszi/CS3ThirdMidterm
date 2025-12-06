#pragma once

/*

PATTERNS
- chain of responsibility: handler, successor

*/

#include <iostream>

class BaseHandler {
    public:
        BaseHandler(BaseHandler* next = nullptr ) : next_(next) {}

        virtual void handleRequest(int amount) {
            if(next_ != nullptr) {
                next_->handleRequest(amount);
            }
            else {
                std::cout << "No handler is capable" << std::endl;
            }
        }

        virtual ~BaseHandler() { delete next_; }

    private:
        BaseHandler* next_;
};

class BeginnerHandler : public BaseHandler {
    public:
        BeginnerHandler(BaseHandler* next = nullptr) : BaseHandler(next) {}

        void handleRequest(int amount) override {
            if(amount < 10) {
                std::cout << "BeginnerHandler handled this request" << std::endl;
            }
            else {
                BaseHandler::handleRequest(amount);
            }
        }
};

class NoviceHandler : public BaseHandler {
    public:
        NoviceHandler(BaseHandler* next = nullptr) : BaseHandler(next) {}

        void handleRequest(int amount) override {
            if(amount < 50) {
                std::cout << "NoviceHandler handled this request" << std::endl;
            }
            else {
                BaseHandler::handleRequest(amount);
            }
        }
};

class ExpertHandler : public BaseHandler {
    public:
        ExpertHandler(BaseHandler* next = nullptr) : BaseHandler(next) {}

        void handleRequest(int amount) override {
            if(amount < 100) {
                std::cout << "ExpertHandler handled this request" << std::endl;
            }
            else {
                BaseHandler::handleRequest(amount);
            }
        }
};