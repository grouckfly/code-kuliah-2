#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }

protected:
    int width, height;
};

// Derived class
class Triangle : public Shape {
public:
    // Metode untuk menghitung luas segitiga
    double getArea() {
        return 0.5 * width * height;
    }
};

int main() {
    // Membuat objek Triangle
    Triangle triangle;
    triangle.setWidth(10);
    triangle.setHeight(5);

    // Menampilkan luas segitiga
    cout << "Luas segitiga: " << triangle.getArea() << endl;

    return 0;
}