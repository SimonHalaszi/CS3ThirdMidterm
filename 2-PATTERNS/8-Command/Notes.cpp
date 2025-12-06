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

*/