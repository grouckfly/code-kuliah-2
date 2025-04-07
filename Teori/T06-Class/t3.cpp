#include <iostream>
using namespace std;

class Line
{
private:
    double length; // Ubah aksesibilitas menjadi private

public:
    void setLength(double len);
    double getLength(void);
};

// Member functions definitions
double Line::getLength(void)
{
    return length;
}

void Line::setLength(double len)
{
    length = len;
}

// Main function for the program
int main()
{
    Line line;

    // set line length using setter
    line.setLength(6.0);
    cout << "Length of line : " << line.getLength() << endl;

    // line.length = 10.0; // Tidak diperbolehkan karena length sekarang private

    return 0;
}