#include <iostream>
class Coffee {
public:
	virtual ~Coffee() = default;
	virtual std::string getDescription() = 0;
	virtual double cost() = 0;
};

class SimpleCoffee :public Coffee {
public:
	std::string getDescription() override{
		return "Simple Coffee";
	}
	double cost() override{
		return 100;
	}
};

class CoffeeDecorator : public Coffee {
public:
	CoffeeDecorator(Coffee*& coffee) : decoratedCoffee{ coffee } {}
	virtual ~CoffeeDecorator() {
		delete decoratedCoffee;
	}
protected:
	Coffee* decoratedCoffee;
};

class MilkDecorator : public CoffeeDecorator {
public:
	MilkDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}
	std::string getDescription() override {
		return decoratedCoffee->getDescription() + ", Milk";
	}
	double cost() override {
		return decoratedCoffee->cost() + 50;
	}
};

class ChocolateDecorator : public CoffeeDecorator {
public:
	ChocolateDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}

	std::string getDescription() override {
		return decoratedCoffee->getDescription() + ", Chocolate";
	}
	double cost() override {
		return decoratedCoffee->cost() + 100;
	}
};

int main() {
	Coffee* myCoffee = new SimpleCoffee();
	std::cout << myCoffee->getDescription() << " $" << myCoffee->cost() << std::endl;

	myCoffee = new MilkDecorator(myCoffee);
	std::cout << myCoffee->getDescription() << " $" << myCoffee->cost() << std::endl;

	myCoffee = new ChocolateDecorator(myCoffee);
	std::cout << myCoffee->getDescription() << " $" << myCoffee->cost() << std::endl;

	delete myCoffee; // Clean up the whole chain

	return 0;
}