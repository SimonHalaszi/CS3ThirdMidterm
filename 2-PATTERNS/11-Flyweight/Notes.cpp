/*

PATTERNS
- flyweight:  intrinsic/extrinsic state, 
  abstract/concrete flyweight, 
  client, factory

NOTES:

* flyweight:  intrinsic/extrinsic state, 
  abstract/concrete flyweight, 
  client, factory

	Motivation:
	
	- Need to share frequently occuring repeated data

	Pattern:

	- Flyweight - creates a pool of objects to be shared and
	reused

	- Terms
		- Intrinsic (immutable) - State independent part to be
		stored in the Flyweight object

		- Extrinsic (mutable) - Stateful part to be stored in the
		client object

	- Participants
		- Abstract Flyweight - Defines interface for the intrinsic
		part

		- Concrete Flyweight - Implements the intrinsic part

		- Client - Stores the extrinsic part of the object

		- Factory - Maintains the collection of flyweight objects

	- Notes
		- Uses Factory pattern to maintain a flyweight registry map

		- Often used in composite to maintain leaf nodes
			- Flyweight will define intrinsic states of leaf nodes

	Structural Pattern

    Motivation in my words:

    Some read only objects can be big and expensive. In this case its useful 
	to only initialize these objects once and reference their intrinsic info 
	when needed, instead of copying this info many times. On top of this
	its useful to have a factory that handles the finding of these objects
	for the client.
      
    Technical Details:

	AbstractFlyweight class defines an interface for the potentially large and
	expensive objects. ConcreteFlyweights implement that actual functionality
	of these objects. A, typically singleton, FlyweightFactory class holds
	a static map that maps Flyweight indentifiers to their corresponding 
	AbstractFlyweight* pointers. When a client needs to reference the expensive data
	held by the Flyweights they consult the FlyweightFactory for the Flyweight
	by identifier. The data of these Flyweights is immutable and read-only.
	Clients are only free to reference it not change it. FlyweightFactory
	handles the creation of Flyweights as they are needed. If client ask
	for unintialized valid identifier it creates the new large ConcreteFlyweight
	object and returns it. If the client ask for an intialized indentifer the
	FlyweightFactory returns a AbstractFlyweight* pointer to the corresponding
	ConcreteFlyweight. Clients own state and data is known as the extrinsic information
	while the data the client refers to with the AbstractFlyweight pointer is
	the Flyweights intrisic data.

*/