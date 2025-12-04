#pragma once

#include <iostream>

// Concrete Base Class 
class BaseOne {
    public:
        BaseOne() : BaseOne(0) {}
        BaseOne(int i) : var_(i) {}

        void funcBaseOne() {
            std::cout << "BaseOne class feature" << std::endl;
        }

        virtual ~BaseOne() {}
    protected:
        int var_;

        void funcBaseOneProtected() {
            std::cout << "Protected BaseOne class feature" << std::endl;
        }
};

// Concrete Base Class 
class BaseTwo {
    public:
        BaseTwo() : BaseTwo(0) {}
        BaseTwo(int i) : var_(i) {}

        void funcBaseTwo() {
            std::cout << "BaseTwo class feature" << std::endl;
        }

        virtual ~BaseTwo() {}
    protected:
        int var_;
};

// Concrete DerivedPublic Class. Doubly inherits
class DerivedPublic : public BaseOne, public BaseTwo {
    public:
        DerivedPublic() : BaseOne() {}
        DerivedPublic(int i) : BaseOne(i) {}

        // funcBaseOne() automatically part of this classes public interface
        // Protected Base Class feature added to public interface using the 'using' keyword
        using BaseOne::funcBaseOneProtected;

        ~DerivedPublic() override {}
};

// Concrete DerivedPrivate Class. Doubly inherits
class DerivedPrivate : private BaseOne, public BaseTwo {
    public:
        DerivedPrivate() : BaseOne() {}
        DerivedPrivate(int i) : BaseOne(i) {}

        // funcBaseOne() must be specified as being used in the public field of this interface
        using BaseOne::funcBaseOne;
        // Protected Base Class feature added to public interface using the 'using' keyword
        using BaseOne::funcBaseOneProtected;

        ~DerivedPrivate() override {}
};

