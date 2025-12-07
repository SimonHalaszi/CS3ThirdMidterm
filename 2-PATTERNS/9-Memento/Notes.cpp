/*

PATTERNS
- memento: originator, memento, caretaker, 
  saving/restoring object state

NOTES:

* memento: originator, memento, caretaker, 
  saving/restoring object state

    Motivation and Pattern:

    - To capture and encapsulate the state of an object for
    later restoration
    
    - Used to implement
        - Checkpoints / Rollbacks
        - Undo Mechanisms
        - History

    Memento Participants:
        - Originator - Creates memento containing snapshot of
        current state, uses memento to restore state

        - Memento - Stores internal state of originator, only
        originator may see internals

        - Caretaker - Keeps memento does not access or examins
        memento's contents

    Motivation in my words:

    Its useful to store the old state of something in case you need to recover it
      
    Technical Details:

    Orginator offers function that returns dynamically allocated Memento that
    was initialized to hold an immutable copy of its current internal state.
    Memento offers function to retrieve this internal state it copied. Orginator
    offers another function that takes in a Memento* to the dynamically allocated
    Memento and can rollback its state based on this Memento. The Caretaker is the
    client that holds onto the dynamically allocated Memento while it might be
    potentially needed for rollingback, and the caretaker cannot change the Mementos
    state.

*/