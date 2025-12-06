#pragma once

/*

PATTERNS
- composite: component, composite, leaf

*/

#include <iostream>
#include <vector>

// AbstractComponent that implements basic component interface
class AbstractComponent {
    public:
        AbstractComponent() : AbstractComponent('\0', nullptr) {}
        AbstractComponent(char c, AbstractComponent* composer) : c_(c), composer_(composer) {}

        // Prints the basic information about this component
        void info() const { 
            std::cout << "Component: " << c_ ;
            if(composer_ != nullptr) {
                std::cout << " inside of component " << c_ << std::endl;
            }
            else {
                std::cout << std::endl;
            }
        }

        char getName() const { return c_; }

        AbstractComponent* getComposer() const { return composer_; }
        void setComposer(AbstractComponent* composer) { composer_ = composer; }

        // Abstract accept function to combine this pattern with visitor pattern
        virtual void accept(class AbstractVisitor* visitor) = 0;

        // Virtual destructor
        virtual ~AbstractComponent() {}

    private:
        char c_;

        // Pointer to optional composer of this component
        AbstractComponent* composer_;
};

// Composite Component
class CompositeComponent : public AbstractComponent {
    public:      
        CompositeComponent() : AbstractComponent() {}
        CompositeComponent(char c, AbstractComponent* composer) : AbstractComponent(c, composer) {}

        // Returns components this component composes
        std::vector<AbstractComponent*>& getComponents() { return components_; }
        
        // Adds a component to this composits components
        void addComponent(AbstractComponent* component) {
            components_.push_back(component);
            // Set added components composer automatically to this component
            component->setComposer(this);
        }
        
        // Overriding of accept to have special functionality for composite components
        virtual void accept(class AbstractVisitor* visitor) override;

        // Composite components handles destruction of its components
        ~CompositeComponent() override {
            for(AbstractComponent* ac : components_) {
                delete ac;
            }
        }

    private:
        // Components this composite composes
        std::vector<AbstractComponent*> components_;
};

// Leaf Component
class LeafComponent : public AbstractComponent {
    public:
        LeafComponent() : AbstractComponent() {}
        LeafComponent(char c, AbstractComponent* composer) : AbstractComponent(c, composer) {}

        // Overriding of accept to have special functionality for leaf components
        void accept(class AbstractVisitor* visitor) override;

        ~LeafComponent() override {}
};

// Abstract Visitor
class AbstractVisitor {
    public:
        // Visit overloads for each type of component
        virtual void visit(LeafComponent* leaf) = 0;
        virtual void visit(CompositeComponent* composite) = 0;
        
        virtual ~AbstractVisitor() {}
};

// Leaf component accept override
void LeafComponent::accept(AbstractVisitor* visitor) {
    // For leaf accept simply just makes visitor visit itself
    visitor->visit(this);
}

// Composite component accept override
void CompositeComponent::accept(AbstractVisitor* visitor) {
    // For composite component the visit visits the composite then all of its components
    visitor->visit(this);

    for(AbstractComponent* ac : components_) {
        ac->accept(visitor);
    }

    std::cout << "No longer in a composite" << std::endl;
}

// Concrete Visitor
class ConcreteVisitor : public AbstractVisitor {
    public:
        // Visit to a leaf just prints that leafs info
        void visit(LeafComponent* leaf) override {
            leaf->info();
        }
        
        // Visit to a composite prints that it is a composite and gets its info
        void visit(CompositeComponent* composite) override {
            std::cout << "Im a composite! ";
            composite->info();
        }

        ~ConcreteVisitor() override {}
};


