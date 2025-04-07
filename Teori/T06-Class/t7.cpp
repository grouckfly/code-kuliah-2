#include <iostream>
using namespace std;

class Line
{
public:
    void setLength(double len);
    double getLength(void);
    Line(double len);           // Constructor
    Line(const Line &obj);      // Copy constructor
private:
    double length;
};

// Member functions definitions including constructor
Line::Line(double len) : length(len) // Member initializer list
{
    cout << "Object is being created, length = " << length << endl;
}

Line::Line(const Line &obj) : length(obj.length) // Copy constructor with member initializer list
{
    cout << "Copy constructor called, length = " << length << endl;
}

void Line::setLength(double len)
{
    length = len;
}

double Line::getLength(void)
{
    return length;
}

// Main function for the program
int main()
{
    Line line1(10.0);
    // get initially set length.
    cout << "Length of line1 : " << line1.getLength() << endl;

    // Create a copy of line1
    Line line2 = line1;
    cout << "Length of line2 : " << line2.getLength() << endl;

    // set line1 length again
    line1.setLength(6.0);
    cout << "Updated length of line1 : " << line1.getLength() << endl;

    return 0;
}