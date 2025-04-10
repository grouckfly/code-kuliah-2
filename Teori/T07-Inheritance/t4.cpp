#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }
    void setRadius(double r) { radius = r; }

protected:
    int width, height;
    double radius;
};

// Derived class: Triangle
class Triangle : public Shape {
public:
    // Metode untuk menghitung luas segitiga
    double getArea() {
        return 0.5 * width * height;
    }
};

// Derived class: Circle (using protected inheritance)
class Circle : protected Shape {
public:
    // Metode untuk mengatur radius
    void setCircleRadius(double r) { setRadius(r); }

    // Metode untuk menghitung luas lingkaran
    double getArea() {
        return 3.14159 * radius * radius;
    }
};

int main() {
    // Membuat objek Triangle
    Triangle triangle;
    triangle.setWidth(10);
    triangle.setHeight(5);
    cout << "Luas segitiga: " << triangle.getArea() << endl;

    // Membuat objek Circle
    Circle circle;
    circle.setCircleRadius(7); // Menggunakan metode setCircleRadius
    cout << "Luas lingkaran: " << circle.getArea() << endl;

    return 0;
}