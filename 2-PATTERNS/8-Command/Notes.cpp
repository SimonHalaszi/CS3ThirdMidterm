/*

PATTERNS
- command: (abstract/concrete) command, client, 
  receiver, invoker, execute()/unexecute()

NOTES:

* command: (abstract/concrete) command, client, 
  receiver, invoker, execute()/unexecute()

    Motivation and Pattern:

	- When need to issue request (command) on object from place
	that does not know about the action or the object (receiver)
	of the request

	- Command Design Pattern allows to make request to receiver
	by turning request itself into an object - command

	- Use if you need to keep track of operations done on an object.
	If you dont need to keep track or have knowledge of what is done
	to object this pattern just overcomplicates normal interfacing with
	the object. Why have commands when I can just call the public interface
	that are underlying called? Exactly, there is no point to the pattern 
	unless we have a reason to care about history, undoing, or logging
	actions done to receiver.

	- Command Participants
		- Abstract Command - Declares an interface for executing the
		command declares execute()

		- Concrete Command - Implements execute(), acts on receiver

		- Client - Creates the concrete command object and sets up
		its receiver

		- Receiver - Object on which operations (commands) are
		performed

		- Invoker - Asks to execute the command

	Motivation in my words:

	Sometimes its useful to keep track at what functions were called at
	run-time on an object (receiver), this is useful for keeping history,
	undoing, or loggic functions that were invoked.
    
    Technical Details:

	AbstractCommand class is defined to give an interface to all ConcreteCommand
	classes to implement. This usually includes an execute and unexecute function
	and a ReceiverClass* pointer. The ConcreteCommand classes implement this interface
	by calling functions of the ReceiverClass and by tracking what object they
	executed on through the pointer. ConcreteCommand may also hold state information
	of what exactly their command did to the object, to be able to unexecute their
	action. Invoker may then be a class or a programmer that dynamically allocates
	new commands with the receiver and then executes these commands. The invoker
	then is free to use these commands to keep run-time track of what has happended
	to the receiver.


*/