/*

PATTERNS
- mediator: abstract/concrete mediator, colleague, push/pull for
  	    mediator

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>
#include "Mediator.hpp"

int main() {
	// Our mediator
	ConcreteMediator* mediator = new ConcreteMediator;

	// Some colleagues, initialized with our mediator
	AbstractColleague* addFromTen = new AdditiveColleague('t', 10, mediator);
	AbstractColleague* multFromFive = new MultiplyingColleague('m', 5, mediator);
	AbstractColleague* addFromEight = new AdditiveColleague('e', 8, mediator);

	// Observe the state of addFromTen (Pulling)
	mediator->observeColleague(addFromTen);

	// Broadcast an int to all colleagues to use (Pushinh)
	mediator->broadcastInt(5);

	// Observe all colleagues to this mediator
	mediator->observeAllColleagues();

	// Unlink addFromEight
	mediator->unlink(addFromEight);

	// addFromEight wont get this broadcast!
	mediator->broadcastInt(5);

	// addFromEight not included!
	mediator->observeAllColleagues();
	
	// message falls on deaf ears
	mediator->observeColleague(addFromEight);

	// Re-link addFromEight
	mediator->link(addFromEight);

	// Communication works both ways
	mediator->observeColleague(addFromEight);
	addFromEight->talkToMediator();

	delete mediator;
	delete addFromTen;
	delete multFromFive;
	delete addFromEight;
}