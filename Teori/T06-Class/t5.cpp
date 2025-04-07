#include <iostream>
using namespace std;

class Box
{
protected:
    double width;
    double length; // Tambahkan atribut length untuk perhitungan luas alas
};

class SmallBox : Box // SmallBox is the derived class.
{
public:
    void setSmallWidth(double wid);
    double getSmallWidth(void);
};

// Member functions of child class
double SmallBox::getSmallWidth(void)
{
    return width;
}

void SmallBox::setSmallWidth(double wid)
{
    width = wid;
}

// Subclass RectangleBox
class RectangleBox : public Box
{
public:
    void setDimensions(double len, double wid)
    {
        length = len;
        width = wid;
    }

    double getBaseArea()
    {
        return length * width;
    }
};

// Main function for the program
int main()
{
    RectangleBox rectBox;

    // Set dimensions of the rectangle box
    rectBox.setDimensions(10.0, 5.0);

    // Calculate and display the base area
    cout << "Base area of RectangleBox : " << rectBox.getBaseArea() << endl;

    return 0;
}