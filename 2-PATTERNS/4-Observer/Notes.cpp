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

*/