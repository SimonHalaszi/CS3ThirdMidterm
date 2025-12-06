#pragma once

/*

PATTERNS
- observer: subject, observer, subscribing, registry,
  message (notification)

*/

#include <set>
#include <map>
#include <iostream>
#include <algorithm>

class Observer;
class Subject;

// Class that holds registry of Subjects to their Observers
class EventRegistry {
    public:
        // Methods that handle the registering of Subjects and Observers
        static void registerObserver(Subject*, Observer*);
        static void deregisterObserver(Subject*, Observer*);
        
        // Method to handle sending messages from a subject to their observers
        static void handleMessage(Subject*);

    private:
        // Registry of Subjects to their Observers
        static std::map<Subject*, std::set<Observer*>> observerMap_;
};

// Initialize static registry
std::map<Subject*, std::set<Observer*>> EventRegistry::observerMap_;

// Observer Class
class Observer {
    public:
        Observer(char c) : c_(c) {}
        char getName() const { return c_; }

        // Method to subscribe this Observer to a Subject
        void subscribe(Subject* s) { EventRegistry::registerObserver(s, this); }
        // Method to unsubscribe this Observer from a Subject
        void unsubscribe(Subject* s) { EventRegistry::deregisterObserver(s, this); }
        
        // Method to handle the messages this Observer gets
        void handleMessage(Subject* s);
    
    private:
        char c_;
};

// Subject Class
class Subject {
    public:
        Subject(char c) : c_(c) {}
        char getName() const { return c_; }

        // Method to message Observers observing this Subject
        void messageObservers() { EventRegistry::handleMessage(this); }

    private:
        char c_;
};

// Method for registering an Observer to a Subject using a registry
void EventRegistry::registerObserver(Subject* s, Observer* o) {
    /*
    If observer s doesnt exist in map yet created an empty set to insert to.
    Insert will add o to that set at s key
    */
    std::cout << "Observer " << o->getName() << " subscribed to Subject " << s->getName() << std::endl; 
    observerMap_[s].insert(o);
}

// Method for deregistering an Observer to a Subject using a registry
void EventRegistry::deregisterObserver(Subject* s, Observer* o) {
    /*
    If observer s doesnt exist in map yet created an empty set to erase from.
    Which will be taking up dead space. And if o exist it will be deleted.
    */
    std::cout << "Observer " << o->getName() << " unsubscribed from Subject " << s->getName() << std::endl; 
    observerMap_[s].erase(o);
}

// Method for message all Observers to a Subject using a registry
void EventRegistry::handleMessage(Subject* s) {
    // For all Observers in the set at observerMap_[s] handle the message from s
    for(Observer* o : observerMap_[s]) {
        o->handleMessage(s);
    }
}

// Method for Observer to handle messages from a Subject
void Observer::handleMessage(Subject* s) {
    std::cout << "Observer " << c_ << " got a message from Subject " << s->getName() << std::endl; 
}



