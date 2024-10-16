#include <iostream>
class Singleton {
private:
	Singleton() { std::cout << "only one"; }
public:
	static Singleton* instance;
	static Singleton& getInstance() {
		if (instance == nullptr) {
			instance = new Singleton();
		}
		return *instance;
	}
};
Singleton* Singleton::instance = nullptr;
int main() {
	Singleton& instance = Singleton::getInstance();
}