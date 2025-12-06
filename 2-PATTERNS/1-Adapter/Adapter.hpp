#pragma once

/*

PATTERNS
- adapter: adaptee, adapter, interface; 
  class and object implementation

*/

// Adaptee Class, that we dont want to change. Interface is func()
class Adaptee {
    public:
        Adaptee() : Adaptee(0) {}
        Adaptee(int i) : i_(i) {}

        int func() {
            return i_;
        }

    private:
        int i_;
};

// Abstract Interface for the Adapter. Interface is multiply()
class AbstractAdapter {
    public:
        AbstractAdapter() : AbstractAdapter(0) {}
        AbstractAdapter(int j) : j_(j) {}

        virtual int multiply() = 0;

        virtual ~AbstractAdapter() {}

    protected:
        int j_;
};

/*
Class example of Adapter, publically inherits interface from AbstractAdapter,
privately inherits Adaptee to hide Adaptee interface from client.
*/
class ClassAdapter : public AbstractAdapter, private Adaptee {
    public:
        ClassAdapter() : ClassAdapter(0, 0) {}
        ClassAdapter(int i, int j) : AbstractAdapter(j), Adaptee(i) {}

        int multiply() override {
            return func() * j_;
        }
};

/*
Object example of Adapter, publically inherits interface from AbstractAdapter,
holds instance of Adaptee privately to hide Adaptee interface from client.
*/
class ObjectAdapter : public AbstractAdapter {
    public: 
        ObjectAdapter() : ObjectAdapter(0, 0) {}
        ObjectAdapter(int i, int j) : AbstractAdapter(i), adaptee_(Adaptee(j)) {}

        int multiply() override {
            return adaptee_.func() * j_;
        }

    private:
        Adaptee adaptee_;
};  