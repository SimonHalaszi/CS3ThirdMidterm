/*

PATTERNS
- chain of responsibility: handler, successor

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include "COR.hpp"

int main() {
    // Runtime creation of chains with varying degrees of request percision
    BaseHandler* chain = new ExpertHandler();

    chain->handleRequest(5);

    delete chain;    
    
    chain = new NoviceHandler(new ExpertHandler());

    chain->handleRequest(5);

    delete chain;

    chain = new BeginnerHandler(new NoviceHandler(new ExpertHandler()));

    chain->handleRequest(5);
    chain->handleRequest(15);
    chain->handleRequest(55);

    chain->handleRequest(150);

    delete chain;   
}