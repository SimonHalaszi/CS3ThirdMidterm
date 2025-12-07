/*

PATTERNS
- memento: originator, memento, caretaker, 
  saving/restoring object state

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include "Memento.hpp"

int main() {
    IntSequence is;
    is.pushInt(1);
    is.pushInt(2);
    is.print();

    // Caretaker
    Memento* checkpoint = is.checkpoint();
    
    is.pushInt(3);
    is.print();

    is.rollback(checkpoint);
    delete checkpoint;
    is.print();

    is.pushInt(4);
    is.pushInt(5);
    is.print();

    checkpoint = is.checkpoint();
    
    is.pushInt(6);
    is.print();
    
    is.rollback(checkpoint);
    delete checkpoint;
    is.print();
}