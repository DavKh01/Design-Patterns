#include <iostream>
class SupportHandler {
public:
	virtual ~SupportHandler() = default;
	void SetNext(SupportHandler* nextHandler) {
		next = nextHandler;
	}
	void handleRequest(const std::string& request) {
		if (canHandle(request)) {
			processRequest(request);
		}
		else if (next) {
			next->handleRequest(request);
		}
		else {
			std::cout << "request wasn't handeled:\n";
		}
	}
protected:
	virtual bool canHandle(const std::string& request) = 0;
	virtual void processRequest(const std::string& request) = 0;
private:
	SupportHandler* next = nullptr;
};

class SupportAgent : public SupportHandler {
protected:
	bool canHandle(const std::string& request) override {
		return request == "basic support";
	}
	void processRequest(const std::string& request) {
		std::cout << "Support agent handeled the request:\n";
	}
};

class Supervisor : public SupportHandler {
protected:
	bool canHandle(const std::string& request) override{
		return request == "intermidiate support";
	}
	void processRequest(const std::string& request) {
		std::cout << "Supervisor handeled the request:\n";
	}
};

class Manager : public SupportHandler {
protected:
	bool canHandle(const std::string& request) {
		return request == "advanced support";
	}
	void processRequest(const std::string& request) {
		std::cout << "Manager handeled the request:\n";
	}
};

int main() {
	SupportAgent sa;
	Supervisor sv;
	Manager mg;

	sa.SetNext(&sv);
	sv.SetNext(&mg);

	std::string requests[] = { "basic support", "intermidiate support", "advanced support", "unknown request" };

	for (const auto& request : requests) {
		sa.handleRequest(request);
	}
}