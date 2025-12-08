/*

PATTERNS
- smart pointers: unique_ptr, make_unique, managing arrays with
  unique_ptr, shared_ptr, use_count(), weak_ptr and reference
  cycle, lock() and expired()

NOTES:

* smart pointers: unique_ptr, make_unique, managing arrays with
  unique_ptr, shared_ptr, use_count(), weak_ptr and reference
  cycle, lock() and expired()

	Whats Wrong with Dumb (Raw) Pointers

	- Ownership unclear: Declaration does not state where it should
	be destroyed when done using

	- Unclear if points to scalar or an arry

	- Exactly once destruction is problematic: What if there ar paths
	in program where pointer is not deallocated (memory leak) or doubly
	deallocated (unspecified behavior, usually segmentation fault)
		- Exceptions are particularly known for escaping clear
		deallocation paths
	
	- Unclear if loose (dangles)

	unique_ptr:

	- Ensures there is a single pointer to dynamically allocated object,
	invokes destructor of object when pointer goes out of scope

	- Need <memory>

	- Declared as such:
		unique_ptr<ObjectType> identifier(new ObjectType(constructor)); // C++11
		
		auto p2 = std::make_unique<ObjectType>(constructor) // C++14

		Array declared as follows

		std::make_unique<ObjectType[]>(size);
		std::unique_ptr<ObjectType[]> p(new ObjectType[size]);

	- Using:
		- Dereference and arrow operator are supporst

		- Cannot copy pointer, assign pointer, or pass pointer by value
			- No other unique_ptr should alias this memory

		- Can std::move()
			uniquePtr2 = std::move(uniquePtr1);
			
			or...

			unique_ptr<ObjectType> uniquePtr3(std::move(uniquePtr2));

		- Can reassign 
			p1.reset(); 
			p2.reset(new ObjectType(constructor));
			p3 = nullptr;

			Deallocates old memory

		- Can check if assigned if(p1)
			- Checks if p1 is or is not nullptr

		- Can be used in STL (co copy algs) 
			std::vector<unique_ptr<int>> v;

		- get() returns internal raw pointer

	- Deallocating: Destructor is called on owned object if
		- Pointer goes out of scope

		- Pointer gets reassigned

		- Pointer is assigned nullptr

	shared_ptr:

	- Keeps track of number of pointers pointinf to an object,
	deallocates object when zero pointers point to it

	- Need <memory>

	- Declaring
		auto sp = std::make_shared<ObjectType>(constructor); // C++11

	- Using
		- Dereference and arrow opertators supported

		- May copy, assign, pass by value

		- May reassign, check if assigned, compare, us in STL

	- Can check how many references
		sp.use_count()

	- Deallocting
		- Calls destructor when last reference disappears (gets
		rassigned, goes out of scope)

	- reset() exists to reset shared_ptr state to nullptr and decrement reference count
		- In case of weak_ptr does not decrement reference count

	Reference Cycle and Weak Pointer

	- shared_ptr may have a reference cycle that prevents objects from
	deallocation
		- The objects point to each other and thus reference count
		never reaches zero.

	- weak_ptr not included in reference count
		- Can be assigned/intialized from shared pointer
		
		- Not derferencable (* or -> are not defined)
			- May cause race condition with deallocation in multithreaded
			apps

			- wp.lock() returns underlying shared pointer

		- May be loose (dangle)
			- expired() to check if loose/unassigned

		- wp.use_count(), works if weak pointer is assigned, weak pointer
		not included in count

	Miscellany

	- No naked new and delete: Cause problems
		int* p = new int(55);

		unique_ptr<int> p1(p);

		unique_ptr<int> p2(p);

	- Preferably no new/delete at all

	- shared_ptr is more powerful but less effcient than unique_ptr
		- unique_ptr is ust a wrapper over a raw pointer

		- shared_ptr stored reference count, requires two memory lookups

	- auto_ptr is deprecated and to be avoided

*/