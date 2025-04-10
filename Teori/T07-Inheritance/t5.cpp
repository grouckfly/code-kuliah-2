#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    virtual double getArea() const = 0; // Virtual function (pure virtual)
    virtual ~Shape() {} // Virtual destructor
};

// Derived class: Triangle
class Triangle : public Shape {
public:
    Triangle(double w, double h) : width(w), height(h) {}

    // Override metode getArea
    double getArea() const override {
        return 0.5 * width * height;
    }

private:
    double width, height;
};

// Derived class: Circle
class Circle : public Shape {
public:
    Circle(double r) : radius(r) {}

    // Override metode getArea
    double getArea() const override {
        return 3.14159 * radius * radius;
    }

private:
    double radius;
};

int main() {
    // Membuat objek Triangle
    Shape* triangle = new Triangle(6, 12);
    cout << "Luas segitiga: " << triangle->getArea() << endl;

    // Membuat objek Circle
    Shape* circle = new Circle(5);
    cout << "Luas lingkaran: " << circle->getArea() << endl;

    // Membersihkan memori
    delete triangle;
    delete circle;

    return 0;
}