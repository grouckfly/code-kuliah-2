#include <iostream>
using namespace std;

class Line
{
public:
    void setLength(double len);
    double getLength(void);
    Line();  // This is the constructor declaration
    ~Line(); // This is the destructor: declaration
private:
    double length;
};

// Member functions definitions including constructor
Line::Line(void)
{
    cout << "Object is being created" << endl;
}

Line::~Line(void)
{
    cout << "Object is being deleted" << endl;
}

void Line::setLength(double len)
{
    length = len;
}

double Line::getLength(void)
{
    return length;
}

class Box
{
public:
    Box();  // Constructor
    ~Box(); // Destructor
    void setDimensions(double len, double wid, double hei);
    double getVolume();

private:
    double length;
    double width;
    double height;
};

// Constructor definition
Box::Box()
{
    cout << "Box object is being created" << endl;
}

// Destructor definition
Box::~Box()
{
    cout << "Box object is being deleted" << endl;
}

// Member function definitions
void Box::setDimensions(double len, double wid, double hei)
{
    length = len;
    width = wid;
    height = hei;
}

double Box::getVolume()
{
    return length * width * height;
}

// Main function for the program
int main()
{
    Line line;
    // set line length
    line.setLength(6.0);
    cout << "Length of line : " << line.getLength() << endl;

    Box box;
    box.setDimensions(5.0, 4.0, 3.0);
    cout << "Volume of box : " << box.getVolume() << endl;

    return 0;
}