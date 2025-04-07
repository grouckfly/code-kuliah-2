#include <iostream>
using namespace std;

class Box
{
public:
    double length;  // Length of a box
    double breadth; // Breadth of a box
    double height;  // Height of a box

    // Member functions declaration
    double getVolume(void);
    double getSurfaceArea(void); // Fungsi untuk menghitung luas permukaan
    void setLength(double len);
    void setBreadth(double bre);
    void setHeight(double hei);
};

// Member functions definitions
double Box::getVolume(void)
{
    return length * breadth * height;
}

double Box::getSurfaceArea(void)
{
    return 2 * (length * breadth + breadth * height + height * length);
}

void Box::setLength(double len)
{
    length = len;
}

void Box::setBreadth(double bre)
{
    breadth = bre;
}

void Box::setHeight(double hei)
{
    height = hei;
}

// Main function for the program
int main()
{
    Box Box1;            // Declare Box1 of type Box
    Box Box2;            // Declare Box2 of type Box
    double volume = 0.0; // Store the volume of a box here
    double surfaceArea = 0.0; // Store the surface area of a box here

    // box 1 specification
    Box1.setLength(6.0);
    Box1.setBreadth(7.0);
    Box1.setHeight(5.0);

    // box 2 specification
    Box2.setLength(12.0);
    Box2.setBreadth(13.0);
    Box2.setHeight(10.0);

    // volume and surface area of box 1
    volume = Box1.getVolume();
    surfaceArea = Box1.getSurfaceArea();
    cout << "Volume of Box1 : " << volume << endl;
    cout << "Surface Area of Box1 : " << surfaceArea << endl;

    // volume and surface area of box 2
    volume = Box2.getVolume();
    surfaceArea = Box2.getSurfaceArea();
    cout << "Volume of Box2 : " << volume << endl;
    cout << "Surface Area of Box2 : " << surfaceArea << endl;

    return 0;
}