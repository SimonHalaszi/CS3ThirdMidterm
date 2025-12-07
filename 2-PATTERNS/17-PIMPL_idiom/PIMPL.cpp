/*

PATTERNS
- PIMPL idiom, motivation, handle/body

*/

#include "PIMPL.hpp"

class Handle::Body {
    public:
        Body(int data)
        : data_(data) {}

        int getData() const { return data_; }
        void setData(int i) { data_ = i; }

    private:
        int data_;
};

Handle::Handle() {
    body_ = new Body(0);
}

Handle::Handle(const Handle& copy) {
    body_ = new Body(copy.body_->getData());
}

Handle& Handle::operator=(const Handle& rhs) {
    if(this != &rhs) {
        delete body_;
        body_ = new Body(rhs.body_->getData());
    }
    return *this;
}

Handle::~Handle() {
    delete body_;
}

int Handle::getData() const { return body_->getData(); }
void Handle::setData(int i) { body_->setData(i); }