/*

PATTERNS
- observer: subject, observer, subscribing, registry,
  message (notification)

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include "Observer.hpp"
#include "ObserverRegistry.hpp"
#include <iostream>

int main() {
    // First Observer.hpp
    DerivedSubject ds('s', 0);
    ConcreteObserver co('o', &ds);

    ds.changeData(1);
    ds.changeData(2);

    ds.deregisterObserver(&co);

    ds.changeData(3);

    ds.registerObserver(&co);

    ds.changeData(4);

    ds.deregisterObserver(&co);

    // Second ObserverRegistry.hpp
    Subject s('s');
    Observer o('o');

    o.subscribe(&s);

    s.messageObservers();

    o.unsubscribe(&s);

    s.messageObservers();

    // Worth noting this two examples are not doing equal task. Thus why I must explicity notify observers in the second
}