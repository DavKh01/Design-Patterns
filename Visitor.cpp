#include <iostream>

class AreaVisitor;

class Shape {
public:
    virtual void accept(AreaVisitor& visitor) = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
public:
    Rectangle(int a, int b) : a(a), b(b) {}
    void accept(AreaVisitor& visitor) override {
        visitor.visit(*this);
    }
    int height() const {
        return a;
    }
    int width() const {
        return b;
    }
private:
    int a;
    int b;
};

class Circle : public Shape {
public:
    Circle(double r) : r(r) {}
    void accept(AreaVisitor& visitor) override {
        visitor.visit(*this);
    }
    double radius() const {
        return r;
    }
private:
    double r;
};

class AreaVisitor {
public:
    void visit(Rectangle& rec) {
        std::cout << rec.height() * rec.width() << '\n';
    }
    void visit(Circle& cir) {
        std::cout << 3.14 * cir.radius() * cir.radius() << '\n';
    }
};

int main() {
    AreaVisitor visitor;
    Rectangle rec(3, 4);
    rec.accept(visitor);

    Circle cir(5.0);
    cir.accept(visitor);

    return 0;
}
