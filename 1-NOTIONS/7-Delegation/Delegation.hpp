#pragma once

#include <iostream>

// Delegatee class that Delegator will reference
class Delegatee {
    public:    
        Delegatee() : Delegatee(0) {}
        Delegatee(int i) : var_(i) {}
    
        int delegateeMethod(int i) { return i * var_; }

    private:
        int var_;
};

// Delegator class that Delegatee will be used from
class Delegator {
    public:
        Delegator() : Delegator(0, nullptr) {}
        Delegator(int i, Delegatee* d) : var_(i), delegatee(d) {}

        // Delegator goes to delegatee for multiplying functionality
        int delegateToDelegatee() {
            return delegatee->delegateeMethod(var_);
        }

        ~Delegator() { delete delegatee; }

    private:
        Delegatee* delegatee;
        int var_;
};