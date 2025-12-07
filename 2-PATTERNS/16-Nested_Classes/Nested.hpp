/*

PATTERNS
- nested classes

*/

// Enclosing Class
class EnclosingClass {
    public:
        EnclosingClass(int i = 0, int pubi = 0, int privi = 0);

        int addInnies() const;

        // May forwardly declare nested class
        class InnerPublicClass {
            public:
                InnerPublicClass(int i = 0)
                : innerPrivateInt_(i) {}

                int getInt() const;

            private:
                int innerPrivateInt_;
        };

        ~EnclosingClass() { delete publicInny_; delete privateInny_; }

    private:
        // Private member of Enclosing Class
        int enclosingInt_;

        // Nested class may be defined inside enclosing class
        class InnerPrivateClass {
            public:
                InnerPrivateClass(int i = 0)
                : innerPrivateInt_(i) {}

                int getInt() const;
            
            private:
                int innerPrivateInt_;
        };

        InnerPublicClass* publicInny_;
        InnerPrivateClass* privateInny_;
};

EnclosingClass::EnclosingClass(int i, int pubi, int privi)
: enclosingInt_(i), 
  publicInny_(new InnerPublicClass(pubi)),
  privateInny_(new InnerPrivateClass(privi))
  {}

int EnclosingClass::addInnies() const {
    // publicInny_->innerPrivateInt_; // cant do
    return publicInny_->getInt() + privateInny_->getInt();
}

int EnclosingClass::InnerPublicClass::getInt() const {
    return innerPrivateInt_;
}

int EnclosingClass::InnerPrivateClass::getInt() const {
    return innerPrivateInt_;
}