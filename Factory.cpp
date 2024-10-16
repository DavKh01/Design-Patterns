#include <iostream>
class Pizza {
public:
	virtual void MakePizza() = 0;
	virtual ~Pizza() = default;
};

class CheesePizza : public Pizza {
public:
	void MakePizza() override {
		std::cout << "Making Cheese Pizza:\n";
	}
};

class PeperoniPizza : public Pizza {
public:
	void  MakePizza() override {
		std::cout << "Making Peperoni Pizza:\n";
	}
};

class PizzaFactory {
public:
	Pizza* CreatePizza(const std::string& type) {
		if (type == "cheese") {
			return new CheesePizza;
		}
		else if (type == "peperoni") {
			return new PeperoniPizza;
		}
		return nullptr;
	}
};

int main() {
	PizzaFactory factory;
	std::string str = "peperoni";
	Pizza* pizza = factory.CreatePizza(str);
	pizza->MakePizza();
	delete pizza;
}