/*

PATTERNS
- observer: subject, observer, subscribing, registry,
  message (notification)

NOTES:

* observer: subject, observer, subscribing, registry,
  message (notification)

    Motivation:
        - Objects (observers) need to synchronize behavior with
        some other object (subject): Observe changing in subject's state
    
    
    Pattern:
        - Observers subscribe to change state notifications, while
        subjects publish changes by notifying observers or sending them
        messages (synonymous terms)

        - Another name for pattern - publish-subscribe

        - Common way to implement GUI interfaces (foundation of so called
        model-view-controller architectural pattern)
            - The "business logic" is in subject hierarchy

            - The "presentation logic" is in observer hierarchy

        - If using abstract/concrete classes
            - Abstract observers/subjects - implement registration/notification
            functionality

            - Concrete observers/subjects - implement subjust state and state
            acquisition by observer

        - There may be a registry of subjects for observers to subscribe to

        - Behavioral pattern

    Study ObserverRegistry. Since the study guide puts emphasis on its topics.

    Motivation in my words:

    Its very useful to have a system in place to where objects (Observers) 
    can be notified when the state of another object (Subject) changes 
    without having to constantly check and waste resources looking for changes.
    And on top of this being useful its even more useful to manage this system
    using a centralized registry that can subscribe these observing objects
    to their subjects and handle this notification process.

    In my opinion, the motivation for this pattern is one of the more obvious
    ones, theres a million things that need something like this. The problem
    is the actual details of this are very involved.

    Technical details (Specifically with Registry):

    Abstract Observer Interface:
        - Holds pointer to Subject it is subscribed to (observes)

        - Has functionality to subscribe itself to subjects, through static
        registry, and internally set subject pointer.

        - Has functionality to unsubscribe itself from subjects, through
        static registry, and internally reset subject pointer.

        - Has functionality of what it does when it gets notified
            - Actually defined in Concrete Observers, other parts arent
            implementation specific.

    Abstract Subject Interface:
        - Has functionality to notify its observers, through static registry

        - Has functionality to change its state in someway
            - Actually defined in Concrete Subject

    Registry:
        - Holds static map that maps an AbstractSubject* to its respective 
        set of AbstractObserver*

        - Has functionality to register an AbstractObserver to an 
        AbstractSubject

        - Has functionality to deregister an AbstractObserver to an
        AbstractSubject
        
        - These two functions take in both as arguments because both are needed
        as arguments to insert to map

        - Provides functionality for Subjects to notify their corresponding
        set of observers

*/