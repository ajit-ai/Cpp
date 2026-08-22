// Inheritance, virtual functions (runtime polymorphism),
// abstract classes, and dynamic_cast.
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

// Abstract base class: has a pure virtual function, cannot be instantiated
class Shape {
   public:
    explicit Shape(string name) : name_(move(name)) {}
    virtual ~Shape() = default;   // always a VIRTUAL destructor in bases

    const string& name() const { return name_; }

    virtual double area() const = 0;      // pure virtual: derived MUST define
    virtual void describe() const {       // overridable with default behavior
        cout << name_ << " has area " << area() << endl;
    }

   private:
    string name_;
};

class Circle : public Shape {
   public:
    explicit Circle(double r) : Shape("Circle"), radius_(r) {}

    double area() const override { return 3.14159 * radius_ * radius_; }
    void describe() const override {
        cout << "Circle of radius " << radius_ << ", area " << area() << endl;
    }

   private:
    double radius_;
};

class Rectangle : public Shape {
   public:
    Rectangle(double w, double h) : Shape("Rectangle"), w_(w), h_(h) {}

    double area() const override { return w_ * h_; }

    // Extra method that only Rectangle has
    bool isSquare() const { return w_ == h_; }

   private:
    double w_, h_;
};

int main() {
    // Polymorphism through base-class pointers
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Circle>(2.0));
    shapes.push_back(make_unique<Rectangle>(3.0, 4.0));
    shapes.push_back(make_unique<Rectangle>(5.0, 5.0));

    for (const auto& shape : shapes) {
        shape->describe();   // correct override chosen at RUNTIME
    }

    cout << "total area = " << ([&] {
        double total = 0;
        for (const auto& s : shapes) total += s->area();
        return total;
    })() << endl;

    // dynamic_cast: safe downcasting from base to derived
    for (const auto& shape : shapes) {
        if (auto* rect = dynamic_cast<Rectangle*>(shape.get())) {
            cout << shape->name() << " is a rectangle, square? "
                 << (rect->isSquare() ? "yes" : "no") << endl;
        } else {
            cout << shape->name() << " is not a rectangle" << endl;
        }
    }

    return 0;
}
