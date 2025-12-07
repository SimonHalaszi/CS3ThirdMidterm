/*

PATTERNS
- registry: canonical vs. non-canonical pattern, 
  use, implementation

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include "Registry.hpp"
#include <iostream>

int main() {
    IntEntry ten("ten", 10);
    IntEntry* twenty = new IntEntry("twenty", 20);

    IntRegistry::addEntry(&ten);
    IntRegistry::addEntry(twenty);

    IntEntry* getter;
    getter = IntRegistry::accessEntry("twenty");
    
    if(getter != nullptr) {
        std::cout << "Entry: " << getter->getName() << " ";
        std::cout << "Has: " << getter->getInt() << " ";
        std::cout << std::endl;
    }

    getter = IntRegistry::accessEntry("ten");
    if(getter != nullptr) {
        std::cout << "Entry: " << getter->getName() << " ";
        std::cout << "Has: " << getter->getInt() << " ";
        std::cout << std::endl;
    }

    IntRegistry::removeEntry("ten");

    getter = IntRegistry::accessEntry("ten");
    if(getter != nullptr) {
        std::cout << "Entry: " << getter->getName() << " ";
        std::cout << "Has: " << getter->getInt() << " ";
        std::cout << std::endl;
    }

    delete twenty;
}