#include <iostream>
class Image {
public:
	virtual void display() = 0;
	virtual ~Image() = default;
};

class RealImage : public Image {
public:
	RealImage(std::string& filename) : filename(filename) {
		load();
	}
	void display() override {
		std::cout << "displaying " << filename << std::endl;
	}
private:
	void load() {
		std::cout << "loading " << filename << " from disk...\n";
	}
	std::string filename;
};

class ProxyImage : public Image {
public:
	ProxyImage(std::string filename) : filename(filename), realimage(nullptr){}
	~ProxyImage() {
		delete realimage;
	}
	void display() override {
		if (!realimage) {
			realimage = new RealImage(filename);
		}
		realimage->display();
	}
private:
	std::string filename;
	RealImage* realimage;
};

int main() {
	Image* image = new ProxyImage("test.jpg");
	image->display();

	image->display();

	delete image;
}