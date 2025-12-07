#pragma once

/*

PATTERNS
- command: (abstract/concrete) command, client, 
  receiver, invoker, execute()/unexecute()

*/

#include <iostream>
#include <vector>
#include <stack>

// Receiver
class IntSequence {
	public:
		IntSequence(const std::vector<int>& sequence = {}) 
		: sequence_(sequence) {}

		// Pushes int to sequence vector
		void pushInt(int i) {
			sequence_.push_back(i);
		}

		// Pops int to sequence vector
		int popInt() {
			if(!sequence_.empty()) {
				int i = sequence_.back();
				sequence_.pop_back();
				return i;
			}
			return -1;
		}

		// Prints sequence
		void print() const {
			for(int i : sequence_) {
				std::cout << i << " ";
			}
			std::cout << std::endl;
		}

	private:
		// Sequence of ints
		std::vector<int> sequence_;
};

// Abstract Command
class AbstractCommand {
	public:
		AbstractCommand(IntSequence* intSequence) 
		: intSequence_(intSequence) {}

		// Basic interface for a command, needs to have execute capability and capability to unexecute
		virtual void execute() = 0;
		virtual void unexecute() = 0;
		
		virtual ~AbstractCommand()  {}
		
	protected:
		// Pointer to the IntSequence so that commands can operate on it
		IntSequence* intSequence_;
};

// Concrete Command
class PushCommand : public AbstractCommand {
	public:
		PushCommand(IntSequence* intSequence, int i)
		: AbstractCommand(intSequence), i_(i) {}

		// Push command executes by calling pushInt
		void execute() override {
			intSequence_->pushInt(i_);
		}

		// Push command unexecutes by calling popInt
		void unexecute() override {
			intSequence_->popInt();
		}

		~PushCommand()  {}

	private:
		// Internal integer this command used in its operations
		int i_;
};

// Concrete Command
class PopCommand : public AbstractCommand {
	public:
		PopCommand(IntSequence* intSequence)
		: AbstractCommand(intSequence), i_(-1) {}

		// Push command executes by calling popInt
		void execute() override {
			i_ = intSequence_->popInt();
		}

		// Push command unexecutes by calling pushInt
		void unexecute() override {
			intSequence_->pushInt(i_);
		}

		~PopCommand()  {}

	private:
		// Internal integer this command used in its operations
		int i_;
};

// Invoker: Uses commands on receiver. Keeps track of what commands were used in a stack
class IntSequenceWithHistory {
	public:
		IntSequenceWithHistory(const std::vector<int>& intSequence = {})
		: intSequence_(intSequence) {}

		// pushInt in invoker will dynamically allocate new PushCommand that pushes int i
		void pushInt(int i) {
			AbstractCommand* command = new PushCommand(&intSequence_, i);
			command->execute();
			doneCommands_.push(command);
		}

		// popInt in invoker will dynamically allocate new PopCommand that pops integer at back
		void popInt() {
			AbstractCommand* command = new PopCommand(&intSequence_);
			command->execute();
			doneCommands_.push(command);			
		}

		// Uses the unexecute at command on top of stack to undo it then deletes this command
		void undo() {
			if(!doneCommands_.empty()) {
				AbstractCommand* command = doneCommands_.top();
				doneCommands_.pop();
				command->unexecute();
				delete command;
			} else {
				std::cout << "No commands to undo" << std::endl;
			}
		}

		// Prints sequence
		void print() { intSequence_.print(); }

	private:
		// Receiver that invoker will execute commands on
		IntSequence intSequence_;
		// Stack of commands done on receiver
		std::stack<AbstractCommand*> doneCommands_;
};