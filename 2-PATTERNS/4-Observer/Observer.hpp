#pragma once

/*

PATTERNS
- observer: subject, observer, subscribing, registry,
  message (notification)

*/

#include <unordered_set>
#include <iostream>

class BaseSubject;

// AbstractObserver that implements interface for AbstractSubject to notify concrete observers
class AbstractObserver {
    public:
        // Constructor that will be used to register this observer with subject
        AbstractObserver(BaseSubject* subject);
        
        // Method subject will use to notify observer
        virtual void getNotified() const = 0;
};

// BaseSubject that implements interface for concrete subjects to register, deregister, and notify their observers in a set
class BaseSubject {
    public:
        // Register an observer to subjects set of observers
        void registerObserver(AbstractObserver* ao) { observers_.insert(ao); }
        // Deregister an observer to subjects set of observers
        void deregisterObserver(AbstractObserver* ao) { observers_.erase(ao); }
        
        // Notify all observers in subjects set of observers
        void notifyObservers() const { 
            for(AbstractObserver* ao : observers_) {
                ao->getNotified();
            }
        }

    private:
        // Set of all the observers that are registered with this subject
        std::unordered_set<AbstractObserver*> observers_;
};

/*
Implementation of AbstractObserver constructor. Which must be declared after
BaseSubject because it needs to call the registerObserver method to register
this observer into the BaseSubject set.
*/
AbstractObserver::AbstractObserver(BaseSubject* subject) {
    // So client can not potentially construct a base ConcreteObserver with nullptr and cause issues
    if(subject != nullptr) {
        subject->registerObserver(this);
    }
}

class DerivedSubject;

// ConcreteObserver class that implements AbstractObserver interface
class ConcreteObserver : public AbstractObserver {
    public:
        // Constructors for ConcreteObserver
        ConcreteObserver() : ConcreteObserver('\0', nullptr) {}
        ConcreteObserver(char c, DerivedSubject* subject);
    
        // Overriding getNotified
        void getNotified() const override;
    private:
        // Name for Observer
        char c_;
        // Pointer to specific derived subject this concrete observer is observing
        DerivedSubject* subject_;
};

// DerivedSubject that uses BaseSubject interface and extends it.
class DerivedSubject : public BaseSubject {
    public:
        // Constructors for DerivedSubject
        DerivedSubject() : DerivedSubject('\0', 1) {}
        DerivedSubject(char c, int i) : c_(c), i_(i) {}

        // Modifying method that notifys Observers to the changes
        void changeData(int i) { i_ = i; notifyObservers(); }
        
        // Getters used by the Observer after getting notified. (Pull method of communication)
        char getName() const { return c_; }
        int getData() const { return i_; }
    private:
        // Data internal to Observer
        char c_;
        int i_;
};

/*
ConcreteObserver constructor. Needs to be implemented after DerivedSubject because otherwise compiler
isnt certain that DerivedSubject actual inherits BaseSubject so AbstractObserver constructor could not be called
*/
ConcreteObserver::ConcreteObserver(char c, DerivedSubject* subject)
: c_(c), subject_(subject), AbstractObserver(subject) {}

/*
Actual implementation of what ConcreteObserver will do after DerivedSubject notifies it using
the notifyObservers method from BaseSubject which called getNotified
*/
void ConcreteObserver::getNotified() const {
    if(subject_ != nullptr) {
        std::cout << "Observer " << c_ << " got notified that "
        << "Subject " << subject_->getName()
        << " changed its data to: " << subject_->getData() << std::endl;        
    }
}