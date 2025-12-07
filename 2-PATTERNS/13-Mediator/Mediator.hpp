#pragma once

/*

PATTERNS
- mediator: abstract/concrete mediator, colleague, push/pull for
  mediator

*/

#include <set>
#include <iostream>

class AbstractColleague;

// AbstractMediator class that defines Mediator interface
class AbstractMediator {
	public:
		// Linking functions for colleagues to join and leave communication with mediator
		virtual void link(AbstractColleague*) = 0;
		virtual void unlink(AbstractColleague*) = 0;
		
		// Communication methods
		virtual void broadcastInt(int i) = 0; // Push communication
		virtual void observeColleague(AbstractColleague*) = 0; // Pull communication (internally)
		virtual void observeAllColleagues() = 0;
};

// ConcreteMediator that defines semantics of Mediator interface
class ConcreteMediator : public AbstractMediator {
	public:
		ConcreteMediator() : colleagues_() {}

		void link(AbstractColleague*) override;
		void unlink(AbstractColleague*) override;
		void broadcastInt(int i) override;
		void observeColleague(AbstractColleague*) override;
		void observeAllColleagues() override;

	private:
		// Using a set to keep track of colleagues that are communicating with Mediator
		std::set<AbstractColleague*> colleagues_;
};

// AbstractColleague class that defines Colleague interface
class AbstractColleague {
	public:
		// Colleague is initialized with its mediator and automatically joins communication
		AbstractColleague(char c = '\0', int i = 0, AbstractMediator* am = nullptr)
		: c_(c), i_(i), mediator_(am) { 
			if(am != nullptr) am->link(this); 
		}

		// Communication methods
		virtual void getFromMediator(const int& i) = 0; // Pull communication
		
		void talkToMediator() {
			if(mediator_ != nullptr) {
				mediator_->observeColleague(this);	// Colleague pushes self to mediator
			}
		}

		char getName() const { return c_; }
		int getInt() const { return i_; }
		AbstractMediator* getMediator() const { return mediator_; }

		// Method so that colleagues may potentially change Mediators
		void changeMediator(AbstractMediator* newMediator) {
			// Dont redudantly change mediators
			if(newMediator == mediator_) {
				return;
			}

			// Keep track of oldMediator for unlinking
			AbstractMediator* oldMediator = mediator_;
			// Set mediator to new mediator
			mediator_ = newMediator;
			if(oldMediator != nullptr) {
				oldMediator->unlink(this);
			}
		} 

		virtual ~AbstractColleague() {}

	protected:
		char c_;
		int i_;
		// Pointer to mediator that is communicating with this colleague
		AbstractMediator* mediator_;
};

// Concrete Colleagues that define semantics of abstract functions of Colleague
class MultiplyingColleague : public AbstractColleague {
	public:
		MultiplyingColleague(char c = '\0', int i = 0, AbstractMediator* am = nullptr)
		: AbstractColleague(c, i, am) {}

		void getFromMediator(const int& i) override {
			i_ *= i;
		}
};

class AdditiveColleague : public AbstractColleague {
	public:
		AdditiveColleague(char c = '\0', int i = 0, AbstractMediator* am = nullptr)
		: AbstractColleague(c, i, am) {}

		void getFromMediator(const int& i) override {
			i_ += i;
		}
};

// Function for linking a colleague to a mediator
void ConcreteMediator::link(AbstractColleague* colleague) {
	colleague->changeMediator(this);
	colleagues_.insert(colleague);
	// Forcefully make sure this colleague interally has this Mediator
}

// Function for unlinking a colleague from a mediator
void ConcreteMediator::unlink(AbstractColleague* colleague) {
	colleague->changeMediator(nullptr);
	colleagues_.erase(colleague);
	// Forcefully make sure this colleague interally has no Mediator
}

// Function for pushing an integer to all colleagues
void ConcreteMediator::broadcastInt(int i) {
	for(AbstractColleague* colleague : colleagues_) {
		colleague->getFromMediator(i);
	}
}

void ConcreteMediator::observeColleague(AbstractColleague* colleague) {
	// Colleague is not an actual colleage of this Mediator.
	if(colleague->getMediator() != this) {
		return;
	}
	// Mediator pulls information from colleague that pushes itself to it
	std::cout << "Mediator is observing colleague ";
	std::cout << colleague->getName() << ". ";
	std::cout << "Which has a integer ";
	std::cout << colleague->getInt() << ". ";
	std::cout << std::endl;
}

void ConcreteMediator::observeAllColleagues() {
	for(AbstractColleague* colleague : colleagues_) {
		observeColleague(colleague);
	}
}