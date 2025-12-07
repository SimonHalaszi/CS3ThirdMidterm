#pragma once

/*

PATTERNS
- chain of responsibility: handler, successor

*/

#include <iostream>

// BaseHandler class that will be reconsulted if Derived Handlers cant handle a request
class BaseHandler {
    public:
        BaseHandler(BaseHandler* successor = nullptr ) : successor_(successor) {}

        // Base implementation of handling a request
        virtual void handleRequest(int amount) {
            // If there is a successor_ allow it to try and handle request
            if(successor_ != nullptr) {
                successor_->handleRequest(amount);
            }
            // If there is no successor_ then this request couldnt be handled
            else {
                std::cout << "No handler is capable" << std::endl;
            }
        }

        virtual ~BaseHandler() { delete successor_; }

    private:
        BaseHandler* successor_;
};

// Derived Handler
class BeginnerHandler : public BaseHandler {
    public:
        BeginnerHandler(BaseHandler* next = nullptr) : BaseHandler(next) {}

        // Overrides BaseHandler function
        void handleRequest(int amount) override {
            // If inputted request meets this condition this handler can meet the request
            if(amount < 10) {
                std::cout << "BeginnerHandler handled this request" << std::endl;
            }
            // If not consult BaseHandler implementation to see if we should go next or not
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