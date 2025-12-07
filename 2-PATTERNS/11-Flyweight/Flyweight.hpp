#pragma once

/*

PATTERNS
- flyweight:  intrinsic/extrinsic state, 
  abstract/concrete flyweight, 
  client, factory

*/

#include <iostream>
#include <map>

enum class FlyweightName {one, two};

// Abstract Flyweight
class AbstractFlyweight {
	public:
		AbstractFlyweight(int i = 1) : i_(i) {}

		// Abstract function for per concrete flyweight functionality
		virtual void printName() const = 0;
		
		// Returns const reference to the intrinsic part for client to use
		const int& getIntrinsic() const { return i_; }

		virtual ~AbstractFlyweight() {}
	private:
		/*
		This intrinsic part is potentially very large, thus the
		need for the FlyWeight pattern. Const because intrinisic part
		is immutable.
		*/
		const int i_;
};

// Concrete Flyweight
class OneFlyweight : public AbstractFlyweight {
	public:
		OneFlyweight() : AbstractFlyweight(1) {}

		// Implementation of abstract function
		void printName() const override {
			std::cout << "One";
		}

		~OneFlyweight() override {}
};

// Concrete Flyweight
class TwoFlyweight : public AbstractFlyweight {
	public:
		TwoFlyweight() : AbstractFlyweight(2) {}

		// Implementation of abstract function
		void printName() const override {
			std::cout << "Two";
		}

		~TwoFlyweight() override {}
};

// Factory, Implements the resource pool
class FlyweightFactory {
	public:
		/*
		Function for retreiving singular concrete flyweight instance
		inside the static pool.
		*/
		static AbstractFlyweight* getFlyweight(FlyweightName name) {
			// If this name does not map to an instance yet
			if(pool_.find(name) == pool_.end()) {
				// Dynamically allocate new instance for name to map to
				if(name == FlyweightName::one) {
					pool_[name] = new OneFlyweight;
				}
				else if(name == FlyweightName::two) {
					pool_[name] = new TwoFlyweight;
				}
			}
			// Return this instance
			return pool_[name];
		};

	private:
		/*
		Static mapping of valid FlyweightNames to their corresponding
		concrete flyweights. This is the resource pool.
		*/
		static std::map<FlyweightName, AbstractFlyweight*> pool_;
};

// Initialize static map
std::map<FlyweightName, AbstractFlyweight*> FlyweightFactory::pool_;

// Client class that uses flyweight to access potentially expensive intrisic data
class Client {
	public:
		Client(char c = '\0', FlyweightName fn = FlyweightName::one) 
		: c_(c), flyweight_(FlyweightFactory::getFlyweight(fn)) {}

		void printState() const {
			std::cout << "Client " << c_
			<< ". Using Flyweight "; flyweight_->printName();
			std::cout << " which holds intrinsic data " 
			<< flyweight_->getIntrinsic() << std::endl;
		}

		void changeFlyweight(FlyweightName fn) {
			flyweight_ = FlyweightFactory::getFlyweight(fn);
		}

	private:
		// Client extrinsic data
		char c_;
		// Flyweight intrinsic data
		AbstractFlyweight* flyweight_;
};