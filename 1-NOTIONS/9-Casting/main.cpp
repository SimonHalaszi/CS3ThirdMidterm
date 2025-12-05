/*

Notions
- C++11 style type casting, static_cast vs. dynamic_cast; 
  reinterpret_cast; const_cast

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>

class BaseAbs {
    public:
        virtual void func() = 0;

        virtual ~BaseAbs() {}
};

class DerivedAbs1 : public BaseAbs {
    void func() override {}
};

class DerivedAbs2 : public BaseAbs {
    void func() override {}
};

class BaseNotAbs {
    public:
        void func() {}

        virtual ~BaseNotAbs() {}
};

class DerivedNotAbs1 : public BaseAbs {
    // Nothing
};

class OtherClass {

};

class IntWrapper {
    public: 
        int i;
};

int main() {
    // Static Cast
    
    int i = static_cast<int>('a'); // Works!
    std::cout << i << std::endl;

    BaseAbs* ptr = new DerivedAbs1;

    DerivedAbs1* da1ptr = static_cast<DerivedAbs1*>(ptr); // Works, is correct
    DerivedAbs2* da2ptr = static_cast<DerivedAbs2*>(ptr); // Works, not correct

    if(da1ptr) {
        std::cout << "da1ptr assigned to " << da1ptr << std::endl;
    }
    if(da2ptr) {
        std::cout << "da1ptr assigned to " << da2ptr << std::endl;
    }

    // Dynamic Cast

    da1ptr = dynamic_cast<DerivedAbs1*>(ptr); // Works, is correct
    if(da1ptr != nullptr) {
        std::cout << "Dynamic cast worked" << std::endl;
    }
    else {
        std::cout << "Dynamic cast did not work" << std::endl;
    }    

    da2ptr = dynamic_cast<DerivedAbs2*>(ptr); // Does not work, is not correct
    if(da2ptr != nullptr) {
        std::cout << "Dynamic cast worked" << std::endl;
    }
    else {
        std::cout << "Dynamic cast did not work" << std::endl;
    }

    BaseAbs* baseptr;

    baseptr = dynamic_cast<BaseAbs*>(ptr); // Works, is correct
    if(baseptr != nullptr) {
        std::cout << "Dynamic cast worked" << std::endl;
    }
    else {
        std::cout << "Dynamic cast did not work" << std::endl;
    }

    OtherClass* otherptr;

    otherptr = dynamic_cast<OtherClass*>(ptr); // Does not work, is not correct
    if(otherptr != nullptr) {
        std::cout << "Dynamic cast worked" << std::endl;
    }
    else {
        std::cout << "Dynamic cast did not work" << std::endl;
    }

    delete ptr;

    // Wont even compile / Wouldnt work
    // BaseNotAbs* newptr = new DerivedNotAbs1; 
    // DerivedNotAbs1* dna1ptr = dynamic_cast<DerivedNotAbs1*>(newptr)

    // Reinterpret cast

    IntWrapper iw;
    iw.i = 10;

    i = reinterpret_cast<int&>(iw);
    std::cout << i << std::endl;

    bool b;
    
    i = reinterpret_cast<int&>(b);
    std::cout << i << std::endl;

    // Const cast

    int j = 20;
    const int& constjref = j; // Say j passed by const reference into function
    // constjref = 40; // Cant do but I want to
    int& nonconstjref = const_cast<int&>(constjref); // Now I have nonconst version of constjref
    nonconstjref = 40; // Is now allowed inside my function! Without changing passing paradigm

    // Const cast causes undefined behavior however if int j was const to begin with

}