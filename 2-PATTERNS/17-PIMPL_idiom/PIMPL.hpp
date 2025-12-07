#pragma once

/*

PATTERNS
- PIMPL idiom, motivation, handle/body

*/

class Handle {
    public:
        // Constructor
        Handle();
        
        // Big three
        Handle(const Handle&);
        Handle& operator=(const Handle&);
        ~Handle();

        // Handle functions
        int getData() const;
        void setData(int);

    private:
        class Body;
        Body* body_;
}; 