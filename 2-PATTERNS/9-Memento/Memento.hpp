#pragma once

/*

PATTERNS
- memento: originator, memento, caretaker, 
           saving/restoring object state

*/

#include <iostream>
#include <vector>

// Originator
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

        // Methods originator implements for Memento pattern
        // Returns dynamically allocated Memento with current state internally
        class Memento* checkpoint() const;
        // Assigns internals to the internals of inputted Memento
        void rollback(const class Memento* checkpoint);

	private:
		// Sequence of ints
		std::vector<int> sequence_;
};

// Memento
class Memento {
    public:
        Memento(const IntSequence& intSequence) 
        : intSequence_(intSequence) {}
        
        const IntSequence& getInternals() const { 
            return intSequence_; 
        }

    private:
        const IntSequence intSequence_;
};

Memento* IntSequence::checkpoint() const {
    std::cout << "State Checkpointed" << std::endl;
    return new Memento(*this); // Copying of the IntSequence into Memento
}

void IntSequence::rollback(const Memento* checkpoint) {
    std::cout << "State Rollbacked" << std::endl;
    *this = checkpoint->getInternals(); // Copying in of IntSequence from Memento
}