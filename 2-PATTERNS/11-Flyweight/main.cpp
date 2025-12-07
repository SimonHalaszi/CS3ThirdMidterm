/*

PATTERNS
- flyweight:  intrinsic/extrinsic state, 
  abstract/concrete flyweight, 
  client, factory

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include "Flyweight.hpp"

int main() {
	Client* clientA = new Client('A', FlyweightName::one);
	clientA->printState();

	Client* clientB = new Client('B', FlyweightName::two);
	clientB->printState();

	clientA->changeFlyweight(FlyweightName::two);
	clientA->printState();

	// Programmer client can grab flyweights themselves
	AbstractFlyweight* flyweight = FlyweightFactory::getFlyweight(FlyweightName::two);
	flyweight->printName(); std::cout << std::endl;

	// NOT LEGAL; Pattern enforces intrisic data is immutable
	// flyweight->getIntrinsic() = 3;

	delete clientA;
	delete clientB;
}