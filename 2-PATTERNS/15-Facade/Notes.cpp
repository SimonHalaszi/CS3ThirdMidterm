/*

PATTERNS
- facade: facade, subsystem

NOTES:

* facade: facade, subsystem

    Motivation and Pattern:

    - Facade - Object that provides single simplified interface
    to more general facilities of a subsystem

    - Motivation - Fixed, potentially complex classes, whose
    interface cannot be changed
        - Legacy, used elsewhere, too complicated for clients

    - Participants
        - Facade - Knows which subsystem classes are responsible
        for request, delegates request to appropraite subsystem
        objects

        - Subsystem classes - Implement functioanlity, are not away
        of facade

    - Promotes loose couple between clients and subsystem

    - Structural pattern

    Relationships to Other Patterns
    
    - Adapter - Wraps a single legacy class to do something else
        - Facade attempts to simplify interface of an entire subsystem
        of legacy classes
        
        - Facade does not intend to adapt functionality of subsystem like
        adapter does, more it attempts to make the functionality of the
        subsystem easier to use

    - Mediator - Has more complex communication between (colleagues)
    classes

    - Facade is often Singleton (As it usually tends to be very verbose)

    Motivation in my words:
  
    When you have a super complicated system that can be encapsulated by a cleaner
    interface. Where this clean interface would be more convenient and easy to use 
    for clients.

    Technical Details:

    This pattern is more abstract, so not much technical to say. Its similar to Adapter
    but instead of working to Adapt a singular legacy class into something else.
    This intends to adapt a super complicateed interface into a super simple one while
    keep functionality the same. And just like Adapter it can be done in both Class
    and Object forms. Where Facade either inherits all the classes that make up its
    subsystem or has objects that make up its subsystem that it calls functions of
    inside of its interface. The object form is more common because it is much
    cleaner to implement. And thats why Facades are usually singletons because
    they tend to be very large in size and would take up a lot of memory otherwise.

    A good example is your operating system. The Facade for that is the Windows GUI
    or Linux Terminal you interact with. Because actually have to load processes and
    manage memory yourself would be a headache/not even really possible. So the GUI
    and Terminal wrap them up nicely for the average person. And also think for
    Windows you can only have one operating system instance at a time! Because otherwise
    that large subsystem would quickly eat up your resources.

*/