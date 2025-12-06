/*

PATTERNS
- command: (abstract/concrete) command, client, 
  receiver, invoker, execute()/unexecute()

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include "Command.hpp"

int main() {
	// Invoker that keeps track of commands executed on its interal receiver
	IntSequenceWithHistory sequence;

	sequence.pushInt(10);
	sequence.print();

	sequence.popInt();
	sequence.print();

	sequence.undo();
	sequence.print();

	sequence.pushInt(20); sequence.pushInt(30); sequence.pushInt(40);
	sequence.print();
	
	sequence.undo();
	sequence.print();

	sequence.popInt();
	sequence.print();

	sequence.undo();
	sequence.print();

	sequence.undo();
	sequence.print();
	
	sequence.undo();
	sequence.print();
	
	sequence.undo();
	sequence.print();

	sequence.undo();
}