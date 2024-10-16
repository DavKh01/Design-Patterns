#include <iostream>
class Button {
public:
	virtual void MakeButton() = 0;
	virtual ~Button() = default;
};

class WindowsButton : public Button{
public:
	void MakeButton() override {
		std::cout << "Making Windows Button\n";
	}
};

class LinuxButton : public Button{
public:
	void MakeButton() override {
		std::cout << "Making Linux Button\n";
	}
};

class MacButton : public Button {
public:
	void MakeButton() {
		std::cout << "Making Mac Button\n";
	}
};

class CheckBox {
public:
	virtual void MakeCheckBox() = 0;
	virtual ~CheckBox() = default;
};

class WindowsCheckBox : public CheckBox {
public:
	void MakeCheckBox() {
		std::cout << "Making Windows CheckBox\n";
	}
};

class LinuxCheckBox : public CheckBox {
public:
	void MakeCheckBox() {
		std::cout << "Making Linux CheckBox\n";
	}
};

class MacCheckBox : public CheckBox {
public:
	void MakeCheckBox() {
		std::cout << "Making Mac CheckBox\n";
	}
};

class GuiFactory {
public:
	virtual Button* createButton() = 0;
	virtual CheckBox* createCheckBox() = 0;
	virtual ~GuiFactory() = default;
};

class WindowsFactory : public GuiFactory {
public:
	Button* createButton() {
		return new WindowsButton;
	}
	CheckBox* createCheckBox() {
		return new WindowsCheckBox;
	}
};

class LinuxFactory : public GuiFactory {
public:
	Button* createButton() {
		return new LinuxButton;
	}
	CheckBox* createCheckBox() {
		return new LinuxCheckBox;
	}
};

class MacFactory : public GuiFactory{
public:
	Button* createButton() {
		return new MacButton;
	}
	CheckBox* createCheckBox() {
		return new MacCheckBox;
	}
};

class AbstractFactory {
public:
	void CreateButton(std::string& system) {
		if (system == "windows") {
			factory = new WindowsFactory;
		}
		else if (system == "linux") {
			factory = new LinuxFactory;
		}
		else if (system == "mac") {
			factory = new MacFactory;
		}
		else {
			std::cout << "The request is not supported!!!" << std::endl;
		}
		Button* button = factory->createButton();
		CheckBox* checkbox = factory->createCheckBox();
		button->MakeButton();
		checkbox->MakeCheckBox();
	}
private:
	GuiFactory* factory = nullptr;
};


int main() {
	std::string system;
	AbstractFactory ob;
	std::cout << "enter your system name: ";
	std::cin >> system;
	ob.CreateButton(system);
}
