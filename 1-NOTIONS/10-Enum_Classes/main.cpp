/*

Notions
- C++11 enum classes

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

enum UnscopedEnums1 {one, two, three, four};

//enum UnscopedEnums2 {four, five, six, seven}; // Naming conflicts not legal with unscoped enums
enum UnscopedEnums2 {five, six, seven, eight};

enum class ScopedEnums1 {a, b, c, d};

enum class ScopedEnums2 {d, e, f, g}; // Naming conflicts legal with scoped enums

#include <iostream>

// using ScopedEnums1::a; // Legal in C++20

int main() {
    UnscopedEnums1 myUnscopedEnum1 = one;
    UnscopedEnums2 myUnscopedEnum2 = seven;

    // Compiler warning though it is legal
    // if(!(one == seven)) { std::cout << "Comparison of unrelated unscoped enums is legal" << std::endl }

    ScopedEnums1 myScopedEnum1 = ScopedEnums1::a;
    ScopedEnums2 myScopedEnum2 = ScopedEnums2::d;
    ScopedEnums2 myScopedEnum3 = ScopedEnums2::d;

    // if(myScopedEnum1 == myScopedEnum2) // Wont compile, not legal
    if(myScopedEnum2 == myScopedEnum3) {
        std::cout << "Comparison of related scoped enums is legal" << std::endl;
    }
}