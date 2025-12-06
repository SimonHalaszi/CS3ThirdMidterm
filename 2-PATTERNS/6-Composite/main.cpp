/*

PATTERNS
- composite: component, composite, leaf

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include "Composite.hpp"

int main() {
    // Create a composite
    CompositeComponent* A = new CompositeComponent('A', nullptr);

    // Create leafs and add them to composite
    LeafComponent* a = new LeafComponent('a', A);
    A->addComponent(a);
    LeafComponent* b = new LeafComponent('b', A);
    A->addComponent(b);

    // Create a concrete visitor
    AbstractVisitor* v = new ConcreteVisitor();

    // Can accept the same visitor to either a composite or leaf
    A->accept(v); std::cout << std::endl;
    a->accept(v); std::cout << std::endl;

    CompositeComponent* B = new CompositeComponent('B', nullptr);

    // Composites can compose other composites
    A->addComponent(B);

    // Creating leafs for composite B
    LeafComponent* c = new LeafComponent('c', B);
    B->addComponent(c);
    LeafComponent* d = new LeafComponent('d', B);
    B->addComponent(d);    

    // Can also create leaf in place for a component
    B->addComponent(new LeafComponent('e', B));
    
    // Check output to see nested hierarchy
    A->accept(v); std::cout << std::endl;
    B->accept(v); std::cout << std::endl;

    // Can simply delete composite that composes all other components
    delete A;

    // Leaf component can exist on its own
    LeafComponent* e = new LeafComponent('e', nullptr);
    e->accept(v);

    // Deletion of independet leaf and visitor
    delete e;
    delete v;
}