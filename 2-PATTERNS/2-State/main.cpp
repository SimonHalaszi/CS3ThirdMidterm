/*

PATTERNS
- state: context, state abstract/concrete

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include "State.hpp"

int main() {
    // Context behavior depends on state it is. Behavior printed by reportState.
    Context context(Center::instance());
    context.reportState();

    // Interface of context can automatically handle state changes internally.
    context.left();
    context.reportState();

    context.left();
    context.reportState();

    context.right();
    context.reportState();

    context.right();
    context.reportState();

    context.right();
    context.reportState();

    context.left();
    context.reportState();

    // Client can manually change context state.
    context.changeState(Right::instance());
    context.reportState();

    context.changeState(Left::instance());
    context.reportState();

    context.changeState(Center::instance());
    context.reportState();
}