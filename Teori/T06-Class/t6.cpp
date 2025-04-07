#include <iostream>
using namespace std;

class Line
{
public:
    void setLength(double len);
    double getLength(void);
    Line(double len); // Constructor dengan parameter
private:
    double length;
};

// Member functions definitions including constructor
Line::Line(double len)
{
    length = len;
    cout << "Object is being created with length: " << length << endl;
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
    Line line(6.0); // Membuat objek dengan panjang awal 6.0
    cout << "Length of line : " << line.getLength() << endl;

    // Mengubah panjang menggunakan setter
    line.setLength(10.0);
    cout << "Updated length of line : " << line.getLength() << endl;

    return 0;
}