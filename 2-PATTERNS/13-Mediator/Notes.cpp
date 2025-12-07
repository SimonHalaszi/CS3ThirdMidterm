/*

PATTERNS
- mediator: abstract/concrete mediator, colleague, push/pull for
  mediator

NOTES:

* mediator: abstract/concrete mediator, colleague, push/pull for
  mediator

  	Motivation and Pattern:

  	- Define an objects that encapsulates how other objects
  	interact

  	- Prevents objects from referring to each other
		- Loose coupling

		- Prevents spaghetti of references

	- Controlled interactions through mediator

	Participants:

	- Absract mediator - Defines interface for communicating 
	between colleague objects.

	- Concrete mediator - Actual implementation and coordinating
	of communication between colleagues.

	- Colleague classes
		- Each colleague knows the mediator

		- Each colleague communicates with mediator to reach other
		colleagues

	- May use push and/or pull communication methods

	- If abused, Mediator may turn into a God Object

	Motivation in my words:

    When you want to have a central object that can communicate to
	other objects and be communicated to by other objects.
      
    Technical Details:

	AbstractMediator defines interface functions for linking and unlinking
	AbstractColleagues to and from the Mediator. As well as functions for
	Communicating to AbstractColleagues and receiving messages from
	AbstractColleagues. ConcreteMediator actually implements these functions.
	Usually by having a private set of AbstractColleagues* pointers. And by
	implementing the AbstractMediator accordingly. 

	AbstractColleague defines interface for ConcreteColleagues to implement,
	this interface includes functionality for ConcreteColleagues to send a message
	to its Mediator or to receive a message from its Mediator. ConcreteColleagues
	implement how this actual receiving of information from mediator is handled.
	AbstractColleague interface can define the sending of a message.

	Mediator can observe its colleagues at anytime, and can send a message to
	any colleague at any time. And the colleagues can handle these messages at
	any time and can message the Mediator at any time.
	

*/