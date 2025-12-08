/*

PATTERNS
- smart pointers: unique_ptr, make_unique, managing arrays with
  	unique_ptr, shared_ptr, use_count(), weak_ptr and reference
	cycle, lock() and expired()

c++ main.cpp
./a.out > output.txt
valgrind --leak-check=full --log-file=valgrind_output.log ./a.out
rm ./a.out

*/

#include <memory>
#include <iostream>

// Classes used to make reference cycle

class A {
	public:
		std::shared_ptr<class B> bPtr_;
		~A() {}
};

class B {
	public:
		/*
		If we did another shared pointer here then if the reference count would
		never be zero is either aPtr_ or bPtr_ 
		*/
		// std::shared_ptr<class A> aPtr_;

		// Make atleast one part of this cycle weak. 
		std::weak_ptr<A> aPtr_;
		~B() {}
};

int main() {
	{
	std::unique_ptr<int> up1(new int(10));
	std::cout << *up1 << std::endl;

	std::unique_ptr<int> up2;
	// up2 = up1; // Cant do, Cant copy value of unique_ptr
	up2 = std::make_unique<int>(20);
	std::cout << *up2 << std::endl;

	/*
	Can do, old 20 int wont be leaked, it will get destroyed.
	Then up2 will be reassigned. Not a feature of dumb pointers
	*/
	up2 = std::make_unique<int>(40);

	// Arrays declared as such, both size 10
	std::unique_ptr<int[]> upa1(new int[10]);
	std::unique_ptr<int[]> upa2 = std::make_unique<int[]>(10);

	// Interface with like normal pointer array
	for(int i = 0; i < 10; ++i) {
		upa2[i] = i;
	}
	for(int i = 0; i < 10; ++i) {
		std::cout << upa2[i] << " ";
	}
	std::cout << std::endl;

	// Cant get underlying pointer, but now object is not unqiue
	int* p1 = up1.get();
	std::cout << *p1 << std::endl;
	} // Scope for all these pointers ended. Memory is deallocated

	{
		std::shared_ptr<A> a = std::make_shared<A>();
		std::shared_ptr<B> b = std::make_shared<B>();

		/*
		Even though objects refer to each other there is no cycle.
		Because b internally has a weak_ptr of type A
		*/
		a->bPtr_ = b;
		b->aPtr_ = a;

		std::cout << a->bPtr_.use_count() << std::endl; // 2 (b, and bPtr_)
		std::cout << b->aPtr_.use_count() << std::endl; // 1 (a, aPtr_ doesnt count)

		// expired() returns if weak pointer is poiting to nothing
		if(!b->aPtr_.expired()) {
			std::cout << "Weak ptr is still pointing to somewhere" << std::endl;
		}

		// lock() gets weak pointers underlying shared_pointer
		std::shared_ptr<A> a2 = b->aPtr_.lock();

		std::cout << b->aPtr_.use_count() << std::endl; // 2 (a, a2, aPtr_ doesnt count)

		b->aPtr_.reset();
		if(b->aPtr_.expired()) {
			std::cout << "Weak ptr is still expired!" << std::endl;
		}

		std::cout << a.use_count() << std::endl; // 2 (a, a2)

		// Just so we restablish reference cycle before we leave scope
		b->aPtr_ = a;

	} // Scope for all these pointers ended. Memory is deallocated
	// No memory leak at exit because reference cycle is properly handled.
	// Valgrind confirms this.
}