/*

PATTERNS
- strategy: strategy, context, push/pull for strategy

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>
#include "Strategy.hpp"

int main() {
    // Our context
    IntContext* context = new IntContext(1);

    // First, Push Strategies

    // Polymorphically interface, dynamically allocate add strategy
    Push_AbstractStrategy* pushStrategy = new Push_AddStrategy();
    context->setPushStrategy(pushStrategy);
    
    context->executePushStrategy();
    std::cout << context->getInt() << std::endl;
    
    delete pushStrategy;

    // Can change how pushStrategy functions at runtime
    pushStrategy = new Push_MultStrategy();
    context->setPushStrategy(pushStrategy);
    
    context->executePushStrategy();
    std::cout << context->getInt() << std::endl;
    
    delete pushStrategy;

    // Reset state for same results
    context->setInt(1);

    // Second, Pull Strategies

    // Polymorphically interface, dynamically allocate add strategy
    Pull_AbstractStrategy* pullStrategy = new Pull_AddStrategy(context);

    pullStrategy->execute();
    std::cout << context->getInt() << std::endl;
    
    delete pullStrategy;

    // Can change how pullStrategy functions at runtime
    pullStrategy = new Pull_MultStrategy(context);

    pullStrategy->execute();
    std::cout << context->getInt() << std::endl;
    
    delete pullStrategy;    

    delete context;
}